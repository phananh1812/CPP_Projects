#ifndef STAFF_H
#define STAFF_H

#include <string>
#include "Officer.h"

using namespace std;

class Staff : public Officer {
    public:
        // Constructor nhận đủ thông tin của cả Officer và Staff
        Staff(const string& name, int age, const string& gender, const string& address, string job);
        
        void setStaffJob(string job);

        // Thêm const vào cuối hàm cho biết rằng phương thức này không thay đổi bất kỳ thành viên nào của lớp.
        string getStaffJob() const;

    private:
        string staffJob;

};

#endif