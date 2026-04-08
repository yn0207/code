#ifndef SOPHUC_H
#define SOPHUC_H
class cSoPhuc
{
    private:
       double iThuc;
       double iAo;
    public:
        cSoPhuc(double t=0, double a=0);
        void Nhap();
        void Xuat();
        bool Kiem_tra();
        cSoPhuc Tong(cSoPhuc sp);
        cSoPhuc Hieu(cSoPhuc sp);
        cSoPhuc Tich(cSoPhuc sp);
        cSoPhuc Thuong(cSoPhuc sp);
};
#endif