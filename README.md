# task-manager-app

# description
A simple command-line application designed for a user to input, view, edit, and delete tasks. This application automatically loads tasks from a file upon startup. It was built as a personal project to practice and develop core programming concepts like data structures, file handling, and modular design.

# features
• Add New Tasks
• View Task List
• Mark Tasks as Complete
• Edit Task Desciptions
• Delete a Single Task
• Clear Task List
• Save Task List to File (tasks.txt)
• Load Tasks from File Upon Startup

# technologies used
• C++
• Standard Template Library
• File I/O

# how to run
• Clone the Repository:
  - git clone https://github.com/kelseyzoeydurden/task-manager-app.git
• Navigate to the Project Folder:
  - cd task-manager-app
• Compile the Program:
  - g++ taskmanagerapp.cpp -o taskmanagerapp
• Run the Program:
  - ./taskmanagerapp.exe

# how this works
• Each task contains a description and completion status
• Tasks are stored in a vector of structs
• Tasks are optionally stored in tasks.txt file so they exist between runs.

# example output
[x] type README.md
[] upload source code

# what i learned here
• how to use vectors and structs
• input/output in c++
• writing and calling functions
• basic principles of software design

# future improvement tasks
• add priority levels for each task
• make this more user-friendly

# author
• Kelsey Zoey Durden
• github.com/kelseyzoeydurden
