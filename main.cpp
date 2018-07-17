#include <iostream>
#include "queue.h"


int main()
{

	Queue<int> q;

	for (int i = 0; i < 10; i++)
		q.push(rand() % 100);


	while (!q.empty())
	{
		std::cout << q.front() << std::endl;
		q.pop();
	}


	return 0;
}