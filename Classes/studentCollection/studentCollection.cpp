
#include "studentRecord.h"
#include "studentCollection.h"


studentCollection::studentCollection() {
    _listHead = NULL;
}

void studentCollection::addRecord(studentRecord newStudent) {
    studentNode *newNode = new studentNode;

    newNode->studentData = newStudent;
    newNode->next = _listHead;
    _listHead = newNode;
}

studentRecord studentCollection::recordWithNumber(int idNum) {
    studentNode *loopPtr = _listHead;
    while (loopPtr != NULL && loopPtr->studentData.getStudentID() != idNum) {
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL) {
        studentRecord dummyRecord(-1,-1, "");
        return dummyRecord;
    }
    else {
        return loopPtr->studentData;
    }
}

void studentCollection::removeRecord(int idNum) {
    studentNode * loopPtr = _listHead;
    studentNode * trailing = NULL;
    while (loopPtr != NULL && loopPtr->studentData.getStudentID() != idNum) {
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }
    if (loopPtr == NULL) return;

    if (trailing == NULL) {
        _listHead = _listHead->next;
    }
    else {
        trailing->next = loopPtr->next;
    }
    delete loopPtr;
}

void studentCollection::deleteList(studentList &listPtr) {
    while (listPtr != NULL) {
        studentNode *temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

studentCollection::~studentCollection() {
    deleteList(_listHead);
}

studentCollection::studentList studentCollection::getCopiedList(const studentList original) {
    if (original == NULL) {
        return NULL;
    }
    studentList newList = new studentNode;
    newList->studentData = original->studentData;
    studentNode * oldLoopPtr = original->next;
    studentNode * newLoopPtr = newList;
    while (oldLoopPtr != NULL) {
        newLoopPtr->next = new studentNode;
        newLoopPtr = newLoopPtr->next;
        newLoopPtr->studentData = oldLoopPtr->studentData;
        oldLoopPtr = oldLoopPtr->next;
    }
    newLoopPtr->next = NULL;
    return newList;
}

studentCollection& studentCollection::operator=(const studentCollection &rhs) {
    if (this != &rhs) {
        deleteList(_listHead);
        _listHead = getCopiedList(rhs._listHead);
    }
    // return pointer to lhs
    return *this;
}

studentCollection::studentCollection(const studentCollection &original) {
    _listHead = getCopiedList(original._listHead);
}