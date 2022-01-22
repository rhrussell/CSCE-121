 #ifndef student_H
 #define student_H
 
 #include <string>
 #include <iostream>

 using namespace std;
 
 struct Student{

        //constructors
        Student();
        Student(int newstudentID);
        Student(int newstudentID, double newGPA);
        Student(int newstudentID, double newGPA, string newMajor);
        Student(int newstudentID, double newGPA, string newMajor, bool new_record_status);

        void print();

        //dont need getter or setter functions because variables arent private

        //member variables
        int studentID;
        double GPA;
        string major;
        bool record_status;

        Student* next;
 };

  bool operator==(Student& s1, Student& s2);

 #endif