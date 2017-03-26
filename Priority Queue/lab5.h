# include <cstdlib>
#include<iostream>
using namespace std;
class Node
{
public:
    Node *next;
    Node *prev;
    int data;
};
class queue
{
public:
    queue();
    ~queue();
    queue(const queue& other);
    void enqueue(int);
    int dequeue();
    bool isEmpty();
    void print();
private:

    Node *head;
    
};

