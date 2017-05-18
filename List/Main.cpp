#include <iostream>
#include <list>

std::list<int> superMerge (std::list<int> l1, std::list<int> l2)
{
	std::list<int> l3;
	
	l1.sort();
	l2.sort();

	l1.merge(l2);
	
	l1.sort();
	
	while (l1.size() != 0)
	{
		l3.push_back(l1.back());
		l1.pop_back();
	}

	return l3;
}

void change(std::list <int> &l1)
{
	int pLast = l1.back();   // Previous Last
	int pFirst = l1.front(); // Previous First

	l1.pop_back();
	l1.push_back(pFirst);

	l1.pop_front();
	l1.push_front(pLast);
}

int getElementPos(std::list<int> l1, int pos)
{
	for (int i = 0; i < pos - 1; i++)
	{
		l1.pop_front();
	}
	return l1.front();
}

void removeDuplicates(std::list<int>&l3)  // ------------------- TO DO
{
	l3.sort();
	l3.unique();
}

void removeElement(std::list<int>&l3, int elem)
{
	l3.remove(elem);
}

bool palindrome(std::list <int> l1)
{
	while (l1.size() > 1)
	{
		if (l1.front() != l1.back())
		{
			return false;
		}
		l1.pop_back();
		l1.pop_front();
	}
	return true;
}

int main()
{
	std::list <int> l1{ 6, 7, 3, 5 };
	std::list <int> l2{10, 8, 5, 3 };
	std::list <int> l3;

	/*int num;

	l3 = superMerge(l1, l2);

	change(l3);

	num = getElementPos(l3, 3);
	
	removeDuplicates(l3);

	removeElement(l1, 3);

	while (l3.size() != 0)
	{
		std::cout << l3.front() << std::endl;
		l3.pop_front();
	}

	std::cout << std::endl << num;*/

	if (palindrome(l1))
	{
		std::cout << "true";
	}

	else
	{
		std::cout << "false";
	}

	return 0;
}