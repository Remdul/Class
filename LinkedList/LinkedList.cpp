#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include "LinkedList.h"

#define mark() {std::cout << "Location: " << __LINE__ << std::endl;}
/*
#define ASSERT_EQUAL(EXPRESSION, EXPECTED) \
std::cout << "Testing" << #EXPRESSION << "is equal to " << #EXPECTED << ": ";\
if (EXPECTED == (EXPRESSION))\
{std::cout << "PASS\n";}\
else {std::cout << "FAIL\n";}\
*/
//Implement asVector
//Implement Unit tests
//Convert Doubly Linked List

LinkedList::LinkedList()
{
    _listHead = NULL;
    _listTail = NULL;
    _size     = 0;
}

LinkedList::~LinkedList()
{
    Node *deleteNode = _listHead;
    Node *nextDeleteNode;
    if (_listHead == NULL)
    {
        std::cout << "Memory has been Chomped." << std::endl;
        return;
    }
    while (deleteNode != NULL) {
        nextDeleteNode = deleteNode->_nextNode;
        delete deleteNode;
        deleteNode = nextDeleteNode;
    }
}

void LinkedList::printList() const
{
    Node *printNode = _listHead;
    if (_listHead == NULL)
    {
        std::cout << "List is Empty. You Fail." << std::endl;
        return;
    }
    std::cout << "LinkedList Contents: " << std::endl;
    while (printNode != NULL) {
        std::cout << printNode->_value << std::endl;
        printNode = printNode->_nextNode;
    }
}

void LinkedList::addNodeEnd(int value)
{
    if (_listHead == NULL)
    {
        Node *newNode = new Node(value);
        _size += 1;
        _listHead = newNode;
        _listTail = newNode;
    }
    else
    {
        Node *newNode = new Node(value);
        _size += 1;
        Node *current = _listTail;
        current->_nextNode = newNode;
        _listTail = newNode;
    }
}

void LinkedList::addNodeBegin(int value)
{
    if (_listHead == NULL)
    {
        Node *newNode = new Node(value);
        _size += 1;
        _listHead = newNode;
        _listTail = newNode;
    }
    else
    {
        Node *newNode = new Node(value);
        _size += 1;
        newNode->_nextNode = _listHead;
        _listHead = newNode;
    }
}

int LinkedList::size() const
{
    Node *current   = _listHead;
    int count       = 0;
    while (NULL != current)
    {
        count++;
        current = current->_nextNode;
    }
    return count;
}

int LinkedList::getSize() const
{
    return _size;
}

int LinkedList::at(int index) const
{
    Node *findNode = _listHead;
    int indexCounter = 0;
    while (NULL != findNode)
    {
        if (indexCounter == index)
        {
            return findNode->_value;
        }
        findNode = findNode->_nextNode;
        indexCounter += 1;
    }
    // Failed to find in List
    return -1;
}
void LinkedList::insertBefore(int index, int value)
{
    Node *findNode = _listHead;
    Node *insertNode = new Node(value);
    int indexCounter = 0;
    if (_listHead == NULL || index == 0)
    {
        addNodeBegin(value);
        return;
    }
    while (_listTail != findNode)
    {
        if (indexCounter == (index -1 ))
        {
            insertNode->_nextNode = findNode->_nextNode;
            findNode->_nextNode = insertNode;
            _size += 1;
            return;
        }
        findNode = findNode->_nextNode;
        indexCounter += 1;
    }
    addNodeEnd(value);
    return;
}
int LinkedList::popHead()
{
    int poppedValue;
    if (_listHead == NULL)
    {
        return -1;
    }
    if (_listHead == _listTail)
    {
        delete _listHead;
        _size -= 1;
        _listHead = NULL;
        _listTail = NULL;
        return -1;
    }
    Node *nextNode= _listHead->_nextNode;

    poppedValue = _listHead->_value;
    delete _listHead;
    _size -= 1;
    _listHead = nextNode;
    return poppedValue;
}
int LinkedList::popTail()
{
    int poppedValue;
    if (_listHead == NULL)
    {
        return -1;
    }
    if (_listHead == _listTail)
    {
        delete _listHead;
        _size -= 1;
        _listHead = NULL;
        _listTail = NULL;
        return -1;
    }
    Node *nextNode= _listHead;

    while (_listTail != nextNode->_nextNode)
    {
        nextNode= nextNode->_nextNode;
    }
    poppedValue = _listTail->_value;
    delete _listTail;
    _size -= 1;
    nextNode->_nextNode = NULL;
    _listTail = nextNode;
    return poppedValue;
}
int LinkedList::popAt(int index)
{
    if (NULL == _listHead)
    {
        return -1;
    }
    if(_listHead == _listTail)
    {
        delete _listHead;
        _size -= 1;
        _listHead = NULL;
        _listTail = NULL;
        return -1;
    }
    if (0 == index)
    {
        popHead();
        return -1;
    }

    if (_size == index)
    {
        popTail();
        return -1;
    }
    if (_size < index)
    {
        return -1;
    }
    Node *findNode = _listHead;
    int indexCounter = 0;
    while (NULL != findNode)
    {
        if (indexCounter == (index - 1))
        {
            Node *tempNode = findNode->_nextNode;
            findNode->_nextNode = tempNode->_nextNode;
            delete tempNode;
            _size -= 1;
        }
        findNode = findNode->_nextNode;
        indexCounter += 1;
    }
    return -1;
}
bool test(std::vector<int>expectedValues, LinkedList List)
{
    for (int i = 0; i < expectedValues.size(); i++)
    {
        if (expectedValues[i] == List.operator [](i))
        {
            std::cout << "Pass" << std::endl;
            return true;
        }
    }
    std::cout << "Fail" << std::endl;
    return false;
}
//this needs to be scoped
std::vector<int> LinkedList::asVector()
{
    int sizeTotal = size();
    std::vector<int> values;
    for (int i = 0; i < size(); i++)
    {

    }
    return values;
}

int main(int argc, const char * argv[])
{
    LinkedList listMain;
    const int addtoList = 5;
    for (int i = 0; i < addtoList; i++)
    {
        listMain.addNodeEnd(i);
    }
    std::vector<int>expectedValues;
    expectedValues.push_back(0);
    expectedValues.push_back(1);
    expectedValues.push_back(2);
    expectedValues.push_back(3);
    listMain.printList();
    std::cout <<"SIZE:: "<< listMain.getSize() << std::endl;
//    ASSERT_EQUAL(listMain.popAt(1), expectedValues);
    listMain.popAt(7);
    test(expectedValues, listMain);
}
