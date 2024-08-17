main: main.cpp pmm.o state.o
	g++ -std=c++17 -o main main.cpp pmm.o state.o

pmm.o: PatternMatchingMachine.cpp PatternMatchingMachine.h
	g++ -std=c++17 -c -o pmm.o PatternMatchingMachine.cpp

state.o: State.cpp State.h
	g++ -std=c++17 -c -o state.o State.cpp 

clean:
	rm -f *.o
	rm -f *~
	rm -f main