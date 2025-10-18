// cpp-todo-list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include "task.h"

void display_menu()
{
	std::cout << "1. Add Task" << std::endl;
	std::cout << "2. View Tasks" << std::endl;
	std::cout << "3. Update Task" << std::endl;
	std::cout << "4. Delete Task" << std::endl;
	std::cout << "5. Exit" << std::endl;
}

int get_user_choice()
{
	int choice;
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	return choice;
}

int main()
{	
	std::list<Task> tasks;

	display_menu();

	bool running = true;
	while (running)
	{
		switch (get_user_choice())
		{
		case 1:
		{
			Task newTask = Task();
			newTask.prompt_for_details();
			tasks.push_back(newTask);
			break;
		}
		case 2:
		{
			std::list<Task> ::iterator it;
			for (it = tasks.begin(); it != tasks.end(); ++it)
			{
				it->display();
				std::cout << "------------------------" << std::endl;
			}
			break;
		}
		case 3:
			break;
		case 4:
			break;
		case 5:
			std::cout << "Exiting..." << std::endl;
			running = false;
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			break;
		}
	}
}

