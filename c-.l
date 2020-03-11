%{
#include<stdlib.h>
#include<string.h>
#include"scanType.h"
#include "treeNode.h"
#include "util.h"
#include<ctype.h>
#include"c-.tab.h"

static int line = 1;

static int countQuotes(char* input) {
	int len = strlen(input), result = 0, i = 0;
	for(; i < len; i++) {
	    if(input[i] == '"') {
	    	result++;
  	    }
	}
	return result;
}
// Remove a garbage char
static void removeChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

static void removeCharByIndex(char *str, int index) {
    char *src;
    for (src = str+index; *src != '\0'; *src = *(src+1),++src) ;
    *src = '\0';
}

static void replaceCharByIndex(char* str, char newCh, int index) {
	int i = 0;
	for(;i <=strlen(str); i++) {
		if(i == index) {
		   str[i] = newCh;
		}
	}
}

// Function to check repeat char next to each other
static int* repeatCharNextTo(char* strInput, char charInput) {
    int i =0, len = strlen(strInput);
    int numOccur = 0;
    int* arrayOccur = new int[2];
    for(; i < len; i++) {
        if(strInput[i] == charInput && strInput[i + 1] == charInput){
            numOccur++;
            arrayOccur[0] = numOccur;
            arrayOccur[1] = i;
        }
    }
    return arrayOccur;
}

static void replaceAll(char* str, char oldChar, char newChar) {
	int i = 0;

       // Run till end of string
       while(str[i] != '\0')
       {
            // If occurrence of character is found */
            if(str[i] == oldChar)
            {
                str[i] = newChar;
            }

            i++;
    }

}

/*
* Function to set Value for token
*/
static int setValue(int linenum, int tokenClass, char *svalue) {
    // All the needed char 
    char backS = '\\'; // contain \ value
    char empty = '\0';
    char wspace = ' ';
    char newLineChr = 'n'; 
	// Create the pass-back data space
	yylval.tokenData = new TokenData;
	
        yylval.tokenData->tokenclass = tokenClass;
        yylval.tokenData->linenum = linenum;
        yylval.tokenData->tokenstr = strdup(svalue);
    
        // handle special conversions
       switch (tokenClass) {
       case NUMCONST:{
                yylval.tokenData->numValue = atof(svalue); 
                break;
  	}
        case ID:{
                yylval.tokenData->idValue = svalue[0] - 'a'; 
                break;
	}
        case TRUE:{
                int flag = strcmp(svalue, "true");
                if(flag == 0) {
                     yylval.tokenData->boolValue = 1;
                }else{
                    yylval.tokenData->boolValue = 0;
                }
	        break;
	}
            case FALSE:{
                int flag = strcmp(svalue, "true");
                if(flag == 0) {
                     yylval.tokenData->boolValue = 1;
                }else{
                    yylval.tokenData->boolValue = 0;
                }
	        break;
	}
	case CHARCONST:{
        char* holder = svalue;
		if(strchr(holder, backS)!= NULL && strchr(holder, empty) == NULL && strchr(holder, newLineChr) == NULL) {
            removeChar(holder, backS);
            yylval.tokenData->tokencharVal = holder; // Handle CHARCONST Value: ''' Input: '\''
		} else if(strchr(holder, backS) != NULL && strchr(holder, empty) != NULL && strchr(holder, newLineChr) == NULL) {
            removeChar(holder, backS);
	    	replaceAll(holder, empty, wspace);
            yylval.tokenData->tokencharVal = holder; // Handle CHARCONST Value: ' ' Input: '\0'
		} else if (strchr(holder, backS) != NULL && strchr(holder, empty) == NULL && strchr(holder, newLineChr) !=NULL) {
                 removeChar(holder, backS);
                 removeChar(holder, newLineChr);
                yylval.tokenData->tokencharVal = ((char*)"'\n'");  
        }else {
            yylval.tokenData->tokencharVal = holder; 
            
        }
		break;
	}
	case STRINGCONST:{
	   int numQuotes = countQuotes(svalue);
	   char *temp = strndup(svalue, strlen(svalue) - 1);
           char result[strlen(svalue)];
           int i = 0 , j = 0;
	   for(; i < strlen(svalue); i++) {
		printf("BACKSLAH: %c\n", temp[i]);
		if(temp[i] == '\\') { // Start with Back slash
            printf("1: %c\n", temp[i]);
			if(temp[i+1] == 'n') { // \n case
            printf("2: %c\n", temp[i]);
				result[j] = temp[i];
				result[j++] = temp[i];
			} else if (temp[i+1] == '\\') { // \\ case
            printf("3: %c\n", temp[i]);
				result[j] = empty;
				//result[j++] = empty;
			}else if (temp[i+1] == '"') {
				printf("3 %c\n", temp[i+1]);
				result[j] = empty;
			} else if(temp[i+1] >= 'a' && temp[i+1] <= 'z') {
				printf("4: %c\n", temp[i]);
				result[j++] = temp[i +1];
			} else {
            	printf("5: %c\n", temp[i]);
				result[j] = empty;
			}
		} else {
               printf("6: %c\n", temp[i]);
			result[j] = temp[i];
			result[j++] = temp[i+1];
		}


	   }
       /*for(i = 1; i < strlen(svalue) - 1; i++) {
           if(temp[i] == backS && temp[i+1] == newLineChr) { // /n
               result[j] = temp[i];
               result[j++] = temp[i+1];
           } else if (temp[i] == backS && temp[i+1] == '\0') {// /0
                result[j] = empty;
               result[j++] = empty;
           } else if (temp[i] == backS && temp[i+1] == backS) {// //
                result[j] = temp[i];
               result[j++] = empty;
           }  else if (temp[i] == backS && temp[i+1] == '"') { // /"
                result[j] = empty;
              // result[j++] = temp[i+1];
           } else{
                result[j] = temp[i];
                result[j++] = temp[i+1];
           }
       }*/
       	
        yylval.tokenData->tokenstrVal = strdup(result); 

    //    int* arrayNumOfBackS;
	//    arrayNumOfBackS = repeatCharNextTo(temp, backS);
	//    // State each condition
	//    if(numQuotes == 2 && strchr(temp, backS) == NULL) {
	// 	         replaceAll(temp, '"', '\'');
	// 	         yylval.tokenData->tokenstrVal = temp; 
    //         } else if (numQuotes == 2 && strchr(temp, backS) != NULL && strchr(temp, newLineChr) !=NULL) {
    //              removeChar(temp, backS);
    //              removeChar(temp, newLineChr);
    //     		 yylval.tokenData->tokenstrVal = ((char*)"'\n'"); 
    //         } else if (numQuotes == 2 && strchr(temp, backS) != NULL) {
    //             if(arrayNumOfBackS[0] == 1){ // Base case only // in string
    //                 replaceAll(temp, '"', '\'');
    //                 removeCharByIndex(temp, arrayNumOfBackS[1]);
    //             } else {
    //                 replaceAll(temp, '"', '\'');
    //                 removeChar(temp, backS);
    //             }
    //             yylval.tokenData->tokenstrVal = temp;
    //         } else if (numQuotes > 2 && strchr(temp, backS) != NULL){
    //             int len = strlen(temp);
	//             replaceCharByIndex(temp, '\'', 0);
	//             replaceCharByIndex(temp, '\'', len - 1);
    //             removeChar(temp, backS);
    //             yylval.tokenData->tokenstrVal = temp;
    //         } else {
	//     	    yylval.tokenData->tokenstrVal = temp;
   	//         }
	       break;
   	}
	default:
		break;
        }   

    // return token class
    return tokenClass;

}
%}

