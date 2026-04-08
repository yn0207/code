#include <iostream>
#include "Date.h"
using namespace std;

/*Đầu vào: Nhập từ bàn phím
Đầu ra: Gán giá trị hợp lệ cho iNgay, iThang, iNam
Chức năng: 
    - Nhập ngày, tháng, năm từ bàn phím và kiểm tra tính hợp lệ cơ bản
    - Kiểm tra kiểu dữ liệu (phải là số)
    - Ngày > 0, tháng từ 1-12, năm trong khoảng cho phép
    - Sau khi nhập xong, kiểm tra ngày có hợp lệ với tháng hay không*/
void Date::Nhap()
{
    //nhập ngày
    cout<<"Nhập ngày: ";
    while(true)
    {
        if(!(cin>>iNgay))//nhập không phải số
        {
            cout<<"Ngày không hợp lệ. Vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if(iNgay <= 0)//ngày > 0
        {
            cout<<"Ngày không hợp lệ. Vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else break;
    }
    //nhập tháng
    cout<<"Nhập tháng: ";
    while(true)
    {
        if(!(cin>>iThang))//nhập không phải số
        {
            cout<<"Tháng không hợp lệ. Vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if(iThang <= 0 || iThang > 12)//tháng từ 1->12
        {
            cout<<"Tháng không hợp lệ. Vui lòng nhập lại: ";
            cin.ignore(10000, '\n');
        }
        else break;
    }
    //nhập năm
    cout<<"Nhập năm: ";
    while(true)
    {
        if(!(cin>>iNam))//nhập không phải số
        {
            cout<<"Năm không hợp lệ. Vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if(iNam < 1000 || iNam > 2026)//giới hạn năm
        {
            cout<<"Năm không hợp lệ. Vui lòng nhập lại: ";
            cin.ignore(10000, '\n');
        }
        else break;
    }

    int maxDay;
    // xác định số ngày trong tháng
    switch(iThang)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDay = 31;
            break;

        case 4: case 6: case 9: case 11:
            maxDay = 30;
            break;

        case 2:
            if((iNam % 400 == 0) || (iNam % 4 == 0 && iNam % 100 != 0))
                maxDay = 29;
            else
                maxDay = 28;
            break;
    }
    while(iNgay > maxDay)
    {
        cout<<"Ngày không hợp lệ. Vui lòng nhập lại: ";
        cin>>iNgay;
    }
}
/*Đầu vào: Sử dụng dữ liệu trong đối tượng
Đầu ra: In ra màn hình ngày/tháng/năm
Chức năng: Xuất ngày tháng năm ra màn hình theo định dạng dd/mm/yyyy*/
void Date::Xuat()
{
    cout << iNgay << "/" << iThang << "/" << iNam;
}
/*Đầu vào: Sử dụng iNgay, iThang, iNam hiện tại
Đầu ra: Cập nhật lại iNgay, iThang, iNam thành ngày tiếp theo
Chức năng: Tính và cập nhật ngày kế tiếp của ngày hiện tại
    - Tăng ngày lên 1
    - Nếu vượt số ngày trong tháng → reset ngày, tăng tháng
    - Nếu tháng > 12 → reset tháng, tăng năm
*/
void Date::NgayThangNamTiepTheo()
{
    int maxDay;

    // xác định số ngày trong tháng
    switch(iThang)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDay = 31;
            break;

        case 4: case 6: case 9: case 11:
            maxDay = 30;
            break;

        case 2:
            if((iNam % 400 == 0) || (iNam % 4 == 0 && iNam % 100 != 0))
                maxDay = 29;
            else
                maxDay = 28;
            break;
    }
    iNgay++;
    if(iNgay > maxDay)//khi ngày vượt số ngày trong tháng
    {
        iNgay = 1;//reset ngày
        iThang++;//tăng tháng

        if(iThang > 12)//khi tháng lớn hơn 12
        {
            iThang = 1;//reset tháng
            iNam++;//tăng năm
        }
    }
}