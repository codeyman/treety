CC=clang++
CFLAGS=-c -Wall -Weffc++ -Wextra -std=c++11 -DTEST_TREE  
LDFLAGS= -stdlib=libc++
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
