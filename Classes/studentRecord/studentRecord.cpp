#include "studentRecord.h"

using namespace std;

// A class helps both in encapsulation and information hiding

bool studentRecord::isValidGrade(int grade) {
    if ((grade >= 0) && (grade <= 100))
        return true;
    else
        return false;
}

void studentRecord::setGrade(int newGrade) {
    // validation
    if (isValidGrade(newGrade))
        _grade = newGrade;
    else
        cout << "Invalid range for grade";
}

int studentRecord::getGrade() {
    return _grade;
}

void studentRecord::setStudentID(int newID) {
    // Validation?
    _studentID = newID;
}

string studentRecord::getName() {
    return _name;
}

void studentRecord::setName(string newName) {
    _name = newName;
}

studentRecord::studentRecord(int newGrade, int newID, string newName) {
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

studentRecord::studentRecord() {
    // Sensible defaults
    setGrade(0);
    setStudentID(-1);
    setName("");
}

string studentRecord::letterGrade() {
    if (!isValidGrade(_grade)) return "ERROR";
    const int NUMBER_CATEGORIES = 11;
    const string GRADE_LETTER[] = {
        "F", "D", "D+", "C-", "C", "C+", "B-",
        "B", "B+", "A-", "A"
    };
    const int LOWEST_GRADE_SCORE[] = {
        0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93
    };
    int category = 0;
    while (category < NUMBER_CATEGORIES &&
            LOWEST_GRADE_SCORE[category] <= _grade)
            category++;
    return GRADE_LETTER[category - 1];

}