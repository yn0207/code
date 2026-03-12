#include <iostream>
#include <math.h>

using namespace std;

struct PS{
    int tu;
    int mau;
};
int gcd(int a, int b);
void rutgon(PS &p);
void nhap(PS &p);
void xuat(PS p);

int main ()
{
    PS p;
    nhap(p);
    rutgon(p);
    xuat(p);
    return 0;
}

//tìm ucln
int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b, a%b);
}
//hàm rút gọn
void rutgon(PS &p)
{
    int i = gcd(abs(p.tu), abs(p.mau));//tìm ucln
    p.tu /= i; //rút gọn tử
    p.mau /= i; //rút gọn mẫu
    if(p.mau < 0) //khi mẫu âm thì đổi dấu
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
 }
 void xuat(PS p)
 {
    cout<<"Phân số sau khi rút gọn: ";
    if(p.mau == 1)
       cout<<p.tu;
    else
       cout<<p.tu<< "/" <<p.mau;
 }