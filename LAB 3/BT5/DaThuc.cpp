#include <iostream>
#include <cmath>
#include "DaThuc.h"
using namespace std;

/*
Đầu vào: n - bậc của đa thức
Chức năng: Constructor có tham số - cấp phát mảng hệ số có kích thước n+1 và gán tất cả hệ số = 0
*/
cDaThuc::cDaThuc(int n)
{
    bac = n;
    a = new double[bac +1];
    for(int i = 0; i <= bac; i++)
       a[i] = 0;
}

/*
Đầu vào: p - đối tượng cDaThuc cần sao chép
Chức năng: Copy constructor - tạo bản sao của đa thức
*/
cDaThuc::cDaThuc(const cDaThuc &p)
{
    bac = p.bac;
    a = new double[bac + 1];
    for(int i = 0; i <= bac; i++)
        a[i] = p.a[i];
}

//Destructor - giải phóng bộ nhớ động đã cấp phát cho mảng hệ số
cDaThuc::~cDaThuc()
{
    delete[] a;
}

//Nhập bậc và hệ số từ bàn phím
void cDaThuc::Nhap()
{
    cout << "Nhập bậc đa thức: ";
    cin >> bac;
    
    delete[] a;
    a = new double[bac + 1];
    for(int i = bac; i >= 0; i--)
    {
        cout << "Nhập hệ số bậc " << i << ": ";
        cin >> a[i];
    }
}

//In đa thức ra màn hình 
void cDaThuc::Xuat()
{
    bool Dain = false; //chưa in phần tử nào
    for(int i = bac; i >= 0; i--)
    {
        if(a[i] != 0)
        {
            if(Dain)  // nếu đã in ít nhất 1 hạng tử 
            {
            if(a[i] > 0) cout << " + ";  // in dấu + trước
            else cout << " - ";           // in dấu - trước
            }
            else if(a[i] < 0) cout << "-";   // hạng tử đầu tiên mà âm thì in dấu -
            double val = abs(a[i]);
            if(val != 1 || i == 0)
              cout << val;
            if(i > 0)
            {
                cout << "x";
                if(i > 1)
                  cout << "^" << i;
            }
            Dain = true;
        }
    }
    if(!Dain) cout << "0";
    cout << endl;
}

/*
Đầu vào: Giá trị x
Đầu ra: Kết quả của biểu thức
Chức năng: Tính giá trị của đa thức tại điểm x cho trước
*/
double cDaThuc::TinhGiaTri(double x)
{
    double kq = 0;
    for(int i = 0; i <= bac; i++)
    {
        kq += a[i] * pow(x, i);
    }

    return kq;
}

/*
Đầu vào: p - đa thức cần cộng thêm
Đầu ra: Tổng 2 đa thức
Chức năng: Cộng 2 đa thức và trả về đa thức mới
*/
cDaThuc cDaThuc::Tong(const cDaThuc &p)
{
    int maxBac = max(bac, p.bac);
    cDaThuc kq(maxBac);
    for(int i = 0; i <= maxBac; i++)
    {
        double heso1 = (i <= bac) ? a[i] : 0;
        double heso2 = (i <= p.bac) ? p.a[i] : 0;
        kq.a[i] = heso1 + heso2;
    }
    return kq;
}

/*
Đầu vào: p - đa thức bị trừ
Đầu ra: Hiệu 2 đa thức
Chức năng: Trừ 2 đa thức và trả về đa thức mới
*/
cDaThuc cDaThuc::Hieu(const cDaThuc &p)
{
    int maxBac = max(bac, p.bac);
    cDaThuc kq(maxBac);
    for(int i = 0; i <= maxBac; i++)
    {
        double heso1 = (i <= bac) ? a[i] : 0;
        double heso2 = (i <= p.bac) ? p.a[i] : 0;
        kq.a[i] = heso1 - heso2;
    }
    return kq;
}

/*
Đầu vào: const cDaThuc& p - đa thức cần gán
Đầu ra: Tham chiếu đến đối tuợng hiện tại
Chức năng: Gán nội dung của p cho đối tượng hiện tại
*/
cDaThuc& cDaThuc::operator = (const cDaThuc &p)
{
    if(this != &p)
    {
        delete[] a;
        bac = p.bac;
        a = new double[bac + 1];
        for(int i = 0; i <= bac; i++)
            a[i] = p.a[i];
    }
    return *this;
}