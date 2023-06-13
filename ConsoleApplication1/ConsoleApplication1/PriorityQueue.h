#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Heap.h"

template <typename T>
class PriorityQueue 
{
	T* tab = nullptr;
	int size = 0;
	bool (*cmp)(T, T);

public:
	PriorityQueue(int maxSize, bool (*c)(T, T)) 
	{
		tab = new T[maxSize];
		cmp = c;
	}
	
	void push(T val)
	{
		Heap<T>::push(tab, val, size, cmp);
	}
	
	void pop()
	{
		Heap<T>::pop(tab, size, cmp);
	}

	T top()
	{
		return tab[1];
	}

	void setTab(T* tab, int size) 
	{
		this->tab = tab;
		this->size = size;
	}

	void changeComp(bool (*c)(T, T))
	{
		cmp = c;
	}

	int getSize()
	{
		return size;
	}
	
	T getData(int index)
	{
		return tab[index];
	}
};
#endif PRIORITYQUEUE_H