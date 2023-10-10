#include "../inc/Schedule.h"

Schedule::Schedule(){
    
}

bool Schedule::classesCrash(Class &class1, Class &class2){
    if(class1.getWeekDay() == class2.getWeekDay()){
        if(class1.getStartHour() == class2.getStartHour()){
            if((class1.getType()=="TP" || class2.getType()=="TP") || (class1.getType()=="PL" || class2.getType()=="PL")){
                return false;
            } else return true;
        }else if((class1.getStartHour() < class2.getStartHour())&&(class1.getStartHour()+class1.getDuration() > class2.getStartHour())){
            if((class1.getType()=="TP" || class2.getType()=="TP") || (class1.getType()=="PL" || class2.getType()=="PL")){
                return false;
            } else return true;
        }else if((class1.getStartHour() > class2.getStartHour())&&(class2.getStartHour()+class2.getDuration() > class1.getStartHour())){
            if((class1.getType()=="TP" || class2.getType()=="TP") || (class1.getType()=="PL" || class2.getType()=="PL")){
                return false;
            } else return true;
        }
    }

    return true;
}

void Schedule::addClass(Class &class_){
    for(Class classes : this->studentClasses){
        if(classesCrash(classes,class_)){
            printf("Classes crashed!\n");
            return;
        }
    }
    this->studentClasses.push_back(class_);
    printf("Class added to student schedule!\n");
}

void Schedule::removeClass(Class &class_){
    int mark;
    for(int i = 0; i < this->studentClasses.size(); i++){
        if(this->studentClasses.at(i)==class_){
            mark = i;
        }
    }
    auto it = this->studentClasses.begin();
    advance(it,mark);
    this->studentClasses.erase(it);
}