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
            if(flagCheck) {printf("L: program | R: declarationList\n");};
        }
        ;
/*2*/
declarationList : declarationList declaration {
                  $$ = linkChild($1, $2);
                  ; if(flagCheck) {printf("L: declarationList | R: declarationList declaration\n");};}
                | declaration { $$ = $1 ;if(flagCheck) {printf("L: declarationList | R: declaration\n");};}
                ;
/*3*/
declaration : varDeclaration {$$ = $1; if(flagCheck) {printf("L: declaration | R: varDeclaration\n");};}
            | funDeclaration {$$ = $1 ;if(flagCheck) {printf("L: declaration | R: funDeclaration\n");};}
            ;

/*4*/
varDeclaration : typeSpecifier varDeclList ';' { $$ = $2 ;  
                childExpType($$, $1);
                if(flagCheck) {printf("L: varDeclaration | R: typeSpecifier varDeclList\n");};}
               ;

/*5*/
scopedVarDeclaration : scopedTypeSpecifier varDeclList ';' {
                              $$ = $2;
                              childExpType($$, $1);
                              if(flagCheck) {printf("L: scopedVarDeclaration | R: scopedTypeSpecifier varDeclList\n");};}
                     ;  
/*6*/
varDeclList : varDeclList ',' varDeclInitialize {
                              // Add silding
                             $$ = linkChild($1, $3);
                    if(flagCheck) {printf("L: varDeclList | R: varDeclList ',' varDeclInitialize\n");};}
            | varDeclInitialize {
                    $$ = $1; 
                    if(flagCheck) {printf("L: varDeclList | R: varDeclInitialize\n");};}
            ;

/*7*/
varDeclInitialize : varDeclId { $$ = $1; if(flagCheck) {printf("L: varDeclInitialize | R: varDeclId\n");};}
                  | varDeclId ':' simpleExpression {
                    $$ = $1;
                    $$->child[0] = $3;
                    if(flagCheck) {printf("L: varDeclInitialize | R: varDeclId : simpleExpression\n");};}
                  ;
/*8*/
varDeclId : ID  { if(flagCheck) {printf("L: varDeclId | R: ID\n");};
                  $$ = newDeclNode(VarK, $1->linenum);
                  $$->attr.string = strdup($1->tokenstr);}
                | ID '['NUMCONST']' {
                  $$ = newDeclNode(VarK, $1->linenum);
                  $$->attr.value = $3->numValue;
                  $$->dataType = $1;
	                $$->attr.op = T_LBRAC;
                  $$->isArray = true;
                  if(flagCheck) {printf("L: varDeclId | R: ID [NUMCONST] \n");};}
                ;

/*9*/
scopedTypeSpecifier : STATIC typeSpecifier  { $$ = $2; if(flagCheck){printf("L: scopedTypeSpecifier | R: STATIC typeSpecifier\n");}; }
                    | typeSpecifier {$$ = $1; if(flagCheck){printf("L: scopedTypeSpecifier | R: typeSpecifier: \n");};}
                    ;
/*10*/
typeSpecifier : INT {$$ = Int; if(flagCheck){printf("L: typeSpecifier | R: INT \n");};}
              | BOOL {$$ = Bool; if(flagCheck){printf("L: typeSpecifier | R: BOOL \n");};}
              | CHAR {$$ = Char; if(flagCheck){ printf("L: typeSpecifier | R: CHAR \n");};}
              ;
/*11*/
funDeclaration : typeSpecifier ID '('params')' statement {
                $$ = newDeclNode(FuncK, $2->linenum);
                $$->attr.string = strdup($2->tokenstr);
                $$->expType = Void;
                $$->child[0] = $4;
                $$->child[1] = $6; 
		            if(flagCheck) {printf("L: funDeclaration | R: typeSpecifier ID (params) statement\n");};}
               | ID '('params')' statement {
                 $$ = newDeclNode(FuncK, $1->linenum);
           		   $$->attr.name = strdup($1->tokenstr);
		            $$->expType = Void;
                 $$->child[0] = $3;
                 $$->child[1]  = $5;
                 if(flagCheck) {printf("L: funDeclaration | R: ID (params) statement\n");};}
               ;
