//
// Created by azozello on 09.05.17.
//

#ifndef CAMPUS2_MANAGER_H
#define CAMPUS2_MANAGER_H

#include <vector>
#include "Human.h"
#include "../area/Room.h"
#include "Student.h"
#include "Staff.h"

class Manager : public Human{
private:
    string password;
public:
    Manager(bool sex, const string &name, const string &password);
    Manager();

    const string &getPassword() const;
    void setPassword(const string &password);

    vector<Room> loadRooms();
    vector<Student> loadStudents();
    vector<Staff> loadStaff();
    vector<Room> freeRooms();

    void addRoom(Room room);
    void addStudent(Student student);
    void addStaff(Staff staff);
};


#endif //CAMPUS2_MANAGER_H
