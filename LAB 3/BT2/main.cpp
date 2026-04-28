#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "DaGiac.h"
#include "Diem.h"
using namespace std;


int main()
{
    cDaGiac dg;
    cout << "Nhập đa giác\n";
    dg.Nhap();

    cout << "---BAN ĐẦU---" << endl;
    dg.Xuat();
    cout << "Chu vi đa giác: " << dg.ChuVi() << endl;
    cout << "Diện tích đa giác: " << dg.DienTich() << endl;
    dg.KiemTraLoai();

    double dx, dy;
    cout << "\nNhập dx, dy: ";
    cin >> dx >> dy;
    dg.TinhTien(dx, dy);
    cout << "\nSau khi tịnh tiến:\n";
    dg.Xuat();

    double goc;
    cDiem O;
    cout << "\nNhập góc quay: ";
    cin >> goc;
    cin.ignore(1000, '\n');
    cout << "\nNhập tâm quay:\n";
    O.Nhap();
    dg.Quay(goc, O);
    cout << "\nSau khi quay:\n";
    dg.Xuat();

    double k;
    cout << "\nNhập k: ";
    cin >> k;
                
    if (k == 0)
        cout << "\nKhông hợp lệ (k = 0)\n";
    else
    {
        if (k == 1)
            cout << "Đa giác không thay đổi\n";
        else if (k > 1)
            cout << "Đa giác phóng to " << k << " lần\n";
        else if (k > 0 && k < 1)
            cout << "Đa giác thu nhỏ " << 1.0 / k << " lần\n";
        else if (k < 0)
        {
            cout << "Đa giác bị đối xứng và ";
            if (k < -1)
                cout << "phóng to " << fabs(k) << " lần\n";
            else if (k > -1)
                cout << "thu nhỏ " << 1.0 / fabs(k) << " lần\n";
            else
                cout << "không thay đổi kích thước (k = -1)\n";
        }
    }
    dg.TyLe(k);
    cout << "Sau khi phóng to / thu nhỏ:\n";
    dg.Xuat();
    return 0;
}