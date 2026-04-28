#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.h"
using namespace std;

/*
Đầu vào: Số x cần kiểm tra
Đầu ra: True / False
Chức năng: Kiểm tra số x có phải số nguyên tố không
*/
bool cArray::LaSNT(int x) const
{
    if(x < 2) return false;
    for(int i = 2; i*i <= x; i++)
    {
        if(x % i == 0) 
          return false;
    }
    return true;
}

//Constructor mặc định - khởi tạo mảng rỗng
cArray::cArray()
{
    n = 0;
    arr = NULL;
}

//Constructor có tham số - cấp phát động mảng arr với n phần tử
cArray::cArray(int n)
{
    this->n = n;
    arr = new int[n];
}

//Destructor - giải phóng bộ nhớ động đã cấp phát cho mảng arr
cArray::~cArray()
{
    delete[] arr;
}

//Tạo mảng với các giá trị ngẫu nhiên
void cArray::TaoNgauNhien()
{
    for(int i = 0; i < n; i++)
       arr[i] = rand() % 201 - 100; //Trong đoạn [-100, 100]
}

//Xuất phần tử ra màn hình
void cArray::Xuat() const
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//Đếm số lần xuất hiện của x trong mảng
int cArray::Dem(int x) const
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
          count++;
    }
    return count;
}

//Kiểm tra xem mảng có tăng dần không
bool cArray::TangDan() const
{
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1])
          return false;
    }
    return true;
}

/*
Đầu ra: Giá trị lẻ nhỏ nhất, nếu không có trả về -1
Chức năng: Tìm phần tử lẻ nhỏ nhất trong mảng
*/
int cArray::LeNhoNhat() const
{
    int res = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] % 2 != 0 && arr[i] < res)
        {
            res = arr[i];
        }
    }

    return (res == INT_MAX) ? -1 : res;
}

/*
Đầu ra: Số nguyên tố lớn nhất, nếu không có trả về -1
Chức năng: Tìm số nguyên tố lớn nhất trong mảng
*/
int cArray::SNTLonNhat() const
{
    int res = -1;
    for(int i = 0; i < n; i++)
    {
        if(LaSNT(arr[i]) && arr[i] > res)
        {
            res = arr[i];
        }
    }
    return res;
}

//Sắp xếp mảng tăng dần theo Selection Sort
void cArray::SapXepTang()
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;                        // Giả sử phần tử nhỏ nhất tại i
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])          
                minIdx = j;
        }
        if (minIdx != i)                       
            swap(arr[i], arr[minIdx]);
    }
}

//Sắp xếp mảng giảm dần theo Selection Sort
void cArray::SapXepGiam()
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIdx = i;                        // Giả sử phần tử lớn nhất tại i
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxIdx])          
                maxIdx = j;
        }
        if (maxIdx != i)                      
            swap(arr[i], arr[maxIdx]);
    }
}