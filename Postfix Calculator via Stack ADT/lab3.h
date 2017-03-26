#include <iostream>
#include <cmath>
struct Node
{
    Node* next;
    double data;
    Node() {
        data = 0;
        next = NULL;
    }
};
class Stack
{
public:
    Stack();
    ~Stack();
    void push(double);
    double pop();
    double top();
private:
    int size;
    Node *cursor;
};

