#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a struct to store student information (name and marks)
struct Student {
    string name;
    int marks;
};

// Merge function to merge two halves of the array in descending order of marks
void merge(vector<Student>& students, int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;

    // Recursively split the array
    merge(students, left, mid);
    merge(students, mid + 1, right);
    
    // Merge step: temporary vector to hold merged values
    vector<Student> temp;
    int i = left, j = mid + 1;
    
    while (i <= mid && j <= right) {
        if (students[i].marks > students[j].marks) {
            temp.push_back(students[i]);
            i++;
        } else {
            temp.push_back(students[j]);
            j++;
        }
    }
    
    // Add remaining students
    while (i <= mid) {
        temp.push_back(students[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(students[j]);
        j++;
    }
    
    // Copy the sorted students back into the original vector
    for (int k = left; k <= right; ++k) {
        students[k] = temp[k - left];
    }
}

// Function to read the input data (student names and marks)
void inputStudentData(vector<Student>& students, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Enter the name of student " << i + 1 << ": ";
        cin.ignore();  // Ignore leftover newline character
        getline(cin, students[i].name);  // Input the student's name
        cout << "Enter the marks of " << students[i].name << ": ";
        cin >> students[i].marks;  // Input the student's marks
    }
}

// Function to display the sorted list of students
void displaySortedStudents(const vector<Student>& students) {
    cout << "\nSorted List of Students (Descending order of Marks):\n";
    for (const auto& student : students) {
        cout << student.name << " - " << student.marks << endl;
    }
}

int main() {
    int n;

    // Input number of students
    cout << "Enter the number of students: ";
    cin >> n;

    // Create a vector to store the student data
    vector<Student> students(n);

    // Input student names and marks
    inputStudentData(students, n);

    // Perform Merge Sort based on marks
    merge(students, 0, n - 1);

    // Display the sorted list of students
    displaySortedStudents(students);

    return 0;
}
