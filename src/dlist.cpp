#include <iostream>
#include <math.h>
#include "dlist.h"

using namespace std;

dlist::~dlist() {
	dlist *follow;
	do {
		prev = nullptr;
		follow = next;
		next = nullptr;
		delete data;
		data = nullptr;
	} while (follow != nullptr);
}