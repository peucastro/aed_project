#include "../inc/Class.h"
#include "Class.h"


Class::Class(string ucCode, string classCode, string weekDay, double startHour, double duration, string type){
    this->uc.setUcCode(ucCode);
    this->uc.addClass(classCode);
    this->weekDay = weekDay;
    this->startHour = startHour;
    this->duration = duration;
    this->type = type;
}

Uc Class::getUc(){
    return this->uc;
}

void Class::setUc(const Uc &uc){
    this->uc = uc;
}

void Class::addStudent(Student student){
    Student new_student = Student(student.getstudentCode(), student.getstudentName());
    this->students.push_back(new_student);
}

void Class::removeStudent(Student student){
    int mark;
    for(int i = 0; i < this->students.size(); i++){
        if(this->students.at(i)==student){
            mark = i;
        }
    }
    auto it = this->students.begin();
    advance(it,mark);
    this->students.erase(it);
}

vector<Student> Class::getStudents(){
    return this->students;
}

/*public:
    Class(string ucCode, string classCode, string weekDay, double startHour, double duration, string type);
    Uc getUc();
    string getClass();
    void setUc(const Uc &uc);
    void addStudent(Student student);
    void removeStudent(Student student);
    vector<Student> getStudents();

private:
    Uc uc;
    vector<Student> students;
    string weekDay;
    double startHour;
    double duration;
    string type;
};
*/

