#include <iostream>
#include "ThoiGian.h"
using namespace std;

int main()
{
    ThoiGian t;
    cout<<"Nhập thời gian\n";
    t.Nhap();

    cout<<"Thời gian ban đầu: ";
    t.Xuat();

    t.TinhCongThemMotGiay();

    cout<<"\nThời gian sau khi cộng thêm một giây: ";
    t.Xuat();

    return 0;
}