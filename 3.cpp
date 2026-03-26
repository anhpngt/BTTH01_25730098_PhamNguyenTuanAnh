// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 3. Viết chương trình cho phép người dùng nhập vào hai phân số. Tính tổng, hiệu,
// tích, thương giữa chúng và xuất kết quả ra màn hình.

#include <iostream>
#include <numeric>
#include "3.h"

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

    cout << "Tong cua hai phan so:" << endl;
    f1.Add(f2).Print();

    cout << "Hieu cua hai phan so:" << endl;
    f1.Subtract(f2).Print();

    cout << "Tich cua hai phan so:" << endl;
    f1.Multiply(f2).Print();

    cout << "Thuong cua hai phan so:" << endl;
    f1.Divide(f2).Print();

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

// Add adds two fractions and returns the result.
Fraction Fraction::Add(Fraction other)
{
    int iNewNumerator = this->iNumerator * other.iDenominator + other.iNumerator * this->iDenominator;
    int iNewDenominator = this->iDenominator * other.iDenominator;
    return Fraction(iNewNumerator, iNewDenominator);
}

// Subtract subtracts two fractions and returns the result.
Fraction Fraction::Subtract(Fraction other)
{
    int iNewNumerator = this->iNumerator * other.iDenominator - other.iNumerator * this->iDenominator;
    int iNewDenominator = this->iDenominator * other.iDenominator;
    return Fraction(iNewNumerator, iNewDenominator);
}

// Multiply multiplies two fractions and returns the result.
Fraction Fraction::Multiply(Fraction other)
{
    int iNewNumerator = this->iNumerator * other.iNumerator;
    int iNewDenominator = this->iDenominator * other.iDenominator;
    return Fraction(iNewNumerator, iNewDenominator);
}

// Divide divides two fractions and returns the result.
Fraction Fraction::Divide(Fraction other)
{
    if (other.iNumerator == 0)
    {
        throw invalid_argument("Khong the chia cho 0.");
    }
    int iNewNumerator = this->iNumerator * other.iDenominator;
    int iNewDenominator = this->iDenominator * other.iNumerator;
    return Fraction(iNewNumerator, iNewDenominator);
}
