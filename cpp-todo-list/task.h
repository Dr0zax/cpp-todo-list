#include <iostream>

class Task
{
private:
	static int next_id;
	int id;
	std::string title;
	std::string description;
	std::string dueDate;
	int progressPercentage;
	bool completed = false;
	bool progressable = false;

public:
	Task(int id, std::string title, std::string description, std::string dueDate, int progressPercenatge, bool isCompleted, bool isProgressable);
	Task();

	void prompt_for_details();
	void mark_as_completed();
	void progress(int progress);
	void display();
	const std::string serialize();
	const std::string progress_bar();
	std::string get_title();
	std::string get_description();
	std::string get_due_date();
	const int get_id();
	const bool isProgressable();
	const bool isCompleted();
};
