#ifndef ENGINEER_H
#define ENGINEER_H

#include <string>
#include "Officer.h"

using namespace std;

class Engineer : public Officer {
    public:
        // Constructor nhận đủ thông tin của cả Officer và Engineer
        Engineer(const string& name, int age, const string& gender, const string& address, string major);

        void setEngineerMajor(string major);

        // Thêm const vào cuối hàm cho biết rằng phương thức này không thay đổi bất kỳ thành viên nào của lớp.
        string getEngineerMajor() const;

    private:
        string engineerMajor;

};

#endif