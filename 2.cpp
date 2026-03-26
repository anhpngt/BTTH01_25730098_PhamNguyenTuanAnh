// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 2. Viết chương trình cho phép người dùng nhập vào hai phân số, tìm phân số lớn
// nhất và xuất kết quả ra màn hình.

#include <iostream>
#include <numeric>
#include "2.h"

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
    cout << "Nhap phan so thu nhat:" << endl;
    Fraction f1 = InputFraction();
    cout << "Nhap phan so thu hai:" << endl;
    Fraction f2 = InputFraction();

    if (f1.CompareTo(f2) > 0)
    {
        cout << "Phan so thu nhat lon hon." << endl;
        cout << "Phan so lon hon la: ";
        f1.Print();
    }
    else if (f1.CompareTo(f2) < 0)
    {
        cout << "Phan so thu hai lon hon." << endl;
        cout << "Phan so lon hon la: ";
        f2.Print();
    }
    else
    {
        cout << "Hai phan so bang nhau." << endl;
        cout << "Ca hai phan so la: ";
        f1.Print();
    }

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

// CompareTo compares this fraction to another fraction.
// Returns 1 if this fraction is greater, -1 if smaller, and 0 if equal.
int Fraction::CompareTo(Fraction other)
{
    // Cross multiply to compare, so that we don't have to deal with floats
    int iLhs = this->iNumerator * other.iDenominator;
    int iRhs = other.iNumerator * this->iDenominator;
    if (iLhs > iRhs)
        return 1;
    else if (iLhs < iRhs)
        return -1;
    else
        return 0;
}
