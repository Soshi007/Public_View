##Soshi Jain Part 7

all: Main.exe

Main.exe: Main.o Shape.o Triangle.o Rectangle.o Circle.o Point.o Edge.o
	g++ -o Main.exe Main.o Shape.o Triangle.o Rectangle.o Circle.o Point.o Edge.o

Main.o: Main.cpp
	g++ -c Main.cpp

Shape.o: Shape.cpp Shape.h
	g++ -c Shape.cpp

Triangle.o: Triangle.cpp Triangle.h
	g++ -c Triangle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ -c Rectangle.cpp

Circle.o: Circle.cpp Circle.h
	g++ -c Circle.cpp

Point.o: Point.cpp Point.h
	g++ -c Point.cpp

Edge.o: Edge.cpp Edge.h
	g++ -c Edge.cpp

clean:
	rm -f *.o main