// Officer.h
#ifndef OFFICER_H
#define OFFICER_H

#include <string>
using namespace std;

class Officer {
    public:
        // Constructor và Destructor (nếu cần thiết)
        // Officer();  // Constructor mặc định

        Officer(const string& name, int age, const string& gender, const string& address);

        // Lớp Officer cần có phương thức ảo (virtual ~Officer())
        // Biến Officer* có thể dùng dynamic_cast để kiểm tra kiểu thực tế.
        // Nếu không có hàm ảo, dynamic_cast sẽ báo lỗi vì không thể xác định kiểu động (runtime).

        virtual ~Officer() {}                   // Thêm hàm hủy ảo để đảm bảo hủy đúng lớp con
        // virtual void showInfo() const = 0;   // Thêm phương thức ảo thuần ảo (nếu muốn)

        // Phương thức Setter để nhập thông tin
        void setName(string name);
        void setAge(int age);
        void setGender(string gender);
        void setAddress(string address);

        // Phương thức Getter để lấy thông tin
        // Thêm const vào cuối hàm (getName() const) cho biết rằng phương thức này không thay đổi bất kỳ thành viên nào của lớp.
        string getName() const;
        int getAge() const;
        string getGender() const;
        string getAddress() const;
        void printOfficerInfo() const;

    private:
        string name;
        int age;
        string gender;
        string address;
};

#endif
