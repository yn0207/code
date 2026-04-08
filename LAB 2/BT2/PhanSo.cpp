#include <iostream>
#include "PhanSo.h"
using namespace std;
/*
-Đầu vào: Hai số nguyên a, b
-Đầu ra: Ước chung lớn nhất của a và b
-Chức năng: Sử dụng thuật toán Euclid (đệ quy) để tìm UCLN
*/ 
int ucln(int a, int b)
{
    if(b==0) return a; //b=0 thì a là ucln
    return ucln(b, a%b); //đệ quy tìm ucln
}
/*
-Đầu vào: Nhập từ bàn phím tử số (iTu) và mẫu số (iMau)
-Đầu ra: Gán giá trị hợp lệ cho phân số
-Chức năng:
 + Kiểm tra dữ liệu nhập có phải số nguyên không
 + Đảm bảo mẫu số khác 0
 + Sau khi nhập xong thì tự động rút gọn phân số
*/ 
 void PhanSo::Nhap()
 {
    //nhập tử số
    cout<<"Nhập tử số: ";
    while(!(cin>>iTu)) //nếu nhập không phải số nguyên
    {
        cout<<"Dữ liệu không hợp lệ. Vui lòng nhập lại tử số: ";
        cin.clear(); //xoá lỗi
        cin.ignore(10000, '\n'); //bỏ dữ liệu sai trong bộ đệm
    }
    //nhập mẫu số
    cout<<"Nhập mẫu số: ";
    while(true)
    {
        if(!(cin>>iMau)) //nếu không phải số nguyên
        {
        cout<<"Dữ liệu không hợp lệ. Vui lòng nhập lại mẫu số: ";
        cin.clear(); 
        cin.ignore(10000, '\n');
        }
        else if(iMau==0) //kiểm tra mẫu bằng 0
        {
            cout<<"Dữ liệu không hợp lệ. Vui lòng nhập lại mẫu số: ";
        }
        else break; //dữ liệu hợp lệ thoát khỏi vòng lặp
    }
 }

/*
-Đầu ra: In phân số ra màn hình
-Chức năng:
+ Nếu mẫu = 1 thì chỉ in tử
+ Ngược lại in dạng tử/mẫu*/
void PhanSo::Xuat()
{
    if(iTu == 0)
        cout << 0;//tu = 0 => phân số = 0
    else if(iMau == 1)
        cout << iTu;
    else
        cout << iTu << "/" << iMau;
}

/*
-Đầu vào: Phân số hiện tại (iTu, iMau)
-Đầu ra: Phân số đã được rút gọn
-Chức năng:
+ Rút gọn phân số
*/
void PhanSo::RutGon()
{
    int i = ucln(abs(iTu), abs(iMau));//tìm ucln
    iTu /= i; //rút gọn tử
    iMau /= i; //rút gọn mẫu
    if(iMau < 0) //mẫu âm thì đổi dấu
    {
        iTu = -iTu;
        iMau = -iMau;
    }
}

/*
-Đầu vào: Một phân số ps
-Đầu ra: Phân số là tổng của phân số hiện tại và ps
-Chức năng:
+ Quy đồng mẫu số
+ Tính tử số mới
+ Rút gọn kết quả
*/ 
 PhanSo PhanSo::Tong(PhanSo ps)
 {
    PhanSo c;
    c.iTu = iTu*ps.iMau + iMau*ps.iTu;//quy đồng tử
    c.iMau = iMau*ps.iMau;//quy đồng mẫu
    c.RutGon();//rút gọn phân số
    return c;
 }

/*
-Đầu vào: Một phân số ps
-Đầu ra: Phân số là hiệu của phân số hiện tại và ps
-Chức năng:
+ Quy đồng mẫu số
+ Trừ tử số
+ Rút gọn kết quả
*/ 
 PhanSo PhanSo::Hieu(PhanSo ps)
 {
    PhanSo c;
    c.iTu = iTu*ps.iMau - iMau*ps.iTu;//quy đồng tử
    c.iMau = iMau*ps.iMau;//quy đồng mẫu
    c.RutGon();//rút gọn phân số
    return c;
 }

/*
-Đầu vào: Một phân số ps
-Đầu ra: Phân số là tích của hai phân số
-Chức năng:
+ Nhân tử với tử
+ Nhân mẫu với mẫu
+ Rút gọn kết quả
*/ 
 PhanSo PhanSo::Tich(PhanSo ps)
 {
    PhanSo c;
    c.iTu = iTu*ps.iTu;//quy đồng tử
    c.iMau = iMau*ps.iMau;//quy đồng mẫu
    c.RutGon();//rút gọn phân số
    return c;
 }

/*
-Đầu vào: Một phân số ps
-Đầu ra: Phân số là thương của phân số hiện tại và ps
-Chức năng:
+ Nhân phân số hiện tại với nghịch đảo của ps
+ Rút gọn kết quả
*/ 
 PhanSo PhanSo::Thuong(PhanSo ps)
 {

    PhanSo c;
    c.iTu = iTu*ps.iMau;//quy đồng tử
    c.iMau = iMau*ps.iTu;//quy đồng mẫu
    c.RutGon();//rút gọn phân số
    return c;
 }

/*
-Đầu vào: Một phân số ps
-Đầu ra: 
+ Trả về 1 nếu phân số hiện tại > ps
+ Trả về -1 nếu phân số hiện tại < ps
+ Trả về 0 nếu hai phân số bằng nhau
-Chức năng:
+ So sánh hai kết quả để xác định quan hệ lớn hơn, nhỏ hơn hay bằng nhau
*/ 
 int PhanSo::SoSanh(PhanSo ps)
 {
    int t = iTu * ps.iMau;
    int p = iMau * ps.iTu;
    if(t > p)
      return 1; //phân số a lớn hơn
    else if(t < p)
      return -1; //phân số b lớn hơn
    else 
      return 0; //hai phân số bằng nhau
 }
 /*Hàm kiểm tra phân số 0*/
 bool PhanSo::Kiem_tra()
 {
    return iTu != 0;
 }