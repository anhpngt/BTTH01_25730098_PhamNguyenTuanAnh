// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

#include <iostream>
#include <numeric>
#include "bai1.h"

using namespace std;

Fraction inputFraction() {
    int iNumerator, iDenominator;
    cout << "Nhap tu so: ";
    cin >> iNumerator;
    cout << "Nhap mau so: ";
    cin >> iDenominator;
    return Fraction(iNumerator, iDenominator);
}

/**
Bai 1: Viết chương trình cho phép người dùng nhập vào một phân số, rút gọn phân số
và xuất kết quả ra màn hình.
*/
int main() {
    cout << "Nhap phan so thu nhat: " << endl;
    Fraction ps1 = inputFraction();

    cout << "Nhap phan so thu hai: " << endl;
    Fraction ps2 = inputFraction();
}

// Initialize a new Fraction with the given numerator and denominator.
Fraction::Fraction(int iNumerator, int iDenominator) {
    this->iNumerator = iNumerator;
    this->iDenominator = iDenominator;
    reduce();
}

void Fraction::reduce() {
    int g = gcd(abs(iNumerator), abs(iDenominator));
    iNumerator /= g;
    iDenominator /= g;
    // Keep the sign on the numerator
    if (iDenominator < 0) {
        iNumerator = -iNumerator;
        iDenominator = -iDenominator;
    }
}