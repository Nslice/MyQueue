#include <iostream>
#include "queue.h"
#include "workermi.h"

const int SIZE = 5;

int main()
{
	Worker* lolas[SIZE];
	Queue<Worker*> qu;
	Worker* tmpWk;

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: waiter  s: singer  "
			<< "t: singing waiter  q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == nullptr)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;

		switch (choice)
		{
		case 'w':
			qu.push(new Waiter);
			break;
		case 's':
			qu.push(new Singer);
			break;
		case 't':
			qu.push(new SingingWaiter);
			break;
		}
		cin.get();
		qu.back()->Set();
	}

	cout << "\nHere is your staff:\n";
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		qu.front()->Show();
		delete qu.front();
		qu.pop();
	}
	
	cout << "Bye.\n";
	return 0;
}

