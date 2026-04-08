#include <iostream>
#include <iomanip>
#include "ThoiGian.h"
using namespace std;
/*
-Đầu vào: 
+ gio: giờ (0 → 23)
+ phut: phút (0 → 59)
+ giay: giây (0 → 59)
-Chức năng: Khởi tạo đối tượng thời gian với giá trị giờ, phút, giây ban đầu
*/
ThoiGian::ThoiGian(int gio, int phut, int giay)
{
    iGio = gio;
    iPhut = phut;
    iGiay = giay;
}
/*
-Đầu vào: nhập từ bàn phím giờ, phút, giây
-Đầu ra: gán giá trị cho iGio, iPhut, iGiay
-Chức năng: Nhập thời gian hợp lệ (giờ < 24, phút < 60, giây < 60), có kiểm tra dữ liệu
*/
void ThoiGian::Nhap()
{
    cout << "Nhập giờ, phút, giây: ";
    
    while(true)
    {
        if(!(cin >> iGio >> iPhut >> iGiay))
        {
            cout << "Dữ liệu không hợp lệ. Vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(100000, '\n');
        }
        else if(iGio < 0 || iGio >= 24 ||
                iPhut < 0 || iPhut >= 60 ||
                iGiay < 0 || iGiay >= 60)
        {
            cout << "Dữ liệu không hợp lệ. Vui lòng nhập lại: ";
            cin.ignore(100000, '\n');
        }
        else
        {
            break;
        }
    }
}
/*
-Đầu ra: In ra thời gian theo định dạng hh:mm:ss
-Chức năng: Hiển thị thời gian ra màn hình
*/
void ThoiGian::Xuat()
{
    cout << setfill('0')
         << setw(2) << iGio << ":"
         << setw(2) << iPhut << ":"
         << setw(2) << iGiay;
}
/*
-Đầu vào: sử dụng thời gian hiện tại
-Đầu ra: cập nhật lại iGio, iPhut, iGiay
-Chức năng: Tăng thời gian hiện tại lên 1 giây, tự động xử lý tràn:
+ 60 giây → tăng 1 phút
+ 60 phút → tăng 1 giờ
+ 24 giờ → quay về 00:00:00
*/
void ThoiGian::TinhCongThemMotGiay()
{
    iGiay++;
    if(iGiay == 60)
    {
        iGiay = 0;
        iPhut++;
        if(iPhut == 60)
        {
            iPhut = 0;
            iGio++;
            if(iGio == 24)
            {
                iGio = 0;
            }
        }
    }
}