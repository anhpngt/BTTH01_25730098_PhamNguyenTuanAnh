// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 4. Viết chương trình cho phép người dùng nhập vào một dãy gồm n phân số. Tìm
// và xuất ra màn hình phân số lớn nhất. Sắp xếp dãy phân số tăng dần/giảm dần.

#include "4.h"
#include <algorithm>
#include <iostream>
#include <numeric>

#define MAX_FRACTIONS 100

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
	int iN;
	cout << "Nhap so luong phan so: ";
	cin >> iN;
	if (iN <= 0)
	{
		cout << "So luong phan so phai lon hon 0." << endl;
		return 1;
	}

	Fraction arrFractions[MAX_FRACTIONS];
	for (int i = 0; i < iN; i++)
	{
		cout << "Nhap phan so thu " << (i + 1) << ":" << endl;
		arrFractions[i] = InputFraction();
	}

	// Find the largest
	int iMaxIdx = 0;
	for (int i = 1; i < iN; i++)
	{
		if (arrFractions[i].CompareTo(arrFractions[iMaxIdx]) > 0)
			iMaxIdx = i;
	}
	cout << "Phan so lon nhat: ";
	arrFractions[iMaxIdx].Print();

	// Sort ascending
	sort(arrFractions, arrFractions + iN, [](Fraction a, Fraction b) { return a.CompareTo(b) < 0; });
	cout << "Day phan so sap xep tang dan:" << endl;
	for (int i = 0; i < iN; i++)
	{
		cout << "\t";
		arrFractions[i].Print();
	}
	// Sort descending
	sort(arrFractions, arrFractions + iN, [](Fraction a, Fraction b) { return a.CompareTo(b) > 0; });
	cout << "Day phan so sap xep giam dan:" << endl;
	for (int i = 0; i < iN; i++)
	{
		cout << "\t";
		arrFractions[i].Print();
	}

	return 0;
}

// Default constructor: initializes to 0/1.
Fraction::Fraction()
{
	this->iNumerator = 0;
	this->iDenominator = 1;
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
