#include "MyList.h"


MyList::MyList()
{
	first = nullptr;
	last = nullptr;
	Size = 0;
}

MyList::MyList(MyList &copy)
{
	MyList aux = copy;
	while (size() < copy.size())
	{
		push_back(aux.back());
		aux.pop_back();
	}
}

//void MyList::push_front(int elem)  // --------------------- ARREGLAR
//{
//	/*node aux;
//	aux.info = elem;
//	aux.next = MyList::first;
//
//	MyList::first->info = aux.info;
//	MyList::first->next = aux.next;
//	MyList::first->previous = nullptr;
//	
//	size++;*/
//
//	
//
//}

void MyList::push_front(int elem)
{
	node *aux = new node();
	aux->info = elem;
	if (size() == 0) {

		first = aux;
		last = aux;
	}

	else {
		first->previous = aux;
		aux->previous = first;
		first = aux;
	}

	Size++;
}

void MyList::push_back(int elem)   // --------------------- ARREGLAR
{
	/*node aux2;
	aux2.info = elem;
	aux2.next = MyList::last;

	MyList::last->info = aux2.info;
	MyList::last->next = nullptr;
	MyList::last->previous = aux2.previous;
	Size++;*/
}

void MyList::pop_back()
{
	delete last/*->info;
	delete &last->next;
	delete &last->previous*/;
	Size--;
}

void MyList::pop_front()
{
	delete first;
	Size--;
}

int MyList::front()
{
	return first->info;
}

int MyList::back()
{
	return last->info;
}

int MyList::size()
{
	return Size;
}

bool MyList::isEmpty()
{
	return (size() == 0);
}

MyList::~MyList()
{
	while (!MyList::isEmpty())
	{
		pop_front();
	}
}
