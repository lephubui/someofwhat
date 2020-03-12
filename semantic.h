#ifndef _SEMANTIC_H_
#define _SEMANTIC_H_
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "treeNode.h"
#include "symbolTable.h"

void printSemanticTree(TreeNode *tree);

void semanticAnalysisTree(TreeNode * mTree);

void checkNode(TreeNode * tree);

void treeParseProcess ( TreeNode * parentNode, TreeNode * node, SymbolTable * symtable );

void printErrorsWarnings();

static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) );
#endif

