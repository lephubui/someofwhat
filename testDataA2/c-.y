%{ 
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "treeNode.h"
#include "scanType.h"
#include "ourgetopt.h"
#include "util.h"

#ifdef CPLUSPLUS

extern int yylex();
extern FILE* yyin;
static TreeNode * savedTree; /* stores syntax tree for later return */

#endif

void yyerror(const char *msg)
{
      printf("ERROR(PARSER): %s\n",msg);
}

// the syntax tree goes here
TreeNode *syntaxTree;

static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
bool flagCheck = false;
// variable storage
double vars[26];
%}

%union {
    ExpType expType;
    TokenData *tokenData; 
    TreeNode *tree;

}

// token specifies the token classes from the scanner
// Nonterminals
%type <tree> program declarationList statementList declaration varDeclaration 
%type <tree> funDeclaration scopedVarDeclaration varDeclList varDeclInitialize
%type <tree> varDeclId params paramList paramTypeList localDeclarations
%type <tree> statement simpleExpression sumExpression mulExpression
%type <tree> expression expressionStmt compoundStmt iterationStmt returnStmt breakStmt 
%type <tree> constant andExpression mutable iterationRange unaryRelExpression relExpression factor
%type <tree> immutable unaryExpression unaryop mulop call args argList paramId matchedWhile unmatchedWhile
%type <tree> matched unmatched matchedIf unmatchedIf relop sumop optionalStmt matchedElse unmatchedElse paramIdList
%type <expType> typeSpecifier scopedTypeSpecifier

// Terminals
%token <tokenData> STRINGCONST BOOL INT CHAR EQUAL ASPC RETURN NUMCONST ID LOOP FOREVER STATIC IF ELSE OR AND RANGE THEN DO NOT NONE
%token <tokenData> TRUE ELSEIF FALSE DIVASS LESSEQ GRTEQ DEC ADDASS SUBASS MULASS NOTEQ WHILE BREAK CHARCONST INC
%token <tokenData> '('
%token <tokenData> ')'
%token <tokenData> ','
%token <tokenData> '>'
%token <tokenData> '<'
%token <tokenData>  PLUS  MINUS MULTIPLY DIVIDE MODULUS QUESTION
%token <tokenData> ':'
%token <tokenData> '{'
%token <tokenData> '}'
%token <tokenData> ';'
%token <tokenData> '='
%token <tokenData> '['
%token <tokenData> ']'

%define parse.error verbose

%%
/*1*/
program : declarationList {
            $$ = $1; 
            syntaxTree = $$; 
            if(flagCheck) {printf("program\n");};
        }
        ;
/*2*/
declarationList : declarationList declaration {
		              // TreeNode *t = $1;
                  //             if(t != NULL){
                  //               while(t->sibling != NULL){
                  //                 t = t->sibling;
                  //               }
                  //               t->sibling = $2;
                  //             } else {
                  //               t = $2;
                  //             }
                  $$ = linkChild($1, $2);
                  ; if(flagCheck) {printf("declarationList declaration\n");};}
                | declaration { $$ = $1 ;if(flagCheck) {printf("declaration\n");};}
                ;
/*3*/
declaration : varDeclaration {$$ = $1; if(flagCheck) {printf("varDeclaration\n");};}
            | funDeclaration {$$ = $1 ;if(flagCheck) {printf("funDeclaration\n");};}
            ;

/*4*/
varDeclaration : typeSpecifier varDeclList ';' { $$ = $2 ;  
                childExpType($$, $1);
                if(flagCheck) {printf("typeSpecifier varDeclList\n");};}
               ;

/*5*/
scopedVarDeclaration : scopedTypeSpecifier varDeclList ';' {
                              $$ = $2;
                              childExpType($$, $1);
                              if(flagCheck) {printf("scopedTypeSpecifier varDeclList\n");};}
                     ;  
/*6*/
varDeclList : varDeclList ',' varDeclInitialize {
                              // Add silding
                             $$ = linkChild($1, $3);
                    if(flagCheck) {printf("varDeclList ',' varDeclInitialize\n");};}
            | varDeclInitialize {
                    $$ = $1; 
                    if(flagCheck) {printf("varDeclInitialize\n");};}
            ;

