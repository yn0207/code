#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>
#include <iomanip>
#include "DaGiac.h"
#include "Diem.h"
using namespace std;


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/*
Đầu vào: Nhập đối tượng điểm P, Q
Đầu ra: Khoảng cách giữa 2 điểm P, Q
Chức năng: Tính khoảng cách giữa 2 điểm
*/
double cDaGiac::KhoangCach(const cDiem& P, const cDiem& Q) const
{
    double dx = P.getX() - Q.getX();
    double dy = P.getY() - Q.getY();
    return sqrt((dx * dx) + (dy * dy));
}

//Kiểm tra n>=3 và diện tích khác 0
bool cDaGiac::HopLe() const
{
    if(n < 3) return false;
    if(n >= 3 && DienTich() == 0) return false;
    //Kiểm tra khoảng cách giữa 2 điểm có trùng nhau không
    for(int i = 0; i < n; i++)
    {
        if(KhoangCach(ds[i], ds[(i+1)%n]) == 0) return false;
    }
    return true;
}

//Constructor mặc định
cDaGiac::cDaGiac(): ds(NULL), n(0) {}; //Khởi tạo đa giác rỗng: ds = NULL, n = 0

//Constructor có tham số
//Tạo một đa giác từ danh sách các điểm được truyền vào
cDaGiac::cDaGiac(int soCanh, cDiem* dsDiem)
{
    n = soCanh;
    ds = new cDiem[n]; 
    for(int i = 0; i < n; i++)
        ds[i] = dsDiem[i]; 
}

//Copy Constructor - tạo đa giác mới là bản sao của dg
cDaGiac::cDaGiac(const cDaGiac& dg)
{
    n = dg.n;
    ds = new cDiem[n];
    for(int i = 0; i < n; i++)
       ds[i] = dg.ds[i];
}

//Destructor - giải phóng bộ nhớ động của mảng ds
cDaGiac::~cDaGiac()
{
    delete[] ds;
}

/*
Đầu vào: dg - đối tượng tam giác nguồn
Đầu ra: Trả về tham chiếu đến đối tượng hiện tại
Chức năng: 
- Gán nội dung của dg vào đối tượng hiện tại
- Tự kiểm tra gán cho chính mình để tránh xoá dữ liệu nguồn
*/
cDaGiac& cDaGiac::operator = (const cDaGiac& dg)
{
    if(this != &dg)
    {
        delete[] ds;
        n = dg.n;
        ds = new cDiem[n];
        for(int i = 0; i < n; i++)
           ds[i] = dg.ds[i];
    }
    return *this;
}

/*
Đầu vào: soCanh - số đỉnh mới
         dsDiem - mảng đỉnh mới
Chức năng:
- Giải phóng bộ nhứo cũ trước khi cấp phát lại
- Gán lại dữ liệu cho đa giác từ mảng đỉnh mới
*/
void cDaGiac::Set(int soCanh, cDiem* dsDiem)
{
    delete[] ds;
    n = soCanh;
    ds = new cDiem[n];
    for(int i = 0; i < n; i++)
       ds[i] = dsDiem[i];
}

//Getter lấy số cạnh
int cDaGiac::getSoCanh() const
{
    return n; //Trả về số cạnh(= số đỉnh) của đa giác
}

/*
Đầu vào: chỉ số đỉnh i
Đầu ra: Trả về danh sách đỉnh 
Chức năng: Trả về đỉnh thứ i của đa giác
*/
cDiem cDaGiac::getDinh(int i) const
{
    return ds[i];
}

