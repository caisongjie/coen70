#include <iostream>
#include "lab5_2.h"

using namespace std;

void OrderedList::insert(T value) {
	if (N == 0) {
		cursor = new Node(value,NULL,NULL);
	} else {
		end();
		while(cursor != NULL) {
			if (value > cursor->data) {
				Node* tmp = new Node(value,cursor,cursor->next);
				cursor->next = tmp;
				if (tmp->next != NULL) {
					tmp->next->prev = tmp;
				}
				return;
			}
			if (cursor->prev == NULL) {
				Node* tmp = new Node(value,cursor->prev, cursor);
				cursor->prev = tmp;
				return;
			}
			cursor = cursor->prev;
		}
	}
	N++;
}

void OrderedList::attach(T value) {
	if (N == 0) {
		cursor = new Node(value,NULL,NULL);
	} else {
		start();
		while(cursor != NULL) {
			if (value < cursor->data) {
				Node* tmp = new Node(value,cursor->prev,cursor);
				cursor->prev = tmp;
				if (tmp->prev != NULL) {
					tmp->prev->next = tmp;
				}
				return;
			}
			if (cursor->next == NULL) {
				Node* tmp = new Node(value,cursor, cursor->next);
				cursor->next = tmp;
				return;
			}
			cursor = cursor->next;
		}
	}
	N++;
}

bool OrderedList::remove(T value){
	if (N == 0) {
		cout << "List is empty";
		return false;
	}
	start();
	while(cursor != NULL) {
		if (cursor->data == value) {
			remove_current();
			return true;
		}
		cursor = cursor->next;
	}
	cout << "Value was not in the list.";
	return false;
}


