#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "queue.h"

using namespace std;

int main() {
	//queue *q = new queue(5);
	cout << "creating a queue of 10 elements..." << endl;
	queue q(10);

	cout << "pushing 12 elements..." << endl;
	for (int i = 1; i < 12; i++)
	{ q.push(i); }

	cout << "queue : " << q << endl;
	cout << "the first in the queue = " << q.peek() << endl;
	cout << "size = " << q.size();
	cout << "; length = " << q.length() << endl;
	cout << "pop!" << endl;
	q.pop();
	cout << "queue : " << q << endl;
	cout << "the first in the queue = " << q.peek() << endl;
	cout << "size = " << q.size();
	cout << "; length = " << q.length() << endl;
	system("pause");
	//delete q;
}