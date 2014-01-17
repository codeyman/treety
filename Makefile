CC=clang++
CFLAGS=-c -Wall -Weffc++ -Wextra -std=c++11   
LDFLAGS= -stdlib=libc++
SOURCES=Tree.cc Showoff.cc AVLTree.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=treetyTest 
#EXECFLAG=-DTEST_TREE
EXECFLAG=-DTEST_AVLTREE

all: $(SOURCES) $(EXECUTABLE)

debug: CFLAGS += -DDEBUG -g
debug: $(EXECUTABLE)

avltest: EXECFLAG=-DTEST_AVLTREE
avltest: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS)  $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $(EXECFLAG) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
