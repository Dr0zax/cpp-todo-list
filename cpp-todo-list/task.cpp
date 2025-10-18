#include "task.h"
#include <string>

Task::Task(std::string title, std::string description, std::string dueDate, int progressPercenatge, bool isCompleted, bool isProgressable)
{
	this->title = title;
	this->description = description;
	this->dueDate = dueDate;
	this->progressPercentage = progressPercenatge;
	this->isCompleted = isCompleted;
	this->isProgressable = isProgressable; // Default value, can be modified later
}

Task::Task() {}

void Task::prompt_for_details()
{
	std::cout << "Enter task title: ";
	std::cin.ignore(); // Clear the input buffer
	std::getline(std::cin, this->title);
	std::cout << "Enter task description: ";
	std::getline(std::cin, this->description);
	std::cout << "Enter due date (YYYY-MM-DD): ";
	std::getline(std::cin, this->dueDate);
	char progressableChoice;
	std::cout << "Is this a progressable task? (y/n): ";
	std::cin >> progressableChoice;
	if (progressableChoice == 'y' || progressableChoice == 'Y')
	{
		this->isProgressable = true;
		this->progressPercentage = 0; // Start at 0% for progressable tasks
	}
	else
	{
		this->isProgressable = false;
		this->isCompleted = false; // Start as not completed for non-progressable tasks
	}
}

void Task::mark_as_completed()
{
	this->isCompleted = true;
}

void Task::progress(int progress)
{
	if (isProgressable)
	{
		if (this->progressPercentage + progress >= 100)
		{
			this->progressPercentage = 100;
			mark_as_completed();
		}
		else
		{
			this->progressPercentage += progress;
		}
	}
}

void Task::display()
{
	std::cout << "Title: " << title << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "Due Date: " << dueDate << std::endl;
	if (!isProgressable)
	{
		std::cout << "Completed: " << (isCompleted ? "Yes" : "No") << std::endl;
	}
	else 
	{
		std::cout << "Progress: " << progress_bar() << " " << progressPercentage << "%" << std::endl;
	}
}

std::string Task::get_title()
{
	return this->title;
}

std::string Task::get_description()
{
	return this->description;
}

std::string Task::get_due_date()
{
	return this->dueDate;
}

void Task::serialize()
{
}

std::string Task::progress_bar()
{
	std::string bar = "[";
	int totalBars = 10;
	int filledBars = (progressPercentage / 10);
	for (int i = 0; i < totalBars; i++)
	{
		if (i < filledBars)
		{
			bar += "#";
		}
		else
		{
			bar += "-";
		}
	}
	bar += "]";
	return bar;
}
