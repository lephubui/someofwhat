#ifndef _UTIL_H_
#define _UTIL_H_

#include "treeNode.h"
/* Procedure printToken prints a token 
 * and its lexeme to the listing file
 */
void printToken( TokenType, const char* );
void printTree( TreeNode * tree );
TreeNode * newDeclNode(DeclKind kind, int lineNum);
TreeNode * newStmtNode(StmtKind kind,  int lineNum);
TreeNode * newExpNode(ExpKind kind, int lineNum);
void childExpType(TreeNode *mTree, ExpType mType);
TreeNode * linkChild( TreeNode * child1, TreeNode * child2 );

char * copyString(char * s, int line);
#endif
