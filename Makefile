main: main.o utils.o airlines.o airports.o planes.o routes.o
	clang++ main.o utils.o airlines.o airports.o planes.o routes.o -o main

utils.o : utils.h utils.cpp
	clang++ -c utils.cpp

airlines.o : airlines.h airlines.cpp 
	clang++ -c airlines.cpp

airports.o : airports.h airports.cpp 
	clang++ -c airports.cpp

planes.o : planes.h planes.cpp 
	clang++ -c planes.cpp
	
routes.o : routes.h routes.cpp 
	clang++ -c routes.cpp

main.o : main.cpp
	clang++ -c main.cpp

clean : 
	rm main *.o
	
clear :
	rm main *.o
