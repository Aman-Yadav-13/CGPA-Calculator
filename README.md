# CGPA Calculator

A simple C++ program to calculate the CGPA (Cumulative Grade Point Average) of a student based on their enrolled subjects, credit hours, and grade points.

## Features

- Add multiple subjects with their details (name, credit hours, and grade points).
- Automatically calculate the CGPA using the formula:
  CGPA = Weighted Grade Points \ Total Credits
- Display the student's name and their calculated CGPA.

## Program Structure

### Classes
1. **Subject**: Represents a subject with attributes:
   - Subject name
   - Credit hours
   - Grade points

2. **Student**: Represents a student with attributes:
   - Student name
   - List of subjects
   - Methods to calculate CGPA and display details

### Functions
- **`addSubject()`**: Adds a subject to the student's record.
- **`calculateCGPA()`**: Calculates the CGPA based on the student's enrolled subjects.
- **`displayCGPA()`**: Outputs the student's name and their CGPA.
