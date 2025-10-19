# cpp-todo-list

A small, single-user command-line to-do list application written in C++. It provides basic task management operations: add, view, update (progress or mark complete), delete, save to CSV, and load from CSV.

## Features

- Add tasks with title, description and due date
- View tasks with a progress bar and status
- Update tasks by progressing them or marking them completed
- Delete tasks by ID
- Save and load tasks from CSV files

## Files

- `cpp-todo-list/program.cpp` — main program and menu-driven UI
- `cpp-todo-list/task.h` — `Task` class declaration
- `cpp-todo-list/task.cpp` — `Task` class implementation (task logic, serialization)

## Build & Run

These instructions assume you're on Windows. Two common ways to build:

1) Visual Studio (recommended)

- Open `cpp-todo-list.sln` in Visual Studio (2017/2019/2022).
- Build the solution (Build > Build Solution).
- Run the resulting executable from Visual Studio or find it in the project's Debug/Release folder.

2) g++ (MinGW / MSYS / WSL)

If you have a working g++ on Windows, you can compile from the command line. Open PowerShell and run (from the repository root):

```powershell
g++ -std=c++17 -I cpp-todo-list -o todo.exe cpp-todo-list\program.cpp cpp-todo-list\task.cpp
```

Then run:

```powershell
.\todo.exe
```

If you're on WSL or Linux/macOS, adjust the backslashes to forward slashes and the executable name (e.g., `./todo`).

## Usage

When you run the program you'll see a numbered menu:

1. Add Task — prompts for task details (title, description, due date)
2. View Tasks — lists tasks with IDs, progress, and details
3. Update Task — enter a task ID to progress it (if progressable) or mark it complete
4. Delete Task — remove a task by ID
5. Save Tasks — save the current list to a CSV file (default suggested: `tasks.csv`)
6. Load Tasks — load tasks from a CSV file
7. Exit — quit the program

When saving/loading the program uses a simple CSV serialization. Each line represents a task and is parsed when loading.

## Data format (CSV)

Each task is serialized on a single line with comma-separated fields. The project code contains a serializer and parser in `task.cpp` / `program.cpp` to read/write this format.

## Assumptions & Notes

- This is a small demo app; it does not provide concurrency, authentication, or multi-user storage.
- Input validation is basic — be careful when entering file paths and numeric choices.
- The CSV format is simplistic and does not escape commas inside text fields.

## Contributing

Contributions are welcome. For small improvements, open a pull request.

## License

This project is provided as-is under the MIT License. See `LICENSE` if present or add one when you choose a license.

## Contact

If you have questions about this example, open an issue on the repository.

### Sources Used

https://www.w3schools.com/cpp/cpp_iterators.asp
