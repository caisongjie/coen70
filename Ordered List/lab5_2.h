#include <iostream>
#include "lab5.cpp"
#pragma once
typedef int T;
using namespace std;

class OrderedList:public List {
public:
	OrderedList():List(){}
	//Member Functions
	void insert(T) ;
	void attach(T) ;
	bool remove(T);
    
};