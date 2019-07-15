all: task4

task4: main.o globals.o Point.o Knight.o
	g++ main.o globals.o Point.o Knight.o -g -Wall -o task4

main.o: main.cc globals.hh Point.hh Knight.hh

Globals.o: globals.cc globals.hh
Point.o: Point.cc Point.hh
Knight.o: Knight.hh Knight.cc

clean:
	rm -f *.o *~ a.out task4