/*12*/
params : paramList {$$ = $1; if(flagCheck){printf("L: params | R: paramList\n"); };}
       | { /*empty*/$$ = NULL;  if(flagCheck){printf("L: params | R: NULL\n");};} 
       ;
/*13*/
paramList : paramList ';' paramTypeList { 
            // Add silbilin
            $$ = linkChild($1, $3);
            if(flagCheck){ printf("L: paramList | R: paramList ; paramTypeList\n");};}
          | paramTypeList {
            $$ = $1;
            if(flagCheck) {printf("L: paramList | R: paramTypeList\n");};}
          ;
/*14*/
paramTypeList : typeSpecifier paramIdList { $$ = $2; 
              childExpType($$, $1);
              if(flagCheck){printf("L: paramTypeList | R: typeSpecifier paramIdList\n");};}
              ;
/*15*/
paramIdList : paramIdList ',' paramId { 
              //Adding sibling;
              $$ = linkChild($1, $3);
              if(flagCheck){ printf("L: paramIdList | R: paramIdList ',' paramId\n");};}
            | paramId { $$ = $1 ;if(flagCheck){ printf("L: paramIdList | R: paramId\n");};}
            ;

/*16*/
paramId : ID  {
              $$ = newDeclNode(ParamK, $1->linenum);
              $$->attr.name = strdup($1->tokenstr);
              //$$->expType = Void;
              if(flagCheck){printf("L: paramId | R: ID\n");};}
        | ID '['']' { 
              $$ = newDeclNode(ParamK, $1->linenum);
              $$->attr.name = strdup($1->tokenstr);
              //$$->expType = Void;
              $$->isArray = true;
          if(flagCheck){printf("L: paramId | ID []\n");};}
        ;
/*17*/
statement : expressionStmt {$$ = $1; if(flagCheck){printf("L: statement | R: expressionStmt\n");};}
          | compoundStmt  {$$ = $1; if(flagCheck){printf("L: statement | R: compoundStmt\n");};}
          | matchedIf {$$ = $1; if(flagCheck){printf("L: statement | R: matchedIf\n");};}
          | unmatchedIf {$$ = $1; if(flagCheck){printf("L: statement | R: unmatchedIf\n");};} 
          | iterationStmt {$$ = $1; if(flagCheck){printf("L: statement | R: iterationStmt\n");};}
          | returnStmt {$$ = $1; if(flagCheck){printf("L: statement | R: returnStmt\n");};}
          | breakStmt {$$ = $1; if(flagCheck){printf("L: statement | R: breakStmt\n");};}
          ;
/*18*/
expressionStmt : expression ';' {$$ = $1; if(flagCheck){printf("L: expressionStmt | R: expression ; \n");};}
               | ';'        { if(flagCheck){printf("L: expressionStmt | R: ; \n");};}
               ;

/*19*/
compoundStmt : '{' localDeclarations statementList '}' {
             $$ = newStmtNode(CompoundK, $1->linenum);
             $$->attr.op = T_LPAREN;
             $$->child[0] = $2;
             $$->child[1] = $3; 
             if(flagCheck){printf("L: compoundStmt | R: {localDeclarations statementList}\n");};}
             ;
/*20*/
localDeclarations : localDeclarations scopedVarDeclaration {
                  //Add sibling $1 and $2
                  $$ = linkChild($1, $2);
                  //$$ = $1; 
                  if(flagCheck){printf("L: compoundStmt | R: localDeclarations scopedVarDeclaration\n");};}
                  | { /*empty*/}
                  ;
/*21*/
statementList : statementList statement {
              // Adding sibling
              $$ = linkChild($1, $2);
              //$$ = $1;
              if(flagCheck){ printf("L: statementList | R: statementList statement\n");};}
              | {/*empty*/}
              ;
