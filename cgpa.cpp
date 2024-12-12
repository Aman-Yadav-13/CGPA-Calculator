#include<iostream>
#include<vector>

using namespace std;

// Class representing a Subject with its name, credit hours, and grade points
class Subject{
    string subjectName; // Name of the subject
    int credit;         // Credit hours for the subject
    float gradePoint;   // Grade point for the subject

    public:
        // Constructor to initialize Subject with name, credit, and grade point
        Subject(string subjectName, int credit, float gradePoint){
            this->subjectName = subjectName;
            this->credit = credit;
            this->gradePoint = gradePoint;
        }

        // Getter method to retrieve the credit hours of the subject
        int getCredit(){
            return credit;
        }

        // Getter method to retrieve the grade point of the subject
        float getGradePoint(){
            return gradePoint;
        }
};

// Class representing a Student with a name and a list of subjects
class Student{
    string studentName;        // Name of the student
    vector<Subject> subjects;  // List of subjects the student has enrolled in

    public:
        // Constructor to initialize Student with a name
        Student(string studentName){
            this->studentName = studentName;
        }

        // Method to add a subject with its details to the student's record
        void addSubject(string subjectName, int credit, float gradePoint){
            Subject newSubject(subjectName, credit, gradePoint); // Create a new Subject object
            subjects.push_back(newSubject); // Add the subject to the list
        }

        // Method to calculate the CGPA of the student based on enrolled subjects
        float calculateCGPA(){
            int totalCredit = 0;          // Total credit hours for all subjects
            float weightGradePoint = 0;  // Weighted sum of grade points

            // Iterate through all subjects and compute total credits and weighted grade points
            for(auto &subject : subjects){
                totalCredit += subject.getCredit();
                weightGradePoint += subject.getCredit() * subject.getGradePoint();
            }

            // Calculate CGPA as the weighted grade points divided by total credits
            return totalCredit > 0 ? weightGradePoint / totalCredit : 0;
        }

        // Method to display the student's name and calculated CGPA
        void displayCGPA(){
            cout << "Student name : " << studentName << endl;

            float cgpa = calculateCGPA(); // Calculate CGPA

            cout << "CGPA : " << cgpa << endl;
        }
};

int main(){
    string studentName;   // Variable to store the student's name
    int totalSubjects;    // Variable to store the number of subjects

    // Input student's name
    cout << "Enter student's name : " << endl;
    getline(cin, studentName);

    // Input number of subjects the student has enrolled in
    cout << "Enter number of subjects : " << endl;
    cin >> totalSubjects;

    Student student(studentName); // Create a Student object with the entered name

    // Input details for each subject
    for(int i=0 ; i<totalSubjects ; i++){
        string subjectName; // Variable to store the subject's name
        int credit;         // Variable to store the credit hours of the subject
        float gradePoint;   // Variable to store the grade point of the subject

        cin.ignore(); // Clear the input buffer

        // Input subject's name
        cout << "Enter subject Name : " << endl;
        getline(cin, subjectName);

        // Input credit hours for the subject
        cout << "Enter credit : " << endl;
        cin >> credit;

        // Input grade point for the subject
        cout << "Enter grade point : " << endl;
        cin >> gradePoint;

        // Add the subject to the student's record
        student.addSubject(subjectName, credit, gradePoint);
    }

    // Display the calculated CGPA for the student
    student.displayCGPA();

    return 0;
}
