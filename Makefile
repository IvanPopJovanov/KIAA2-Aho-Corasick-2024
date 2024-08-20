main: main.o pmm.o state.o
	g++ -std=c++17 -g -o main.out main.o pmm.o state.o

main.o: main.cpp PatternMatchingMachine.h State.h
	g++ -std=c++17 -c -g -o main.o main.cpp

pmm.o: PatternMatchingMachine.cpp PatternMatchingMachine.h
	g++ -std=c++17 -c -g -o pmm.o PatternMatchingMachine.cpp 

state.o: State.cpp State.h
	g++ -std=c++17 -c -g -o state.o State.cpp 

clean:
	rm -f *.o
	rm -f *~
	rm -f *.out