//Soshi Jain Phase 2
#include "DynamicArray.h"
#include <cassert>
#include "Shape.h" 
using namespace std;


template <class T>
DynamicArray<T>::DynamicArray() : capacity(2), numElements(0) {//Soshi Jain
    p =new T[capacity];
}

template <class T>
DynamicArray<T>::DynamicArray(int s) : capacity(s), numElements(0) {//Soshi Jain
    assert(s>0);
    p =new T[capacity];
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& d)
    : capacity(d.capacity), numElements(d.numElements) {//Soshi Jain
    cout<<"DynamicArray ==> Copy constructor was called"<<endl;
    p = new T[capacity];
    for (int i=0; i<numElements; ++i) {
        p[i] = d.p[i];
    }
}

template <class T>
DynamicArray<T>::~DynamicArray() {//Soshi Jain
    delete[] p;
    cout <<"DynamicArray ==> Destructor was called"<<endl;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& d) {//Soshi Jain
    if (this != &d) {
        cout<<"DynamicArray ==> Assignment op was called"<<endl;
        delete[] p;
        capacity = d.capacity;
        numElements = d.numElements;
        p = new T[capacity];
        for (int i=0; i<numElements;++i) {
            p[i] = d.p[i];
        }
    }
    return *this;
}

template <class T>
int DynamicArray<T>::getCapacity() const {//Soshi Jain
    return capacity;
}

template <class T>
int DynamicArray<T>::getNumElements() const {//Soshi Jain
    return numElements;
}

template <class T>
T& DynamicArray<T>::operator[](int index) {
    assert(index>= 0 && index < numElements);
    return p[index];
}

template <class T>
void DynamicArray<T>::add(const T& e) {//Soshi Jain//Lauryn stanislaus added const refernce to avoid changing the passed object 
    if (numElements==capacity) {
        capacity *= 2;
        T* temp = new T[capacity];
        for (int i= 0; i<numElements; ++i) {
            temp[i] = p[i];
        }
        delete[] p;
        p = temp;
    }
    p[numElements++] = e;
}
template class DynamicArray<Shape*>;
