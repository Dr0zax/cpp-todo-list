#include <iostream>

class Task
{
private:
	std::string title;
	std::string description;
	std::string dueDate;
	int progressPercentage;
	bool isCompleted = false;
	bool isProgressable;

public:
	Task(std::string title, std::string description, std::string dueDate, int progressPercenatge, bool isCompleted, bool isProgressable);
	Task();

	void prompt_for_details();
	void mark_as_completed();
	void progress(int progress);
	void display();
	void serialize();
	std::string progress_bar();
	std::string get_title();
	std::string get_description();
	std::string get_due_date();
};
