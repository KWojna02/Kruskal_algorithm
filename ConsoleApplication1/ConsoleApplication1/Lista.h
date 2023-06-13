#ifndef LISTA_H
#define LISTA_H

template <typename T>
struct Item 
{
	T data;					
	Item<T>* next = nullptr;
};

template <typename T>
class List
{
private:
	Item<T>* head;			
	Item<T>* tail;
	int size;			

public:
	List()					
	{
		head, tail = nullptr;
		size = 0;
	}
	void newItem(T data) 				
	{
		Item<T>* newItem = new Item<T>;				
		newItem->data = data;						
		if (head == nullptr)
		{
			head = newItem;
			tail = newItem;							
		}
		else
		{
			tail->next = newItem;
			tail = newItem;
		}
		size++;										
	}
	void newItem(int number, T data)
	{
		Item<T>* newItem = new Item<T>;
		newItem->data = data;						
		newItem->next = nullptr;

		int i = 0;
		Item<T>* temp = head;						

		while (i < number - 2 && temp != nullptr)
		{
			temp = temp->next;
			i++;
		}
		if (number == 0)						
		{
			newItem->next = temp;
			head = newItem;
		}
		else if (number == 1)					
		{
			Item<T>* next = head->next;
			head->next = newItem;
			newItem->next = next;
		}
		else
		{
			Item<T>* next = temp->next->next;   
			temp->next->next = newItem;
			newItem->next = next;
		}
		size++;
	}
	T getItem(int number) 
	{
		int i = 0;
		Item<T>* temp = head;
		while (i < number && temp != nullptr)
		{
			temp = temp->next;
			i++;
		}
		if (temp != nullptr)
		{
			return temp->data;
		}
	}

	Item<T>* _getItem(int number)
	{
		int i = 0;
		Item<T>* temp = head;
		while (i < number && temp != nullptr)
		{
			temp = temp->next;
			i++;
		}
		if (temp != nullptr)
		{
			return temp;
		}
	}

	void editItem(int number, T data) 
	{
		int i = 0;
		Item<T>* temp = head;
		while (i < number && temp != nullptr)
		{
			temp = temp->next;
			i++;
		}
		if (temp != nullptr)
		{
			temp->data = data;
		}
	}

	void deleteItem(int number) 
	{
		int i = 0;
		Item<T>* temp = head;
		
		while (i < number - 1 && temp != nullptr)
		{
			temp = temp->next;
			i++;
		}

		if (number == 0)			
		{
			temp = head->next;			
			delete head;				
			head = temp;				

		}
		else if (number == size - 1)		
		{
			delete tail;				
			tail = temp;				
		}
		else
		{
			Item<T>* next = temp->next->next;	
			delete temp->next;					
			temp->next = next;					
		}

		size--;
	}

	int getSize() 
	{
		return size;
	}

	void swap(int s, int d) 
	{
		Item<T>* e1 = _getItem(s);
		Item<T>* e2 = _getItem(d);
		T temp = e1->data;
		e1->data = e2->data;
		e2->data = temp;
	}

	void quickSort(int left, int right, bool (*cmp)(T,T)) 
	{
		if (left < right) 
		{
			T pivot = getItem(left);
			int i = left + 1;

			for (int j = left + 1; j <= right; j++) 
			{
				if (!cmp(getItem(j), pivot)) 
				{
					swap(i, j);
					i++;
				}
			}
			int pivotIndex = i - 1;
			swap(left, i - 1);
			quickSort(left, pivotIndex - 1, cmp);
			quickSort(pivotIndex + 1, right, cmp);
		}
	}
};

#endif LISTA_H