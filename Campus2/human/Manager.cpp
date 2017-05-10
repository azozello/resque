#include <algorithm>
#include <fstream>
#include "Manager.h"

Manager::Manager() {}

Manager::Manager(bool sex, const string &name, const string &password) : Human(sex, name), password(password) {}

const string &Manager::getPassword() const {
    return password;
}

void Manager::setPassword(const string &password) {
    Manager::password = password;
}

inline bool space(char c){
    return std::isspace(c);
}

inline bool notspace(char c){
    return !std::isspace(c);
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

vector<Room> Manager::loadRooms() {
    vector<Room> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Campus2/data/rooms.txt");
    int vectorIndex = 0;
    while(file) {
        Room *room = new Room();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                room->setName(temp[i]);
            } else if(i==1){
                room->setNumber(stoi(temp[i]));
            }
        }
        if (room->getName()!="") {
            result.insert(result.end(), *room);
        }
        vectorIndex++;
    }
    file.close();
    return result;
}

vector<Staff> Manager::loadStaff() {
    vector<Staff> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Campus2/data/staff.txt");
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

vector<Student> Manager::loadStudents() {
    vector<Student> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Campus2/data/students.txt");
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
                Room *room = new Room();
                room->setNumber(stoi(temp[i]));
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

vector<Room> Manager::freeRooms() {
    vector<Room> allRooms = loadRooms();
    vector<Student> students = loadStudents();

    vector<Room> freeRooms;

    for (int i = 0; i < allRooms.size(); ++i) {
        int temp = 0;
        for (int j = 0; j < students.size(); ++j) {
            if (students[j].getRoom().getNumber()==allRooms[i].getNumber()){
                temp++;
            }
        }
        if (temp<5){
            freeRooms.insert(freeRooms.end(), allRooms[i]);
        }
    }
    return freeRooms;
}

void Manager::addRoom(Room room) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Campus2/data/rooms.txt",ios::app);
    fout<<room.getName()<<" "<<room.getNumber()<<endl;
    fout.close();
}

void Manager::addStaff(Staff staff) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Campus2/data/staff.txt",ios::app);
    fout<<staff.getName()<<" "<<staff.getJob()<<" "<<staff.getSalary()<<endl;
    fout.close();
}

void Manager::addStudent(Student student) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Campus2/data/students.txt",ios::app);
    fout<<student.getName()<<" "<<student.getGroup()<<" "<<student.getRoom().getNumber()<<endl;
    fout.close();
}