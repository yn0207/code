#include <iostream>
#include <iomanip>
#include "NhanVienSX.h"
using namespace std;

int main()
{
    int n;
    cout << "Nhập số nhân viên: ";
    cin >> n;

    cNhanVienSX *ds = new cNhanVienSX[n];
    for(int i = 0; i < n; i++)
    {
        cout << "\nNhân viên thứ " << i+1 << ":\n";
        ds[i].Nhap();
    }

    cout << "\nDanh sách nhân viên:\n";
    for(int i = 0; i < n; i++)
        ds[i].Xuat();

    int min = 0;
    for(int i = 0; i < n; i++)
    {
        if(ds[i].Luong() < ds[min].Luong())
          min = i;
    }
    cout << "\nNhân viên có lương thấp nhất:\n";
    ds[min].Xuat();

    double tong = 0;
    for(int i = 0; i < n; i++)
    {
        tong += ds[i].Luong();
    }
    cout << "----------------------";
    cout << "\nTổng lương: " << fixed << setprecision(3) << tong << endl;
    cout << "----------------------";

    int max = 0;
    for(int i = 1; i < n; i++)
    {
        int namA = ds[i].getNam(), thangA = ds[i].getThang(), ngayA = ds[i].getNgay();
        int namB = ds[max].getNam(), thangB = ds[max].getThang(), ngayB = ds[max].getNgay();
        
        if(namA < namB ||
          (namA == namB && thangA < thangB) ||
          (namA == namB && thangA == thangB && ngayA < ngayB))
        {
            max = i;
        }
    }
    cout << "\nNhân viên có tuổi lớn nhất:\n";
    ds[max].Xuat();

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(ds[i].Luong() > ds[j].Luong())
               swap(ds[i], ds[j]);
        }
    }

    cout << "\nDanh sách nhân viên sau khi sắp xếp:\n";
    for(int i = 0; i < n; i++)
      ds[i].Xuat();
    
    delete[] ds;
    return 0;
}