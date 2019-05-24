#pragma once
#include <iostream>
using namespace std;

struct dlist {
	int *data = new int;
		dlist *next;
		dlist *prev;

	~dlist();
};
