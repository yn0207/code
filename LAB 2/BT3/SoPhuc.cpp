#include <iostream>
#include "SoPhuc.h"
using namespace std;
/*Kiểm tra số phức 0*/
bool cSoPhuc::Kiem_tra()
{ 
    if (iThuc == 0 && iAo == 0)
    {
        return false; 
    }
    else return true; 
}
/*
-Đầu vào: 
+ t: phần thực (mặc định = 0)
+ a: phần ảo (mặc định = 0)
-Đầu ra: khởi tạo đối tượng số phức với iThuc = t, iAo = a
-Chức năng: tạo một số phức với giá trị ban đầu
*/
cSoPhuc::cSoPhuc(double t, double a)
{
    iThuc = t;
    iAo = a;
}
/*
- Đầu vào: nhập từ bàn phím phần thực và phần ảo trên cùng 1 dòng
- Đầu ra: gán giá trị cho thuộc tính iThuc và iAo của số phức
- Chức năng: nhập 1 số phức và kiểm tra dữ liệu hợp lệ
*/
void cSoPhuc::Nhap()
{
    while(true)
    {
        cout << "Nhập phần thực và phần ảo: ";
        
        if(cin >> iThuc >> iAo)
        {
            break; 
        }
        else
        {
            cout << "Dữ liệu không hợp lệ. Vui lòng nhập lại!\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}
/*
-Đầu ra: in ra màn hình số phức dạng a+bi
-Chức năng: xuất số phức ra màn hình 
*/
void cSoPhuc::Xuat()
{
    if(iThuc == 0 && iAo == 0)
        cout<<0;
    else if(iAo == 0)
        cout << iThuc;

    else if(iThuc == 0)
        cout << iAo << "i";

    else
    {
        if(iAo != 1)
        {
            if(iAo > 0)
            cout << iThuc << " + " << iAo << "i";
            else
            cout << iThuc << " - " << -iAo << "i";
        }
        else
        {
            if(iAo > 0) 
            cout << iThuc << " + " << "i";
            else 
            cout << iThuc << " - " << "i";
        }
    }
}
/*
-Đầu vào: đối tượng sp(số phức cần cộng)
-Đầu ra: tổng hai số phức
-Chức năng: tính tổng hai số phức
*/
cSoPhuc cSoPhuc::Tong(cSoPhuc sp)
{
    cSoPhuc kq;
    kq.iThuc = iThuc + sp.iThuc;
    kq.iAo = iAo + sp.iAo;
    return kq;
}
/*
-Đầu vào: đối tượng sp(số phức cần trừ)
-Đầu ra: hiệu hai số phức
-Chức năng: tính hiệu hai số phức
*/
cSoPhuc cSoPhuc::Hieu(cSoPhuc sp)
{
    cSoPhuc kq;
    kq.iThuc = iThuc - sp.iThuc;
    kq.iAo = iAo - sp.iAo;
    return kq;
}
/*
-Đầu vào: đối tượng sp(số phức cần nhân)
-Đầu ra: tích hai số phức
-Chức năng: tính tích hai số phức
*/
cSoPhuc cSoPhuc::Tich(cSoPhuc sp)
{
    cSoPhuc kq;
    kq.iThuc = iThuc*sp.iThuc - iAo*sp.iAo;
    kq.iAo = iThuc*sp.iAo + iAo*sp.iThuc;
    return kq;
}
/*
-Đầu vào: đối tượng sp khác 0(số phức cần chia) hoặc số phức bằng 0
-Đầu ra: thương hai số phức
-Chức năng: tính thương hai số phức
*/
cSoPhuc cSoPhuc::Thuong(cSoPhuc sp)
{

    cSoPhuc kq;
    kq.iThuc = (iThuc*sp.iThuc + iAo*sp.iAo)/(sp.iThuc*sp.iThuc + sp.iAo*sp.iAo);
    kq.iAo = (iAo*sp.iThuc - iThuc*sp.iAo)/(sp.iThuc*sp.iThuc + sp.iAo*sp.iAo);
    return kq;
}