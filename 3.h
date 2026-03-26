// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

#pragma once

class Fraction
{
private:
	int iNumerator;
	int iDenominator;

	void Reduce();

public:
	Fraction(int iNumerator, int iDenominator);

	void Print();
	Fraction Add(Fraction other);
	Fraction Subtract(Fraction other);
	Fraction Multiply(Fraction other);
	Fraction Divide(Fraction other);
};
