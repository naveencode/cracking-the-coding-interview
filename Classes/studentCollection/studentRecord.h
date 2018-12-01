#include <iostream>
#include <string>


// A class helps both in encapsulation and information hiding

class studentRecord {
    public:
        // overloaded constructors
        studentRecord();
        studentRecord(int newGrade, int newID, std::string newName);

        // getters and setters
        int getGrade();
        void setGrade(int newGrade);
        int getStudentID();
        void setStudentID(int newID);
        std::string getName();
        void setName(std::string newName);

        // support methods that benefit client
        std::string letterGrade();

    private:
        // general helper function
        bool isValidGrade(int grade);

        int _grade;
        int _studentID;
        std::string _name;
};
