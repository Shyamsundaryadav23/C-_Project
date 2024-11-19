/*                          
                           Assignment No 2.A

Problem statement

Consider Employee database of PCCOE (at least 20 records). Database contains different fields of 
every employee like EMP-ID, EMP-Name and EMP-Salary.  
a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort.


Name: Shyam Sundar Yadav
PRN: 123B1B267
Roll.No:SYCOD267
Batch: D3
Course: Data Structures Laboratory
*/

// Program

#include<iostream>
using namespace std;

class Employee
{
    string name;   // Name of the employee
    int emp_id;    // Employee ID
    float salary;  // Salary of the employee

public:
    // Function to read the details of an employee
    void read()
    {
        cout << "Enter the employee name: ";
        cin.ignore();                // Ignore the newline character left in the input buffer
        getline(cin, name);           // Read the employee's name including spaces
        cout << "Enter the employee ID: ";
        cin >> emp_id;                // Read the employee's ID
        cout << "Enter the salary: ";
        cin >> salary;                // Read the employee's salary
    }

    // Function to display the details of an employee
    void display()
    {
        cout << "Name: " << name << "\n";      // Display the employee's name
        cout << "ID: " << emp_id << "\n";      // Display the employee's ID
        cout << "Salary: " << salary << "\n";  // Display the employee's salary
    }

    // Declaring quicksort and partition functions as friend functions
    // so they can access private members of the Employee class
    friend void quicksort(Employee arr[], int i, int j);
    friend int partition(Employee arr[], int f, int l);
};

// Partition function for the quicksort algorithm
// It returns the position of the pivot after placing it in the correct spot
int partition(Employee arr[], int left, int right)
{
    int i = left;                  // Start index
    int j = right;                 // End index
    Employee pivot = arr[left];    // Select the leftmost element as pivot

    // Partitioning process: reordering elements around the pivot
    while (i < j)
    {
        // Increment 'i' until an element greater than the pivot (EMP-ID) is found
        while (arr[i].emp_id <= pivot.emp_id && i < right)
            i++;

        // Decrement 'j' until an element smaller than or equal to the pivot (EMP-ID) is found
        while (arr[j].emp_id > pivot.emp_id)
            j--;

        // Swap elements if 'i' is still less than 'j'
        if (i < j)
        {
            Employee temp = arr[i];  // Temporary variable for swapping
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place the pivot in the correct position (swap with 'j')
    Employee temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    return j;  // Return the position of the pivot
}

// Quicksort function to recursively sort the array of employees
void quicksort(Employee arr[], int i, int j)
{
    if (i < j)  // Base condition: if there are more than one element
    {
        // Find the partition position
        int pos = partition(arr, i, j + 1);  // Partition the array

        // Recursively sort elements before and after partition
        quicksort(arr, i, pos - 1);  // Sort the left part
        quicksort(arr, pos + 1, j);  // Sort the right part
    }
}

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    cin.ignore();  // To avoid any leftover newline characters

    Employee obj[n];  // Array of Employee objects

    // Read details of all employees
    for (int i = 0; i < n; i++)
    {
        obj[i].read();  // Call the read function for each employee
    }

    // Perform quicksort on the array of employees based on their EMP-ID
    quicksort(obj, 0, n - 1);

    // Display sorted details of all employees
    for (int i = 0; i < n; i++)
    {
        obj[i].display();  // Call the display function for each employee
    }

    return 0;
}
