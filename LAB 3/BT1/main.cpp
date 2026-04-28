#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "TamGiac.h"
#include "Diem.h"
using namespace std;


int main()
{
    cTamGiac tg;
    cout << "Nhập tam giác\n";
    tg.Nhap();

    cout << "---BAN ĐẦU---" << endl;
    tg.Xuat();
    cout << "Chu vi tam giác: " << tg.ChuVi() << endl;
    cout << "Diện tích tam giác: " << tg.DienTich() << endl;
    tg.KiemTraLoai();

    double dx, dy;
    cout << "\nNhập dx, dy: ";
    cin >> dx >> dy;
    tg.TinhTien(dx, dy);
    cout << "\nSau khi tịnh tiến:\n";
    tg.Xuat();

    double goc;
    cDiem O;
    cout << "\nNhập góc quay: ";
    cin >> goc;
    cin.ignore(1000, '\n');
    cout << "\nNhập tâm quay:\n";
    O.Nhap();
    tg.Quay(goc, O);
    cout << "\nSau khi quay:\n";
    tg.Xuat();

    double k;
    cout << "\nNhập k: ";
    cin >> k;
                
    // Làm tròn k đến 2 chữ số thập phân để so sánh chính xác hơn
    double kTron = round(k * 100) / 100;
 
    if(kTron == 0)
        cout << "\nKhông hợp lệ (k = 0)\n";
    else
    {
        if(kTron == 1)
            cout << "Tam giác không thay đổi\n";
        else if(kTron > 1)
            cout << "Tam giác phóng to " << kTron << " lần\n";
        else if(kTron > 0 && kTron < 1)
            cout << "Tam giác thu nhỏ " << 1.0 / kTron << " lần\n";
        else if(kTron < 0)
        {
            cout << "Tam giác bị đối xứng và ";
        if(kTron == -1)
            cout << "không thay đổi kích thước (k = -1)\n";
        else if(kTron < -1)
            cout << "phóng to " << abs(kTron) << " lần\n";
        else // -1 < kTron < 0
            cout << "thu nhỏ " << 1.0 / abs(kTron) << " lần\n";
        }
    }
    
    tg.TyLe(k);
    cout << "Sau khi phóng to / thu nhỏ:\n";
    tg.Xuat();

    return 0;
}