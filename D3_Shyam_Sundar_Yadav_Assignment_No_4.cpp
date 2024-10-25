/*
                                                         Assignment No 4
Problem Statement

Implement a simple text editor application using a doubly linked list to manage the text buffer. 
Text editor should support the following functionalities:  
a. Insert text 
b. Delete text 
c. Display text 
d. Search text 
e. Print text in reverse 

Name: Shyam Sundar yadav
PRN:123B1B267
Batch: D3
Course: Data Structure Laboratry

*/
// Program

#include<iostream>
using namespace std;

// Class representing each text entry in the editor
class Editor {
    string text; // The text content
public:
    Editor *next; // Pointer to the next node
    Editor *prev; // Pointer to the previous node
    
    // Constructor to initialize pointers
    Editor() {
        prev = next = NULL;
    }

    // Function to read text from user
    void read() {
        cin.ignore(); // Ignore any leftover input
        cout << "Enter the text: ";
        getline(cin, text);
    }

    // Destructor to clear pointers
    ~Editor() {
        prev = next = NULL;
    }

    // Function to return the text content
    string gettext() {
        return text;
    }

    // Function to display the text
    void display() {
        cout << "Text In Editor: " << text << "\n";
    }
};

// Class representing the text editor, managing multiple Editor nodes
class text_editor {
    Editor *head, *tail; // Pointers to the head and tail of the list
public:
    // Constructor to initialize head and tail
    text_editor() {
        head = tail = NULL;
    }

    // Destructor to clear head and tail
    ~text_editor() {
        head = tail = NULL;
    }

    // Function declarations for text editor operations
    void add_text();
    void display_text();
    void add_text_at_begin();
    void add_text_at_any(string s);
    void display_rev();
    void search(string sc);
    void delete_text(string d);
};

// Function to add text to the end of the list
void text_editor::add_text() {
    Editor *nn, *cn;
    nn = new Editor(); // Create a new Editor node
    nn->read(); // Read text from user
    if (head == NULL) {
        // If the list is empty, initialize head and tail
        head = tail = nn;
    } else {
        // Traverse to the end and add the new node
        for (cn = head; cn->next != NULL; cn = cn->next);
        cn->next = nn; // Link new node to the last node
        nn->prev = cn; // Link last node to the new node
        tail = nn; // Update tail
    }
}

// Function to display all text entries
void text_editor::display_text() {
    Editor *cn;
    if (head == NULL) {
        cout << "List Empty!!\n"; // Handle empty list
        return;
    }
    for (cn = head; cn != NULL; cn = cn->next) {
        cn->display(); // Display each text entry
    }
}

// Function to add text at the beginning of the list
void text_editor::add_text_at_begin() {
    Editor* nn = new Editor();  // Create a new node
    nn->read();  // Read text from user

    if (head == NULL) {
        // If the list is empty, initialize head and tail
        head = tail = nn;
    } else {
        // Add at the beginning of the list
        nn->next = head;
        head->prev = nn;
        head = nn;  // Update head to new node
    }
}

// Function to add text after a specific entry
void text_editor::add_text_at_any(string s) {
    Editor *cn = head, *nn = new Editor();
    nn->read(); // Read text from user

    if (head == NULL) {
        head = tail = nn; // If list is empty, initialize head and tail
        return;
    }

    // Traverse the list to find the matching text
    while (cn != NULL && cn->gettext() != s) {
        cn = cn->next;
    }

    if (cn != NULL) { // If a matching text is found
        nn->next = cn->next; // Link new node to the next node
        nn->prev = cn; // Link new node to the current node

        if (cn->next != NULL) {
            cn->next->prev = nn; // Update the next node's previous pointer
        } else {
            tail = nn; // Update tail if inserted at the end
        }
        cn->next = nn; // Link current node to the new node
    } else {
        cout << "Text not found!\n"; // Handle case where text is not found
        delete nn;
    }
}

// Function to display all text entries in reverse order
void text_editor::display_rev() {
    if (tail == NULL) {
        cout << "List Empty\n";  // Handle empty list
        return;
    }

    Editor* cn = tail;  // Start from tail
    while (cn != NULL) {
        cn->display();  // Display each text entry
        cn = cn->prev;  // Move to previous node
    }
}


// Function to delete a specific text entry
void text_editor::delete_text(string d) {
    if (head == NULL) {
        cout << "Text editor is empty!!\n"; // Handle empty list
        return;
    }

    Editor *cn = head;

    // Traverse the list to find the node to delete
    while (cn != NULL && cn->gettext() != d) {
        cn = cn->next;
    }

    if (cn == NULL) {
        cout << "Text not found!\n"; // Handle case where text is not found
        return;
    }

    // Unlink the node
    if (cn == head) {  // If the node to be deleted is the head
        head = cn->next; // Update head to next node
        if (head != NULL) {
            head->prev = NULL; // Update new head's previous pointer
        }
    } else if (cn == tail) {  // If the node to be deleted is the tail
        tail = cn->prev; // Update tail to previous node
        if (tail != NULL) {
            tail->next = NULL; // Update tail's next pointer
        }
    } else {  // For a middle node
        cn->prev->next = cn->next; // Link previous node to next node
        cn->next->prev = cn->prev; // Link next node to previous node
    }

    delete cn; // Free memory
}

// Function to search for a specific text entry
void text_editor::search(string s) {
    Editor *cn = head; // Initialize the pointer to head
    bool found = false;
    
    while (cn != NULL) {
        if (s == cn->gettext()) {
            cout << "Text is found!!\n"; // Display if found
            cn->display();
            found = true;
            break; // Stop at the first match
        }
        cn = cn->next; // Move to the next node
    }

    if (!found) {
        cout << "Text not found.\n"; // Handle case where text is not found
    }
}

int main() {
    text_editor T; // Create a text editor instance
    int choice;
    while (true) {
        // Display menu options
        cout << "Simple Text Editor \n";
        cout << "1. Add New Text\n2. Display Text list\n3. Add Text Beginning\n";
        cout << "4. Display list in reverse\n5. Add at any position\n6. Delete text\n";
        cout << "7. To search text\n0. Exit\n";
        cout << "Enter the choice: ";
        cin >> choice;
        
        // Handle user choice
        switch (choice) {
            case 1:
                T.add_text(); // Add new text
                break;
            case 2:
                T.display_text(); // Display all text
                break;
            case 3:
                T.add_text_at_begin(); // Add text at beginning
                break;
            case 4:
                T.display_rev(); // Display text in reverse
                break;
            case 5: {
                string s;
                cout << "Enter the text place: ";
                cin.ignore();
                getline(cin, s); // Get text to add after
                T.add_text_at_any(s);
                break;
            }
            case 6: {
                string d;
                cin.ignore();
                cout << "Enter the text to delete: ";
                getline(cin, d); // Get text to delete
                T.delete_text(d);
                break;
            }
            case 7: {
                string e;
                cin.ignore();
                cout << "Enter the text to search: ";
                getline(cin, e); // Get text to search
                T.search(e);
                break;
            }
            case 0:
                exit(0); // Exit the program
            default:
                cout << "Invalid choice!!\nTry Again\n"; // Handle invalid input
        }
    }
    return 0;
}
