#pragma once
#include <iostream>
#include "dlist.h"

using namespace std;

class queue
{
public:
	queue(int count);
	~queue();
	queue(queue &&other);
	queue &operator=(queue &&other);
	int size() const;	// возвращает размеры очереди
	int length() const;	// возвращает реальную длину очереди
	void push(int value); //добавляет элемент в конец очереди
	void pop();  //удаляет элемент из начала очереди
	int peek();  //возвращает элемент из конца очереди
	friend std::ostream& operator<<(std::ostream &out, const queue &ex);

private:
	//char full = 0;
	dlist *first;
	dlist *last;
};
