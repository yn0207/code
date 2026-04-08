#ifndef THOIGIAN_H
#define THOIGIAN_H

class ThoiGian
{
    private:
    int iGio;
    int iPhut;
    int iGiay;
    public:
    ThoiGian(int gio = 0, int phut = 0, int giay = 0);
    void Nhap();
    void Xuat();
    void TinhCongThemMotGiay();
};

#endif