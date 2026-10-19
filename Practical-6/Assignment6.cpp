#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    int prn;

public:
    Student(string n, int a, int p) : Person(n, a), prn(p) {}

    void displayStudent() {
        displayPerson();
        cout << "PRN: " << prn << endl;
    }
};

class GraduateStudent : public Student {
private:
    string thesisTopic;

public:
    GraduateStudent(string n, int a, int p, string topic)
        : Student(n, a, p), thesisTopic(topic) {}

    void displayGraduateStudent() {
        displayStudent();
        cout << "Thesis Topic: " << thesisTopic << endl;
    }
};

class Faculty : public Person {
protected:
    string department;

public:
    Faculty(string n, int a, string dept) : Person(n, a), department(dept) {}

    void displayFaculty() {
        displayPerson();
        cout << "Department: " << department << endl;
    }
};

class Staff : public Person {
private:
    string role;

public:
    Staff(string n, int a, string r) : Person(n, a), role(r) {}

    void displayStaff() {
        displayPerson();
        cout << "Role: " << role << endl;
    }
};

class BasePerson {
protected:
    string name;

public:
    BasePerson(string n) : name(n) {}
};

class StudentBase : virtual public BasePerson {
protected:
    int prn;

public:
    StudentBase(string n, int p) : BasePerson(n), prn(p) {}
};

class EmployeeBase : virtual public BasePerson {
protected:
    double salary;

public:
    EmployeeBase(string n, double s) : BasePerson(n), salary(s) {}
};

class TeachingAssistant : public StudentBase, public EmployeeBase {
private:
    string assignedCourse;

public:
    TeachingAssistant(string n, int p, double s, string course)
        : BasePerson(n), StudentBase(n, p), EmployeeBase(n, s), assignedCourse(course) {}

    void displayTA() {
        cout << "TA Name: " << name << endl;
        cout << "PRN: " << prn << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Assigned Course: " << assignedCourse << endl;
    }
};

class ResearchTA : public TeachingAssistant {
private:
    string researchArea;

public:
    ResearchTA(string n, int p, double s, string course, string area)
        : BasePerson(n), TeachingAssistant(n, p, s, course), researchArea(area) {}

    void displayResearchTA() {
        displayTA();
        cout << "Research Area: " << researchArea << endl;
    }
};

int main() {
    cout << "=== 1. Single Inheritance ===" << endl;
    Student s1("Rahul Sharma", 20, 10322101);
    s1.displayStudent();

    cout << "\n=== 2. Multilevel Inheritance ===" << endl;
    GraduateStudent g1("Aman Verma", 24, 10321805, "AI in Healthcare");
    g1.displayGraduateStudent();

    cout << "\n=== 3. Hierarchical Inheritance ===" << endl;
    Faculty f1("Dr. Priya Patil", 42, "Computer Engineering");
    Staff st1("Suresh Pawar", 38, "Lab Assistant");
    f1.displayFaculty();
    cout << endl;
    st1.displayStaff();

    cout << "\n=== 4. Multiple Inheritance ===" << endl;
    TeachingAssistant ta1("Neha Gupta", 10322509, 15000.0, "Object Oriented Programming");
    ta1.displayTA();

    cout << "\n=== 5. Hybrid Inheritance ===" << endl;
    ResearchTA rta1("Rohan Mehta", 10321988, 25000.0, "Data Structures", "Deep Learning");
    rta1.displayResearchTA();

    return 0;
}
