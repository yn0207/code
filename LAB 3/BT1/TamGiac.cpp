#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>
#include <iomanip>
#include "TamGiac.h"
#include "Diem.h"
using namespace std;


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//Constructor mặc định
cTamGiac::cTamGiac(): A(0,0), B(0,1), C(1,0) {}; //Tạo tam giác với 3 điểm A(0,0); B(0,1); C(1,0);

/*
Constructor có tham số
Đầu vào: 3 điểm a, b, c
Đầu ra: Tam giác với 3 điểm tương đương
Chức năng: Khởi tạo tam giác với 3 điểm cho trước
*/
cTamGiac::cTamGiac(cDiem a, cDiem b, cDiem c): A(a), B(b), C(c) {}; 

/*
Constructor có tham số
Đầu vào: Nhập 6 toạ độ cho 3 điểm
Đầu ra: Tam giác từ 6 toạ độ
Chức năng: Khởi tạo tam giác với 6 toạ độ vừa nhập
*/
cTamGiac::cTamGiac(double ax, double ay, double bx, double by, double cx, double cy): A(ax, ay), B(bx, by), C(cx, cy) {};

//Destructor
cTamGiac::~cTamGiac() {}; //Giải phóng bộ nhớ

//Getter lấy điểm A
cDiem cTamGiac::getA() const
{
    return A; //Trả về điểm A
}

//Getter lấy điểm B
cDiem cTamGiac::getB() const
{
    return B; //Trả về điểm B
}

//Getter lấy điểm C
cDiem cTamGiac::getC() const
{
    return C; //Trả về điểm C
}

//Setter gán 3 điểm 
void cTamGiac::Set(cDiem a, cDiem b, cDiem c)
{
    //Cập nhật lại A, B, C
    A = a;
    B = b;
    C = c;
}

//Setter gán 6 toạ độ
void cTamGiac::Set(double ax, double ay, double bx, double by, double cx, double cy)
{
    //Cập nhật lại A, B, C
    A = cDiem(ax, ay);
    B = cDiem(bx, by);
    C = cDiem(cx, cy);
}

/*
Đầu vào: tg - đối tượng tam giác nguồn
Đầu ra: Trả về tham chiếu đến đối tượng hiện tại
Chức năng: 
- Gán nội dung của tg vào đối tượng hiện tại
- Tự kiểm tra gán cho chính mình để tránh xoá dữ liệu nguồn
*/
cTamGiac& cTamGiac::operator = (const cTamGiac& tg)
{
    if(this != &tg)
    {
        A = tg.A;
        B = tg.B;
        C = tg.C;
    }
    return *this;
}

/*
Đầu vào: Nhập điểm P, Q
Đầu ra: Khoảng cách giữa 2 điểm P, Q
Chức năng: Tính khoảng cách giữa 2 điểm
*/
double cTamGiac::KhoangCach(const cDiem &P, const cDiem &Q) const
{
    return sqrt(pow((P.getX() - Q.getX()), 2) + pow((P.getY() - Q.getY()), 2));
}

/*
Đầu ra: True / False
Chức năng: Kiểm tra điều kiện tam giác có hợp lệ không
*/
bool cTamGiac::HopLe() const
{
    double a = KhoangCach(B, C);
    double b = KhoangCach(A, C);
    double c = KhoangCach(A, B);
    return(a + c > b && a + b > c && b + c > a);
}

/*
Đầu vào: Nhập 3 điểm tam giác tù bàn phím
Đầu ra: Gán giá trị hợp lệ cho tam giác
Chức năng: Nhập và kiểm tra xem tam giác đó có hợp lệ không
*/
void cTamGiac::Nhap()
{
    while(true)
    {
        cout << "Nhập toạ độ A:\n";
        A.Nhap();
        cout << "Nhập toạ độ B:\n";
        B.Nhap();
        cout << "Nhập toạ độ C:\n";
        C.Nhap();
        if(!HopLe())
        {
            cout << "Ba điểm không tạo thành tam giác. Vui lòng nhập lại!";
            cout << endl;
        }
        else break;
    }
}

