main: main.o
	clang++ main.o -o main
main.o : airlines.h main.cpp
	clang++ -c airlines.h main.cpp

clean : 
	rm main *.o
