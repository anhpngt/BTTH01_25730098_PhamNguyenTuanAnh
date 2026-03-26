// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

#pragma once

#include <string>

using namespace std;

class Date
{
private:
	unsigned int iDay;
	unsigned int iMonth;
	unsigned int iYear;

public:
	Date(unsigned int iDay, unsigned int iMonth, unsigned int iYear);
	bool IsValid();
	string DayOfWeek();
	string ToString(); // to print easily, rather than using Print()
};