/*
Đầu ra: 3 điểm của tam giác
*/
void cTamGiac::Xuat() const
{
    cout << "A";
    A.Xuat();
    cout << endl;
    cout << "B";
    B.Xuat();
    cout << endl;
    cout << "C";
    C.Xuat();
    cout << endl;
}

/*
Đầu ra: Chu vi tam giác
*/
double cTamGiac::ChuVi() const
{
    double a = KhoangCach(B, C);
    double b = KhoangCach(A, C);
    double c = KhoangCach(A, B);
    return a + b + c;
}

/*
Đầu ra: Diện tích tam giác
*/
double cTamGiac::DienTich() const
{
    double a = KhoangCach(B, C);
    double b = KhoangCach(A, C);
    double c = KhoangCach(A, B);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

/*
Đầu ra: In ra loại tam giác
Chức năng: Kiểm tra tam giác thuộc loại nào
*/
void cTamGiac::KiemTraLoai() const
{
    if(!HopLe())
    {
        cout << "Không phải tam giác\n";
        return;
    }

    double a = KhoangCach(B, C);
    double b = KhoangCach(A, C);
    double c = KhoangCach(A, B);

    // Tính 3 góc bằng định lý cosine, đổi sang độ
    double gocA = acos((b*b + c*c - a*a) / (2*b*c)) * 180.0 / M_PI;
    double gocB = acos((a*a + c*c - b*b) / (2*a*c)) * 180.0 / M_PI;
    double gocC = acos((a*a + b*b - c*c) / (2*a*b)) * 180.0 / M_PI;
 
    // Làm tròn đến 2 chữ số thập phân 
    gocA = round(gocA * 100) / 100;
    gocB = round(gocB * 100) / 100;
    gocC = round(gocC * 100) / 100;
 
    // Kiểm tra có góc nào bằng 90 độ không
    bool coGocVuong = (gocA == 90 || gocB == 90 || gocC == 90);
 
    // Kiểm tra có 2 góc nào bằng nhau không (tam giác cân)
    bool coHaiGocBang = (gocA == gocB || gocB == gocC || gocA == gocC);
 
    if(gocA == 60 && gocB == 60 && gocC == 60)
        cout << "Tam giác đều\n";
    else if(coGocVuong && coHaiGocBang)
        cout << "Tam giác vuông cân\n";
    else if(coGocVuong)
        cout << "Tam giác vuông\n";
    else if(coHaiGocBang)
        cout << "Tam giác cân\n";
    else
        cout << "Tam giác thường\n";
}

/*
Đầu vào: Nhập dx, dy (độ dời vị trí theo toạ độ x,y)
Đầu ra: Cập nhật lại vị trí 3 điểm
Chức năng: Tịnh tiến tam giác trong mặt phẳng
*/
void cTamGiac::TinhTien(double dx, double dy)
{
    A.TinhTien(dx, dy);
    B.TinhTien(dx, dy);
    C.TinhTien(dx, dy);
}

/*
Đầu vào: Nhập hệ số tỉ lệ k
Đầu ra: Cập nhật lại toạ độ 3 điểm
Chức năng: Phóng to / thu nhỏ tam giác theo tỉ lệ
*/
void cTamGiac::TyLe(double k)
{
    A.TyLe(k);
    B.TyLe(k);
    C.TyLe(k);
}

/*
Đầu vào: Nhập góc quay và tâm quay
Đầu ra: Cập nhật lại toạ độ điểm
Chức năng: Quay tam giác quanh góc và tâm quay cho trước
*/
void cTamGiac::Quay(double goc, const cDiem& O)
{
    A.Quay(goc, O);
    B.Quay(goc, O);
    C.Quay(goc, O);
}
