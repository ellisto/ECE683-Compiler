CC=g++
CFLAGS=-g -c
SOURCES=compiler.cc fsm.cc  linecounter.cc  report_error.cc  scanner.cc  symboltable.cc  token.cc parser.cc code_writer.cc symboltableentry.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=compiler

all: $(SOURCES) $(EXECUTABLE) runtime.a

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

runtime.a: runtime.o
	ar rcs libruntime.a runtime.o

runtime.o: 	
	gcc -lm -c runtime.c -o runtime.o

.PHONY: clean
clean:
	rm -rf *o $(EXECUTABLE)
