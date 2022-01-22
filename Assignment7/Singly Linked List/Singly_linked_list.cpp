/*  Author: Ryan Russell
    Date: 11/13/19
    Section: CSCE-121-530
    UIN: 227006614
    E-mail: rhrussell@tamu.edu
    Assignment 7 Problem - Singly Linked List: creates a Singly Linked List
*/


//#include "student_structs.h"
//#include "singly_linked_list.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Student
{
    //member variables
    int studentID;
    double GPA;
    string major;
    bool record_status;

    Student() : studentID(0), GPA(0.0), major("CSCE"), record_status(true) {};
    Student(int newstudentID) : studentID(newstudentID), GPA(0.0), major("CSCE"), record_status(true) {};
    Student(int newstudentID, double newGPA) : studentID(newstudentID), GPA(newGPA), major("CSCE"), record_status(true) {};
    Student(int newstudentID, double newGPA, string newmajor) : studentID(newstudentID), GPA(newGPA), major(newmajor), record_status(true) {};
    Student(int newstudentID, double newGPA, string newmajor, bool newrecord_status) : studentID(newstudentID), GPA(newGPA), major(newmajor), record_status(newrecord_status) {};


    //dont need getter or setter functions because variables arent private

    Student* next;
};

ostream& operator<<(ostream& os, Student& stud)
{
    os << stud.studentID;
    return os;
}

void print(Student *stud)
{
    cout << stud->studentID << '\t' << stud->GPA << '\t' << stud->major << '\t' << stud->record_status << endl;
}

class InvalidInsert{};
class InvalidRemove{};

class Singly_linked_list
{
    public:
      
        struct Node
        {
            Student data;
            Node* next;
            Node(Student data) : data(data), next(NULL) {};
        };

        Student *head, *tail;

        Singly_linked_list() {head = NULL; tail = NULL; }
 
        void insert_first(Student stud)
        {
            Student *ptr = new Student(stud);

            if(head == NULL)
            { 
                head = ptr;
                head->next = NULL;
            }
            else
            {
                ptr->next = head; //says the next node is equal to head 
                head = ptr; //sets that pointer to point to head
            }
        }

        void insert_after(Student bef, Student stud)
        {
            Student *ptr = new Student(stud);
            Student *temp = new Student();
            temp = head;
            while(temp->studentID != bef.studentID)
            {
                temp = temp->next; //sets temp to the next node
            }
            //bef.next = temp;
            ptr->next = temp->next;
            temp->next = ptr;
        }

        void remove_first()
        {
            if(head == NULL)
            {
                //throw InvalidRemove("Invalid Removal");
            }
            Student *temp = head;
            head = head->next;
            free(temp);
            //return head;
        }

        void remove_after(Student stud)
        {
            Student *ptr = new Student(stud);
            Student *temp = new Student();
            temp = head;
            while(temp->studentID != ptr->studentID)
            {
                temp = temp->next;
            }
            Student *placeholder = temp->next->next;
            free(temp->next);
            temp->next = placeholder;
        }

        void print_list()
        {
            Student *temp = head;
            while(temp != NULL)
            {
                //temp = temp->next;
                cout << temp->studentID << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main()
{
    Singly_linked_list *lst = new Singly_linked_list();

    /*lst->print_list();

    Student stud0(0, 3, "CSCE", true);
    lst->insert_first(stud0);
    lst->print_list();

    Student stud1(1,2, "CSCE", false);
    lst->insert_first(stud1);
    lst->print_list();

    Student stud2(2, 3, "CSCE", true);
    lst->insert_first(stud2);
    lst->print_list();

    Student stud4(4, 3, "CSCE", true);
    lst->insert_first(stud4);
    lst->print_list();

    Student stud3(3, 3, "CSCE", true);
    lst->insert_after(stud4, stud3);
    lst->print_list();

    lst->remove_first();
    lst->print_list();

    lst->remove_after(stud3);
    lst->print_list();*/

    string fileName;
    fileName = "data.txt";
    ifstream ist;
    ist.open(fileName);
    if(!ist)
    {
        //perror("Can't Open Input File", fileName);
    }

    int id;
    double gpa;
    string major;
    bool status;
    string line;
    string stringID;
    string stringGPA;
    string stringStatus;
    
    for(int i = 0; i < 10; i++)
    {
        getline(ist, line);
        //cout << line << endl;
        istringstream iss(line);
        iss >> stringID;
        id = stoi(stringID);
        iss >> stringGPA;
        gpa = stod(stringGPA);
        iss >> major;
        iss >> stringStatus;
        if(stringStatus == "true")
        {
            status = true;
        }
        else
        {
            status = false;
        }
        
        
        //line >> id >> gpa >> major >> status;
        Student stud(id,gpa,major,status);
        //cout << stud << endl;
        lst->insert_first(stud);
    }

    lst->print_list();
}