/*7*/
varDeclInitialize : varDeclId { $$ = $1; if(flagCheck) {printf("varDeclInitialize\n");};}
                  | varDeclId ':' simpleExpression {
                    $$ = $1;
                    $$->child[0] = $3;
                    if(flagCheck) {printf("varDeclId\n");};}
                  ;
/*8*/
varDeclId : ID  { if(flagCheck) {printf("varDeclId\n");};
                  $$ = newDeclNode(VarK, $1->linenum);
                  $$->attr.string = strdup($1->tokenstr);}
                | ID '['NUMCONST']' {
                  $$ = newDeclNode(VarK, $1->linenum);
                  $$->attr.value = $3->numValue;
                  $$->dataType = $1;
	                $$->attr.op = $2->tokenclass;
                  $$->isArray = true;
                  if(flagCheck) {printf("ID NUMCONST Token: \n");};}
                ;

/*9*/
scopedTypeSpecifier : STATIC typeSpecifier  { $$ = $2; if(flagCheck){printf("STATIC typeSpecifier %d Token: \n", $1->linenum);}; }
                    | typeSpecifier {$$ = $1; if(flagCheck){printf("Type Specifier: \n");};}
                    ;
/*10*/
typeSpecifier : INT {$$ = Int; if(flagCheck){printf("INT TYPE\n");};}
              | BOOL {$$ = Bool; if(flagCheck){printf("BOOL TYPE\n");};}
              | CHAR {$$ = Char; if(flagCheck){ printf("CHAR TYPE\n");};}
              ;
/*11*/
funDeclaration : typeSpecifier ID '('params')' statement {
                $$ = newDeclNode(FuncK, $2->linenum);
                $$->attr.string = strdup($2->tokenstr);
                $$->expType = $1;
                $$->child[0] = $4;
                $$->child[1] = $6; 
		            if(flagCheck) {printf("typeSpecifier ID params statement\n");};}
               | ID '('params')' statement {
                 $$ = newDeclNode(FuncK, $1->linenum);
           		   $$->attr.name = strdup($1->tokenstr);
		            $$->expType = Void;
                 $$->child[0] = $3;
                 $$->child[1]  = $5;
                 if(flagCheck) {printf("ID params statement\n");};}
               ;
/*12*/
params : paramList {$$ = $1; if(flagCheck){printf("paramList\n"); };}
       | { /*empty*/  $$ = NULL; }
       ;
/*13*/
paramList : paramList ';' paramTypeList { 
            // Add silbilin
            $$ = linkChild($1, $3);
            if(flagCheck){ printf("paramList ; paramTypeList\n");};}
          | paramTypeList {
            $$ = $1;
            if(flagCheck) {printf("paramList\n");};}
          ;
/*14*/
paramTypeList : typeSpecifier paramIdList { $$ = $2; 
                childExpType($$, $1);
              if(flagCheck){printf("typeSpecifier paramIdList\n");};}
              ;
/*15*/
paramIdList : paramIdList ',' paramId { 
              //Adding sibling;
              $$ = linkChild($1, $3);
              if(flagCheck){ printf("paramIdList ',' paramId\n");};}
            | paramId { $$ = $1 ;if(flagCheck){ printf("paramId\n");};}
            ;

/*16*/
paramId : ID  {
              $$ = newDeclNode(ParamK, $1->linenum);
              $$->attr.name = strdup($1->tokenstr);
              //$$->expType = Void;
              if(flagCheck){printf("ID\n");};}
        | ID '['']' { 
              $$ = newDeclNode(ParamK, $1->linenum);
              $$->attr.name = strdup($1->tokenstr);
              //$$->expType = Void;
              $$->isArray = true;
          if(flagCheck){printf("ID with [ \n");};}
        ;
/*17*/
statement : expressionStmt {$$ = $1; if(flagCheck){printf("expressionStmt\n");};}
          | compoundStmt  {$$ = $1; if(flagCheck){printf("compoundStmt\n");};}
          | matchedIf {$$ = $1; if(flagCheck){printf("selectionStmt\n");};}
          | unmatchedIf {$$ = $1; if(flagCheck){printf("selectionStmt\n");};} 
          | iterationStmt {$$ = $1; if(flagCheck){printf("iterationStmt\n");};}
          | returnStmt {$$ = $1; if(flagCheck){printf("returnStmt\n");};}
          | breakStmt {$$ = $1; if(flagCheck){printf("breakStmt\n");};}
          ;
