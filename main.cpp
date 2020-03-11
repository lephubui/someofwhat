
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "treeNode.h"
#include "scanType.h"
#include "ourgetopt.h"
#include "c-.tab.h"
#include "util.h"
#include "semantic.h"
#include "printtree.h"

extern TreeNode *syntaxTree;

extern TreeNode *preTree;
extern TreeNode *postTree;

extern FILE* yyin;

int main(int argc, char *argv[]){
  int c;
  int counter = 1;
  extern char *optarg;
  int flagTree = 0, findIndex;
  
  int numErrors=0; 
  int  numWarnings=0;

  // hunt for a string of options
  while ((c = ourGetopt(argc, argv,(char*)("pd"))) != -1) {
    switch (c) {  
    case 'd':
      break;
    case 'p':
      flagTree = 1;
      break;
    case 'P':
      flagTree = 3;
      break;
    case '?':
      findIndex = optind;
      break;                                                                       
    default:                                                                                                
      exit(1);
      counter++;
    }

    if(argc > 1){
      if(yyin = fopen(argv[optind], "r")){
	     yyparse();
	if(flagTree == 1){
	   printTree(syntaxTree);
          //checkNode(syntaxTree);
          //printSemanticTree(syntaxTree);
	} else if(flagTree == 3){
          checkNode(syntaxTree);
        } else{
          exit(1);                  
	}      
      }  
    }                      
              
  }

  // report the number of errors and warnings
  printf("Number of warnings: %d\n", numWarnings);
  printf("Number of errors: %d\n", numErrors);
  return 0;
}