/*22*/ 
optionalStmt : expressionStmt {$$ = $1; if(flagCheck){printf("L: optionalStmt | R: expressionStmt\n");};}
          | compoundStmt  {$$ = $1; if(flagCheck){printf("L: optionalStmt | R: compoundStmt\n");};}
          | returnStmt {$$ = $1; if(flagCheck){printf("L: optionalStmt | R: returnStmt\n");};}
          | breakStmt {$$ = $1; if(flagCheck){printf("L: optionalStmt | R: breakStmt\n");};}
          ;
/*23*/
/*selectionStmt : matchedIf
              | unmatchedIf
              ;*/

matched : matchedIf {if(flagCheck){printf("L: matched | R: matchedIf\n");};}
        | matchedWhile {if(flagCheck){printf("L: matched | R: matchedWhile\n");};}
        | optionalStmt {if(flagCheck){printf("L: matched | R: optionalStmt\n");};}
        ;

unmatched :  unmatchedIf {if(flagCheck){printf("L: unmatched | R: unmatchedIf\n");};}
          | unmatchedWhile {if(flagCheck){printf("L: unmatched | R: unmatchedWhile\n");};}
          ;

matchedIf : IF simpleExpression THEN matched matchedElse
          {
            // New statement
            $$ = newStmtNode(IfK, $1->linenum);
            $$->expType = Void;
            $$->child[0] = $2;
            $$->child[1] = $4;
            $$->child[2] = $5;
            if(flagCheck){printf("L: matchedIf | R: IF simpleExpression THEN matched matchedElse\n");}
          }
          ;

matchedElse: ELSEIF simpleExpression THEN matched matchedElse
          {
            $$ = newStmtNode(ElsifK, $1->linenum);
            $$->child[0] = $2;
            $$->child[1] = $4;
            $$->child[2] = $5;
            if(flagCheck){printf("L: matchedElse | R: ELSEIF simpleExpression THEN matched matchedElse\n");}
          }
          | ELSE matched { 
            $$ = $2;
            if(flagCheck){printf("L: matchedElse | R: ELSE matched\n");}
            }
          ;

unmatchedIf: IF simpleExpression THEN matched
            {
              $$ = newStmtNode(IfK, $1->linenum);
                $$->child[0] = $2;
                $$->child[1] = $4;
                if(flagCheck){printf("L: unmatchedIf | R: IF simpleExpression THEN matched\n");}
            }
            | IF simpleExpression THEN unmatched{
               $$ = newStmtNode(IfK, $1->linenum);
                $$->child[0] = $2;
                $$->child[1] = $4;
                if(flagCheck){printf("L: unmatchedIf | R: IF simpleExpression THEN unmatched\n");}
            }
            |  IF simpleExpression THEN matched unmatchedElse {
              $$ = newStmtNode(ElsifK, $1->linenum);
                $$->child[0] = $2;
                $$->child[1] = $4;
                $$->child[2] = $5;
                if(flagCheck){printf("L: unmatchedIf | R: IF simpleExpression THEN matched unmatchedElse\n");}
            }
            ;
unmatchedElse: ELSEIF simpleExpression THEN matched {
                $$ = newStmtNode(ElsifK, $1->linenum);
                $$->child[0] = $2;
                $$->child[1] = $4;
                if(flagCheck){printf("L: unmatchedElse | R: ELSEIF simpleExpression THEN matched\n");}                
          }
          | ELSEIF simpleExpression THEN matched unmatchedElse
          {
              $$ = newStmtNode(ElsifK, $1->linenum);
              $$->child[0] = $2;
              $$->child[1] = $4;
              $$->child[2] = $5;
              if(flagCheck){printf("L: unmatchedElse | R: ELSEIF simpleExpression THEN matched unmatchedElse\n");}
          } 
          | ELSEIF simpleExpression THEN unmatched{
             $$ = newStmtNode(ElsifK, $1->linenum);
              $$->child[0] = $2;
              $$->child[1] = $4;
              if(flagCheck){printf("L: unmatchedElse | R: ELSEIF simpleExpression THEN unmatched\n");}
          }
          | ELSE unmatched {
            $$ = $2;
            if(flagCheck){printf("L: unmatchedElse | R: ELSE unmatched\n");}

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
                if(flagCheck){printf("L: iterationRange | R: = simpleExpression RANGE simpleExpression\n");};}
               | '=' simpleExpression RANGE simpleExpression ':' simpleExpression {
                 // add child
                 $$ = newStmtNode(RangeK, $1->linenum);
                $$->child[0] = $2;
                $$->child[1] = $4;     
                $$->child[2] = $6;
                 if(flagCheck){printf("L: iterationRange | R: = simpleExpression RANGE simpleExpression : simpleExpression\n");};}
               ;

