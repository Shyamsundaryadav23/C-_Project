/*
                                                      Assignment No.9.A
Problem Statement

a. Implement a restaurant waitlist system using the queue data structure. Restaurant waitlist 
provide following facility: 
a. Add Party to Waitlist 
b. Seat Party 
c. Display Waitlist 


Name: Shyam Sundar Yadav
PRN: 123B1B267
Batch: D3
Course: Data Structures Laboratory

*/
#include <iostream>
#include <string>

using namespace std;

#define size 10 // Maximum size of the waitlist

// Class representing a customer
class customer {
    string name;        // Customer's name
    long long phone_no; // Customer's phone number

public:
    // Method to read customer details
    void read() {
        cout << "Enter Customer name: ";
        cin.ignore(); // Ignore any leftover newline in input buffer
        getline(cin, name); // Read full name with spaces
        cout << "Enter phone number: ";
        cin >> phone_no; // Read phone number as a long long
    }

    // Method to display customer details
    void display() {
        cout << "Customer Name: " << name << endl;
        cout << "Phone Number: " << phone_no << endl;
    }
};

// Class representing the restaurant waitlist
class restaurant {
    customer Q[size]; // Array to hold the waitlist of customers
    int rear, front;  // Pointers for the rear and front of the queue

public:
    // Constructor to initialize the waitlist
    restaurant() {
        rear = front = -1; // Initialize pointers to indicate an empty queue
    }

    // Method to add a customer to the waitlist
    void addTowaitlist() {
        if (rear == size - 1) { // Check if the waitlist is full
            cout << "Restaurant is full!!" << endl;
        } else {
            rear = rear + 1; // Increment the rear pointer
            Q[rear].read(); // Call read to add a customer
            if (front == -1) { // If first customer is added
                front = 0; // Set front to 0
            }
        }
    }

    // Method to seat a party from the waitlist
    void seatToparty() {
        if (front == -1 || front > rear) { // Check if the waitlist is empty
            cout << "Restaurant is empty!!" << endl;
        } else {
            Q[front].display(); // Display the front customer details
            front = front + 1; // Move front forward to the next customer
            if (front > rear) { // Reset when empty
                front = rear = -1; // Set both front and rear to -1
            }
        }
    }

    // Method to display the current waitlist
    void displaywaitlist() {
        if (front == -1) { // Check if the waitlist is empty
            cout << "Waitlist is empty!" << endl;
            return; // Exit if the waitlist is empty
        }

        for (int i = front; i <= rear; i++) { // Traverse the waitlist
            Q[i].display(); // Display each customer's details
        }
    }
};

int main() {
    restaurant r; // Create an instance of the restaurant class
    int choice;   // Variable to store user choice

    // Loop for menu options
    do {
        cout << "\n1. Add to waitlist\n2. Seat a party\n3. Display waitlist\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Read user choice

        switch (choice) {
            case 1:
                r.addTowaitlist(); // Add a customer to the waitlist
                break;
            case 2:
                r.seatToparty(); // Seat a party from the waitlist
                break;
            case 3:
                r.displaywaitlist(); // Display the current waitlist
                break;
            case 4:
                cout << "Exiting..." << endl; // Exit message
                break;
            default:
                cout << "Invalid choice! Please try again." << endl; // Handle invalid choice
        }
    } while (choice != 4); // Continue until the user chooses to exit

    return 0; // Return 0 to indicate successful execution
}
