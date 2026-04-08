#include <iostream>
#include <iomanip>
#include "PhanSo.h"
using namespace std;

int main()
{
    PhanSo ps1, ps2;
    cout<<"Nhập phân số 1 "<<endl;
    ps1.Nhap();

    cout<<"Nhập phân số 2 "<<endl;
    ps2.Nhap();

    cout<<"\nPhân số 1: ";
    ps1.RutGon();
    ps1.Xuat();

    cout<<"\nPhân số 2: ";
    ps2.RutGon();
    ps2.Xuat();

    // Tính toán
    PhanSo tong = ps1.Tong(ps2);
    PhanSo hieu = ps1.Hieu(ps2);
    PhanSo tich = ps1.Tich(ps2);
    PhanSo thuong = ps1.Thuong(ps2);

    cout << "\nTổng: ";
    tong.Xuat();

    cout << "\nHiệu: ";
    hieu.Xuat();

    cout << "\nTích: ";
    tich.Xuat();

    cout << "\nThương: ";
    if(ps2.Kiem_tra())
    {
        cout << fixed << setprecision(2);
        thuong.Xuat();
    }
    else
        cout<<"Không thể chia!";

    // So sánh
    int max = ps1.SoSanh(ps2);
    if(max == 1)
    {
        cout<<"\nPhân số lớn nhất: ";
        ps1.Xuat();
    }
    else if(max == -1)
    {
        cout<<"\nPhân số lớn nhất: ";
        ps2.Xuat();
    }
    else
      cout<<"\nHai phân số bằng nhau";
    return 0;
}
