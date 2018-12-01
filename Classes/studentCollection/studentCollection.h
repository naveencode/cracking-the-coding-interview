#include <iostream>
#include <string>

#include "studentRecord.h"

class studentCollection {
    private:
        struct studentNode {
            studentRecord studentData;
            studentNode * next;
        };
    
    public:
        studentCollection();
        studentCollection(const studentCollection &original);
        ~studentCollection();

        void addRecord(studentRecord newStudent);
        studentRecord recordWithNumber(int idNum);
        void removeRecord(int idNum);

        // operator overloading
        studentCollection& operator=(const studentCollection & rhs);

    private:
        typedef studentNode * studentList;
        studentList _listHead;

        void deleteList(studentList &listPtr);
        studentList getCopiedList(const studentList original);
};

