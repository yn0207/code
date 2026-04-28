#include <iostream>
#include <cmath>
#include "DaThuc.h"
using namespace std;

int main()
{
    cDaThuc p1, p2;

    cout << "Nhập đa thức thứ nhất\n";
    p1.Nhap();
    cout << "Nhập đa thức thứ hai\n";
    p2.Nhap();

    cout << "P1 = "; p1.Xuat();
    cout << "P2 = "; p2.Xuat();

    cDaThuc tong = p1.Tong(p2);
    cout << "P1 + P2 = "; tong.Xuat();

    cDaThuc hieu = p1.Hieu(p2);
    cout << "P1 - P2 = "; hieu.Xuat();

    double x;
    cout << "Nhập x: "; cin >> x;
    cout << "P1(" << x << ") = " << p1.TinhGiaTri(x) << endl;

    return 0;
}