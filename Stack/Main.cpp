#include <stack>
#include <queue>
#include <iostream>

void superMerge(std::stack<int> s1, std::stack<int> s2, std::stack<int> &result) // DONE
{
	std::stack<int> c1;
	std::stack<int> c2;

	int last;

	while (!s1.empty())
	{
		c1.push(s1.top());
		s1.pop();
	}
	while (!s2.empty())
	{
		c2.push(s2.top());
		s2.pop();
	}

	while (!c1.empty() && !c2.empty())
	{
		if (c1.top() >= c2.top()) 
		{
			result.push(c1.top());
			c1.pop();
			last = 1;
		}
		else
		{
			result.push(c2.top());
			c2.pop();
			last = 2;
		}

	}
	if (last == 1) {
		result.push(c2.top());
	}
	else
	{
		result.push(c1.top());
	}
}

void putHat(std::stack<int> s1, std::stack<int> s2, std::stack<int> &result) // DONE
{
	std::stack<int>aux;
	while (!s2.empty())
	{
		aux.push(s2.top());
		s2.pop();
	}
	while (!aux.empty())
	{
		result.push(aux.top());
		aux.pop();
	}
	while (!s1.empty())
	{
		aux.push(s1.top());
		s1.pop();
	}
	while (!aux.empty())
	{
		result.push(aux.top());
		aux.pop();
	}
}

std::queue<int> transformToQ(std::stack<int> s1) // DONE
{
	std::queue<int> result;
	while(!s1.empty())
	{
		result.push(s1.top());
		s1.pop();
	}
	return result;
}

bool isHat(std::stack<int> s1, std::stack<int> s2) // DONE
{
	int difSize = s2.size() - s1.size();
	int i = 0;

	while (i < difSize)
	{
		s2.pop();
		i++;
	}
	
	while (!s1.empty())
	{
		if (s1.top() != s2.top())
		{
			return false;
		}
		s1.pop();
		s2.pop();
	}
	return true;

}

bool balancedP(std::stack<char>s1)// DONE
{
	int cont = 0;
	while (!s1.empty())
	{
		if (s1.top() == '(')
		{
			cont++;
		}
		else
		{
			cont--;
		}
		s1.pop();
	}
	return (cont == 0);
}

std::stack<int> change(std::stack<int> s1) // DONE
{
	std::stack<int> result;
	std::stack<int> aux (s1);
	//
	int s1Top;
	int s1Bot;
	
	s1Top = s1.top();
	while (!s1.empty())
	{
		s1Bot = s1.top();
		s1.pop();
	}

	aux.pop();
	aux.push(s1Bot);
	while (!aux.empty())
	{
		result.push(aux.top());
		aux.pop();
	}
	result.pop();
	result.push(s1Top);
	return result;
}

void main()
{
	std::stack<int> s1({7, 5, 3, 1});
	std::stack<int> s2({8, 6, 4, 2});

	std::stack<int> result;

	std::stack<char> c1({ '(', ')', ')', ')' });

	std::queue<int> resultQ;

	/*for (int i = 0; i < 10; i+=2)
	{
		s1.push(i + 2);
		s2.push(i + 1);
	}*/

	superMerge(s2, s1, result);
	//putHat(s1, s2, result);
	//resultQ = transformToQ(s1);

	//s2 = change(s2);

	while (!result.empty())
	{
		std::cout << result.top() << std::endl;
		result.pop();
	}

	/*if (balancedP(c1))
	{
		std::cout << "Balanced";
	}
	else
	{
		std::cout << "Not balanced";
	}*/
}