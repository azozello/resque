//
// Created by azozello on 08.05.17.
//

#include "../h/Staff.h"

Staff::Staff() {}

const string &Staff::getJob() const {
    return job;
}

void Staff::setJob(const string &job) {
    Staff::job = job;
}

float Staff::getSalary() const {
    return salary;
}

void Staff::setSalary(float salary) {
    Staff::salary = salary;
}

Staff::Staff(bool sex, const string &name, const string &job, float salary) : Human(sex, name), job(job),
                                                                              salary(salary) {}
