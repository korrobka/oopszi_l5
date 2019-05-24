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
	int size() const;	// ���������� ������� �������
	int length() const;	// ���������� �������� ����� �������
	void push(int value); //��������� ������� � ����� �������
	void pop();  //������� ������� �� ������ �������
	int peek();  //���������� ������� �� ����� �������
	friend std::ostream& operator<<(std::ostream &out, const queue &ex);

private:
	//char full = 0;
	dlist *first;
	dlist *last;
};
