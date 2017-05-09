#include <iostream>
#include <fstream>
#include <algorithm>
#include "../h/Hostel.h"

Hostel::Hostel() {}

inline bool space(char c){
    return std::isspace(c);
}

inline bool notspace(char c){
    return !std::isspace(c);
}

Room Hostel::getRoomByNumber(int number) {
    Room *room = new Room();
    vector<Room> all = loadRooms();
    for (int i = 0; i < all.size(); ++i) {
        if (all[i].getNumber()==number){
            return all[i];
        }
    }
    room->setInfo("New");
    room->setNumber(number);
    return *room;
}

vector<string> split(const string& s){
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = s.begin();
    while(i!=s.end()){
        i = find_if(i, s.end(), notspace);
        iter j = find_if(i, s.end(), space);
        if(i!=s.end()){
            ret.push_back(string(i, j));
            i = j;
        }
    }
    return ret;
}

vector<Room> Hostel::loadRooms() {
    vector<Room> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Campus/files/rooms.txt");
    int vectorIndex = 0;
    while(file) {
        Room *room = new Room();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                room->setInfo(temp[i]);
            } else if(i==1){
                room->setNumber(stoi(temp[i]));
            }
        }
        if (room->getInfo()!="") {
            result.insert(result.end(), *room);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

vector<Staff> Hostel::loadStaff() {
    vector<Staff> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Campus/files/staff.txt");
    int vectorIndex = 0;
    while(file) {
        Staff *staff = new Staff();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                staff->setName(temp[i]);
            } else if(i==1){
                staff->setJob(temp[i]);
            } else if(i==2){
                staff->setSalary(stof(temp[i]));
            }
        }
        if (staff->getName()!="") {
            result.insert(result.end(), *staff);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

vector<Student> Hostel::loadStudents() {
    vector<Student> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Campus/files/students.txt");
    int vectorIndex = 0;
    while(file) {
        Student *student = new Student();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                student->setName(temp[i]);
            } else if(i==1){
                student->setGroup(temp[i]);
            } else if(i==2){
                student->setYear(stoi(temp[i]));
            } else if(i==3){
                Room *room = new Room(stoi(temp[i]));
                student->setRoom(*room);
            }
        }
        if (student->getName()!="") {
            result.insert(result.end(), *student);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

vector<Teacher> Hostel::loadTeachers() {
    vector<Teacher> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Campus/files/teachers.txt");
    int vectorIndex = 0;
    while(file) {
        Teacher *teacher = new Teacher();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                teacher->setName(temp[i]);
            } else if(i==1){
                teacher->setStatus(temp[i]);
            } else if(i==2){
                Room *room = new Room(stoi(temp[i]));
                teacher->setRoom(*room);
            }
        }
        if (teacher->getName()!="") {
            result.insert(result.end(), *teacher);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

vector<Room> Hostel::freeRooms() {
    vector<Room> allRooms = loadRooms();
    vector<Student> students = loadStudents();
    vector<Teacher> teachers = loadTeachers();

    vector<Room> freeRooms;

    for (int i = 0; i < allRooms.size(); ++i) {
        int temp = 0;
        for (int j = 0; j < students.size(); ++j) {
            if (students[j].getRoom().getNumber()==allRooms[i].getNumber()){
                temp++;
            }
        }
        for (int j = 0; j < teachers.size(); ++j) {
            if (teachers[j].getRoom().getNumber()==allRooms[i].getNumber()){
                temp++;
            }
        }
        if (temp<5){
            freeRooms.insert(freeRooms.end(), allRooms[i]);
        }
    }
    return freeRooms;
}

void Hostel::saveRooms(vector<Room> rooms) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Campus/files/rooms.txt", ios::trunc);
    for (int i = 0; i < rooms.size(); ++i) {
        fout<<rooms[i].getInfo()<<" "<<rooms[i].getNumber()<<endl;
    }
    fout.close();
}

void Hostel::saveStudents(vector<Student> students) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Campus/files/students.txt",ios::trunc);
    for (int i = 0; i < students.size(); ++i) {
        fout<<students[i].getName()<<" "<<students[i].getGroup()<<" "<<students[i].getYear()<<" "<<students[i].getRoom().getNumber()<<endl;
    }
    fout.close();
}

void Hostel::saveStaff(vector<Staff> staff) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Campus/files/staff.txt",ios::trunc);
    for (int i = 0; i < staff.size(); ++i) {
        fout<<staff[i].getName()<<" "<<staff[i].getJob()<<" "<<staff[i].getSalary()<<endl;
    }
    fout.close();
}

void Hostel::saveTeachers(vector<Teacher> teachers) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Campus/files/teachers.txt",ios::trunc);
    for (int i = 0; i < teachers.size(); ++i) {
        fout<<teachers[i].getName()<<" "<<teachers[i].getStatus()<<" "<<teachers[i].getRoom().getNumber()<<endl;

    }
    fout.close();
}

void Hostel::addRoom(Room room) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Campus/files/rooms.txt",ios::app);
    fout<<room.getInfo()<<" "<<room.getNumber()<<endl;
    fout.close();
}

void Hostel::addStaff(Staff staff) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Campus/files/staff.txt",ios::app);
    fout<<staff.getName()<<" "<<staff.getJob()<<" "<<staff.getSalary()<<endl;
    fout.close();
}

void Hostel::addTeacher(Teacher teacher) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Campus/files/teachers.txt",ios::app);
    fout<<teacher.getName()<<" "<<teacher.getStatus()<<" "<<teacher.getRoom().getNumber()<<endl;
    fout.close();
}

void Hostel::addStudent(Student student) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Campus/files/students.txt",ios::app);
    fout<<student.getName()<<" "<<student.getGroup()<<" "<<student.getYear()<<" "<<student.getRoom().getNumber()<<endl;
    fout.close();
}


