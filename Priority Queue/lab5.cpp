#include <iostream>
#include <cstdlib>
#include "lab5.h"
using namespace std;

queue::queue()
{
    head=NULL;
}

queue::~queue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

queue::queue(const queue &other)
{
    //self check
    if(this== &other)
    {
        return;
    }
    //return if the source is an empty queue
    if (other.head==NULL) {
        return;
    }
    
    else
    {
        head=NULL;
        for(Node *temp=other.head;temp!=NULL;temp=temp->next)
        {
            enqueue(temp->data);
        }
    }
}

void queue::enqueue(int num)
{
    Node *temp= new Node;
    temp->data=num;
    //first case: insert the first value
    if(isEmpty())
    {
        head= temp;
        temp->next=NULL;
        temp->prev=NULL;
        return;
    }
    //second case: insert the largest number before the head
    if (num>head->data) {
        temp->next=head;
        head->prev=temp;
        temp->prev=NULL;
        head=temp;
        return;
    }
    //general case: insert the number between two values
    Node *cursor=head;
    while(cursor->next!=NULL)
    {
        if (num>=cursor->next->data) {
            temp->next=cursor->next;
            temp->prev=cursor;
            cursor->next->prev=temp;
            cursor->next=temp;
            return;
        }
        cursor=cursor->next;
    }
    temp->next=NULL;
    cursor->next=temp;
}

int queue::dequeue()
{
    if(isEmpty())
    {
        cout<< "queue is Empty"<<endl;
        return -1;
    }
    int temp=head->data;
    Node *cursor=head;
    if(head->next==NULL)
    {
        delete cursor;
        head=NULL;
        
        return temp;
    }
    head=head->next;
    delete cursor;
    return temp;
}

bool queue::isEmpty()
{
    return head==NULL;
}


void queue::print()
{
    for (Node * temp= head; temp!=NULL; temp=temp->next)
    {
        cout<<temp->data<<endl;
    }
}