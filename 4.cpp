// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

/**
4. Viết chương trình cho phép người dùng nhập vào một dãy gồm n phân số. Tìm
và xuất ra màn hình phân số lớn nhất. Sắp xếp dãy phân số tăng dần/giảm dần.
*/

#include <iostream>
#include <numeric>
#include <algorithm>
#include "4.h"

#define N 100

using namespace std;

Fraction inputFraction()
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
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "So luong phan so phai lon hon 0." << endl;
        return 1;
    }

    Fraction fractions[N];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan so thu " << (i + 1) << ":" << endl;
        fractions[i] = inputFraction();
    }

    // Find the largest
    int maxIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (fractions[i].CompareTo(fractions[maxIdx]) > 0)
            maxIdx = i;
    }
    cout << "Phan so lon nhat: ";
    fractions[maxIdx].Print();

    // Sort ascending
    sort(fractions,
         fractions + n,
         [](Fraction a, Fraction b)
         { return a.CompareTo(b) < 0; });
    cout << "Day phan so sap xep tang dan:" << endl;
    for (int i = 0; i < n; i++)
        fractions[i].Print();

    // Sort descending
    sort(fractions,
         fractions + n,
         [](Fraction a, Fraction b)
         { return a.CompareTo(b) > 0; });
    cout << "Day phan so sap xep giam dan:" << endl;
    for (int i = 0; i < n; i++)
        fractions[i].Print();

    return 0;
}

// Default constructor: initializes to 0/1.
Fraction::Fraction()
{
    this->iNumerator = 0;
    this->iDenominator = 1;
}

/**
Initialize a new Fraction with the given numerator and denominator.

Note that the constructor will automatically reduce the fraction to its simplest form.
*/
Fraction::Fraction(int iNumerator, int iDenominator)
{
    if (iDenominator == 0)
    {
        throw invalid_argument("Mau so khong duoc bang 0.");
    }
    this->iNumerator = iNumerator;
    this->iDenominator = iDenominator;
    reduce();
}

// Reduce the fraction to its simplest form.
void Fraction::reduce()
{
    int g = gcd(abs(this->iNumerator), abs(this->iDenominator));
    this->iNumerator /= g;
    this->iDenominator /= g;
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
    int lhs = this->iNumerator * other.iDenominator;
    int rhs = other.iNumerator * this->iDenominator;
    if (lhs > rhs)
        return 1;
    else if (lhs < rhs)
        return -1;
    else
        return 0;
}
