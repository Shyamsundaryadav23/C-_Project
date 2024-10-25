/*
                                                       Assignment No.7

Problem Statement:

Implement a browser history management system using a stack data structure to track the user's 
browsing history. The system should support the following functionalities: 
a. Add visited page 
b. Navigate back 
c. View current page 
d. Check if history is empty or not


Name: Shyam Sundar Yadav
PRN: 123B1B267
Batch: D3
Course: Data Structures Laboratory

*/


// Browser History Management System
#include <iostream>
#include<cstring>
using namespace std;

class webpage {
    string site; // Stores the site name or URL
public:
    webpage *next; // Pointer to the next webpage in history (acts as a stack node)

    // Constructor to initialize 'next' pointer to nullptr
    webpage() {
        next = nullptr;
    }

    // Method to take input from the user for the site
    void read() {
        cout << "Search your site: ";
        cin.ignore(); // To ignore the newline from previous input
        getline(cin, site); // Read the complete site URL or name
    }

    // Method to display the current site
    void display() {
        cout << "Current site: " << site << "\n";
    }
};

class browser_History {
    webpage *top; // Pointer to the top of the stack (most recent webpage)
public:
    // Constructor to initialize 'top' to nullptr
    browser_History() {
        top = nullptr;
    }

    // Methods for managing browser history
    void addNewpage();       // Add a new webpage to the stack (history)
    void navigateBack();     // Remove the most recent webpage (go back)
    void showCurrentsite();  // Display the current webpage
    bool isEmpty();          // Check if history is empty
};

// Add a new webpage to the history (stack)
void browser_History::addNewpage() {
    webpage *page = new webpage; // Create a new webpage object
    page->read();                // Take input for the site name/URL
    // Add new page on top of the stack
    page->next = top; // New page points to the previous top page
    top = page;       // Update top to the new page
}

// Go back to the previous page in the history
void browser_History::navigateBack() {
    if (isEmpty()) {
        cout << "No pages in history to navigate back!" << "\n";
        return;
    }
    
    webpage *temp = top; // Store the current top (current page)
    top = top->next;     // Move top to the previous page
    delete temp;         // Delete the old top (current page)
}

// Display the current page (the top of the stack)
void browser_History::showCurrentsite() {
    if (isEmpty()) {
        cout << "No current site!" << "\n";
        return;
    }
    top->display(); // Call display method of the current page (top)
}

// Check if the browser history is empty
bool browser_History::isEmpty() {
    return top == nullptr; // Returns true if top is null (empty history)
}

int main() {
    browser_History T; // Create a browser history object
    int ch;            // Variable for user choice

    cout << "Browser History: \n";
    while (true) {
        // Display the menu
        cout << "1. Add New page\n2. Navigate Back\n3. Show Current site\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> ch;

        // Use a switch-case to handle the user's choice
        switch (ch) {
            case 1:
                T.addNewpage(); // Add a new page to the history
                break;
            case 2:
                T.navigateBack(); // Go back to the previous page
                break;
            case 3:
                T.showCurrentsite(); // Display the current page
                break;
            case 4:
                exit(0); // Exit the program
            default:
                cout << "Invalid choice!! Try again\n"; // Invalid input handling
                break;
        }
    }
    return 0;
}
