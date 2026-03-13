#include <iostream>
#include <string>

using namespace std;

struct HocSinh
{
    string tenHS;
    float diemToan;
    float diemVan;
    float DTB;
};
//khai báo hàm
void nhap(HocSinh &hs);
void xuat(HocSinh hs);
float diemTB(HocSinh hs);
bool tenHopLe(string ten);

int main()
{
    HocSinh hs;//tạo biến học sinh
    nhap(hs);
    xuat(hs);
    return 0;
}
//hàm kiểm tra tên hợp lệ
bool tenHopLe(string ten)
{
    if(ten.length() == 0)//không cho tên rỗng
        return false;
    for(size_t i=0; i<ten.length(); i++)
    {
        char c = ten[i];
        if(c >= '0' && c <= '9')//không cho phép số
           return false;
        if(c == '@' || c == '#' || c == '$' || c == '%' || c == '!' || c == '*')//không cho ký tự đặc biệt
           return false;
    }
    return true;
}
//hàm nhập thông tin học sinh
void nhap(HocSinh &hs)
{
    //nhập tên
    do
    {
        cout<<"Nhập họ tên: ";
        getline(cin, hs.tenHS);
        if(!tenHopLe(hs.tenHS))
          cout<<"Tên không hợp lệ. Vui lòng nhập lại: "<<endl;
    } while(!(tenHopLe(hs.tenHS)));
    //nhập điểm toán
    do
    {
        cout<<"Nhập điểm toán: ";
        while(!(cin>>hs.diemToan)){
            cout<<"Dữ liệu không hợp lệ. Vui lòng nhập lại điểm toán: ";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        if(hs.diemToan<0 || hs.diemToan>10)
        {
        cout<<"Điểm không hợp lệ. Vui lòng nhập lại"<<endl;
        }
    } while(hs.diemToan<0 || hs.diemToan>10);
    //nhập điểm văn
    do
    {
        cout<<"Nhập điểm văn: ";
        while(!(cin>>hs.diemVan)){
            cout<<"Dữ liệu không hợp lệ. Vui lòng nhập lại điểm văn: ";
            cin.clear();
            cin.ignore(10000,'\n');
        }
        if(hs.diemVan<0 || hs.diemVan>10)
        {
        cout<<"Điểm không hợp lệ. Vui lòng nhập lại"<<endl;
        }
    } while(hs.diemVan<0 || hs.diemVan>10);
}
//hàm tính điểm trung bình
float diemTB(HocSinh hs)
{
    return (hs.diemToan + hs.diemVan) / 2.0;
}
//hàm xuất thông tin học sinh
void xuat(HocSinh hs)
{
    cout<<"Họ và tên học sinh: "<<hs.tenHS<<endl;
    cout<<"Điểm toán: "<<hs.diemToan<<endl;
    cout<<"Điểm văn: "<<hs.diemVan<<endl;
    cout<<"Điểm trung bình: "<<diemTB(hs)<<endl;
}
