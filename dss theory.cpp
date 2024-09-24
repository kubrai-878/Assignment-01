#include <iostream>
#include <string>
using namespace std;

struct Task {
    int taskId;           
    string description;   
    int priority;          
    Task* next;           
};

struct TaskList {
    Task* head;  

    TaskList() {
        head = NULL;  
    }

    void addTask(int id, string description, int priority) {
        Task* newTask = new Task;  
        newTask->taskId = id;      
        newTask->description = description;  
        newTask->priority = priority; 
        newTask->next = NULL;  


        if (head == NULL || newTask->priority > head->priority) {
            newTask->next = head;  
            head = newTask;        
        } else {
            Task* current = head;
            while (current->next != NULL && current->next->priority > newTask->priority) {
                current = current->next;
            }
            newTask->next = current->next;  
            current->next = newTask;       
        }
    }

    void removeHighestPriorityTask() {
        if (head != NULL) {
            Task* temp = head;  
            head = head->next;  
            delete temp;        
            cout << "Highest priority task removed." << endl;
        } else {
            cout << "No tasks to remove." << endl;  
        }
    }

    void removeTaskById(int id) {
        if (head == NULL) { 
            cout << "Task list is empty." << endl;
            return;
        }
        if (head->taskId == id) { 
            Task* temp = head;   
            head = head->next;     
            delete temp;          
            cout << "Task with ID " << id << " removed." << endl;
            return;
        }

        
        Task* current = head;
        while (current->next != NULL) {
            if (current->next->taskId == id) {
                Task* temp = current->next; 
                current->next = temp->next;  
                delete temp;                 
                cout << "Task with ID " << id << " removed." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Task with ID " << id << " not found." << endl;
    }

    void viewAllTasks() const {
        if (head == NULL) {  
            cout << "No tasks in the list." << endl;
            return;
        }

        Task* current = head;
        while (current != NULL) {
            cout << "Task ID: " << current->taskId << endl;
            cout << "Description: " << current->description << endl;
            cout << "Priority: " << current->priority << endl;
            cout << endl;
            current = current->next;  
        }
    }
};

int main() {
    TaskList taskList; 
    int choice;         

    
    while (true) {
        cout << "1. Add a new task" << endl;
        cout << "2. View all tasks" << endl;
        cout << "3. Remove the highest priority task" << endl;
        cout << "4. Remove a task by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;  
        switch (choice) {
            case 1: {
                int id, priority;
                string description;
                cout << "Enter task ID: ";
                cin >> id;              
                cin.ignore();           
                cout << "Enter task description: ";
                getline(cin, description);  
                cout << "Enter priority level: ";
                cin >> priority;        
                taskList.addTask(id, description, priority); 
                break;
            }
            case 2:
                taskList.viewAllTasks(); 
                break;
            case 3:
                taskList.removeHighestPriorityTask(); 
                break;
            case 4: {
                int id;
                cout << "Enter task ID to remove: ";
                cin >> id;  
                taskList.removeTaskById(id);  
                break;
            }
            case 5:
                return 0; 
            default:
                cout << "Invalid choice. Please try again." << endl;  }
                
    }
    return 0;
}

