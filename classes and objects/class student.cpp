#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    float marks;

public:

    // Default Constructor
    Student() {
        name = "N/A";
        rollNo = 0;
        marks = 0;
        cout << "Default Constructor Called\n";
    }

    // Parameterized Constructor
    Student(string name, int rollNo, float marks) {
        this->name = name;
        this->rollNo = rollNo;

        if(marks >= 0)
            this->marks = marks;
        else
            this->marks = 0;

        cout << "Parameterized Constructor Called\n";
    }

    // Copy Constructor
    Student(const Student &obj) {
        name = obj.name;
        rollNo = obj.rollNo;
        marks = obj.marks;

        cout << "Copy Constructor Called\n";
    }

    float getMarks() const {
        return marks;
    }

    string getName() const {
        return name;
    }

    void display() const {
        cout << "\nName: " << name;
        cout << "\nRoll No: " << rollNo;
        cout << "\nMarks: " << marks << endl;
    }
};

// ?? Function that compares two students
// Passed by value ? copy constructor will be called
Student findTopper(const Student &s1,const Student &s2) {

    if(s1.getMarks() > s2.getMarks())
        return s1;
    else
        return s2;
}

int main() {

    // ?? Array of objects
    Student students[3] = {
        Student("Ali", 101, 85),
        Student("Sara", 102, 92),
        Student("Abiha", 103, 78)
    };

    cout << "\n--- All Students ---\n";
    for(int i = 0; i < 3; i++) {
        students[i].display();
    }

    // Compare first two students
    Student topper = findTopper(students[0], students[1]);

    cout << "\n--- Topper Between First Two ---\n";
    topper.display();

    return 0;
}