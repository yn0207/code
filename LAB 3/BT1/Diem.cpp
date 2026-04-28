#define _USE_MATH_DEFINES 
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string.h>
#include "Diem.h"
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//Constructor mặc định
cDiem::cDiem(): x(0), y(0) {}; //Khởi tạo điểm tại góc toạ độ 

//Constructor có tham số
cDiem::cDiem(double x, double y) : x(x), y(y) {} //Khởi tạo điểm với giá trị truyền vào cho ra toạ độ (x,y)

//Getter lấy hoành độ
double cDiem::getX() const
{
    return x; // Trả về hoành độ của điểm 
}

//Getter lấy tung độ
double cDiem::getY() const
{
    return y; //Trả về tung độ của điểm
}

//Setter gán hoành độ
void cDiem::setX(double x)
{ 
    this->x = x; //Cập nhật giá trị hoành độ
}

//Setter gán tung độ
void cDiem::setY(double y)
{
    this->y = y; //Cập nhật giá trị tung độ
}

/*
Đầu vào: Nhập toạ độ x, y từ bàn phím
Đầu ra: Gán giá trị hợp lệ cho x, y
Chức năng: Kiểm tra hợp lệ, nhập lại nếu nhập sai
*/
void cDiem::Nhap()
{
    while(true)
    {
        cout << "Nhập x, y: ";
        cin >> x >> y;
        if(cin.fail())
        {
            cout << "Dữ liệu không hợp lệ. Vui lòng nhập lại!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else
        {
            cin.ignore(1000, '\n');
            break;
        }
    }
}

// Làm tròn 2 chữ số thập phân, bỏ số 0 và dấu chấm thừa ở cuối
string formatSo(double v)
{
    string s = to_string(round(v * 100) / 100);

    // xóa số 0 dư
    while (!s.empty() && s.back() == '0') s.pop_back();
    if (!s.empty() && s.back() == '.') s.pop_back();

    return s;
}

//Đầu ra: In ra điểm có toạ độ (x,y)
void cDiem::Xuat() const
{
    cout << "(" << formatSo(x) << "," << formatSo(y) << ")";
}

/*
Đầu vào: Nhập dx, dy (độ dời vị trí theo toạ độ x,y)
Đầu ra: Cập nhật lại toạ độ điểm
Chức năng: Tịnh tiến điểm trong mặt phẳng
*/
void cDiem::TinhTien(double dx, double dy)
{
    x += dx;
    y += dy;
}

/*
Đầu vào: Nhập hệ số tỉ lệ k
Đầu ra: Cập nhật lại toạ độ điểm
Chức năng: Phóng to / thu nhỏ điểm theo tỉ lệ
*/
void cDiem::TyLe(double k)
{
    x *= k;
    y *= k;
}
 
/*
Đầu vào: Nhập góc quay và tâm quay
Đầu ra: Cập nhật lại toạ độ điểm
Chức năng: Quay quanh góc và tâm quay cho trước
*/
void cDiem::Quay(double goc, const cDiem &O)
{
    double rad = goc * M_PI / 180;

    double x0 = x - O.getX();
    double y0 = y - O.getY();

    double xr = x0 * cos(rad) - y0 * sin(rad);
    double yr = x0 * sin(rad) + y0 * cos(rad);

    x = xr + O.getX();
    y = yr + O.getY();
}