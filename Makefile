main: main.o pmm.o state.o pmmMatrix.o pmmTree.o
	g++ -std=c++17 -g -o main.exe main.o pmm.o state.o pmmMatrix.o pmmTree.o

main.o: main.cpp PatternMatchingMachine.h State.h PmmMatrix.h
	g++ -std=c++17 -c -g -o main.o main.cpp

pmm.o: PatternMatchingMachine.cpp PatternMatchingMachine.h
	g++ -std=c++17 -c -g -o pmm.o PatternMatchingMachine.cpp 

state.o: State.cpp State.h
	g++ -std=c++17 -c -g -o state.o State.cpp 
	
pmmMatrix.o: PmmMatrix.cpp PmmMatrix.h
	g++ -std=c++17 -c -g -o pmmMatrix.o PmmMatrix.cpp 
	
pmmTree.o: pmmTree.cpp pmmTree.h
	g++ -std=c++17 -c -g -o pmmTree.o pmmTree.cpp 

clean:
	rm -f *.o
	rm -f *~
	rm -f *.out