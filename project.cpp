#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// Structure to represent a student
struct Student {
    int id;
    string name;
    float grade;
    Student* next;  // Pointer to next student in the linked list
};
// Head pointer of the linked list (points to the first student)
Student* head = nullptr;
// Hash Map for fast lookup by student ID
unordered_map<int, Student*> studentMap;
// Function to add a student to the linked list
void addStudent(int id, const string& name, float grade) {
    Student* newStudent = new Student;
    newStudent->id = id;
    newStudent->name = name;
    newStudent->grade = grade;
    newStudent->next = nullptr;
    // If the list is empty, make the new student the head
    if (head == nullptr) {
        head = newStudent;
    } else {
        // Traverse to the end of the list
        Student* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // Add new student at the end
        temp->next = newStudent;
    }
    // Add student to the hash map for fast lookup
    studentMap[id] = newStudent;
    cout << "Student added successfully!\n";
}
// Function to remove a student by ID
void removeStudent(int id) {
    if (head == nullptr) {
        cout << "No students in the system.\n";
        return;
    }
    Student* temp = head;
    Student* prev = nullptr;
    // Check if the student to be removed is the head
    if (temp != nullptr && temp->id == id) {
        head = temp->next;  // Change the head
        delete temp;
        studentMap.erase(id);  // Remove from the hash map
        cout << "Student removed successfully!\n";
        return;
    }
    // Search for the student to be removed
    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    // If the student was not found
    if (temp == nullptr) {
        cout << "Student with ID " << id << " not found.\n";
        return;
    }
    // Remove the student
    prev->next = temp->next;
    delete temp;
    studentMap.erase(id);  // Remove from the hash map
    cout << "Student removed successfully!\n";
}
// Function to search for a student by ID
void searchStudentByID(int id) {
    if (studentMap.find(id) != studentMap.end()) {
        Student* student = studentMap[id];
        cout << "Student found: ID: " << student->id << ", Name: " << student->name
             << ", Grade: " << student->grade << endl;
    } else {
        cout << "Student with ID " << id << " not found.\n";
    }
}
// Function to search for a student by name using Linear Search
void searchStudentByName(const string& name) {
    Student* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->name == name) {
            cout << "Student found: ID: " << temp->id << ", Name: " << temp->name
                 << ", Grade: " << temp->grade << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Student with name " << name << " not found.\n";
    }
}
// Function to display all students
void displayAllStudents() {
    if (head == nullptr) {
        cout << "No students available.\n";
        return;
    }

    Student* temp = head;
    while (temp != nullptr) {
        cout << "ID: " << temp->id << ", Name: " << temp->name
             << ", Grade: " << temp->grade << endl;
        temp = temp->next;
    }
}
// Function to sort students by grade using Bubble Sort
void sortStudentsByGrade() {
    if (head == nullptr) {
        cout << "No students to sort.\n";
        return;
    }
    bool swapped;
    Student* temp1;
    Student* temp2 = nullptr;
    do {
        swapped = false;
        temp1 = head;
        while (temp1->next != temp2) {
            if (temp1->grade > temp1->next->grade) {
                // Swap grades and names
                swap(temp1->grade, temp1->next->grade);
                swap(temp1->name, temp1->next->name);
                swap(temp1->id, temp1->next->id);
                swapped = true;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    } while (swapped);
    cout << "Students sorted by grade.\n";
}
// Function to display the menu
void displayMenu() {
    cout << "\n--- Student Management System ---\n";
    cout << "1. Add Student\n";
    cout << "2. Remove Student\n";
    cout << "3. Search Student by ID\n";
    cout << "4. Search Student by Name\n";
    cout << "5. Display All Students\n";
    cout << "6. Sort Students by Grade\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}
int main() {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        if (choice == 1) {
            int id;
            string name;
            float grade;
            cout << "Enter student ID: ";
            cin >> id;
            cin.ignore();  // Ignore leftover newline character
            cout << "Enter student name: ";
            getline(cin, name);
            cout << "Enter student grade: ";
            cin >> grade;
            addStudent(id, name, grade);
        } else if (choice == 2) {
            int id;
            cout << "Enter student ID to remove: ";
            cin >> id;
            removeStudent(id);
        } else if (choice == 3) {
            int id;
            cout << "Enter student ID to search: ";
            cin >> id;
            searchStudentByID(id);
        } else if (choice == 4) {
            string name;
            cout << "Enter student name to search: ";
            cin.ignore();
            getline(cin, name);
            searchStudentByName(name);
        } else if (choice == 5) {
            displayAllStudents();
        } else if (choice == 6) {
            sortStudentsByGrade();
        } else if (choice == 7) {
            cout << "Exiting the program.\n";
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