matchedWhile : WHILE simpleExpression DO matched  {
              $$ = newStmtNode(WhileK, $1->linenum);
              $$->child[0] = $2;
              $$->child[1] = $4;
              if(flagCheck){ printf("L: matchedWhile | R: WHILE simpleExpression DO matched\n");};}
              | LOOP FOREVER matched  { 
                $$ = newStmtNode(LoopForeverK, $1->linenum);
                $$->child[0] = $3;
                if(flagCheck){ printf("L: matchedWhile | R: LOOP FOREVER matched\n");};}
              | LOOP ID iterationRange DO matched {
                $$ = newStmtNode(LoopK, $1->linenum);
                $$->child[0] = newExpNode(IdK, $2->linenum);
                $$->child[0]->attr.name = strdup($2->tokenstr);;
                $$->child[1] = $3;
                $$->child[2] = $5;
                if(flagCheck){ printf("L: matchedWhile | R: LOOP FOREVER matched\n");};}
              ;

unmatchedWhile : WHILE simpleExpression DO unmatched  {
              $$ = newStmtNode(WhileK, $1->linenum);
              $$->child[0] = $2;
              $$->child[1] = $4;
              if(flagCheck){ printf("L: unmatchedWhile | R: WHILE simpleExpression DO unmatched\n");};}
              | LOOP FOREVER unmatched  { 
                 $$ = newStmtNode(LoopForeverK, $1->linenum);
                $$->child[0] = $3;
                if(flagCheck){ printf("L: unmatchedWhile | R: LOOP FOREVER unmatched\n");};}
              | LOOP ID iterationRange DO unmatched {
                 $$ = newStmtNode(LoopK, $1->linenum);
                $$->child[0] = newExpNode(IdK, $2->linenum);
                $$->child[0]->attr.name = strdup($2->tokenstr);;
                $$->child[1] = $3;
                $$->child[2] = $5;
                if(flagCheck){ printf("L: unmatchedWhile | R: LOOP FOREVER unmatched\n");};}
              ;


/*25*/
iterationStmt : WHILE simpleExpression DO statement  {
              $$ = newStmtNode(WhileK, $1->linenum);
              //Add child $2 and $4
              $$ = newStmtNode(WhileK, $1->linenum);
              $$->child[0] = $2;
              $$->child[1] = $4;
              ;if(flagCheck){ printf("L: iterationStmt | R: WHILE simpleExpression DO statement\n");};}
              | LOOP FOREVER statement  { 
                $$ = newStmtNode(LoopForeverK, $1->linenum);
                $$->child[0] = $3;                
                if(flagCheck){ printf("L: iterationStmt | R: LOOP FOREVER statement\n");};}
              | LOOP ID iterationRange DO statement {
                $$ = newStmtNode(LoopK, $1->linenum);
                $$->child[0] = newExpNode(IdK, $2->linenum);
                $$->child[0]->attr.name = strdup($2->tokenstr);;
                $$->child[1] = $3;
                $$->child[2] = $5;
                if(flagCheck){ printf("L: iterationStmt | R: LOOP FOREVER statement\n");};}
              ;
