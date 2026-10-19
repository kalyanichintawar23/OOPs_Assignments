#include <iostream>
#include <string>

using namespace std;

class ReportCardGenerator;

class Student {
private:
    int studentID;
    string name;
    double marks[3];

public:
    static int totalStudents;

    Student(int studentID, string name, double m1, double m2, double m3) {
        this->studentID = studentID;
        this->name = name;
        this->marks[0] = m1;
        this->marks[1] = m2;
        this->marks[2] = m3;
        totalStudents++;
    }

    inline double calculateTotal() {
        return marks[0] + marks[1] + marks[2];
    }

    inline double calculatePercentage() {
        return calculateTotal() / 3.0;
    }

    void comparePerformance(Student &other) {
        if (this->calculatePercentage() > other.calculatePercentage()) {
            cout << this->name << " has a higher percentage than " << other.name << endl;
        } else if (this->calculatePercentage() < other.calculatePercentage()) {
            cout << other.name << " has a higher percentage than " << this->name << endl;
        } else {
            cout << this->name << " and " << other.name << " have the same percentage." << endl;
        }
    }

    static int getTotalStudents() {
        return totalStudents;
    }

    friend class ReportCardGenerator;
};

int Student::totalStudents = 0;

class ReportCardGenerator {
public:
    void generateReport(Student &s) {
        cout << "--- STUDENT REPORT CARD ---" << endl;
        cout << "ID: " << s.studentID << endl;
        cout << "Name: " << s.name << endl;
        cout << "Subject 1: " << s.marks[0] << endl;
        cout << "Subject 2: " << s.marks[1] << endl;
        cout << "Subject 3: " << s.marks[2] << endl;
        cout << "Total Marks: " << s.calculateTotal() << "/300" << endl;
        cout << "Percentage: " << s.calculatePercentage() << "%" << endl;
        cout << "---------------------------" << endl;
    }
};

int main() {
    Student s1(101, "Rahul", 85.5, 90.0, 88.0);
    Student s2(102, "Priya", 92.0, 81.5, 95.0);

    ReportCardGenerator reporter;
    
    reporter.generateReport(s1);
    cout << endl;
    reporter.generateReport(s2);
    cout << endl;

    s1.comparePerformance(s2);
    cout << endl;

    cout << "Total Students Registered: " << Student::getTotalStudents() << endl;

    return 0;
}
