#ifndef CNHANVIENSX_H
#define CNHANVIENSX_H

#include <string>
using namespace std;


class cNhanVienSX
{
    private:
    string maNV;
    string tenNV;
    int Ngay;
    int Thang;
    int Nam;
    int soSP;
    double donGia;

    public:
    //Constructor
    cNhanVienSX();
    cNhanVienSX(const cNhanVienSX& other);
    cNhanVienSX& operator = (const cNhanVienSX& other);

    //Getter
    string getMaNV() const;
    string getTenNV() const;
    int getNgay() const;
    int getThang() const;
    int getNam() const;
    int getSP() const;
    double getGia() const;

    //Setter
    void setMaNV(string ma);
    void setTenNV(string ten);
    void setNgay(int ngay);
    void setThang(int thang);
    void setNam(int nam);
    void setSP(int sp);
    void setGia(double dg);

    void Nhap();
    void Xuat() const;
    double Luong() const;
    int Tuoi(int namSinh) const;

};

#endif