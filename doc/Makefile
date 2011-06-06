TEX=pdflatex
TEXFLAGS=
DOT=dot
DOTFLAGS=-Tpng
TEXSOURCES=compiler.tex 
DOTSOURCES=scanner.dot
OBJECTS=$(DOTSOURCES:.dot=.png)
EXECUTABLE=compiler.pdf

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(TEX) $(TEXFLAGS) $(TEXSOURCES)

.dot.png:
	$(DOT) $(DOTFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf *.aux *.log *~  $(EXECUTABLE)

