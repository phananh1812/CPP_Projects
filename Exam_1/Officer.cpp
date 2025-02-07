

#include <iostream>
#include "Officer.h" 

using namespace std;

///////////
// Tạo Constructor mặc định nếu muốn có thể tạo đối tượng mà không cần truyền tham số
///////////
// Officer::Officer() : name(""), age(0), gender(""), address("") {}       // Constructor mặc định

Officer::Officer(const string& name, int age, const string& gender, const string& address) 
    : name(name), age(age), gender(gender), address(address) {}



// Tại sao cần Setter và Getter?
// - Bảo vệ dữ liệu: Không cho phép truy cập trực tiếp vào thuộc tính của lớp.
// - Kiểm soát dữ liệu: Có thể thêm logic kiểm tra trước khi gán giá trị.
// - Tính đóng gói (Encapsulation): Giúp mã nguồn dễ bảo trì hơn.

// Phương thức Setter để nhập thông tin
void Officer::setName(string inputName) {
    name = inputName;
}

void Officer::setAge(int inputAge) {
    age = inputAge;
}

void Officer::setGender(string inputGender) {
    gender = inputGender;
}

void Officer::setAddress(string inputAddress) {
    address = inputAddress;
}

// Phương thức Getter 
string Officer::getName() const {           // const ở cuối hàm cho biết rằng phương thức này không thay đổi bất kỳ thành viên nào của lớp.
    return name;
}

int Officer::getAge() const {
    return age;
}

string Officer::getGender() const {
    return gender;
}

string Officer::getAddress() const {
    return address;
}

void Officer::printOfficerInfo() const {
    cout << "Tên: " << name << "\n"
         << "Tuổi: " << age << "\n"
         << "Giới tính: " << gender << "\n"
         << "Địa chỉ: " << address << "\n";
}


///////////
// Khi nào sử dụng this?
///////////
// void setName(string name) {  
//     this->name = name;               // Không bị xung đột khi trùng tên biến truyền vào hàm
// }