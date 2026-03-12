#include <iostream>
#include <math.h>

using namespace std;

struct PS{
    int tu;
    int mau;
};

void nhap(PS &p);
void xuat(PS p);
int ucln(int a, int b);
void rutgon(PS &p);
PS tong(PS a, PS b);
PS hieu(PS a, PS b);
PS tich(PS a, PS b);
PS thuong(PS a, PS b);

int main ()
{
    PS p1, p2;
    cout<<"Nhập phân số thứ nhất "<<endl;
    nhap(p1);
    cout<<"Nhập phân số thứ hai "<<endl;
    nhap(p2);
    xuat(tong(p1, p2));
    cout<<endl;
    xuat(hieu(p1, p2));
    cout<<endl;
    xuat(tich(p1, p2));
    cout<<endl;
    xuat(thuong(p1, p2));
    return 0;
}

//tìm ucln
int ucln(int a, int b)
{
    if(b==0) return a; //b=0 thì a là ucln
    return ucln(b, a%b); //đệ quy tìm ucln
}
//hàm rút gọn
void rutgon(PS &p)
{
    int i = ucln(abs(p.tu), abs(p.mau));//tìm ucln
    p.tu /= i; //rút gọn tử
    p.mau /= i; //rút gọn mẫu
    if(p.mau < 0) //mẫu âm thì đổi dấu
    {
        p.tu = -p.tu;
        p.mau = -p.mau;
    }
}
//hàm nhập phân số
 void nhap(PS &p)
 {
    //nhập tử số
    cout<<"Nhập tử số: ";
    while(!(cin>>p.tu)) //nếu nhập không phải số nguyên
    {
        cout<<"Dữ liệu không hợp lệ. Vui lòng nhập lại tử số: ";
        cin.clear(); //xoá lỗi
        cin.ignore(10000, '\n'); //bỏ dữ liệu sai trong bộ đệm
    }
    //nhập mẫu số
    cout<<"Nhập mẫu số: ";
    while(true)
    {
        if(!(cin>>p.mau)) //nếu không phải số nguyên
        {
        cout<<"Dữ liệu không hợp lệ. Vui lòng nhập lại mẫu số: ";
        cin.clear(); 
        cin.ignore(10000, '\n');
        }
        else if(p.mau==0) //kiểm tra mẫu bằng 0
        {
            cout<<"Dữ liệu không hợp lệ. Vui lòng nhập lại mẫu số: ";
        }
        else break; //dữ liệu hợp lệ thoát khỏi vòng lặp
    }
    rutgon(p);
 }
 //hàm xuất phân số
 void xuat(PS p)
 {
    if(p.mau == 1)//khi mẫu bằng 1 thì in tử
       cout<<p.tu;
    else
       cout<<p.tu<< "/" <<p.mau; //in ra theo dạng tu/mau
 }
 //hàm tính tổng 2 phân số
 PS tong(PS a, PS b)
 {
    PS c;
    c.tu = a.tu*b.mau + b.tu*a.mau;//quy đồng tử
    c.mau = a.mau*b.mau;//quy đồng mẫu
    rutgon(c);//rút gọn phân số
    return c;
 }
 //hàm tính hiệu 2 phân số
 PS hieu(PS a, PS b)
 {
    PS c;
    c.tu = a.tu*b.mau - b.tu*a.mau;//tính tủ
    c.mau = a.mau*b.mau;//tính mẫu
    rutgon(c);//rút gọn phân số
    return c;
 }
 //hàm tính tích 2 phân số
 PS tich(PS a, PS b)
 {
    PS c;
    c.tu = a.tu*b.tu;//nhân tử
    c.mau = a.mau*b.mau;//nhân mẫu
    rutgon(c);
    return c;
 }
 //hàm tính thương 2 phân số
 PS thuong(PS a, PS b)
 {
    PS c;
    c.tu = a.tu * b.mau;//nhân chéo tử
    c.mau = a.mau*b.tu;//nhân chéo mẫu
    rutgon(c);
    return c;
 }