#include <iostream>
#include <string>

using namespace std;

// A class helps both in encapsulation and information hiding

class studentRecord {
    public:
        // overloaded constructors
        studentRecord();
        studentRecord(int newGrade, int newID, string newName);

        // getters and setters
        int getGrade();
        void setGrade(int newGrade);
        int getStudentID();
        void setStudentID(int newID);
        string getName();
        void setName(string newName);

        // support methods that benefit client
        string letterGrade();

    private:
        // general helper function
        bool isValidGrade(int grade);

        int _grade;
        int _studentID;
        string _name;
};
