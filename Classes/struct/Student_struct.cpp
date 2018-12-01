#include <iostream>

// Only encapsulation
// No information hiding
struct student {
    int grade;
    int studentID;
    std::string name;
    student(int newGrade, int newID, std::string newName) {
        grade = newGrade;
        studentID = newID;
        name = newName;
    }

    void display_info() {
        std::cout << "Student name is " << name << std::endl;
        std::cout << "Grade is " << grade << std::endl;
        std::cout << "ID is " << studentID << std::endl;
    }
};

int main() {
    // student* s = new student(1,10,"Naveen");
    student s(1, 110, "Naveen");
    s.display_info();
    // delete s;
    return 0;
}