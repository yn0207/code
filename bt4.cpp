#include <iostream>

using namespace std;

struct Ngay{
    int ngay;
    int thang;
    int nam;
};
//khai báo hàm
void nhap(Ngay &n);
void xuat(Ngay n);
bool namNhuan(int nam);
int ngayTrongThang(int thang, int nam);
Ngay ngay_tiep(Ngay n);

int main ()
{
    Ngay n;
    cout<<"Nhập ngày, tháng, năm:";
    nhap(n);
    int maxNgay = ngayTrongThang(n.thang, n.nam);//tìm số ngày tối đa trong tháng
    //kiểm tra dữ liệu hợp lệ
    if(n.ngay<1 || n.thang<1 || n.thang>12 || n.ngay>maxNgay)
    {
        cout<<"Ngày không hợp lệ";
        return 0;
    }
    Ngay ngaytiep = ngay_tiep(n);//tìm ngày kế tiếp
    xuat(ngaytiep);
    return 0;
}
//nhập ngày
void nhap(Ngay &n)
{
    while(true)
    {
        if(!(cin>>n.ngay>>n.thang>>n.nam))//nhập không phải số
        {
            cout<<"Dữ liệu không hợp lệ. Vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else if(n.ngay<0 || n.thang<0 || n.nam<0)//ngày, tháng, năm nhỏ hơn 0
        {
            cout<<"Không nhập số âm. Vui lòng nhập lại: ";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else break;//dữ liệu hợp lệ thì thoát khỏi vòng lặp
    }
}
//hàm xuất
void xuat(Ngay n)
{
    cout<<n.ngay<<"/"<<n.thang<<"/"<<n.nam;//xuất theo dạng dd/mm/yyyy
}
//kiểm tra năm nhuận
bool namNhuan(int nam)
{
    if(nam%400==0) return true;
    if(nam%4==0 && nam%100!=0) return true;
    return false;//không phải năm nhuận
}
//số ngày trong tháng
int ngayTrongThang(int thang, int nam)
{
    switch(thang)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;//tháng có 31 ngày
        case 4: case 6: case 9: case 11:
            return 30;//tháng có 30 ngày
        case 2:
            if(namNhuan(nam)) return 29;//tháng 2 năm nhuận có 29 ngày
            else return 28;//tháng 2 năm không nhuận có 28 ngày
        default:
            return 0;
    }
}
//tìm ngày kế tiếp
Ngay ngay_tiep(Ngay n)
{
    Ngay ngayTiep = n;//tạo biến lưu ngày tiếp theo
    int maxNgay = ngayTrongThang(n.thang, n.nam);//tìm ngày tối đa trong tháng
    if(n.ngay < maxNgay) 
     ngayTiep.ngay++;//tăng ngày lên 1
    else
    {
        ngayTiep.ngay = 1;//sang ngày đầu tháng mới
        if(n.thang == 12)//nếu tháng 12
        {
            ngayTiep.thang = 1;//sang tháng 1
            ngayTiep.nam++;//tăng năm lên 1
        }
        else
        {
            ngayTiep.thang++;//tăng tháng 
        }
    }
    return ngayTiep;//trả về ngày tiếp theo
}
