# DSA-Project
 LGU Project Submitted To Sir Zaheer ud Din
 Student Management System

 Overview

A simple command-line application for managing student data. This system allows adding, removing, searching, sorting, and displaying students' information efficiently. It uses a combination of a linked list and a hash map for data management.

Features
Add Students: Input student details (ID, Name, Grade) and add them to the system.
Remove Students: Remove students from the system using their unique ID.
Search Students:
  - By ID (fast lookup using a hash map).
  - By Name (linear search through the list).
  Display All Students: View all students' information.
- Sort Students: Sort students based on their grades using bubble sort.

Usage Guide

After running the program, a menu will appear with options to interact with the system. For example:

```
--- Student Management System ---
1. Add Student
2. Remove Student
3. Search Student by ID
4. Search Student by Name
5. Display All Students
6. Sort Students by Grade
7. Exit
Enter your choice:
```

Follow the prompts to perform various operations. For example, to add a student, you’ll input their ID, name, and grade when prompted.

Results

Here are examples of program outputs:

Adding a Student:

```
Enter student ID: 101
Enter student name: Alice
Enter student grade: 85.5
Student added successfully!
```

Searching for a Student by ID:

```
Enter student ID to search: 101
Student found: ID: 101, Name: Alice, Grade: 85.5
```

Displaying All Students:

```
ID: 101, Name: Alice, Grade: 85.5
ID: 102, Name: Bob, Grade: 92.0
```

Project Structure

```
Student-Management-System/
│
├── README.md           # Project overview and instructions
├── src/                # Source code files
│   └── main.cpp        # Main program
├── data/               # Placeholder for input/output datasets
├── results/            # Output examples (e.g., screenshots, logs)
└── requirements.txt    # List of dependencies (if applicable)
```

Future Enhancements

- Add file I/O support to save and load student data.
- Implement a GUI for better user experience.
- Add unit tests for each function.

License

This project is licensed under the MIT License. See the `LICENSE` file for details.

The code belongs to Malik Abdullah from LGU submitted to Sir Zaher ud din