/*
Đầu vào: Nhập dữ liệu đa giác từ bàn phím
Đầu ra: Gán giá trị hợp lệ cho n và danh sách đối tượng
Chức năng: Nhập và kiểm tra đa giác dó hợp lệ không
*/
void cDaGiac::Nhap()
{
    while(true)
    {
        cout << "Nhập số đỉnh: ";
        cin >> n;
        if(cin.fail() || n < 3)
        {
            cout << "\nSố đỉnh không hợp lệ. Vui lòng nhập lại!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        delete[] ds;
        ds = new cDiem[n];
        for(int i = 0; i < n; i++)
        {
            cout << "\nNhập đỉnh thứ " << i+1 << ":\n";
            ds[i].Nhap();
        }
        
        if(!HopLe())
        {
            cout << "Các đỉnh không tạo thành đa giác. Vui lòng nhập lại!\n";
            continue;
        }
        break;
    }
}

//Xuất thông tin các đỉnh của đa giác ra màn hình
void cDaGiac::Xuat() const
{
    cout << "Đa giác có " << n << " đỉnh:\n";
    for(int i = 0; i < n; i++)
    {
        cout << " D" << i+1;
        ds[i].Xuat();
        cout <<  endl;
    }
}

//Đầu ra: Chu vi đa giác
double cDaGiac::ChuVi() const
{
    double cv = 0;
    for(int i = 0; i < n; i++)
      cv += KhoangCach(ds[i] , ds[(i+1) % n]);
    return cv;
}

//Đầu ra: Diện tích đa giác 
double cDaGiac::DienTich() const
{
    double s = 0;
    for(int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        //Công thức Shoelace (Gauss)
        s += ds[i].getX() * ds[j].getY();
        s -= ds[j].getX() * ds[i].getY();
    }

    return fabs(s) / 2.0;
}

// Lồi: tất cả tích có hướng (cross product) của hai cạnh liên tiếp cùng dấu
bool cDaGiac::LaLoi() const
{
    if(!HopLe()) return false;
    if(n == 3) return true;
    int sign = 0;
    for(int i = 0; i < n; i++)
    {
        int j = (i+1) % n;
        int k = (i+2) % n;

        double dx1 = ds[j].getX() - ds[i].getX();
        double dy1 = ds[j].getY() - ds[i].getY();
        double dx2 = ds[k].getX() - ds[j].getX();
        double dy2 = ds[k].getY() - ds[j].getY();

        double cross = dx1 * dy2 - dy1 * dx2; //Tích có hướng

        if (cross != 0)
        {
            int s = (cross > 0) ? 1 : -1;
            if (sign == 0)
                sign = s;
            else if (sign != s)
                return false;
        }
    }
    return true;
}

bool cDaGiac::LaLom() const
{
    return HopLe() && !LaLoi();
}

//Tính góc tại đỉnh thứ i
double cDaGiac::GocTaiDinh(int i) const
{
    int prev = (i-1+n) % n;
    int next = (i+1) % n;
    const cDiem& A = ds[prev];
    const cDiem& B = ds[i];
    const cDiem& C = ds[next];

    double ux = A.getX() - B.getX();
    double uy = A.getY() - B.getY();
    double vx = C.getX() - B.getX();
    double vy = C.getY() - B.getY();

    //Độ dài vecto
    double tu = sqrt(ux * ux + uy * uy);
    double tv = sqrt(vx * vx + vy * vy);
    if(tu == 0 || tv == 0)
       return 0.0;
    
    double dot = ux * vx + uy * vy; //Tích vô hướng
    double cosTheta = dot / (tu * tv); //Tính góc
    cosTheta = max(-1.0, min(1.0, cosTheta));

    return acos(cosTheta); //Trả về giá trị radian
}

//Đều: tất cả các cạnh và tất cả các góc đều bằng nhau
bool cDaGiac::LaDeu() const
{
    //Kiểm tra cạnh
    if(!HopLe()) return false;
    double canh0 = KhoangCach(ds[0], ds[1]);
    for(int i = 1; i < n; i++)
    {
        if(KhoangCach(ds[i], ds[(i+1) % n]) != canh0)
           return false;
    }

    //Kiểm tra góc
    double goc0 = GocTaiDinh(0);
    for(int i = 0; i < n; i++)
    {
        if(GocTaiDinh(i) != goc0)
        return false;
    }
    return true;
}

/*
Đầu ra: In ra các loại đa giác
Chức năng: Kiểm tra đa giác thuộc loại nào
*/
void cDaGiac::KiemTraLoai() const
{
    if(!HopLe())
    {
        cout << "Không phải đa giác\n";
        return;
    }

    cout << "Loại: Đa giác " << n << " cạnh";
    if(LaDeu())
      cout << ", đều";
    else if(LaLoi())
      cout << ", lồi";
    else
      cout << ", lõm";
    cout << endl;
}

/*
Đầu vào: dx, dy (lượng dời theo trục Ox, Oy)
Đầu ra: Cập nhật toạ độ tại mỗi đỉnh
Chức năng: Tịnh tiến đa giác
*/
void cDaGiac::TinhTien(double dx, double dy)
{
    for(int i = 0; i < n; i++)
       ds[i].TinhTien(dx, dy);
}

/*
Đầu vào: Nhập góc quay và tâm quay
Đầu ra: Cập nhật toạ độ tại mỗi đỉnh
Chức năng: Quay đa giác theo góc và tâm quay cho trước
*/
void cDaGiac::Quay(double goc, const cDiem& O)
{
    for(int i = 0; i < n; i++)
       ds[i].Quay(goc, O);
}

/*
Đầu vào: Nhập tỉ lệ k
Đầu ra: Cập nhật toạ độ tại mỗi đỉnh
Chức năng: Phóng to / thu nhỏ đa giác 
*/
void cDaGiac::TyLe(double k)
{
    for(int i = 0; i < n; i++)
       ds[i].TyLe(k);
}