/*26*/
returnStmt : RETURN ';' {
              $$ = newStmtNode(ReturnK, $1->linenum);
              //$$->op = $-> type of token
              ;if(flagCheck){printf("L: returnStmt | R: RETURN ;\n");};}
           | RETURN  expression';'  {
		        $$ = newStmtNode(ReturnK, $1->linenum);
              $$->child[1] = $2;
	          if(flagCheck){ printf("L: returnStmt | R: RETURN expression ;\n");};}
           ;
/*27*/
breakStmt : BREAK ';' {
            $$ = newStmtNode(BreakK, $1->linenum);
            if(flagCheck){ printf("L: breakStmt | R: BREAK ;\n");};}
          ;
/*28*/
expression : mutable '=' expression  {
            $$ = newExpNode(AssignK, $1->lineno);
            // $$->attr.op = $2 -> token data
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->expType = Void; // othercase is integer
            $$->attr.op = T_ASSIGN;
            if(flagCheck){ printf("L: expression | R: mutable = expression\n");};}
           | mutable ADDASS expression {
              $$ = newExpNode(AssignK, $1->lineno);
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->expType = Int; // othercase is integer
            $$->attr.op = T_ADDASS;
            if(flagCheck){printf("L: expression | R: mutable ADDASS expression\n");};}
           | mutable SUBASS expression {
               $$ = newExpNode(AssignK, $1->lineno);
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->expType = Void; // othercase is integer
            $$->attr.op = T_SUBASS;
           if(flagCheck){printf("L: expression | R: mutable SUBASS expression\n");};}
           | mutable MULASS expression {
               $$ = newExpNode(AssignK, $1->lineno);
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->expType = Int; // othercase is integer
            $$->attr.op = T_MULASS;
            if(flagCheck){ printf("L: expression | R: mutable MULASS expression\n");};}
           | mutable DIVASS expression  {
               $$ = newExpNode(AssignK, $1->lineno);
            $$->child[0] = $1;
            $$->child[1] = $3;
            $$->expType = Int; // othercase is integer
            $$->attr.op = T_DIVASS;
            if(flagCheck){ printf("L: expression | R: mutable DIVASS expression\n");};}
           | mutable INC {
               $$ = newExpNode(AssignK, $1->lineno);
            $$->child[0] = $1;
            $$->expType = Int; // othercase is integer
            $$->attr.op = T_INC;
            if(flagCheck){printf("L: expression | R: mutable INC\n");};}
           | mutable DEC {
               $$ = newExpNode(AssignK, $1->lineno);
            $$->child[0] = $1;
            $$->expType = Int; // othercase is integer
            $$->attr.op = T_DEC;
              if(flagCheck){ printf("L: expression | R: mutable DEC\n");};}
           | simpleExpression {$$ = $1;if(flagCheck){ printf("L: expression | R: simpleExpression\n");};}
           ;
/*29*/
simpleExpression : simpleExpression OR andExpression {
                $$ = newExpNode(OpK, $2->linenum);
                $$->attr.op =T_OR;
                $$->expType = Bool;
                $$->child[0] = $1;
                $$->child[1] = $3
              ; if(flagCheck){ printf("L: simpleExpression | R: simpleExpression OR andExpression\n");};}
                 | andExpression {$$ = $1; if(flagCheck){ printf("L: simpleExpression | R: andExpression\n");};}
                 ;
/*30*/
andExpression : andExpression AND unaryRelExpression {
              $$ = newExpNode(OpK, $2->linenum);
                $$->attr.op = T_AND;
                $$->expType = Bool;
                $$->child[0] = $1;
                $$->child[1] = $3
              ; if(flagCheck){ printf("L: andExpression | R: andExpression AND unaryRelExpression\n");};}
              | unaryRelExpression {$$ = $1; if(flagCheck){printf("unaryRelExpression\n");};}
              ;
