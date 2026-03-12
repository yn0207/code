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
int SoSanh(PS a, PS b);

int main ()
{
    PS p1, p2;
    cout<<"Nhập phân số thứ nhất "<<endl;
    nhap(p1);
    cout<<"Nhập phân số thứ hai "<<endl;
    nhap(p2);
    int max = SoSanh(p1, p2);
    if(max == 1)
    {
        cout<<"Phân số lớn nhất: ";
        xuat(p1);
    }
    else if(max == -1)
    {
        cout<<"Phân số lớn nhất: ";
        xuat(p2);
    }
    else
      cout<<"Hai phân số bằng nhau";
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
 //hàm so sánh 2 phân số
 int SoSanh(PS a, PS b)
 {
    int t = a.tu * b.mau;
    int p = a.mau * b.tu;
    if(t > p)
      return 1; //phân số a lớn hơn
    else if(t < p)
      return -1; //phân số b lớn hơn
    else 
      return 0; //hai phân số bằng nhau
 }