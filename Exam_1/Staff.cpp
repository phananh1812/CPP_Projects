#include <iostream>
#include "Staff.h"

using namespace std;

Staff::Staff(const string& name, int age, const string& gender, const string& address, string job) 
    : Officer(name, age, gender, address), staffJob(job) {}

void Staff::setStaffJob(string job) {
    staffJob = job;
}

string Staff::getStaffJob() const {
    return staffJob;
}
