#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>

struct Node {
    friend class LinkedList;
public:
    Node(void):_nextNode(NULL){}                                        // Constructor NO value
    Node(int value):_value(value), _nextNode(NULL){}                    // Constructor with Value
    Node(int value, Node* nextNode):_value(value),_nextNode(nextNode){} // Constructor with Value and Next Point
private:
    int _value;
    Node *_nextNode;
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void addNodeEnd(int value);
    void addNodeBegin(int value);
    void insertBefore(int index, int value);
    int size() const;
    void printList() const;
    int at(int index) const;
    int popHead();
    bool iterating();
    int popTail();
    int popAt(int index);
    int getSize() const;
    int operator[](int i){return at(i);}
    std::vector<int> asVector() const;
private:
    Node *_listHead;                                                    // Where doos list start?
    Node *_listTail;                                                    // Where does list end?
    int _size;
};


#endif
