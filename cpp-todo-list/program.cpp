// cpp-todo-list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
#include <fstream>
#include "task.h"
#include <string>
#include <sstream>

static void display_menu()
{
	std::cout << "1. Add Task" << std::endl;
	std::cout << "2. View Tasks" << std::endl;
	std::cout << "3. Update Task" << std::endl;
	std::cout << "4. Delete Task" << std::endl;
	std::cout << "5. Save Tasks" << std::endl;
	std::cout << "6. Load Tasks" << std::endl;
	std::cout << "7. Exit" << std::endl;
}

static int get_user_choice()
{
	int choice = 0;
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	return choice;
}

static std::list<Task>::iterator find_task_by_id(std::list<Task>& tasks, int id)
{
	std::list<Task>::iterator it;
	for (it = tasks.begin(); it != tasks.end(); ++it)
	{
		if (it->get_id() == id)
		{
			return it;
		}
	}
	return tasks.end();
}

static Task create_task_from_serialized(const std::string& serialized)
{
	std::istringstream ss(serialized);
	std::string token;
	std::getline(ss, token, ',');
	int id = std::stoi(token);
	std::getline(ss, token, ',');
	std::string title = token;
	std::getline(ss, token, ',');
	std::string description = token;
	std::getline(ss, token, ',');
	std::string dueDate = token;
	std::getline(ss, token, ',');
	int progressPercentage = std::stoi(token);
	std::getline(ss, token, ',');
	bool isCompleted = (token == "1");
	std::getline(ss, token, ',');
	bool isProgressable = (token == "1");
	return Task(id, title, description, dueDate, progressPercentage, isCompleted, isProgressable);
}

int main()
{	
	std::list<Task> tasks;

	bool running = true;
	while (running)
	{
		display_menu();
		int choice = get_user_choice();
		std::cout << std::endl;
		switch (choice)
		{
		case 1: // Create new Task
		{
			Task newTask = Task();
			newTask.prompt_for_details();
			tasks.push_back(newTask);
			break;
		}
		case 2: // View Tasks
		{
			std::list<Task> ::iterator it;
			for (it = tasks.begin(); it != tasks.end(); ++it)
			{
				it->display();
				std::cout << "------------------------" << std::endl;
			}
			break;
		}
		case 3: // Update Task
			{
				int taskId;
				std::cout << "Enter Task ID to update: ";
				std::cin >> taskId;
				std::list<Task>::iterator it = find_task_by_id(tasks, taskId);

				if (it != tasks.end())
				{
					if (it->isProgressable() == true)
					{
						int progressAmount;
						std::cout << "Enter amount to progress by: ";
						std::cin >> progressAmount;
						it->progress(progressAmount);
					}
					else 
					{
						it->mark_as_completed();
					}
				}
			break;
			}
		case 4: // Delete Task
		{
			int taskId;
			std::cout << "Enter Task ID to delete: ";
			std::cin >> taskId;
			
			auto end = std::remove_if(tasks.begin(), tasks.end(), [taskId](Task& t) { return t.get_id() == taskId; });
			tasks.erase(end, tasks.end());
		}
		case 5: // Save Tasks
		{
			std::string path;
			std::cout << "Enter file path to save tasks (default: tasks.csv): ";
			std::cin >> path;
			std::ofstream outFile;
			outFile.open(path);
			std::for_each(tasks.begin(), tasks.end(), [&outFile](Task& t) { outFile << t.serialize(); });
			outFile.close();
			break;
		}
		case 6: // Load Tasks
		{
			std::string path;
			std::cout << "Enter file path to load tasks from: ";
			std::cin >> path;

			std::ifstream inFile;
			inFile.open(path);
			std::string line;
			while (std::getline(inFile, line))
			{
				Task t = create_task_from_serialized(line);
				tasks.push_back(t);
			}
			break;
		}
		case 7: // Exit
			std::cout << "Exiting..." << std::endl;
			running = false;
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
			break;
		}
		std::cout << std::endl;
	}
}

