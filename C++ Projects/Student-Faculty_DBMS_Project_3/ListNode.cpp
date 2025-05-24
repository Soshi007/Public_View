//Part 4: Ongshi Dugar
#include "ListNode.h"
#include "Person.h"
template<typename T>
ListNode<T>::ListNode(T* data) : data(data), next(nullptr){}
template class ListNode<Person*>; 
