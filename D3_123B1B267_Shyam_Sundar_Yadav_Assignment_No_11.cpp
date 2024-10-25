/*
                                             Assignment No 11

Problem Statement
Consider an employee database of N employees. Make use of a hash table implementation to 
quickly look up the employer's id number.

Name: Shyam Sundar Yadav
PRN: 123B1B267
Batch: D3
Course: Data Structures Laboratory


*/

#include <iostream>
using namespace std;

#define size 10  // Define the size of the hash table

// Employee class that contains details about an employee
class employee {
    int empID;         // Employee ID
    string name;       // Employee name
    long long ph_no;   // Employee phone number

public:
    // Function to read employee details from the user
    void read() {
        cout << "Enter the empID: ";
        cin >> empID;
        cout << "Enter the name: ";
        cin.ignore();  // Ignore newline character left in the buffer
        getline(cin, name);  // Read the name, including spaces
        cout << "Enter the phone_no: ";
        cin >> ph_no;
    }

    // Function to display employee details
    void display() {
        cout << empID << "        " << name << "       " << ph_no << endl;
    }

    // Getter function to retrieve employee ID
    int getempID() {
        return empID;
    }
};

// Class representing the hash table of employees
class HTEmployee {
    employee HT[size];  // Array to store employees
    int flag[size];     // Array to track filled (1) or empty (0) slots

public:
    // Constructor to initialize the hash table flags to 0 (empty)
    HTEmployee() {
        for (int i = 0; i < size; i++) {
            flag[i] = 0;
        }
    }

    // Function to insert a new employee into the hash table
    void insertHT() {
        employee newR;
        newR.read();  // Read employee details
        int ID = newR.getempID();  // Get employee ID
        int hashV = ID % size;     // Compute hash value (index)
        
        // If the computed index is empty, insert the employee there
        if (flag[hashV] == 0) {
            HT[hashV] = newR;
            flag[hashV] = 1;  // Mark the slot as filled
        } else {
            // Linear probing: find the next available slot
            for (int i = 1; i < size; i++) {
                int pos = (hashV + i) % size;
                if (flag[pos] == 0) {
                    HT[pos] = newR;
                    flag[pos] = 1;  // Mark the slot as filled
                    break;
                }
            }
        }
    }

    // Function to display all employees in the hash table
    void display() {
        cout << "Displaying Employees:" << endl;
        cout << "Emp ID" << "     Name" << "     Phone number  " << endl;
        for (int i = 0; i < size; i++) {
            // If the slot is filled, display the employee details
            if (flag[i] == 1) {
                HT[i].display();
            }
            else {
                // Display empty slot placeholders
                cout << " ---   " << "   ---" << "   ---" << endl;
            }
        }
    }

    // Function to delete an employee by their ID
    void deleteHT(int ID) {
        employee delR;   // Temporary variable to hold deleted employee
        int hashV = ID % size;   // Compute hash value (index)

        // Search through the hash table using linear probing
        for (int i = 0; i < size; i++) {
            int pos = (hashV + i) % size;
            
            // If the employee is found at the current position
            if (flag[pos] == 1 && HT[pos].getempID() == ID) {
                delR = HT[pos];   // Copy the employee to delR
                flag[pos] = 0;    // Mark the slot as empty
                cout << "Value is deleted: " << endl;
                delR.display();   // Display the deleted employee's details
                break;
            }
            else {
                // If the ID doesn't match at the current position
                cout << "ID not match" << endl;
                break;
            }
        }
    }

    // Function to search for an employee by their ID
    void search(int ID) {
        employee sR;   // Temporary variable to hold found employee
        int hashV = ID % size;   // Compute hash value (index)

        // Search through the hash table using linear probing
        for (int i = 0; i < size; i++) {
            int pos = (hashV + i) % size;

            // If the employee is found at the current position
            if (flag[pos] == 1 && HT[pos].getempID() == ID) {
                sR = HT[pos];   // Copy the employee to sR
                cout << "Value is Found:" << endl;
                sR.display();   // Display the found employee's details
                return;
            }
        }
        // If the employee was not found in the hash table
        cout << "Employee not found." << endl;
    }
};

// Main function to interact with the hash table
int main() {
    HTEmployee E;    // Create an object of the HTEmployee class
    int choice, empID;

    // Menu-driven loop for inserting, displaying, deleting, and searching employees
    do {
        cout << "1. Insert Employee" << endl;
        cout << "2. Display Employees" << endl;
        cout << "3. Delete Employee" << endl;
        cout << "4. Search Employee" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                E.insertHT();   // Insert a new employee
                break;
            case 2:
                E.display();    // Display all employees
                break;
            case 3:
                cout << "Enter empID to delete: ";
                cin >> empID;
                E.deleteHT(empID);  // Delete an employee by ID
                break;
            case 4:
                cout << "Enter empID to search: ";
                cin >> empID;
                E.search(empID);    // Search for an employee by ID
                break;
            case 5:
                cout << "Exiting..." << endl;   // Exit the program
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;   // Handle invalid input
        }
    } while (choice != 5);  // Repeat until the user chooses to exit

    return 0;
}
