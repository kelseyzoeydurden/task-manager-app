#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

// Adding a Struct for program cleanliness
struct Task {
    string description;
    bool completed;
};

// viewTasks Function
void viewTasks(vector<Task>& tasks) {
    cout << "\nTasks: \n";

    if (tasks.empty()) {
        cout << "There are no tasks in this list. \n";
    }

    else {
        for (size_t i = 0; i < tasks.size(); i++) {
            if (tasks[i].completed) {
                cout << i + 1 << ".) [✓] " << tasks[i].description << "\n";
            }
            else {
                cout << i + 1 << ".) [ ] " << tasks[i].description << "\n";
            }
        }
    }
    cin.ignore(1000, '\n');
    cout << "\nPress Enter to continue.";
    cin.get();
}

// addTask Function
void addTask(vector<Task>& tasks) {
    cin.ignore();
    Task newtask;

    cout << "\nEnter a new task: ";
    getline(cin, newtask.description);

    newtask.completed = false;

    tasks.push_back(newtask);

    cout << "\nA new task has been added. \n";
}

// completeTask Function
void completeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nThere are no tasks to mark as complete. \n";
        return;
    }

    viewTasks(tasks);

    int index;
    cout << "\nEnter the number that corresponds with the task you'd like to mark as complete: ";
    if (!(cin >> index) || index < 1 || index > tasks.size()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid task number. \n";
        return;
    }
    else {
        tasks[index - 1].completed = true;
        cout << "\nTask " << index << " has been marked as complete. \n";
    }

    viewTasks(tasks);
}

//deleteTask function
void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nThere are no tasks to delete. \n";
        cin.ignore(1000, '\n');
        return;
    }

    viewTasks(tasks);

    int index;
    cout << "\nEnter the number that corresponds with the task you'd like to delete: ";
    if (!(cin >> index) || index < 1 || index > tasks.size()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid task number. \n";
        return;
    }
    else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "\nTask " << index << " has been deleted. \n";
    }

    viewTasks(tasks);
}

//editTasks function
void editTasks(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nThere are no tasks to edit. \n";
        return;
    }

   viewTasks(tasks);

    int index = 0;
    cout << "\nEnter the number that corresponds with the task you'd like to edit: ";
    if (!(cin >> index) || index < 1 || index > tasks.size()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid task number. \n";
        return;
    }

    else {
        cin.ignore();
        string newDescription;
        cout << "\nEnter the new description for this task: ";
        getline(cin, newDescription);
        tasks[index - 1].description = newDescription;
        cout << "\nTask " << index << " has been updated. \n";
    }

     viewTasks(tasks);
}

// saveTasks Function
void saveTasks(const vector<Task>& tasks) {
    ofstream outFile("tasks.txt");

    if (outFile.is_open()) {
        for (const Task& task : tasks) {
            outFile << (task.completed ? "[✓] " : "[ ] ") << task.description << "\n";
        }
        outFile.close();
        cout << "\nTasks have been saved to tasks.txt \n";
    }
    else {
        cout << "\nUnable to open file for writing. \n";
            cin.ignore(1000, '\n');
            cout << "\nPress Enter to continue.";
            cin.get();
    }
}

//loadTasks Function
void loadTasks(vector<Task>& tasks) {
    ifstream inFile("tasks.txt");
    tasks.clear();
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {

            Task task;

            if (line.size() >= 4 && line.substr(0, 4) == "[✓] ") {
                task.completed = true;
                task.description = line.substr(4);
            }
            else if (line.size() >= 4 && line.substr(0, 4) == "[ ] ") {
                task.completed = false;
                task.description = line.substr(4);
            }
            else {
                continue;
            }
            tasks.push_back(task);
        }
        inFile.close();
        cout << "\nTasks have been loaded from tasks.txt \n";
    }
    else {
        cout << "\nUnable to open file for reading. \n";
    }
}

//clearTasks Function
void clearTasks(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nThere are no tasks to clear. \n";
        cin.ignore(1000, '\n');
        cout << "\nPress Enter to continue.";
        cin.get();
        return;
    }

    string confirmation;
    cout << "\nAre you sure you want to clear all tasks? (Yes/No): ";
    cin >> confirmation;

    if (confirmation == "Yes" || confirmation == "Y" || confirmation == "y") {
        tasks.clear();
        cout << "\nAll tasks have been cleared. \n";
        cin.ignore(1000, '\n');
        cout << "\nPress Enter to continue.";
        cin.get();
    }
    else {
        cout << "\nClear operation cancelled. \n";
        cin.ignore(1000, '\n');
        cout << "\nPress Enter to continue.";
        cin.get();
    }
}

int main() {
    // Creating the Vector to Store Tasks
    vector<Task> tasks;
    int choice;
    loadTasks(tasks);
    // Creating the Menu Loop
    while (true) {
        cout << "\nTask Manager \n";
        cout << "1.) View Tasks \n";
        cout << "2.) Add a Task \n";
        cout << "3.) Mark a Task as Completed \n";
        cout << "4.) Delete a Task \n";
        cout << "5.) Edit a Task \n";
        cout << "6.) Save Tasks to a File \n";
        cout << "7.) Clear All Tasks \n";
        cout << "8.) Exit the Program \n";
        cout << "Please enter your choice: ";
       // Avoid User Input Error
       if (!(cin >> choice) || choice < 1 || choice > 9) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input.\n";
        continue;
        }
    
    // Choice One: View Tasks
    if (choice == 1) {
        viewTasks(tasks);
    }

    // Choice Two: Add a Task
    else if (choice == 2) {
        addTask(tasks);
    }

    // Choice Three: Mark a Task as Completed
    else if (choice == 3) {
        completeTask(tasks);
    }

    // Choice Four: Delete a Task
    else if (choice == 4) {
        deleteTask(tasks);
    }

    //Choice Five: Edit a Task
    else if (choice == 5) {
        editTasks(tasks);
    }

    //Choice Six: Save Tasks to a File
    else if(choice == 6) {
         saveTasks(tasks);
    }

    //Choice Seven: Clear All Tasks
    else if (choice == 7) {
        clearTasks(tasks);
    }

    //Choice Eight: Exit the Program
    else if (choice == 8) {
            cout << "\nExiting the program. Goodbye! \n";
            break;
        }
        
    }    
}    
