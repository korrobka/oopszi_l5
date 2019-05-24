#include <iostream>
#include <math.h>
#include "queue.h"

using namespace std;

queue::queue(int count) {
	dlist *node;
	dlist *pre;
	for (int i = 0; i < count; i++)
	{
		node = new dlist;
		*node->data = 0;
		//node->data = NULL;
		if (i == 0) {			//конец очереди
			first = node;			// первый элемент очереди - этот
			pre = node;				// сохраняем этот элемент
			node->prev = nullptr;	// предыдущих нету
		}
		else {					// середина очереди
			pre->next = node;		// следующий элемент по отношению к предыдущему - этот			
			node->prev = pre;		// записываем сохраненный элемент как предыдущий по отношению к новому
			pre = node;				// сохраняем этот элемент
		}

		if (i == count - 1) {	// начало списка
			last = node;			// последний элемент очереди - этот
			node->next = nullptr;	// следующего не будет
		}
	}
}

queue::~queue(){
	delete first;
}

queue::queue(queue && other)
{
	first = other.first;
	last = other.last;
	other.first = nullptr;
	other.last = nullptr;
}

queue & queue::operator=(queue && other)
{
	if (this == &other)
	{
		return *this;
	}
	delete first;
	delete last;
	first = other.first;
	last = other.last;
	other.first = nullptr;
	other.last = nullptr;
}

ostream& operator<<(ostream &out, const queue &ex)
{
	dlist *pos = ex.last;
	out << "[ ";
	while (pos->prev != nullptr) {
		if (!*pos->data) {
			out << "x ; ";
		}
		else {
			out << *pos->data << " ; ";
		}

		pos = pos->prev;
	}
	
	out << *pos->data << " ]";
	return out;
}

int queue::size() const
{
	dlist *ptr = first;
	int size = 0;
	while (ptr != nullptr)
	{
		ptr = ptr->next;
		size++;
	}
	return size;
}

int queue::length() const
{
	dlist *ptr = first;
	int size = 0;
	while (ptr != nullptr)
	{
		if (*ptr->data)
		{
			size++;
		}
		ptr = ptr->next;
	}
	return size;
}

void queue::push(int value)
{
	dlist *pos = last;
	if (*pos->data) {
		cout << "queue full" << endl;
	}
	else {
		while (pos->prev != nullptr) {
			if (*pos->prev->data)
				{break;}
			pos = pos->prev;
		}
		*pos->data = value;
	}	
}

void queue::pop()
{
	dlist *pos = first;
	while (pos->next != nullptr) {
		*pos->data = *pos->next->data;
		pos = pos->next;
	}
	*last->data = 0;
}

int queue::peek()
{
	return (*first->data);
}