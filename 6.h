// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

#pragma once

#include <string>

using namespace std;

class Student
{
private:
	string sName;
	float fScoreMath;
	float fScoreLiterature;

public:
	Student();
	Student(string sName, float fScoreMath, float fScoreLiterature);
	void Print();
	float AverageScore();
};
