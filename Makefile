CC=g++
CFLAGS=-c -Wall -DTEST_TREE  
LDFLAGS=
SOURCES=Tree.cc Showoff.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=treetyTest

all: $(SOURCES) $(EXECUTABLE)

debug: CFLAGS += -DDEBUG -g
debug: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
