CC=g++
CFLAGS=-c -Wall -DTEST_TREE
LDFLAGS=
SOURCES=Tree.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=treetyTest

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@
