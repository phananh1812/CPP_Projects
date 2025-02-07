#include <iostream>
#include "Worker.h"

using namespace std;

// Gọi constructor của Officer để khởi tạo các thuộc tính chung
Worker::Worker(const string& name, int age, const string& gender, const string& address, int level) 
    : Officer(name, age, gender, address), workerLevel(level) {}

// Nếu không có constructor, ta phải dùng setter
// -> Tạo một đối tượng Worker, rồi gọi setter để gán giá trị:

// worker->setName("John Doe");
// worker->setAge(30);
// worker->setGender("Male");
// worker->setAddress("New York");
// worker->setWorkerLevel(5);

// officers.push_back(move(worker));  // Thêm vào vector

void Worker::setWorkerLevel(int level) {
    workerLevel = level;
}

int Worker::getWorkerLevel() const {
    return workerLevel;
}