/*18*/
expressionStmt : expression ';' {$$ = $1; if(flagCheck){printf("expression\n");};}
               | ';'        { if(flagCheck){printf("simmicolon\n");};}
               ;

/*19*/
compoundStmt : '{' localDeclarations statementList '}' {
             $$ = newStmtNode(CompoundK, $1->linenum);
             $$->attr.op = $1->tokenclass;

             $$->child[0] = $2;
             $$->child[1] = $3; 
             if(flagCheck){printf("localDeclarations\n");};}
             ;
/*20*/
localDeclarations : localDeclarations scopedVarDeclaration {
                  //Add sibling $1 and $2
                  $$ = linkChild($1, $2);
                  //$$ = $1; 
                  if(flagCheck){printf("localDeclarations scopedVarDeclaration\n");};}
                  | { /*empty*/}
                  ;
/*21*/
statementList : statementList statement {
              // Adding sibling
              $$ = linkChild($1, $2);
              //$$ = $1;
              if(flagCheck){ printf("statementList statement\n");};}
              | {/*empty*/}
              ;
/*22*/ 
optionalStmt : expressionStmt {$$ = $1; if(flagCheck){printf("expressionStmt\n");};}
          | compoundStmt  {$$ = $1; if(flagCheck){printf("compoundStmt\n");};}
          | returnStmt {$$ = $1; if(flagCheck){printf("returnStmt\n");};}
          | breakStmt {$$ = $1; if(flagCheck){printf("breakStmt\n");};}
          ;
/*23*/
/*selectionStmt : matchedIf
              | unmatchedIf
              ;*/

matched : matchedIf 
        | matchedWhile
        | optionalStmt
        ;

unmatched :  unmatchedIf
          | unmatchedWhile
          ;

matchedIf : IF simpleExpression THEN matched matchedElse
          {
            // New statement
            $$ = newStmtNode(IfK, $1->linenum);
            $$->expType = Void;
            $$->child[0] = $2;
            $$->child[1] = $4;
            $$->child[2] = $5;
          }
          ;

matchedElse: ELSEIF simpleExpression THEN matched matchedElse
          {
            $$ = newStmtNode(ElsifK, $1->linenum);
            $$->child[0] = $2;
            $$->child[1] = $4;
            $$->child[2] = $5;
          }
          | ELSE matched { $$ = $2;}
          ;

unmatchedIf: IF simpleExpression THEN matched
            {
              $$ = newStmtNode(IfK, $1->linenum);
                $$->child[0] = $2;
                $$->child[1] = $4;
            }
            | IF simpleExpression THEN unmatched{
               $$ = newStmtNode(IfK, $1->linenum);
                $$->child[0] = $2;
                $$->child[1] = $4;
            }
            |  IF simpleExpression THEN matched unmatchedElse {
              $$ = newStmtNode(ElsifK, $1->linenum);
                $$->child[0] = $2;
                $$->child[1] = $4;
                $$->child[2] = $5;

            }
            ;
unmatchedElse: ELSEIF simpleExpression THEN matched {
                $$ = newStmtNode(ElsifK, $1->linenum);
                $$->child[0] = $2;
                $$->child[1] = $4;
          }
          | ELSEIF simpleExpression THEN matched unmatchedElse
          {
              $$ = newStmtNode(ElsifK, $1->linenum);
              $$->child[0] = $2;
              $$->child[1] = $4;
              $$->child[2] = $5;
          } 
          | ELSEIF simpleExpression THEN unmatched{
             $$ = newStmtNode(ElsifK, $1->linenum);
              $$->child[0] = $2;
              $$->child[1] = $4;
          }
          | ELSE unmatched {
            $$ = $2;
          }
          ;
/*24*/
iterationRange : '=' simpleExpression RANGE simpleExpression {
                // new statment node attr.name = $1
                $$ = newStmtNode(RangeK, $1->linenum);
                $$->child[0] = $2;
                $$->child[1] = $4;
                $$->child[2] = newExpNode(ConstantK, $1->linenum);
                $$->attr.value = 1;
                if(flagCheck){printf("simpleExpression RANGE simpleExpression\n");};}
               | '=' simpleExpression RANGE simpleExpression ':' simpleExpression {
                 // add child
                 $$ = newStmtNode(RangeK, $1->linenum);
                $$->child[0] = $2;
                $$->child[1] = $4;     
                $$->child[2] = $6;
                 if(flagCheck){printf("simpleExpression RANGE simpleExpression simpleExpression\n");};}
               ;

