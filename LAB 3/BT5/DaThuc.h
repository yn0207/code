#ifndef DATHUC_H
#define DATHUC_H

class cDaThuc
{
    private:
    int bac;
    double *a;

    public:
    //Constructỏ
    cDaThuc(int n = 0);
    cDaThuc(const cDaThuc &p);
    //Destructor
    ~cDaThuc();

    double TinhGiaTri(double x);
    void Nhap();
    void Xuat();
    
    cDaThuc Tong(const cDaThuc &p);
    cDaThuc Hieu(const cDaThuc &p);
    cDaThuc& operator = (const cDaThuc &p);
};

#endif