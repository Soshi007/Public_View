//Part 4: Ongshi Dugar
#ifndef LISTNODE_H
#define LISTNODE_H

template <typename T>
class ListNode {
public:
    T* data;
    ListNode<T>* next;
    ListNode(T* data);
};

#endif
