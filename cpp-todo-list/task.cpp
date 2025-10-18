#include "task.h"
#include <string>

int Task::next_id = 0;

Task::Task(int id, std::string title, std::string description, std::string dueDate, int progressPercenatge, bool isCompleted, bool isProgressable) : id(0), title(""), description(""), dueDate(""), progressPercentage(0), completed(false), progressable(false)
{
	this->id = id;
	this->title = title;
	this->description = description;
	this->dueDate = dueDate;
	this->progressPercentage = progressPercenatge;
	this->completed = isCompleted;
	this->progressable = isProgressable;
}

Task::Task() : id(0), title(""), description(""), dueDate(""), progressPercentage(0), completed(false), progressable(false) {}

void Task::prompt_for_details()
{
	std::cout << "Enter task title: ";
	std::cin.ignore();
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
		this->progressable = true;
		this->progressPercentage = 0; // Start at 0% for progressable tasks
	}
	else
	{
		this->progressable = false;
		this->completed = false; // Start as not completed for non-progressable tasks
	}

	this->id = next_id;
	next_id++;
}

void Task::mark_as_completed()
{
	this->completed = true;
}

void Task::progress(int progress)
{
	if (progressable)
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
	std::cout << "Task ID: " << id << std::endl;
	std::cout << "Title: " << title << std::endl;
	std::cout << "Description: " << description << std::endl;
	std::cout << "Due Date: " << dueDate << std::endl;
	if (!progressable)
	{
		std::cout << "Completed: " << (completed ? "Yes" : "No") << std::endl;
	}
	else 
	{
		std::cout << "Progress: " << progress_bar() << " " << progressPercentage << "%" << std::endl;
	}
}

const std::string Task::serialize()
{
	return std::to_string(id) + "," + title + "," + description + "," + dueDate + "," + std::to_string(progressPercentage) + "," + (completed ? "1" : "0") + "," + (progressable ? "1" : "0") + "\n";
}

const std::string Task::progress_bar()
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

const int Task::get_id()
{
	return this->id;
}

const bool Task::isCompleted()
{
	return this->completed;
}

const bool Task::isProgressable()
{
	return this->progressable;
}