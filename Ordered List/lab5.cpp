#include "List.h"
#include <iostream>
using namespace std;

//Constructor
List::List() {
    
    cursor = NULL;
    N = 0;
}

//Copy constructor
List::List(const List &other) {
    this->cursor=NULL;
    *this=other;
    N=other.N;
}

//Destructor
List::~List() {
    while (N == 0) {
        remove_current();
    }
}

List& List::operator=(const List &other) {
    if (this==&other)
    {
        return *this;
    }
    if(other.N==0)
    {
        cout<<"it is an empty list, cannot copy"<<endl;
        return *this;
    }
    start();
    Node *temp=other.cursor;
    while (temp != NULL) {
        insert(temp->data);
    }
    return *this;
}

void List::start() {
    while (cursor->prev != NULL) {
        cursor = cursor->prev;
    }
}

void List::end() {
    while (cursor->next != NULL) {
        cursor = cursor->next;
    }
}

void List::advance(){
    if (cursor != NULL) {
        cursor = cursor -> next;
    }
}

void List::insert(T value) {
    
    if(N==0) {
        Node *temp = new Node(value,NULL,NULL);
        cursor=temp;
        N++;
        return;
    }
    else{
        Node*temp=new Node(value,cursor->prev,cursor);
        cursor->prev=temp;
        cursor=temp;
        N++;
        return;
    }
}

void List::attach(T value){
    if(N==0) {
        Node *temp = new Node(value,NULL,NULL);
        cursor=temp;
        N++;
        return;
    }
    else{
        Node* temp =new Node(value,cursor,cursor->next);
        cursor->next=temp;
        cursor=temp;
        N++;
        return;
    }
}

void List::remove_current(){
    if (cursor==NULL) {
        cout <<"Cannot remove, already empty." << endl;
        return;
    }
    
     Node* temp = cursor;
    
    if(cursor->prev==NULL){
        cursor->next->prev = cursor->prev;
        cursor = cursor->next;
        delete temp;
        N--;
        cout <<"test"<<endl;
        return;
    }
    
    if (cursor->next == NULL) {
        cursor=cursor->prev;
        delete temp;
        N--;
        return;
    }
    cursor -> prev -> next = temp -> next;
    cursor -> next -> prev = temp -> prev;
    cursor = cursor -> next;
    delete temp;
    N--;
}

int List::size() const {
    return N;
}

T List::current() const {
    return cursor->data;
}

ostream& operator<<(ostream& out, const List& other) {
    List::Node*temp = other.cursor;
    //temp->start();
    while (temp->prev != NULL) {
        temp = temp->prev;
    }
    while (temp != NULL) {
        out << temp->data<<endl;
        temp=temp->next;
    }
    return out;
}

/*int main() {
    List test;
    test.insert(1);
    test.insert(2);
    test.attach(3);
    cout<<test<<endl;
    cout<<" printing current "<<test.current()<<endl;
    test.start();
    cout<<"printing current "<<test.current()<<endl;
    test.remove_current();
    cout<<test<<endl;
}*/