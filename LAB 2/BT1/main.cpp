#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    Date a;//khởi tạo đối tượng a thuộc lớp Date
    cout<<"Nhập vào ngày, tháng, năm: "<<endl;
    a.Nhap();//Nhập giá trị ngày, tháng, năm cho đối tượng a

    cout<<"Ngày, tháng, năm hiện tại: ";
    a.Xuat();//xuất ngày, tháng, năm đã lưu trong a
    
    a.NgayThangNamTiepTheo();
    cout<<"\nNgày, tháng, năm tiếp theo: ";
    a.Xuat();//xuất ngày, tháng, năm tiếp theo

    return 0;
}