#include <iostream>
#include "OfficerManagement.h"
#include "Officer.h"    // Cần include ở đây để biết Officer là gì
#include "Worker.h" 
#include "Engineer.h" 
#include "Staff.h" 

using namespace std;

void OfficerManagement::addNewOfficer() {
    char userChoice;
    string inputName, inputGender, inputAddress;
    int type, inputAge;

    Officer newOfficer("", 0, "", "");     // Khai báo bên ngoài vòng lặp -> Bộ nhớ không được cấp phát lại -> Cùng một đối tượng được cập nhật liên tục.

    do {
        // Officer newOfficer;    // Khai báo bên trong -> Bộ nhớ được cấp phát lại -> Mỗi vòng lặp tạo 1 bản ghi riêng, mọi phần tử trong vector có cùng giá trị cuối cùng của newOfficer.

        // Chọn loại cán bộ
        cout << "Chọn loại cán bộ: \n";
        cout << "1. Công nhân\n";
        cout << "2. Kỹ sư\n";
        cout << "3. Nhân viên\n";
        cin >> type;
        cin.ignore();

        cout << "Nhập tên: ";
        getline(cin, inputName);
        newOfficer.setName(inputName);

        cout << "Nhập tuổi: ";
        cin >> inputAge;
        cin.ignore();
        newOfficer.setAge(inputAge);

        cout << "Nhập giới tính: ";
        getline(cin, inputGender);
        newOfficer.setGender(inputGender);

        cout << "Nhập địa chỉ: ";
        getline(cin, inputAddress);
        newOfficer.setAddress(inputAddress);

        // Nhập thông tin riêng và tạo đối tượng
        if (type == 1) {  
            int level;
            cout << "Nhập bậc (1-10): ";
            cin >> level;
            cin.ignore();

            // make_unique<T>(...) là hàm tạo một con trỏ thông minh unique_ptr<T> và cấp phát bộ nhớ động cho đối tượng kiểu T.
            officers.push_back(make_unique<Worker>(inputName, inputAge, inputGender, inputAddress, level));

        } else if (type == 2) {  
            string major;
            cout << "Nhập ngành đào tạo: ";
            getline(cin, major);

            officers.push_back(make_unique<Engineer>(inputName, inputAge, inputGender, inputAddress, major));

        } else if (type == 3) {  
            string job;
            cout << "Nhập công việc: ";
            getline(cin, job);

            officers.push_back(make_unique<Staff>(inputName, inputAge, inputGender, inputAddress, job));

        } else {
            cout << "Lựa chọn không hợp lệ!\n";
            continue;  // Quay lại vòng lặp nếu nhập sai
        }

    } while (userChoice == 'y' || userChoice == 'Y');
}

void OfficerManagement::displayOfficers() {
    if (officers.empty()) {
        cout << "Không có sĩ quan nào trong danh sách." << endl;
        return;
    }

    cout << "\nDanh sách sĩ quan:\n";

    // auto: Giúp trình biên dịch tự động suy luận kiểu dữ liệu của officer (ở đây là Officer).
    // & (tham chiếu): Giúp tránh sao chép toàn bộ đối tượng Officer, chỉ sử dụng tham chiếu đến phần tử trong vector để tiết kiệm bộ nhớ và tăng hiệu suất.

    // for (const auto officer : officers) {  // officer là một bản sao
    // Mỗi lần lặp, một bản sao của Officer được tạo ra → tốn thêm bộ nhớ và thời gian.

    // Chúng ta đang sử dụng vector chứa unique_ptr<Officer>, nên officer trong vòng lặp là 
    // một con trỏ thông minh (unique_ptr<Officer>), không phải đối tượng Officer trực tiếp.

    for (const auto& officer : officers) {
        printOfficerDetails(officer);
    }
}



void OfficerManagement::searchOfficers() {
    string searchName;
    cout << "Nhập tên cần tìm: ";
    getline(cin, searchName);
            
    for (const auto& officer : officers) {
        if (officer->getName() == searchName) {
            cout << "\n" << "Tìm thấy thông tin: " << "\n";
            printOfficerDetails(officer);
            
            return;
        }
    }
    cout << "Không tìm thấy ai có tên: " << searchName << "\n";

}

void OfficerManagement::printOfficerDetails(const unique_ptr<Officer>& officer) const {
    officer->printOfficerInfo();
    if (auto worker = dynamic_cast<Worker*>(officer.get())) {
        cout << "Bậc thợ: " << worker->getWorkerLevel() << "\n";
    } else if (auto engineer = dynamic_cast<Engineer*>(officer.get())) {
        cout << "Ngành đào tạo: " << engineer->getEngineerMajor() << "\n";
    } else if (auto staff = dynamic_cast<Staff*>(officer.get())) {
        cout << "Công việc: " << staff->getStaffJob() << "\n";
    }
    cout << "--------------------------\n";
}

