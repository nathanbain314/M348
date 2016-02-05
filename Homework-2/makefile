all: Algebra.o Bisection.o
	g++ -o bisection Bisection.o Algebra.o

Algebra.o: Algebra.c++
	g++ -c Algebra.c++ -Wno-write-strings

Bisection.o: Bisection.c++
	g++ -c Bisection.c++

clean:
	rm -f *.o
	rm bisection