/*31*/
unaryRelExpression : NOT unaryRelExpression {
                $$ = newExpNode(OpK, $2->lineno);
                $$->attr.op = T_NOT;
                $$->expType = Bool;
                $$->child[0] = $2;
	              if(flagCheck){ printf("L: unaryRelExpression | R: NOT unaryRelExpression\n");};}
                | relExpression {$$ = $1;  if(flagCheck){printf("L: unaryRelExpression | R: relExpression\n");};}
                ;
/*32*/
relExpression : sumExpression relop  sumExpression {
            $$ = $2;
            $$->child[0] = $1;
            $$->child[0] = $3; 
            if(flagCheck){ printf("L: relExpression | R: sumExpression relop sumExpression\n");};}
            |sumExpression {$$ = $1; if(flagCheck){printf("L: relExpression | R: sumExpression\n");};}
              ;
/*33*/
relop : LESSEQ {  $$ = newExpNode(OpK, $1->linenum);
                $$->attr.op = T_LESSEQ;
                $$->expType = Bool;
                 if(flagCheck){ printf("L: relop | R: LESSEQ\n");};
                }
      | '<' {  $$ = newExpNode(OpK, $1->linenum);
                $$->attr.op = T_LT;
                $$->expType = Bool;
                if(flagCheck){ printf("L: relop | R: <\n");};    
            }
      | '>' {  $$ = newExpNode(OpK, $1->linenum);
               $$->attr.op = T_GT;
                $$->expType = Bool;
                if(flagCheck){ printf("L: relop | R: >\n");};        
            }
      | GRTEQ { $$ = newExpNode(OpK, $1->linenum);
                $$->attr.op = T_GRTEQ;
                $$->expType = Bool;
                 if(flagCheck){ printf("L: relop | R: GRTEQ\n");};                
              }
      | ASPC {  $$ = newExpNode(OpK, $1->linenum);
                $$->attr.op = T_EQ;
                $$->expType = Bool;
                 if(flagCheck){ printf("L: relop | R: ASPC\n");};    
              }
      | NOTEQ {  $$ = newExpNode(OpK, $1->linenum);
                $$->attr.op = T_NOTEQ;
                $$->expType = Bool;
                 if(flagCheck){ printf("L: relop | R: NOTEQ\n");};  
              }
      ;
/*34*/
sumExpression : sumExpression sumop mulExpression {
	        $$ = $2;
                $$->child[0] = $1;
                $$->child[1] = $3;
                if(flagCheck){printf("L: sumExpression | R: sumExpression sumop mulExpression\n");};}
              | mulExpression {$$ = $1; if(flagCheck){printf("L: sumExpression | R: mulExpression\n");};}
              ;
/*35*/
sumop : PLUS {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = T_PLUS;
              $$->expType = Int;
                 if(flagCheck){printf("L: sumop | R: PLUS\n");};
             }
      | MINUS {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = T_MINUS;
              $$->expType = Int;
                 if(flagCheck){printf("L: sumop | R: MINUS\n");};              
              }
      ;
/*36*/
mulExpression : mulExpression mulop unaryExpression {$$ = $1;
                $$->child[0] = $1;
                $$->child[1] = $3; if(flagCheck){printf("L: mulExpression | R: mulExpression mulop unaryExpression\n");};}
              | unaryExpression {$$ = $1; if(flagCheck){printf("L: mulExpression | R: unaryExpression\n");};}
              ;
/*37*/
mulop : MULTIPLY {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = T_TIMES;
              $$->expType = Int;
              if(flagCheck){printf("L: mulop | R: MULTIPLY\n");};} 
      | DIVIDE   {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = T_DIV;
              $$->expType = Int;
              if(flagCheck){printf("L: mulop | R: DIVIDE\n");};
              }
      | MODULUS  {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = T_MOD;
              $$->expType = Int;
              if(flagCheck){printf("L: mulop | R: MODULUS\n");};
              }
      ;

/*38*/
unaryExpression : unaryop unaryExpression {$$ = $1; $$->child[0] = $2;
	       		if(flagCheck){printf("L: unaryExpression | R: unaryop unaryExpression\n");};}
                | factor {$$ = $1; if(flagCheck){printf("L: unaryExpression | R: factor\n");};}
                ;
