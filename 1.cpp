// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 1: Viết chương trình cho phép người dùng nhập vào một phân số, rút gọn phân số
// và xuất kết quả ra màn hình.

#include <iostream>
#include <numeric>
#include "1.h"

using namespace std;

// Helper function to input a fraction from the user.
Fraction InputFraction()
{
    int iNumerator, iDenominator;
    cout << "\tNhap tu so: ";
    cin >> iNumerator;
    cout << "\tNhap mau so: ";
    cin >> iDenominator;
    return Fraction(iNumerator, iDenominator);
}

int main()
{
    Fraction f = InputFraction();
    cout << "Phan so vua nhap: ";
    f.Print();
    return 0;
}

// Initialize a new Fraction with the given numerator and denominator.
// The constructor will automatically reduce the fraction to its simplest form.
Fraction::Fraction(int iNumerator, int iDenominator)
{
    if (iDenominator == 0)
    {
        throw invalid_argument("Mau so khong duoc bang 0.");
    }
    this->iNumerator = iNumerator;
    this->iDenominator = iDenominator;
    Reduce();
}

// Reduce the fraction to its simplest form.
void Fraction::Reduce()
{
    int iGcd = gcd(abs(this->iNumerator), abs(this->iDenominator));
    this->iNumerator /= iGcd;
    this->iDenominator /= iGcd;
    // Keep the sign on the numerator
    if (this->iDenominator < 0)
    {
        this->iNumerator = -this->iNumerator;
        this->iDenominator = -this->iDenominator;
    }
}

// Print prints the fraction in the form "numerator/denominator".
void Fraction::Print()
{
    cout << this->iNumerator << "/" << this->iDenominator << endl;
}
