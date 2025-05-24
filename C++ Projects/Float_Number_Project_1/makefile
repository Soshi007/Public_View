all: prog

prog: Float_Number.o Main.o
	g++ -std=c++11 -o prog Float_Number.o main.o

Float_Number.o: Float_Number.cpp Float_Number.h
	g++ -std=c++11 -c Float_Number.cpp

main.o: Main.cpp Float_Number.h
	g++ -std=c++11 -c Main.cpp

clean:
	del *.o prog