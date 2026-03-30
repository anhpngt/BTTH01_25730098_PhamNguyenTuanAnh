// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 1. Cài đặt lớp cPhanSo để biểu diễn khái niệm phân số với hai thành phần dữ liệu
// tử số, mẫu số và các hàm thành phần cộng, trừ, nhân, chia hai phân số, các
// hàm thành phần xuất, nhập, định giá trị cho phân số. Viết chương trình cho
// phép nhập vào hai phân số, in ra kết quả các phép toán cộng, trừ, nhân, chia hai
// phân số kể trên.

#pragma once

#include <iostream>
#include <string>

class cPhanSo
{
private:
    int iTuSo;
    int iMauSo;

    void RutGon();

public:
    cPhanSo();
    cPhanSo(int iTuSo, int iMauSo);

    static cPhanSo NhapTuConsole();
    string ToString();

    cPhanSo Cong(cPhanSo other);
    cPhanSo Tru(cPhanSo other);
    cPhanSo Nhan(cPhanSo other);
    cPhanSo Chia(cPhanSo other);
};