/*
                            Assignment No 1.B
Probelm Statement

Consider a student database of SY COMP class (at least 15 records). Database contains different 
fields of every student like Roll No, Name and SGPA.

Arrange list of students alphabetically using shell sort 


Name: Shyam Sundar Yadav
PRN:123B1B267
Roll.No:SYCOD267
Batch: D3
Course: Data Structures Laboratry
*/
// Program

#include <iostream>
using namespace std;

// Defining a class 'student' which contains three data members: roll number, name, and SGPA
class student
{
    int rno;          // Roll number of the student
    string name;      // Name of the student (using the string type for flexibility)
    float sgpa;       // SGPA (Semester Grade Point Average) of the student

public:
    // Function to read student details from the user
    void read()
    {
        cout<<"Enter the name: ";
        cin.ignore();              // Ignoring any leftover newline character from previous input
        getline(cin, name);        // Reading the student's name including spaces
        cout<<"Enter the roll.no: ";
        cin>>rno;                  // Reading the student's roll number
        cout<<"Enter the sgpa: ";
        cin>>sgpa;                 // Reading the student's SGPA
    }

    // Function to display the student details
    void display()
    {
        cout<<"Name: "<<name<<endl;     // Displaying the student's name
        cout<<"Roll no: "<<rno<<endl;   // Displaying the roll number
        cout<<"SGPA: "<<sgpa<<endl;     // Displaying the SGPA
    }

    // Friend function to perform shell sort on an array of 'student' objects
    // This function has access to private members of the class
    friend void shellsort(student s[], int n);
};

// Function to sort students using Shell Sort algorithm based on their roll numbers
void shellsort(student s[], int n)
{
    int interval = n / 2;  // Initial gap/interval is half the size of the array

    // The loop continues until the interval is reduced to 0
    while (interval >= 1)
    {
        // This loop ensures that all elements are compared and rearranged based on the current gap
        for (int i = interval; i < n; i++)
        {
            student temp = s[i];   // Storing the current student being compared
            int j = i - interval;

            // Move elements that are greater than the current student's roll number
            for (; j >= 0; j -= interval)
            {
                if (s[j].rno > temp.rno) // If the current roll number is greater than temp's roll number
                {
                    s[j + interval] = s[j]; // Shift element to the right
                }
                else
                {
                    break; // No need to shift, stop the inner loop
                }
            }

            // Place the student at the correct position
            s[j + interval] = temp;
        }

        // Reduce the interval for the next pass
        interval /= 2;
    }
}

int main() {
    student sobj[20]; // Array to store details of up to 20 students
    int n;

    // Ask the user for the number of students
    cout<<"Enter the number of the student: ";
    cin>>n;

    // Reading details of each student
    for (int i = 0; i < n; i++)
    {
        sobj[i].read(); // Call the read function for each student
    }

    // Sort the students based on their roll numbers using Shell Sort
    shellsort(sobj, n);

    cout << endl;
    cout<<"After sorting student details are: "<<endl;

    // Display the sorted student details
    for (int i = 0; i < n; i++)
    {
        sobj[i].display(); // Call the display function for each student
    }

    return 0; // End of program
}
