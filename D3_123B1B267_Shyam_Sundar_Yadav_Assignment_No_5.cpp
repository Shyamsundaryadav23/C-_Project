/*
                                                        Assignment No: 5

Problem statement:
Implement a navigation system for a delivery service using a circular linked list to represent 
routes. The navigation system should support the following functionalities: 
a. Add route 
b. Remove route 
c. Display route 


Name: Shyam Sundar yadav
PRN:123B1B267
Batch: D3
Course: Data Structure Laboratry


*/

#include<iostream>
using namespace std;

class Node {
public:
    string st;  // Source point
    string end; // Destination point
    float dist; // Distance between source and destination
    Node *next; // Pointer to the next node in the circular linked list
    
    // Constructor to initialize 'next' pointer to NULL
    Node() {
        next = NULL;
    }
    
    // Method to read source, destination, and distance from user
    void read() {
        cout << "Enter the source: ";
        cin >> st;
        cout << "Enter the destination: ";
        cin >> end;
        cout << "Enter the distance: ";
        cin >> dist;
    }
    
    // Method to display node data
    void display() {
        cout << "Source point: " << st << "\n";
        cout << "Destination: " << end << "\n";
        cout << "Distance: " << dist << " km\n";
    }
    
    // Method to return the source point of the node
    string getsource() {
        return st;
    }
};

class Route {
    Node *tail; // Pointer to the tail of the circular linked list
    
public:
    // Constructor to initialize 'tail' to NULL (empty list)
    Route() {
        tail = NULL;
    }
    
    // Method to insert a new node at the end of the circular linked list
    void insert_end() {
        Node *cn = new Node;
        cn->read(); // Read node data from user
        
        // If list is empty, initialize it with the new node
        if (tail == NULL) {
            tail = cn;
            tail->next = tail; // Make it circular (points to itself)
        } else {
            cn->next = tail->next; // New node points to the head node
            tail->next = cn;       // Tail node points to new node
            tail = cn;             // Update tail to the new node
        }
    }
    
    // Method to insert a new node at the head (start) of the list
    void insert_head() {
        // If list is empty, call insert_end() to insert the first node
        if (tail == NULL) {
            insert_end();
            return;
        }
        
        Node *cn = new Node;
        cn->read();               // Read node data from user
        cn->next = tail->next;    // New node points to the head node
        tail->next = cn;          // Tail node points to the new node (new head)
    }
    
    // Method to print all nodes (routes) in the circular list
    void print_route() {
        if (tail == NULL) {
            cout << "Route is empty.\n"; // Check if list is empty
            return;
        }
        
        Node *temp = tail->next; // Start from the head node
        do {
            temp->display();     // Display the current node
            temp = temp->next;   // Move to the next node
        } while (temp != tail->next); // Continue until we come back to head
    }
    
    // Method to delete a node by source point
    void delete_route() {
        if (tail == NULL) {
            cout << "No route to delete.\n"; // Check if list is empty
            return;
        }
        
        string st;
        cout << "Enter the source: ";
        cin >> st; // Get the source point to delete
        
        Node *t = tail->next; // Start from the head node
        Node *p = tail;       // Previous node pointer
        
        do {
            if (t->getsource() == st) {
                // If there's only one node in the list
                if (t == tail && t->next == tail) {
                    delete t;
                    tail = NULL; // Empty the list
                    return;
                } 
                // If the node to be deleted is the tail node
                else if (t == tail) {
                    p->next = t->next; // Update previous node's next
                    tail = p;          // Update tail
                    delete t;
                    return;
                } 
                // If the node is somewhere in the middle or head
                else {
                    p->next = t->next;
                    delete t;
                    return;
                }
            }
            p = t; // Move previous node pointer forward
            t = t->next; // Move current node pointer forward
        } while (t != tail->next);
        
        cout << "Source not found.\n"; // If source point is not found
    }
};

int main() {
    Route R;
    int choice;

    // Menu-driven program with switch case to handle user actions
    do {
        cout << "\n--- Route Management System ---\n";
        cout << "1. Insert a route at the end\n";
        cout << "2. Insert a route at the beginning\n";
        cout << "3. Delete a route by source\n";
        cout << "4. Display all routes\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform actions based on user input
        switch (choice) {
            case 1:
                R.insert_end(); // Insert a route at the end
                break;
            case 2:
                R.insert_head(); // Insert a route at the beginning
                break;
            case 3:
                R.delete_route(); // Delete a route by source
                break;
            case 4:
                R.print_route(); // Display all routes
                break;
            case 5:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5); // Continue until user chooses to exit

    return 0;
}
