#include <iostream>
#include <vector>
#include "human/Student.h"
#include "human/Staff.h"
#include "human/Manager.h"

void rec(){
    string password = "password";
    string youEnter;
    cout<<"Please enter password:"<<endl;
    cin>>youEnter;
    if (youEnter==password){
        return;
    } else {
        cout<<"Wrong password"<<endl;
        cout<<"Please enter password:"<<endl;
        rec();
    }
}

int main() {
    string anyKey,info,name,job, group;
    int number, year;
    bool sex;
    float salary;
    Manager *manager = new Manager();
    manager->setName("Yura");
    Student *student = new Student();
    Room *room = new Room();
    Staff *staff = new Staff();
    Hostel *hostel = new Hostel();
    vector<Room> rooms = manager->loadRooms();
    vector<Staff> staffVector = manager->loadStaff();
    vector<Student> students = manager->loadStudents();

    rec();

    while (true){
        int flag = 0;
        cout<<"Enter 1 to add new student"<<endl;
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
                delete room,student,staff,hostel;
                return 1;
            case 1:
                cout<<"Enter name:"<<endl;
                cin>>name;
                cout<<"Enter group: "<<endl;
                cin>>group;
                cout<<"Enter room: "<<endl;
                cin>>number;
                student->setName(name);
                student->setGroup(group);
                student->setRoom(room->getRoomByNumber(number));
                manager->addStudent(*student);
                break;
            case 2:
                cout<<"Enter room`s name:    "<<endl;
                cin>>info;
                cout<<"Enter room`s number:  "<<endl;
                cin>>number;
                room->setName(info);
                room->setNumber(number);
                manager->addRoom(*room);
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
                manager->addStaff(*staff);
                break;
            case 4:
            menu:
                cout<<"Enter 1 to show staff"<<endl;
                cout<<"Enter 2 to show rooms"<<endl;
                cout<<"Enter 3 to show students"<<endl;
                cout<<"Enter 4 to show free rooms"<<endl;
                cout<<"Enter 0 to return"<<endl;
                cin>>flag;
                switch (flag){
                    default:
                        cout<<"Unknown command"<<endl;
                        goto menu;
                    case 0:
                        break;
                    case 1:
                        staffVector = manager->loadStaff();
                        for (int i = 0; i < staffVector.size(); ++i) {
                            cout<<"Name: "<<staffVector[i].getName()
                                <<"   Job: "<<staffVector[i].getJob()
                                <<"   Salary: "<<staffVector[i].getSalary()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        goto menu;
                    case 2:
                        rooms = manager->loadRooms();
                        for (int i = 0; i < rooms.size(); ++i) {
                            cout<<"Room number: "<<rooms[i].getNumber()
                                <<"   Info: "<<rooms[i].getName()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        goto menu;
                    case 3:
                        students = manager->loadStudents();
                        for (int i = 0; i < students.size(); ++i) {
                            cout<<"Name: "<<students[i].getName()
                                <<"   Group: "<<students[i].getGroup()
                                <<"   Room number: "<<students[i].getRoom().getNumber()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        goto menu;
                    case 4:
                        vector<Room> free = manager->freeRooms();
                        for (int i = 0; i < free.size(); ++i) {
                            cout<<"Number: "<<free[i].getNumber()
                                <<"   Info: "<<free[i].getName()<<endl;
                        }
                        cout<<"Press any key"<<endl;
                        cin>>anyKey;
                        goto menu;
                }
                break;
        }
    }
}