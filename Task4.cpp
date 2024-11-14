#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;
public:

    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added successfully."<<endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display."<<endl;
            return;
        }

        cout << "Tasks:"<<endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            cout << (tasks[i].completed ? "[Completed] " : "[Pending] ");
            cout << tasks[i].description << endl;
        }
    }

    void markAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed."<<endl;
        } else {
            cout << "Invalid task index."<<endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully."<<endl;
        } else {
            cout << "Invalid task index."<<endl;
        }
    }
};

int main() {
    ToDoList todo;

    int choice;
    string description;
    size_t index;
    cout<<" Your Todo List"<<endl;
    while (true) {
        cout << "Edit Tasks: "<<endl;
        cout << "1. Add Task"<<endl;
        cout << "2. View Tasks"<<endl;
        cout << "3. Mark Task as Completed"<<endl;
        cout << "4. Remove Task"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                todo.addTask(description);
                break;
            case 2:
                todo.viewTasks();
                break;
            case 3:
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todo.markAsCompleted(index);
                break;
            case 4:
                cout << "Enter task index to remove: ";
                cin >> index;
                todo.removeTask(index);
                break;
            case 5:
                cout << "Exiting program."<<endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again."<<endl;
        }
    }

    return 0;
}
