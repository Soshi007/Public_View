all: student_db

student_db: main.o Person.o Student.o Faculty.o LinkedList.o ListNode.o
	g++ -o student_db main.o Person.o Student.o Faculty.o LinkedList.o ListNode.o

main.o: main.cpp Person.h Student.h Faculty.h LinkedList.h
	g++ -c main.cpp

LinkedList.o: LinkedList.cpp LinkedList.h ListNode.h Person.h Student.h Faculty.h
	g++ -c LinkedList.cpp

ListNode.o: ListNode.cpp ListNode.h
	g++ -c ListNode.cpp

Faculty.o: Faculty.cpp Faculty.h Person.h
	g++ -c Faculty.cpp

Student.o: Student.cpp Student.h Person.h
	g++ -c Student.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

clean:
	rm -f *.o student_db
