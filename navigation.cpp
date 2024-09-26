#include<iostream>
using namespace std;

// Node class represents a single route in the system
class Node {
public:
    string st;  // Source point
    string end; // Destination point
    float dist; // Distance between source and destination
    Node *next; // Pointer to the next node (for circular linked list)

    // Constructor
    Node() {
        next = NULL;
    }

    // Function to read input for a node (route)
    void read() {
        cout << "Enter the source: ";
        cin >> st;
        cout << "Enter the destination: ";
        cin >> end;
        cout << "Enter the distance: ";
        cin >> dist;
    }

    // Function to display the route information
    void display() {
        cout << "Source point: " << st << "\n";
        cout << "Destination: " << end << "\n";
        cout << "Distance: " << dist << "\n";
    }

    // Function to return the source (for deletion/searching purposes)
    string getsource() {
        return st;
    }
};

// Route class manages the list of routes using circular linked list
class Route {
    Node *tail;  // Points to the last node (tail) in the circular list

public:
    // Constructor initializes tail to NULL (empty list)
    Route() {
        tail = NULL;
    }

    // Destructor to clean up allocated memory
    ~Route() {
        clear_route();
    }

    // Function to insert a new route at the end of the list
    void insert_end() {
        Node *cn = new Node;  // Create a new node
        cn->read();  // Read route data from the user

        if (tail == NULL) {  // If the list is empty
            tail = cn;       // New node becomes the tail
            tail->next = tail; // Circular reference (points to itself)
        } else {  // Insert at the end
            cn->next = tail->next; // New node points to the first node
            tail->next = cn;       // Tail points to the new node
            tail = cn;             // Update tail to be the new node
        }
    }

    // Function to insert a new route at the head of the list
    void insert_head() {
        if (tail == NULL) { // If the list is empty, insert at the end
            insert_end();
            return;
        }

        Node *cn = new Node;  // Create a new node
        cn->read();           // Read route data
        cn->next = tail->next; // New node points to the first node
        tail->next = cn;       // Tail still points to the last node
    }

    // Function to print all routes in the list
    void print_route() {
        if (tail == NULL) {
            cout << "Route is empty.\n";
            return;
        }

        Node *temp = tail->next;  // Start from the head (next of tail)
        do {
            temp->display();  // Display current node
            temp = temp->next; // Move to the next node
        } while (temp != tail->next);  // Continue until back to the head
    }

    // Function to delete a route by source point
    void delete_route() {
        if (tail == NULL) {
            cout << "No route to delete.\n";
            return;
        }

        string st;
        cout << "Enter the source to delete: ";
        cin >> st;

        Node *t = tail->next;  // Start from the head
        Node *p = tail;        // Previous pointer to assist in deletion

        do {
            if (t->getsource() == st) {  // Found the source to delete
                if (t == tail && t->next == tail) {  // Only one node in the list
                    delete t;  // Delete the single node
                    tail = NULL; // Empty the list
                    return;
                } else if (t == tail) {  // If the node to delete is the tail
                    p->next = t->next; // Previous node points to the first node
                    tail = p;  // Update tail to the previous node
                    delete t;  // Delete the tail node
                    return;
                } else {  // If the node to delete is not the tail
                    p->next = t->next; // Skip the node to delete
                    delete t;  // Delete the node
                    return;
                }
            }
            p = t;  // Move previous pointer
            t = t->next;  // Move to the next node
        } while (t != tail->next);  // Stop if we've traversed the whole list

        cout << "Source not found.\n";  // If source not found
    }

    // Function to delete all nodes and clear the list (used in destructor)
    void clear_route() {
        if (tail == NULL) return;  // No nodes to delete

        Node *current = tail->next;  // Start from head
        Node *nextNode;

        // Loop through all nodes and delete them
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != tail->next);

        tail = NULL;  // Reset tail to NULL after clearing the list
    }
};

int main() {
    Route R;  // Create a Route object to manage routes
    int choice;  // Variable to store user choice

    cout << "Route Navigation System!!\n";
    while (true) {  // Infinite loop to show the menu
        cout << "1. Add source and destination:\n";
        cout << "2. Change first place:\n";
        cout << "3. Delete route\n";
        cout << "4. Show route\n";
        cout << "5. To Exit\n";
        cout << "Enter the choice: ";
        cin >> choice;

        switch (choice) {
        case 1:  // Insert a new route at the end
            R.insert_end();
            break;
        case 2:  // Insert a new route at the head
            R.insert_head();
            break;
        case 3:  // Delete a route by source
            R.delete_route();
            break;
        case 4:  // Print all routes
            R.print_route();
            break;
        case 5:  // Exit the program
            exit(0);
        default:  // Handle invalid choices
            cout << "Invalid Choice!!\n";
        }
    }
    return 0;
}
