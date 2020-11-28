main: main.o utils.o
	clang++ main.o utils.o -o main

utils.o : utils.h utils.cpp
	clang++ -c utils.cpp

airlines.o : airlines.h airlines.cpp 
	clang++ -c airlines.cpp

main.o : main.cpp
	clang++ -c main.cpp

clean : 
	rm main *.o
	
clear :
	rm main *.o
