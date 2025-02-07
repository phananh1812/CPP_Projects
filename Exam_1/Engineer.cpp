#include <iostream>
#include "Engineer.h"

using namespace std;

Engineer::Engineer(const string& name, int age, const string& gender, const string& address, string major) 
    : Officer(name, age, gender, address), engineerMajor(major) {}

void Engineer::setEngineerMajor(string major) {
    engineerMajor = major;
}

string Engineer::getEngineerMajor() const {
    return engineerMajor;
}
