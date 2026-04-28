#ifndef DAGIAC_H
#define DAGIAC_H
#include "Diem.h"

class cDaGiac
{
    private:
        cDiem* ds;      // mảng động các đỉnh
        int n;          // số đỉnh

        double KhoangCach(const cDiem& P, const cDiem& Q) const;

    public:
        // Thiết lập & hủy bỏ
        cDaGiac();
        cDaGiac(int soCanh, cDiem* dsDiem);
        cDaGiac(const cDaGiac& dg);
        ~cDaGiac();

        cDaGiac& operator = (const cDaGiac& dg);

        // Thiết lập
        void Set(int soCanh, cDiem* dsDiem);

        // Getter
        int getSoCanh() const;
        cDiem getDinh(int i) const;

        // Nhập / Xuất
        void Nhap();
        void Xuat() const;

        // Tính toán
        double ChuVi() const;
        double DienTich() const;
        bool HopLe() const;  // kiểm tra n >= 3

        // Kiểm tra loại
        void KiemTraLoai() const;
        double GocTaiDinh(int i) const;
        bool LaLoi() const;    // đa giác lồi
        bool LaLom() const;    // đa giác lõm
        bool LaDeu() const;    // đa giác đều (tất cả cạnh bằng nhau, tất cả góc bằng nhau)

        // Biến đổi
        void TinhTien(double dx, double dy);
        void Quay(double goc, const cDiem& O);
        void TyLe(double k);
};

#endif
