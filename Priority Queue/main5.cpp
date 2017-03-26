#include <iostream>
#include "lab5.h"
#include <cstdlib>

using namespace std;

int main()
{
    queue test;
    test.enqueue(-1);
    test.enqueue(2);
    test.enqueue(-3);
    test.enqueue(4);

    cout<<test.dequeue()<<endl;
    cout<<test.dequeue()<<endl;
    queue test1(test);
    
    
    cout<<"testing copy constructor"<< endl;
    test1.print();
    cout<<test1.dequeue()<<endl;
}