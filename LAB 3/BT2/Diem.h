#ifndef DIEM_H
#define DIEM_H

class cDiem
{
    private:
    double x, y;

    public:
    cDiem();
    cDiem(double x, double y);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    void Nhap();
    void Xuat() const;

    void TinhTien(double dx, double dy);
    void TyLe(double k);
    void Quay(double goc, const cDiem &O);

};
#endif