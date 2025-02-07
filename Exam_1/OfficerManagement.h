#ifndef OFFICERMANAGEMENT_H
#define OFFICERMANAGEMENT_H

#include <vector>
#include <memory>  // Thêm để dùng unique_ptr
#include "Officer.h"

// class Officer;  // Forward declaration, không cần biết chi tiết Officer, chỉ cần khai báo rằng Officer tồn tại

class OfficerManagement {
    public:
        void addNewOfficer();
        void displayOfficers();
        void searchOfficers();

    private:
        // Đa hình → Dùng std::vector<std::unique_ptr<Officer>> (tốt nhất, tránh rò rỉ bộ nhớ).
        // Nếu cần chia sẻ đối tượng → Dùng std::vector<std::shared_ptr<Officer>> (quản lý bộ nhớ tự động).
        // Không nên dùng con trỏ thô - std::vector<Officer*> (dễ rò rỉ bộ nhớ nếu quên delete).

        vector<unique_ptr<Officer>> officers;
        void printOfficerDetails(const unique_ptr<Officer>& officer) const; // Đặt làm private
};

#endif

/*
- Nếu dùng vector<Officer> officers thì bộ nhớ sẽ được lưu:

Stack:
----------------------------------------------------------
| officers (vector chứa trực tiếp các đối tượng Officer)   |
| - Officer("Ali", 32, "Male", "London")                   |
| - Officer("Omar", 28, "Male", "Paris")                   |
| - Officer(Hassan) (Chỉ giữ phần `Officer`, mất `Worker`) |
| - Officer(Ben) ( mất `Staff`)                            |
----------------------------------------------------------

Heap: (Trống, trừ khi `vector` mở rộng)

----------------------------------------------------------
|                                                           |
|                                                           |
|                                                           |
|                                                           |
|                                                           |
----------------------------------------------------------

* Không thể đa hình vì toàn bộ phần tử trong vector được lưu là Officer. Nó chỉ biết "name, age, gender, address" mà không biết level là gì.

==> Do đó cần sử dụng con trỏ (unique_ptr<Officer>), lúc này vector chỉ lưu địa chỉ của đối tượng gốc được cấp phát trên Heap, thay vì lưu trực tiếp Officer.

#########################

- Khi dùng 
    vector<unique_ptr<Officer>> officers;
    officers.push_back(make_unique<Worker>(inputName, inputAge, inputGender, inputAddress, level));
thì bộ nhớ sẽ được lưu:

Stack:
--------------------------------------------------------------
| officers (vector chứa unique_ptr)                           |
| - unique_ptr<Officer> -> (Heap: Object Ali)                 | ví dụ giá trị pointer: 0x60200000f890
| - unique_ptr<Officer> -> (Heap: Object Omar)                |
| - unique_ptr<Officer> -> (Heap: Object Hassan - Worker)     |
| - unique_ptr<Officer> -> (Heap: Object Ben - Staff)         |
--------------------------------------------------------------

Heap:
--------------------------------------------------------------
| Officer("Ali", 32, "Male", "London")                        | thì address ở đây: 0x60200000f890
| Officer("Omar", 28, "Male", "Paris")                        |
| Worker("Hassan", 35, "Male", "Kabul", 5)                    |
| Staff("Ben", 37, "Male", "New York", IT)                    |
--------------------------------------------------------------


Để tìm thông tin ngược lại ta dùng:
    auto worker = dynamic_cast<Worker*>(officer.get());

Bộ nhớ sau khi thực hiện:

Stack:
--------------------------------------------------------------
| officer (unique_ptr<Officer>) -> (Heap: Worker Hassan)      | 0x60200000f8C0
| worker (Worker*) -> (Heap: Worker Hassan)                   | 0x60200000f8C0
--------------------------------------------------------------

Heap:
--------------------------------------------------------------
| Worker("Hassan", 35, "Male", "Kabul", 5)                    | 0x60200000f8C0
--------------------------------------------------------------

Giải thích:
    officer.get() trả về con trỏ Officer* đang quản lý.
    dynamic_cast<Worker*> kiểm tra xem đối tượng được trỏ đến có phải Worker không. Nếu đúng, nó cast về Worker*.
    worker bây giờ là một con trỏ thuần (Worker*), trỏ đến cùng vùng nhớ như officer.get() và có thể truy cập các phương thức của Worker.
*/




