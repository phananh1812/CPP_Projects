#include <iostream>
#include "OfficerManagement.h"

using namespace std;

int main()
{
    OfficerManagement manager;

    cout << "OK";
    
    int choice;
    do {
        cout << "\n1. Thêm cán bộ mới\n2. Hiển thị danh sách\n3. Tìm tên\n0. Thoát\nChọn: ";
        cin >> choice;
        cin.ignore();           // Xử lý ký tự xuống dòng sau khi nhập số

        switch (choice) {
            case 1:
                manager.addNewOfficer();
                break;
            case 2:
                manager.displayOfficers();
                break;
            case 3:
                manager.searchOfficers();
                break;
            case 0:
                cout << "Thoát chương trình!\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ! Vui lòng nhập lại.\n";
        }
    } while (choice != 0);
    
}
