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

## Statement of Work (SoW)

The project is developed using various data structures, including vectors, lists, stacks, queues, and binary search trees, to perform the following tasks:

1. Read and parse the given data into appropriate data structures.
2. Develop a schedule management system with a comprehensive set of functionalities.
3. Perform listings of data with sorting and filtering options.
4. Process requests for new registrations or updates to existing registrations.
5. Maintain a chronological record of all changes made to the system.
6. Include documentation for the implemented functions using Doxygen.

Additionally, the project allows for the implementation of other relevant functionalities as deemed necessary.

## Expected Results

The program allows for the registration and management of various entities, making use of both linear (vector, list, stack, queue) and hierarchical data structures (binary search tree). Important information is saved in files for future use. The program also includes documentation for the code, generated using Doxygen, and indicates the time complexity of the most relevant functions and algorithms.

---
### To run the project, run the following commands:
```
mkdir build
cd build
cmake ..
make
./aed_project
```

---

### Authors

Leonardo Garcia  
Marcel Medeiros  
Pedro Castro