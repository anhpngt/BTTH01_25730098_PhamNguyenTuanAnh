// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 6. Viết chương trình cho phép người dùng nhập vào danh sách học sinh (thông tin
// mỗi học sinh giống bài 5). Tìm và xuất thông tin học sinh có điểm trung bình cao
// nhất, thấp nhất ra màn hình.

#include "6.h"
#include <iostream>

using namespace std;

#define MAX_STUDENTS 100

// Helper function to input a student from the user.
Student InputStudent()
{
	string sName;
	float fScoreMath, fScoreLiterature;
	cin.ignore(); // there's a "\n" left in the buffer
	cout << "\tNhap ho ten: ";
	getline(cin, sName);
	cout << "\tNhap diem toan: ";
	cin >> fScoreMath;
	cout << "\tNhap diem van: ";
	cin >> fScoreLiterature;
	return Student(sName, fScoreMath, fScoreLiterature);
}

int main()
{
	int iN;
	cout << "Nhap so luong hoc sinh: ";
	cin >> iN;
	if (iN <= 0)
	{
		cout << "So luong hoc sinh phai lon hon 0." << endl;
		return 1;
	}

	// Get all the students
	Student arrStudents[MAX_STUDENTS];
	for (int i = 0; i < iN; i++)
	{
		cout << "Nhap thong tin hoc sinh thu " << (i + 1) << ":" << endl;
		arrStudents[i] = InputStudent();
	}

	// Find the student with the highest score
	int iBestStudentIndex = 0;
	for (int i = 1; i < iN; i++)
	{
		if (arrStudents[i].AverageScore() > arrStudents[iBestStudentIndex].AverageScore())
		{
			iBestStudentIndex = i;
		}
	}
	cout << "Hoc sinh co diem trung binh cao nhat: " << endl;
	arrStudents[iBestStudentIndex].Print();

	// Find the student with the lowest score
	int iWorstStudentIndex = 0;
	for (int i = 1; i < iN; i++)
	{
		if (arrStudents[i].AverageScore() < arrStudents[iWorstStudentIndex].AverageScore())
		{
			iWorstStudentIndex = i;
		}
	}
	cout << "Hoc sinh co diem trung binh thap nhat: " << endl;
	arrStudents[iWorstStudentIndex].Print();

	return 0;
}

// Default constructor: initializes to empty name and 0 scores.
Student::Student()
{
	this->sName = "";
	this->fScoreMath = 0;
	this->fScoreLiterature = 0;
}

// Initialize a new Student with the given name and scores.
Student::Student(string sName, float fScoreMath, float fScoreLiterature)
{
	this->sName = sName;
	this->fScoreMath = fScoreMath;
	this->fScoreLiterature = fScoreLiterature;
}

// Print the student's information to the console.
void Student::Print()
{
	cout << "Ho ten: " << sName << endl;
	cout << "Diem toan: " << fScoreMath << endl;
	cout << "Diem van: " << fScoreLiterature << endl;
	cout << "Diem trung binh: " << AverageScore() << endl;
}

// Return the average score of the student.
float Student::AverageScore()
{
	return (fScoreMath + fScoreLiterature) / 2;
}
