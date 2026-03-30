// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 1. Cài đặt lớp cPhanSo để biểu diễn khái niệm phân số với hai thành phần dữ liệu
// tử số, mẫu số và các hàm thành phần cộng, trừ, nhân, chia hai phân số, các
// hàm thành phần xuất, nhập, định giá trị cho phân số. Viết chương trình cho
// phép nhập vào hai phân số, in ra kết quả các phép toán cộng, trừ, nhân, chia hai
// phân số kể trên.

#include "1.h"

using namespace std;

int main()
{
    cout << "Nhap phan so thu nhat" << endl;
    cPhanSo ps1 = cPhanSo::NhapTuConsole();
    cout << "Nhap phan so thu hai" << endl;
    cPhanSo ps2 = cPhanSo::NhapTuConsole();

    cout << "Phan so thu nhat: " << ps1.ToString() << endl;
    cout << "Phan so thu hai: " << ps2.ToString() << endl;

    cout << "=> Ket qua phep cong: " << ps1.Cong(ps2).ToString() << endl;
    cout << "=> Ket qua phep tru: " << ps1.Tru(ps2).ToString() << endl;
    cout << "=> Ket qua phep nhan: " << ps1.Nhan(ps2).ToString() << endl;
    cout << "=> Ket qua phep chia: " << ps1.Chia(ps2).ToString() << endl;
    return 0;
}

// RutGon reduces the fraction to its simplest form.
void cPhanSo::RutGon()
{
    int a = abs(this->iTuSo);
    int b = abs(this->iMauSo);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    this->iTuSo /= a;
    this->iMauSo /= a;

    if (this->iMauSo < 0)
    {
        this->iTuSo *= -1;
        this->iMauSo *= -1;
    }
}

// Default constructor initializes the fraction to zero.
cPhanSo::cPhanSo()
{
    cPhanSo(0, 1);
}

// Parameterized constructor initializes the fraction with given numerator and denominator.
cPhanSo::cPhanSo(int iTuSo, int iMauSo)
{
    if (iMauSo == 0)
    {
        throw std::invalid_argument("Mau so khong duoc bang 0");
    }

    this->iTuSo = iTuSo;
    this->iMauSo = iMauSo;
    RutGon();
}

// NhapTuConsole prompts the user to input the numerator and denominator, and returns a cPhanSo object.
cPhanSo cPhanSo::NhapTuConsole()
{
    int iTuSo, iMauSo;

    cout << "\tNhap tu so: ";
    cin >> iTuSo;

    cout << "\tNhap mau so: ";
    cin >> iMauSo;

    return cPhanSo(iTuSo, iMauSo);
}

// ToString returns a string representation of the fraction in the form "numerator/denominator".
string cPhanSo::ToString()
{
    return to_string(this->iTuSo) + "/" + to_string(this->iMauSo);
}

// Cong adds the current fraction with another fraction and returns the result as a new cPhanSo object.
cPhanSo cPhanSo::Cong(cPhanSo other)
{
    int iTuSo = this->iTuSo * other.iMauSo + other.iTuSo * this->iMauSo;
    int iMauSo = this->iMauSo * other.iMauSo;

    return cPhanSo(iTuSo, iMauSo);
}

// Tru subtracts another fraction from the current fraction and returns the result as a new cPhanSo object.
cPhanSo cPhanSo::Tru(cPhanSo other)
{
    int iTuSo = this->iTuSo * other.iMauSo - other.iTuSo * this->iMauSo;
    int iMauSo = this->iMauSo * other.iMauSo;

    return cPhanSo(iTuSo, iMauSo);
}

// Nhan multiplies the current fraction with another fraction and returns the result as a new cPhanSo object.
cPhanSo cPhanSo::Nhan(cPhanSo other)
{
    int iTuSo = this->iTuSo * other.iTuSo;
    int iMauSo = this->iMauSo * other.iMauSo;

    return cPhanSo(iTuSo, iMauSo);
}

// Chia divides the current fraction by another fraction and returns the result as a new cPhanSo object.
cPhanSo cPhanSo::Chia(cPhanSo other)
{
    if (other.iTuSo == 0)
    {
        throw std::invalid_argument("Khong the chia cho phan so co tu so bang 0");
    }

    int iTuSo = this->iTuSo * other.iMauSo;
    int iMauSo = this->iMauSo * other.iTuSo;

    return cPhanSo(iTuSo, iMauSo);
}