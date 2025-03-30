#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
    string name;
    string id;
    string address;
    string email;
    string phonenum;
public:
    Person(string a, string b, string c, string d, string e) : name(a), id(b), address(c), email(d), phonenum(e) {}
    virtual void displaydetails() {
        cout << "Person Details" << endl;
        cout << "Name:" << name << endl;
        cout << "ID:" << id << endl;
        cout << "Address:" << address << endl;
        cout << "Email:" << email << endl;
        cout << "Phone Number:" << phonenum << endl;
    }
    void updatedetails(string a, string b, string c, string d, string e) {
        name = a;
        id = b;
        address = c;
        email = d;
        phonenum = e;
    }
};

class Student : public Person {
    int coursesEnrolled;
    float GPA;
    int EnrollmentYear;
public:
    Student(string a, string b, string c, string d, string e, int f, float g, int h) 
        : Person(a, b, c, d, e), coursesEnrolled(f), GPA(g), EnrollmentYear(h) {}
    void displaydetails() override {
        cout << "Student Details" << endl;
        Person::displaydetails();
        cout << "Courses Enrolled:" << coursesEnrolled << endl;
        cout << "GPA:" << GPA << endl;
        cout << "Enrollment Year:" << EnrollmentYear << endl;
    }
    string get_name(){
    	return name;
	}
};

class Professor : public Person {
    string department;
    int coursestaught;
    float salary;
public:
    Professor(string a, string b, string c, string d, string e, string f, int g, float h) 
        : Person(a, b, c, d, e), department(f), coursestaught(g), salary(h) {}
    void displaydetails() override {
        cout << "Professor Details" << endl;
        Person::displaydetails();
        cout << "Department:" << department << endl;
        cout << "Courses Taught:" << coursestaught << endl;
        cout << "Salary:" << salary << endl;
    }
};

class Staff : public Person {
    string department;
    string position;
    float salary;
public:
    Staff(string a, string b, string c, string d, string e, string f, string g, float h) 
        : Person(a, b, c, d, e), department(f), position(g), salary(h) {}
    void displaydetails() override {
        cout << "Staff Details" << endl;
        Person::displaydetails();
        cout << "Department:" << department << endl;
        cout << "Position:" << position << endl;
        cout << "Salary:" << salary << endl;
    }
};

class Course {
    string courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;
public:
    Course(string id, string name, int cred, string instr, string sched) 
        : courseId(id), courseName(name), credits(cred), instructor(instr), schedule(sched) {}
    void registerStudent(Student& s) {
        cout << "Student " << s.get_name() << " registered for " << courseName << endl;
    }
    void calculateGrades() {
        cout << "Grades calculated for course " << courseName << endl;
    }
    void displayCourseInfo() {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor << endl;
        cout << "Schedule: " << schedule << endl;
    }
};

int main() {
    Student s1("John Doe", "S1001", "123 Campus Rd", "john@uni.edu", "555-1234", 5, 3.8, 2020);
    Professor p1("Dr. Smith", "P2001", "456 Faculty Ave", "smith@uni.edu", "555-5678", "Computer Science", 4, 75000);
    Staff st1("Jane Brown", "ST3001", "789 Admin Blvd", "jane@uni.edu", "555-9012", "Administration", "Manager", 50000);
    Course c1("CS101", "Introduction to Programming", 4, "Dr. Smith", "Mon/Wed 10-11:30");

    s1.displaydetails();
    p1.displaydetails();
    st1.displaydetails();
    c1.displayCourseInfo();
    c1.registerStudent(s1);
    c1.calculateGrades();

    return 0;
}