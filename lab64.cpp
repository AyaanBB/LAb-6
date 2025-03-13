#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void displayPerson() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

class Student : public Person {
protected:
    int studentID;
    int gradeLevel;

public:
    Student(string n, int a, int id, int grade) : Person(n, a), studentID(id), gradeLevel(grade) {}

    void displayStudent() {
        displayPerson();
        cout << "Student ID: " << studentID << "\nGrade Level: " << gradeLevel << endl;
    }
};

class Teacher : public Person {
protected:
    string subject;
    int roomNumber;

public:
    Teacher(string n, int a, string subj, int room) : Person(n, a), subject(subj), roomNumber(room) {}

    void displayTeacher() {
        displayPerson();
        cout << "Subject: " << subject << "\nRoom Number: " << roomNumber << endl;
    }
};

class GraduateStudent : public Student, public Teacher {
public:
    GraduateStudent(string n, int a, int id, int grade, string subj, int room)
        : Person(n, a), Student(n, a, id, grade), Teacher(n, a, subj, room) {}

    void displayGraduateStudent() {
        cout << "Graduate Student Details:\n";
        displayStudent();
        cout << "Also a Teaching Assistant!\n";
        cout << "Subject: " << subject << "\nRoom Number: " << roomNumber << endl;
    }
};

int main() {
    GraduateStudent grad("Alex Carter", 25, 12345, 7, "Computer Science", 202);
    
    grad.displayGraduateStudent();

    return 0;
}
