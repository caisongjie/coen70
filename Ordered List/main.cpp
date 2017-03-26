#include <iostream>
#include "lab5_2.cpp"

using namespace std;

int main() {
	OrderedList x;
	x.insert(1);
	x.attach(4);
	x.attach(2);
	x.attach(3);
	x.remove(1);
	cout << x;
}
