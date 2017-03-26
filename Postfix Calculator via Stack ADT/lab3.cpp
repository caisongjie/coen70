#include <iostream>
#include <cmath>
#include "lab3.h"

using namespace std;

//CSTOR for stack, initializes the size to zero and the top pointer of the stack to NULL, representing an empty stack.
Stack::Stack()
{
    size=0;
    cursor=NULL;
}

//DSTOR for stack, starts at the top and deletes every node until stack is empty
Stack::~Stack(){
    Node *current = cursor, *next;
    while(current != NULL){
        next = current->next;
        delete current;
        current = next;
    }
    cursor = NULL;
}

//Push creates a new node for the stack and appends it to the top, the size is incremented with each node, and the cursor pointed is updated to point at the new node.
void Stack::push(double x)
{
    Node *s=new Node();
    if(size==0)
    {
        s->data=x;
        s->next = NULL;
        cursor=s;
    }
    else
    {
    s->data=x;
    s->next=cursor;
    cursor=s;
    }
    size++;
    
}

//Pop returns the value stored in the top node, pointed at by cursor. The cursor is updated to the next node down, and the popped node is deleted. Decrements size.
double Stack::pop()
{
    if(size==0)
    {
        return 0;
    }
    else
    {
        Node* dele=cursor;
        double temp = cursor->data;
        cursor=cursor->next;
        delete dele;
        return temp;
        size--;
    }
    
}
//Top returns the value stored in the top node without deleting or modifying any nodes.
double Stack::top()
{
    if(size==0)
    {
        return 0;
    }
    else
    {
        return cursor->data;
    }
}






