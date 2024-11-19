/*
                                                      Assignment No.10



Problem Statement:

Implement a job scheduling system for a manufacturing plant using a double-ended queue. The 
system needs to efficiently manage the processing of jobs on various machines throughout the 
plant. Each job has a Job_priority.  
The system should support the following operations: 
a. Add Job  
b. Remove Job 
c. Display Job 
d. Search Job 


Name: Shyam Sundar yadav
PRN:123B1B267
Batch: D3
Course: Data Structure Laboratry


*/

#include <iostream>
using namespace std;

class Job {
    string jobname;
    string jobtype;
    int priority, times;

public:
    Job *next, *prev;

    Job() {
        next = prev = NULL;
    }

    void read() {
        cout << "Enter the job name: ";
        cin.ignore();
        getline(cin, jobname);
        cout << "Enter the job type: ";
        getline(cin, jobtype);
        cout << "Enter the priority and time: ";
        cin >> priority >> times;
    }

    string getJobname() {
        return jobname;
    }

    int getPriority() {
        return priority;
    }

    void display() {
        cout << "Job name: " << jobname << endl;
        cout << "Job type: " << jobtype << endl;
        cout << "Priority: " << priority << endl;
        cout << "Times: " << times << endl;
    }
};

class Dequeue {
    Job *rear, *front;

public:
    Dequeue() {
        rear = front = NULL;
    }

    ~Dequeue() {
        while (front != NULL) {
            remove_Job_Front();
        }
    }

    // Add Job based on priority
    void add_Job_Priority() {
        Job *nn = new Job;
        nn->read();

        if (front == NULL) { // Empty deque
            front = rear = nn;
        } else if (nn->getPriority() < front->getPriority()) { // Higher priority (lower number)
            nn->next = front;
            front->prev = nn;
            front = nn;
        } else {
            Job *temp = front;
            while (temp->next != NULL && temp->next->getPriority() <= nn->getPriority()) {
                temp = temp->next;
            }

            nn->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = nn;
            } else {
                rear = nn; // If adding to the back
            }
            temp->next = nn;
            nn->prev = temp;
        }
        cout << "Job added based on priority.\n";
    }

    void remove_Job_Front() {
        if (front == NULL) {
            cout << "No jobs to remove from front.\n";
            return;
        }
        Job *temp = front;
        front = front->next;
        if (front != NULL) {
            front->prev = NULL;
        } else {
            rear = NULL;  // If the deque becomes empty
        }
        delete temp;  // Free memory of the removed job
        cout << "Removed job from front.\n";
    }

    void remove_Job_Back() {
        if (rear == NULL) {
            cout << "No jobs to remove from back.\n";
            return;
        }
        Job *temp = rear;
        rear = rear->prev;
        if (rear != NULL) {
            rear->next = NULL;
        } else {
            front = NULL;  // If the deque becomes empty
        }
        delete temp;  // Free memory of the removed job
        cout << "Removed job from back.\n";
    }

    void displayJob() {
        Job *temp = front;  // Start from the front
        if (temp == NULL) {
            cout << "No jobs in the queue.\n";
            return;
        }
        cout << "Jobs in the queue:\n";
            temp->display();
            temp = temp->next;
    }

    void searchJob(string Jname) {
        Job *temp = front;
        while (temp != NULL) {
            if (temp->getJobname() == Jname) {
                cout << "Job is found:\n";
                temp->display();
                return;
            }
            temp = temp->next;
        }
        cout << "Job with name '" << Jname << "' not found.\n";
    }
};

int main() {
    Dequeue D;
    int choice;
    while (true) {
        cout << "1. Add Job Based on Priority\n"
             << "2. Remove Job from Front\n"
             << "3. Remove Job from Back\n"
             << "4. Display Job\n"
             << "5. Search Job\n"
             << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                D.add_Job_Priority();
                break;
            case 2:
                D.remove_Job_Front();
                break;
            case 3:
                D.remove_Job_Back();
                break;
            case 4:
                D.displayJob();
                break;
            case 5: {
                string s;
                cout << "Enter the job name to search: ";
                cin.ignore();
                getline(cin, s);
                D.searchJob(s);
                break;
            }
            case 6:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid Choice! Try Again.\n";
        }
    }
    return 0;
}


