#ifndef WORKER_H
#define WORKER_H

#include "Officer.h"

class Worker : public Officer {
    public:
        // Constructor nhận đủ thông tin của cả Officer và Worker
        Worker(const string& name, int age, const string& gender, const string& address, int level);
        
        void setWorkerLevel(int level);

        // Thêm const vào cuối hàm cho biết rằng phương thức này không thay đổi bất kỳ thành viên nào của lớp.
        int getWorkerLevel() const;

    private:
        int workerLevel;

};

#endif