%option noyywrap

%%

"//".*					{ /* C++ comment */ }
"/*"([^*]|"*"+[^*/])*"*"+"/"             { /* C comment */ }

"int"                           	        { return setValue(line, INT, yytext); }
"bool"                  		            { return setValue(line, BOOL, yytext); }
"char"                  	 	            { return setValue(line, CHAR, yytext); }
"static"                		            { return setValue(line, STATIC, yytext); }
"loop"                  		            { return setValue(line, LOOP, yytext); }
"forever"                  		            { return setValue(line, FOREVER, yytext); }
"return"                		            { return setValue(line, RETURN, yytext); }
"if"					                    { return setValue(line, IF, yytext); }
"else"					                    { return setValue(line, ELSE, yytext); }
"elseif"					                { return setValue(line, ELSEIF, yytext); }
"or"                            	        { return setValue(line, OR, yytext); }
"and"                           	        { return setValue(line, AND, yytext); }
"true"                                      { return setValue(line, TRUE, yytext); }
"false"                                     { return setValue(line, FALSE, yytext); }
"not"                                       { return setValue(line, NOT, yytext); }
"then"                                      { return setValue(line, THEN, yytext); }
"while"                                     { return setValue(line, WHILE, yytext); }
"do"                                        { return setValue(line, DO, yytext); }
"break"                                     { return setValue(line, BREAK, yytext); }
"+"		                                    { return setValue(line, PLUS, yytext); }
"-"		                                    { return setValue(line, MINUS, yytext); }
"*"		                                    {return setValue(line, MULTIPLY, yytext);};
"/"		                                    {return setValue(line, DIVIDE, yytext);};
"%"		                                    {return setValue(line, MODULUS, yytext);};
"?"		                                    {return setValue(line, QUESTION, yytext);};
[\(\)\,\<\>\:\{\}\;\=\[\]]                  {return setValue(line, yytext[0], yytext);}
"=="                     		            { return setValue(line, ASPC, yytext);}
"/="                                        { return setValue(line, DIVASS, yytext);}
"<="                                        { return setValue(line, LESSEQ, yytext);}
">="                                        { return setValue(line, GRTEQ, yytext);}
"--"                                        { return setValue(line, DEC, yytext);}
"++"                                        { return setValue(line, INC, yytext);}
"+="                                        { return setValue(line, ADDASS, yytext);}
"-="                                        { return setValue(line, SUBASS, yytext);}
"*="                                        { return setValue(line, MULASS, yytext);}
"!="                                        { return setValue(line, NOTEQ, yytext);}

[0-9]+                  		            { return setValue(line, NUMCONST, yytext); }	
".."                                        { return setValue(line, RANGE, yytext); }

"'"(\\.|[^\\"])"'"                          { return setValue(line, CHARCONST, yytext); }
"\""([^\"\n]|[\[^n0]])*"\""           	        { return setValue(line, STRINGCONST, yytext); }
[a-zA-Z_][a-zA-Z0-9_]*           	        { return setValue(line, ID, yytext); }
[ \t]                  			            ;  // white space
\n                     			            { line++; /*return setValue(line, yytext[0], yytext);*/ }
.                      			            { return setValue(line, NONE, yytext); }
%%

