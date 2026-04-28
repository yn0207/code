#include <iostream>
#include <iomanip>
#include <cctype>
#include "NhanVienSX.h"
using namespace std;

//Constructor mặc định - khởi tạo nhân viên với giá trị mặc định
cNhanVienSX::cNhanVienSX()
{
    maNV = "";
    tenNV = "";
    Ngay = 1;
    Thang = 1;
    Nam = 2000;
    soSP = 0;
    donGia = 0.0;
}

//Copy constructor - tạo bản sao cho đối tượng nhân viên
cNhanVienSX::cNhanVienSX(const cNhanVienSX& other)
{
    maNV = other.maNV;
    tenNV = other.tenNV;
    Ngay = other.Ngay;
    Thang = other.Thang;
    Nam = other.Nam;
    soSP = other.soSP;
    donGia = other.donGia;
}

/*
Đầu vào: other - đối tượng nguồn
Đầu ra: Tham chiếu đến đối tượng hiện tại
Chức năng: Gán nội dung của other cho đối tượng hiện tại
*/
cNhanVienSX& cNhanVienSX::operator=(const cNhanVienSX& other)
{
    if(this != &other)
    {
        maNV   = other.maNV;
        tenNV  = other.tenNV;
        Ngay   = other.Ngay;
        Thang  = other.Thang;
        Nam    = other.Nam;
        soSP   = other.soSP;
        donGia = other.donGia;
    }
    return *this;
}

//Trả về giá trị mã nhân viên
string cNhanVienSX::getMaNV() const
{
    return maNV;
}

//Trả về giá trị tên nhân viên
string cNhanVienSX::getTenNV() const
{
    return tenNV;
}

//Trả về giá trị ngày
int cNhanVienSX::getNgay() const
{
    return Ngay;
}

//Trả về giá trị tháng
int cNhanVienSX::getThang() const
{
    return Thang;
}

//Trả về giá trị năm
int cNhanVienSX::getNam() const
{
    return Nam;
}

//Trả về số sản phẩm đã gia công
int cNhanVienSX::getSP() const
{
    return soSP;
}

//Trả về gía trị đơn giá một sản phẩm
double cNhanVienSX::getGia() const
{
    return donGia;
}

//Cập nhật mã nhân viên
void cNhanVienSX::setMaNV(string ma)
{
    maNV = ma;
}

//Cập nhật tên nhân viên
void cNhanVienSX::setTenNV(string ten)
{
    tenNV = ten;
}

//Cập nhật ngày
void cNhanVienSX::setNgay(int ngay)
{
    Ngay = ngay;
}

//Cập nhật tháng
void cNhanVienSX::setThang(int thang)
{
    Thang = thang;
}

//Cập nhật năm
void cNhanVienSX::setNam(int nam)
{
    Nam = nam;
}

//Cập nhật số sản phẩm đã gia công
void cNhanVienSX::setSP(int sp)
{
    soSP = sp;
}

//Cập nhật đơn giá một sản phẩm
void cNhanVienSX::setGia(double dg)
{
    donGia = dg;
}

//Tính lương nhân viên = số sản phẩm * đơn giá
double cNhanVienSX::Luong() const
{
    return soSP * donGia;
}

//Tính tuổi năm sinh dựa trên năm sinh
int cNhanVienSX::Tuoi(int namSinh) const
{
    return 2026 - namSinh;
}

//Hàm kiểm tra tên hợp lệ
bool tenHopLe(string ten)
{
    if(ten.length() == 0)//không cho tên rỗng
        return false;
    for(size_t i=0; i<ten.length(); i++)
    {
        char c = ten[i];
        if(c >= '0' && c <= '9')//không cho phép số
           return false;
        if(c == '@' || c == '#' || c == '$' || c == '%' || c == '!' || c == '*')//không cho ký tự đặc biệt
           return false;
    }
    return true;
}

//Kiểm tra có phải năm nhuận không
bool NamNhuan(int y)
{
    return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

//Trả về số ngày trong tháng m của năm y
int soNgayTrongThang(int m, int y)
{
    if(m == 2) return NamNhuan(y) ? 29 : 28;
    if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}

//Kiểm tra ngày, tháng, năm có hợp lệ không
bool HopLe(int d, int m, int y)
{
    if(y < 1900 || y > 2026) return false;
    if(m < 1 || m > 12) return false;
    if(d < 1 || d > soNgayTrongThang(m, y)) return false;
    return true;
}

/*
Đầu vào: Nhập mã nhân viên, tên nhân viên, số sản phẩm, đơn giá từ bàn phím
Đầu ra: Gán giá trị cho đối tượng
Chức năng: Nhập thông tin và kiểm tra xem có hợp lệ không
*/
void cNhanVienSX::Nhap()
{
    cout << "Nhập mã nhân viên (8 chữ số): ";
    cin.ignore(1000, '\n');
    do
    {
        getline(cin, maNV);
        bool hople = (maNV.length() == 8);
        for(int i = 0; i < maNV.length(); i++)
        {
            if(!isdigit(maNV[i]))
            {
                hople = false;
                break;
            }
        }
        if(!hople)
           cout << "Mã không hợp lệ. Vui lòng nhập lại (8 chữ số): ";
        else break;
    } while(true);

    while(true)
    {
        cout << "Nhập họ, tên nhân viên: ";
        getline(cin, tenNV);
        if(!tenHopLe(tenNV))
        {
            cout << "Tên không hợp lệ. Vui lòng nhập lại!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else break;
    }
    
    while(true)
    {
        cout << "Nhập ngày, tháng, năm: ";
        cin >> Ngay >> Thang >> Nam;
        if(cin.fail() || !HopLe(Ngay, Thang, Nam))
        {
            cout << "Ngày sinh không hợp lệ. Vui lòng nhập lại!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else break;
    }

    while(true)
    {
        cout << "Nhập số sản phẩm: ";
        cin >> soSP;
        if(cin.fail() || soSP < 0)
        {
            cout << "Sô sản phẩm không hợp lệ. Vui lòng nhâp lại!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else break;
    }

    while(true)
    {
        cout << "Nhập đơn giá một sản phẩm: ";
        cin >> donGia;
        if(cin.fail() || donGia < 0.0)
        {
            cout << "Đơn giá không hợp lệ. Vui lòng nhập lại!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');        
        }
        else break;
    }

}

//Xuất thông tin của nhân viên
void cNhanVienSX::Xuat() const
{
    cout << "---NHÂN VIÊN---";
    cout << "\nMã: " << maNV;
    cout << "\nHọ tên: " << tenNV;
    cout << "\nNgày sinh: " << Ngay << "/" << Thang << "/" << Nam;
    cout << "\nSố sản phẩm đã gia công: " << soSP;
    cout << "\nĐơn giá một sản phẩm: " << fixed << setprecision(0) << donGia;
    cout << "\nLương: " << fixed << setprecision(3) << Luong() << endl;
}