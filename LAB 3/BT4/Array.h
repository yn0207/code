#ifndef ARRAY_H
#define ARRAY_H

class cArray
{
    private:
    int n;
    int *arr;
    bool LaSNT(int x) const;

    public:
    cArray();
    cArray(int n);
    ~cArray();

    void TaoNgauNhien();
    void Xuat() const;

    int Dem(int x) const;
    bool TangDan() const;

    int LeNhoNhat() const;
    int SNTLonNhat() const;
    
    void SapXepTang();
    void SapXepGiam();
};

#endif