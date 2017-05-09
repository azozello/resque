#include <iostream>
#include <vector>
#include "classes/h/Hostel.h"

using namespace std;

int main() {
    string anyKey,info,name,job, group;
    int number, year;
    bool sex;
    float salary;
    Student *student = new Student();
    Teacher *teacher = new Teacher();
    Room *room = new Room();
    Staff *staff = new Staff();
    Hostel *hostel = new Hostel();
    vector<Room> rooms = hostel->loadRooms();
    vector<Staff> staffVector = hostel->loadStaff();
    vector<Student> students = hostel->loadStudents();
    vector<Teacher> teachers = hostel->loadTeachers();
    while (true){
        int flag = 0;
        cout<<"Enter 1 to add new liver"<<endl;
        cout<<"Enter 2 to add new room"<<endl;
        cout<<"Enter 3 to add new staff"<<endl;
        cout<<"Enter 4 to show campus info"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        cin>>flag;
        switch (flag){
            default:
                cout<<"Unknown command"<<endl;
                break;
            case 0:
                delete room,teacher,student,staff,hostel;
                return 1;
            case 1:
                cout<<"Enter 1 to add teacher"<<endl;
                cout<<"Enter 2 to add student"<<endl;
                cin>>flag;
                switch (flag){
                    default:
                        break;
                    case 1:
                        cout<<"Enter name:"<<endl;
                        cin>>name;
                        cout<<"Enter status: "<<endl;
                        cin>>job;
                        cout<<"Enter room: "<<endl;
                        cin>>number;
                        teacher->setName(name);
                        teacher->setStatus(job);
                        teacher->setRoom(hostel->getRoomByNumber(number));
                        hostel->addTeacher(*teacher);
                        break;
                    case 2:
                        cout<<"Enter name:"<<endl;
                        cin>>name;
                        cout<<"Enter group: "<<endl;
                        cin>>group;
                        cout<<"Enter year: "<<endl;
                        cin>>year;
                        cout<<"Enter room: "<<endl;
                        cin>>number;
                        student->setName(name);
                        student->setGroup(job);
                        student->setYear(year);
                        student->setRoom(hostel->getRoomByNumber(number));
                        hostel->addStudent(*student);
                        break;
                }
                break;
            case 2:
                cout<<"Enter room`s info:    "<<endl;
                cin>>info;
                cout<<"Enter room`s number:  "<<endl;
                cin>>number;
                room->setInfo(info);
                room->setNumber(number);
                hostel->addRoom(*room);
                break;
            case 3:
                cout<<"Enter staff`s sex:    "<<endl;
                cin>>sex;
                cout<<"Enter staff`s name:   "<<endl;
                cin>>name;
                cout<<"Enter staff`s job:    "<<endl;
                cin>>job;
                cout<<"Enter staff`s salary: "<<endl;
                cin>>salary;
                staff->setSalary(salary);
                staff->setJob(job);
                staff->setName(name);
                staff->setSex(sex);
                hostel->addStaff(*staff);
                break;
            case 4:
                cout<<"Enter 1 to show staff"<<endl;
                cout<<"Enter 2 to show rooms"<<endl;
                cout<<"Enter 3 to show teachers"<<endl;
                cout<<"Enter 4 to show students"<<endl;
                cout<<"Enter 5 to show free rooms"<<endl;
                cout<<"Enter 0 to return"<<endl;
                cin>>flag;
                switch (flag){
                    default:
                        cout<<"Unknown command"<<endl;
                        break;
                    case 0:
                        break;
                    case 1:
                        staffVector = hostel->loadStaff();
                        for (int i = 0; i < staffVector.size(); ++i) {
                            cout<<"Name: "<<staffVector[i].getName()
                                <<"   Job: "<<staffVector[i].getJob()
                                <<"   Salary: "<<staffVector[i].getSalary()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        break;
                    case 2:
                        rooms = hostel->loadRooms();
                        for (int i = 0; i < rooms.size(); ++i) {
                            cout<<"Room number: "<<rooms[i].getNumber()
                                <<"   Info: "<<rooms[i].getInfo()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        break;
                    case 3:
                        teachers = hostel->loadTeachers();
                        for (int i = 0; i < teachers.size(); ++i) {
                            cout<<"Name: "<<teachers[i].getName()
                                <<"   Status: "<<teachers[i].getStatus()
                                <<"   Room number: "<<teachers[i].getRoom().getNumber()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        break;
                    case 4:
                        students = hostel->loadStudents();
                        for (int i = 0; i < students.size(); ++i) {
                            cout<<"Name: "<<students[i].getName()
                                <<"   Group: "<<students[i].getGroup()
                                <<"   Year: "<<students[i].getYear()
                                <<"   Room number: "<<students[i].getRoom().getNumber()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        break;
                    case 5:
                        vector<Room> free = hostel->freeRooms();
                        for (int i = 0; i < free.size(); ++i) {
                            cout<<"Number: "<<free[i].getNumber()
                                <<"   Info: "<<free[i].getInfo()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        break;
                }
                break;
        }
    }
}