//Soshi Jain phase 2 part 10
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
using namespace std;


template<class T>
 class DynamicArray {
 public:
    DynamicArray();
    DynamicArray(int s);
    //copy constructor
    DynamicArray(const DynamicArray& d);
    //destructor
    ~DynamicArray();
    //assssignment operator
    DynamicArray<T>& operator=(const DynamicArray& d);
    int getCapacity() const;
    int getNumElements() const;
    T& operator[](int index);
    void add(T &e);
 private:
    T *p;
    int capacity;
    int numElements;
};
#endif
