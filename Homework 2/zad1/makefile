program: program.o swap.o
	g++ program.o swap.o -o program

program.i: program.cpp
	g++ -E program.cpp -o program.i

swap.i: swap.cpp
	g++ -E swap.cpp -o swap.i 

program.s: program.i
	g++ -S program.i -o program.s

swap.s: swap.i
	g++ -S swap.i -o swap.s

program.o: program.s
	g++ -c program.s -o program.o

swap.o: swap.s
	g++ -c swap.s -o swap.o

clean:
	rm -f *.o *.i *.s program

