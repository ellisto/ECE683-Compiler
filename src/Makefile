CC=g++
CFLAGS=-g -c
SOURCES=compiler.cc fsm.cc  linecounter.cc  report_error.cc  scanner.cc  symboltable.cc  token.cc parser.cc code_writer.cc symboltableentry.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=compiler

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf *o $(EXECUTABLE)
