CFLAGS = -ggdb
DEFINES = -DDEBUGGA
INCLUDES = 
LIBS = -lstdc++
EXAMPLE = plotter.o
CC=g++

.cc.o:
	$(CC) -c $(CFLAGS) $(DEFINES) $(INCLUDES) $<

all::	plotter

gnuplot_i.o:	gnuplot_i.hpp
example.o:	plotter.cc

example: $(EXAMPLE)
	$(CC) -o $@ $(CFLAGS) $(EXAMPLE) $(LIBS)

clean: 
	rm -f $(EXAMPLE) plotter
