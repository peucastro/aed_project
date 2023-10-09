/
// Created by marcelmedeiros1 on 09/10/23.
//

#include "../headers/Student.h"

Student::Student() {
    this->studentName = "NO_NAME";
    this->studentCode = "";
}
Student::Student(const string &studentCode, const string &studentName) {
    this->studentCode = studentCode;
    this->studentName = studentName;
}
