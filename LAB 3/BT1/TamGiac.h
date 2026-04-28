#ifndef TAMGIAC_H
#define TAMGIAC_H
#include "Diem.h"

class cTamGiac
{
    private:
    cDiem A, B, C;
    double KhoangCach(const cDiem &P, const cDiem &Q) const ;

    public:
    cTamGiac();
    cTamGiac(cDiem a, cDiem b, cDiem c);
    cTamGiac(double ax, double ay, double bx, double by, double cx, double cy);
    ~cTamGiac();

    cTamGiac& operator = (const cTamGiac &tg);
    void Nhap();
    void Xuat() const;

    cDiem getA() const;
    cDiem getB() const;
    cDiem getC() const;
    void Set(cDiem a, cDiem b, cDiem c);
    void Set(double ax, double ay, double bx, double by, double cx, double cy);

    double ChuVi() const;
    double DienTich() const;
    bool HopLe() const;
    void KiemTraLoai() const;

    void TinhTien(double dx, double dy);
    void TyLe(double k);
    void Quay(double goc, const cDiem& O);

};

#endif