
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
  while ((c = ourGetopt(argc, argv,(char*)("pdP"))) != -1) {
    switch (c) {  
    case 'd':
      break;
    case 'p':
      flagTree = 1;
      break;
    case 'P':
      flagTree = 2;
      break;
    case '?':
      findIndex = optind;
      break;                                                                       
    default:                                                                                                
      exit(1);
      counter++;
    }
  
  TreeNode *errorsWarningTree = syntaxTree;
  if(argc > 1){
        if(yyin = fopen(argv[optind], "r")){
        yyparse();
        if(flagTree == 1){
          // Print the normal tree 
          printTree(syntaxTree);
          
          //printErrorWarningTree(syntaxTree);

        } else if(flagTree == 2){
          // Print warning and errors tree
          printf("Option -P\n");
          semanticAnalysisTree(syntaxTree);
          printErrorWarningTree(syntaxTree);
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
