#pragma once
class MyList
{
public:

	struct node
	{
		int info;
		node *next;
		node *previous;
	};

	node *last;
	node *first;

	int Size;

	MyList();
	MyList(MyList &copy);
	
	~MyList();

	void push_back(int elem);
	void push_front(int elem);

	void pop_back();
	void pop_front();

	int front();
	int back();
	int size();
	bool isEmpty();
};

