#include <iostream>
#include <iomanip>
#include "SoPhuc.h"
using namespace std;

int main ()
{
    cSoPhuc sp1, sp2, kq;
    cout<<"Nhập số phức thứ nhất "<<endl;
    sp1.Nhap();

    cout<<"Nhập số phức thứ hai "<<endl;
    sp2.Nhap();

    cout<<"Số phức thứ nhất: ";
    sp1.Xuat();
    cout << endl;

    cout<<"Số phức thứ hai: ";
    sp2.Xuat();
    cout << endl;

    cout<<"Tổng hai số phức: ";
    kq = sp1.Tong(sp2);
    kq.Xuat();
    cout << endl;

    cout<<"Hiệu hai số phức: ";
    kq = sp1.Hieu(sp2);
    kq.Xuat();
    cout << endl;

    cout<<"Tích hai số phức: ";
    kq = sp1.Tich(sp2);
    kq.Xuat();
    cout << endl;
    
    cout<<"Thương hai số phức: ";
    if ( sp2.Kiem_tra())
    {
        kq = sp1.Thuong(sp2);
        cout << fixed << setprecision(2);
        kq.Xuat();
    }
    else cout << "Không chia được!";
    return 0;
}
