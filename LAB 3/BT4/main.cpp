#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.h"
using namespace std;

int main()
{
    srand(time(0));
    int n;
    cout << "Nhập n: ";
    cin >> n;

    if(n <= 0)
    {
      cout << "\nMảng rỗng\n";
      int x;
      cout << "Nhập x: ";
      cin >> x;
      cout << "\nKhông có phần tử để kiểm tra";
      return 0;
    }
    cArray arr(n);
    arr.TaoNgauNhien();
    cout << "\nMảng: ";
    arr.Xuat();

    float x;
    cout << "\nNhập x: ";
    cin >> x;
    int kq = arr.Dem(x);
    if(kq == 0)
      cout << "Không có giá trị " << x << " trong mảng!" << endl;
    else 
      cout << "Số lần xuất hiện của giá trị " << x << " trong mảng: " << kq << endl;
    
    if(arr.TangDan())
      cout << "\nMảng tăng dần!" << endl;
    else
      cout << "Mảng không tăng dần!" << endl;

    cout << "Phần lẻ nhỏ nhất trong mảng: ";
    cout << arr.LeNhoNhat();

    cout << "\nSố nguyên tố lớn nhất trong mảng: ";
    cout << arr.SNTLonNhat();

    arr.SapXepTang();
    cout << "\nMảng sắp xếp tăng dần: ";
    arr.Xuat();

    arr.SapXepGiam();
    cout << "\nMảng sắp xếp giảm dần: ";
    arr.Xuat();

    return 0;
}