/*39*/
unaryop : MINUS {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = T_MINUS;
              $$->expType = Int;
              if(flagCheck){printf("L: unaryop | R: MINUS\n");};
              } 
        | MULTIPLY {$$ = newExpNode(OpK, $1->linenum);
              $$->attr.op = T_TIMES;
              $$->expType = Int;
              if(flagCheck){printf("L: unaryop | R: MULTIPLY\n");};
              } 
        | QUESTION {$$ = newExpNode(OpK, $1->linenum);
              // $$->attr.op = $1->tokenclass;
              $$->expType = Int;
              if(flagCheck){printf("L: unaryop | R: QUESTION\n");};
              }
        ;
/*40*/
factor : immutable {$$ = $1; if(flagCheck){printf("L: factor | R: immutable\n");};}
       | mutable  {$$ = $1; if(flagCheck){printf("L: factor | R: mutable\n");};}
       ;
/*41*/
mutable : ID {
          $$ = newExpNode(IdK, $1->linenum);
          $$->attr.name = strdup($1->tokenstr);
          ;if(flagCheck){printf("L: mutable | R: ID\n");};}
        | mutable '['expression']' {
          $$ = newExpNode(OpK, $1->lineno);
          $$->child[0] = $1;
          $$->child[1] = $3; 
          if(flagCheck){printf("L: mutable | R: mutable [expression]\n");};}
        ;

/*42*/
immutable : '('expression')' {$$ = $2; if(flagCheck){printf("L: mutable | R: (expression)\n");};}
          | call {if(flagCheck){printf("L: mutable | R: call\n");};}
          | constant {if(flagCheck){printf("L: mutable | R: constant\n");};}
          ;
/*43*/
call : ID '(' args ')' {$$ = newExpNode(CallK, $1->linenum);
                        $$->expType = $3->expType;
                        $$->child[0] = $3;
        if(flagCheck){printf("L: call | R: ID (args)\n");};                
     }
     ;
/*44*/
args : argList {$$ =$1; if(flagCheck){printf("L: args | R: argList\n");};}
     | {$$= NULL; /*empty*/; if(flagCheck){printf("L: args | R: NULL\n");};} 
     ;
/*45*/
argList : argList ',' expression {
          // Add silbling
          $$ = linkChild($1, $3);
          if(flagCheck){printf("L: argList | R: argList ',' expression\n");};
	} 
        | expression {$$ = $1;
          if(flagCheck){printf("L: argList | R: expression\n");};
        }
        ;
/*46*/
constant : NUMCONST {$$ = newExpNode(ConstantK, $1->linenum);
          $$->attr.value = $1->numValue;
          $$->expType=Int;
          if(flagCheck){
          printf("L: constant | R: NUMCONST\n");};}
         | CHARCONST { 
           $$ = newExpNode(ConstantK, $1->linenum);
          $$->attr.value = $1->numValue;
          $$->attr.string = strdup($1->tokencharVal);
          $$->expType=Char;
          if(flagCheck){printf("L: constant | R: CHARCONST\n");};}
         | 
         STRINGCONST  {
           $$ = newExpNode(ConstantK, $1->linenum);
          $$->attr.value = $1->numValue;
          $$->attr.string = strdup($1->tokenstrVal);
          $$->expType=Char;
          if(flagCheck){printf("L: constant | R: STRINGCONST\n");};}
         | 
         TRUE {
           $$ = newExpNode(ConstantK, $1->linenum);
          $$->attr.value = $1->numValue;
          $$->expType=Bool;
          if(flagCheck){printf("L: constant | R: TRUE\n");};}
         | 
         FALSE {
           $$ = newExpNode(ConstantK, $1->linenum);
          $$->attr.value = 1;
           $$->expType=Bool;
          $$->expType=Int;
          if(flagCheck){printf("L: constant | R: FALSE\n");};}
         ;
%%


