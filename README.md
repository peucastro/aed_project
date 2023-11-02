# L.EIC Schedules Management System

The L.EIC Schedules Management System project was developed for the Algorithms and Data Structures course in the 2023/24 academic year of the 2nd year of L.EIC at FEUP.

## Project Description

Elaborating schedules for L.EIC classes can be a complex task. The purpose of this project is not the creation of the schedules, but rather the development of a system to manage schedules after they have been elaborated. The system must include various functionalities related to schedules, such as modifying, searching, viewing, sorting, listing, among others.


## Dataset

The project uses a provided dataset available in `schedule.zip`, which contains real information about L.EIC's schedules for the 1st semester of the academic year 2022/2023 with anonymized student data. The dataset is split into three CSV files:

1. `classes_per_uc.csv`: Contains the existing classes in each course unit (UC).
2. `classes.csv`: Contains the schedules of classes.
3. `students_classes.csv`: Contains the classes of the students in each UC.

The dataset provides information about classes, students, and their schedules, which is essential for the functionality of the system.


## Classes

### Uc Class

The `Uc` class represents a course unit (UC) and provides methods for managing UC information.

### Student Class

The `Student` class represents a student and provides methods for managing student information, including their schedule.

### Lecture Class

The `Lecture` class represents a class lecture and includes information about the UC, class code, students enrolled, day, start time, duration, and lecture type.

### Script Class

The `Script` class reads and processes data from CSV files, allowing the system to handle students and their schedules.

### Request Class

The `Request` class handles various operations related to student enrollments, including adding, removing, and switching courses and classes.


## Results

The program allows for the registration and management of various entities, making use of both linear (vector, list, stack, queue) and hierarchical data structures (binary search tree). Important information is saved in files for future use. The program also includes documentation for the code, generated using Doxygen, and indicates the time complexity of the most relevant functions and algorithms.


### To run the project, run the following commands:
```
mkdir build
cd build
cmake ..
make
./aed_project
```

#### All documentation can be found inside the docs folder

#### To access the Adminstrator area, use the following login and password:
|Login  |Password|
|-------|--------|
|adm    |123     |


---

### Authors

Leonardo Garcia  
Marcel Medeiros  
Pedro Castro