matchedWhile : WHILE simpleExpression DO matched  {
              $$ = newStmtNode(WhileK, $1->linenum);
              $$->child[0] = $2;
              $$->child[1] = $4;
              if(flagCheck){ printf("WHILE simpleExpression DO statement\n");};}
              | LOOP FOREVER matched  { 
                $$ = newStmtNode(LoopForeverK, $1->linenum);
                $$->child[0] = $3;
                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
              | LOOP ID iterationRange DO matched {
                $$ = newStmtNode(LoopK, $1->linenum);
                $$->child[0] = newExpNode(IdK, $2->linenum);
                $$->child[0]->attr.name = strdup($2->tokenstr);;
                $$->child[1] = $3;
                $$->child[2] = $5;
                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
              ;

unmatchedWhile : WHILE simpleExpression DO unmatched  {
              $$ = newStmtNode(WhileK, $1->linenum);
              $$->child[0] = $2;
              $$->child[1] = $4;
              if(flagCheck){ printf("WHILE simpleExpression DO statement\n");};}
              | LOOP FOREVER unmatched  { 
                 $$ = newStmtNode(LoopForeverK, $1->linenum);
                $$->child[0] = $3;
                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
              | LOOP ID iterationRange DO unmatched {
                 $$ = newStmtNode(LoopK, $1->linenum);
                $$->child[0] = newExpNode(IdK, $2->linenum);
                $$->child[0]->attr.name = strdup($2->tokenstr);;
                $$->child[1] = $3;
                $$->child[2] = $5;
                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
              ;


/*25*/
iterationStmt : WHILE simpleExpression DO statement  {
              $$ = newStmtNode(WhileK, $1->linenum);
              //Add child $2 and $4
              $$ = newStmtNode(WhileK, $1->linenum);
              $$->child[0] = $2;
              $$->child[1] = $4;
              ;if(flagCheck){ printf("WHILE simpleExpression DO statement\n");};}
              | LOOP FOREVER statement  { 

                $$ = newStmtNode(LoopForeverK, $1->linenum);
                $$->child[0] = $3;                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
              | LOOP ID iterationRange DO statement {
                $$ = newStmtNode(LoopK, $1->linenum);
                $$->child[0] = newExpNode(IdK, $2->linenum);
                $$->child[0]->attr.name = strdup($2->tokenstr);;
                $$->child[1] = $3;
                $$->child[2] = $5;
                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
              ;
/*26*/
returnStmt : RETURN ';' {
              $$ = newStmtNode(ReturnK, $1->linenum);
              //$$->op = $-> type of token
              ;if(flagCheck){printf("RETURN\n");};}
           | RETURN  expression';'  {
		        $$ = newStmtNode(ReturnK, $1->linenum);
              $$->child[1] = $2;
	      if(flagCheck){ printf("RETURN expression\n");};}
           ;
/*27*/
breakStmt : BREAK ';' {
            $$ = newStmtNode(BreakK, $1->linenum);
            ;if(flagCheck){ printf("BREAK\n");};}
          ;
/*28*/
expression : mutable '=' expression  {
            $$ = newExpNode(AssignK, $1->lineno);
            // $$->attr.op = $2 -> token data
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->expType = Void; // othercase is integer
            $$->attr.op = '=';
            if(flagCheck){ printf(" mutable = expression\n");};}
           | mutable ADDASS expression {
              $$ = newExpNode(AssignK, $1->lineno);
            // $$->attr.op = $2 -> token data
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->expType = Int; // othercase is integer
            $$->attr.op = $2->tokenclass;
             ; if(flagCheck){printf(" mutable ADDASS expression\n");};}
           | mutable SUBASS expression {
               $$ = newExpNode(AssignK, $1->lineno);
            // $$->attr.op = $2 -> token data
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->expType = Void; // othercase is integer
            $$->attr.op = $2->tokenclass;
           if(flagCheck){printf(" mutable SUBASS expression\n");};}
           | mutable MULASS expression {
               $$ = newExpNode(AssignK, $1->lineno);
            // $$->attr.op = $2 -> token data
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->expType = Int; // othercase is integer
            $$->attr.op = $2->tokenclass;
             if(flagCheck){ printf(" mutable MULASS expression\n");};}
           | mutable DIVASS expression  {
               $$ = newExpNode(AssignK, $1->lineno);
            // $$->attr.op = $2 -> token data
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->expType = Int; // othercase is integer
            $$->attr.op = $2->tokenclass;
              if(flagCheck){ printf(" mutable DIVASS expression\n");};}
           | mutable INC {
               $$ = newExpNode(AssignK, $1->lineno);
            // $$->attr.op = $2 -> token data
            $$->child[0] = $1;
            $$->expType = Int; // othercase is integer
            $$->attr.op = $2->tokenclass;
              if(flagCheck){printf(" mutable INC\n");};}
           | mutable DEC {
               $$ = newExpNode(AssignK, $1->lineno);
            // $$->attr.op = $2 -> token data
            $$->child[0] = $1;
            $$->expType = Int; // othercase is integer
            $$->attr.op = $2->tokenclass;
              if(flagCheck){ printf(" mutable DEC\n");};}
           | simpleExpression {$$ = $1;if(flagCheck){ printf(" simpleExpression\n");};}
           ;
/*29*/
simpleExpression : simpleExpression OR andExpression {
                $$ = newExpNode(OpK, $2->linenum);
                $$->attr.op = $2->tokenclass;
                $$->expType = Bool;
                $$->child[0] = $1;
                $$->child[1] = $3
              ; if(flagCheck){ printf("simpleExpression OR andExpression\n");};}
                 | andExpression {$$ = $1; if(flagCheck){ printf("andExpression\n");};}
                 ;
/*30*/
andExpression : andExpression AND unaryRelExpression {
              $$ = newExpNode(OpK, $2->linenum);
                $$->attr.op = $2->tokenclass;
                $$->expType = Bool;
                $$->child[0] = $1;
                $$->child[1] = $3
              ; if(flagCheck){ printf("andExpression AND unaryRelExpression\n");};}
              | unaryRelExpression {$$ = $1; if(flagCheck){printf("unaryRelExpression\n");};}
              ;
/*31*/
unaryRelExpression : NOT unaryRelExpression {
                $$ = newExpNode(OpK, $2->lineno);
                $$->attr.op = $1->tokenclass;
                $$->expType = Bool;
                $$->child[0] = $2;
               // $$->child[1] = $2;
	        if(flagCheck){ printf("NOTTTT unaryRelExpression\n");};}
                   | relExpression {$$ = $1;  if(flagCheck){printf("relExpression\n");};}
                   ;
/*32*/
relExpression : sumExpression relop  sumExpression {
            $$ = $2;
            $$->child[0] = $1;
            $$->child[0] = $3
            ; if(flagCheck){ printf("sumExpression relop sumExpression\n");};}
              |sumExpression {$$ = $1; if(flagCheck){printf("sumExpression\n");};}
              ;
/*33*/
relop : LESSEQ {  $$ = newExpNode(OpK, $1->linenum);
                $$->attr.op = $1->tokenclass;
                $$->expType = Bool;}
      | '<' {  $$ = newExpNode(OpK, $1->linenum);
                $$->attr.op = '<';
                $$->expType = Bool;}
      | '>' {  $$ = newExpNode(OpK, $1->linenum);
                $$->attr.op = '>';
                $$->expType = Bool;}
      | GRTEQ {  $$ = newExpNode(OpK, $1->linenum);
                $$->attr.op = $1->tokenclass;
                $$->expType = Bool;}
      | ASPC {  $$ = newExpNode(OpK, $1->linenum);
                $$->attr.op = $1->tokenclass;
                $$->expType = Bool;}
      | NOTEQ {  $$ = newExpNode(OpK, $1->linenum);
                $$->attr.op = $1->tokenclass;
                $$->expType = Bool;}
      ;
/*34*/
sumExpression : sumExpression sumop mulExpression {
	        $$ = $2;
                $$->child[0] = $1;
                $$->child[1] = $3;
                if(flagCheck){printf("sumExpression sumop mulExpression\n");};}
              | mulExpression {$$ = $1; if(flagCheck){printf("mulExpression\n");};}
              ;
/*35*/
sumop : PLUS {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = $1->tokenclass;
              $$->expType = Int;}
      | MINUS {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = $1->tokenclass;
              $$->expType = Int;}
      ;
/*36*/
mulExpression : mulExpression mulop unaryExpression {$$ = $1;
                $$->child[0] = $1;
                $$->child[1] = $3; if(flagCheck){printf("mulExpression mulop unaryExpression\n");};}
              | unaryExpression {$$ = $1; if(flagCheck){printf("unaryExpression\n");};}
              ;
/*37*/
mulop : MULTIPLY {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = $1->tokenclass;
              $$->expType = Int;} 
      | DIVIDE   {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = $1->tokenclass;
              $$->expType = Int;}
      | MODULUS  {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = $1->tokenclass;
              $$->expType = Int;}
      ;

/*38*/
unaryExpression : unaryop unaryExpression {$$ = $1; $$->child[0] = $2;
	       		if(flagCheck){printf("unaryop unaryExpression\n");};}
                | factor {$$ = $1; if(flagCheck){printf("factor\n");};}
                ;
/*39*/
unaryop : MINUS {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = $1->tokenclass;
              $$->expType = Int;} 
        | MULTIPLY {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = $1->tokenclass;
              $$->expType = Int;} 
        | QUESTION {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = $1->tokenclass;
              $$->expType = Int;}
        ;
/*40*/
factor : immutable {$$ = $1; if(flagCheck){printf("immutable\n");};}
       | mutable  {$$ = $1; if(flagCheck){printf("mutable\n");};}
       ;
/*41*/
mutable : ID {
          $$ = newExpNode(IdK, $1->linenum);
          $$->attr.name = strdup($1->tokenstr);
          ;if(flagCheck){printf("ID\n");};}
        | mutable '['expression']' {
          $$ = newExpNode(OpK, $1->lineno);
          $$->child[0] = $1;
          $$->child[1] = $3; 
          if(flagCheck){printf("mutable\n");};}
        ;

/*42*/
immutable : '('expression')' {$$ = $2;}
          | call {}
          | constant {}
          ;
/*43*/
call : ID '(' args ')' {$$ = newExpNode(CallK, $1->linenum);
                        $$->expType = $3->expType;
                        $$->child[0] = $3;}
     ;
/*44*/
args : argList {$$ =$1;}
     | {$$= NULL; /*empty*/} 
     ;
/*45*/
argList : argList ',' expression {
          // Add silbling
          $$ = linkChild($1, $3);
	} 
        | expression {$$ = $1;}
        ;
/*46*/
constant : NUMCONST {$$ = newExpNode(ConstantK, $1->linenum);
          $$->attr.value = $1->numValue;
          $$->expType=Int;
          if(flagCheck){
          printf("NUMCONST\n");};}
         | CHARCONST { 
           $$ = newExpNode(ConstantK, $1->linenum);
          $$->attr.value = $1->numValue;
          $$->attr.string = strdup($1->tokencharVal);
          $$->expType=Char;
          if(flagCheck){printf("CHARCONST\n");};}
         | 
         STRINGCONST  {
           $$ = newExpNode(ConstantK, $1->linenum);
          $$->attr.value = $1->numValue;
          $$->attr.string = strdup($1->tokenstrVal);
          $$->expType=Char;
          if(flagCheck){printf("STRINGCONST\n");};}
         | 
         TRUE {
           $$ = newExpNode(ConstantK, $1->linenum);
          $$->attr.value = $1->numValue;
          $$->expType=Bool;
          if(flagCheck){printf("TRUE\n");};}
         | 
         FALSE {
           $$ = newExpNode(ConstantK, $1->linenum);
          $$->attr.value = 1;
           $$->expType=Bool;
          $$->expType=Int;
          if(flagCheck){printf("FALSE\n");};}
         ;
%%


int main(int argc, char *argv[]) 
{
    int c;
    int counter = 1;
    extern char *optarg;
    int flagTree = 0;

    // hunt for a string of options
    while ((c = getopt(argc, argv,"pd")) != -1) {
        switch (c) {
        case 'd': 
            yydebug=1;
            break;
        case 'p': 
            flagTree = 1;
            break;
        default: 
            exit(1);
        }
        counter++;
    }

    if(argc > 1){

      if(yyin = fopen(argv[argc - 1], "r")){
        yyparse();
        if(flagTree){
          printTree(syntaxTree);
        } else{
          exit(1);
        }
            
     }
   }
        return 0;
}
