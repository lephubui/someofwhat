BIN  = c-
CC   = g++
CFLAGS = -DCPLUSPLUS -g     # for use with C++ if file ext is .c

SRCS = $(BIN).y $(BIN).l ourgetopt.c util.c symbolTable.cpp printtree.cpp semantic.cpp
HDRS = scanType.h treeNode.h ourgetopt.h util.h symbolTable.h printtree.h semantic.h 
OBJS = lex.yy.o $(BIN).tab.o ourgetopt.o util.o symbolTable.o printtree.o semantic.o
LIBS = -lm

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) main.cpp -o $(BIN)

$(BIN).tab.h $(BIN).tab.c: $(BIN).y
	bison -v -t -d --debug --verbose $(BIN).y  

lex.yy.c: $(BIN).l $(BIN).tab.h
	flex $(BIN).l

all:    
	touch $(SRCS)
	make

clean:
	rm -f $(OBJS) $(BIN) lex.yy.c $(BIN).tab.h $(BIN).tab.c $(BIN).tar $(BIN).output *~

tar: 	
	tar -cvf $(BIN).tar $(SRCS) $(HDRS) makefile 
	ls -l $(BIN).tar
