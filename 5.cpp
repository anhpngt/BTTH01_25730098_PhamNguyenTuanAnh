// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 5. Viết chương trình cho phép người dùng nhập họ tên, điểm toán, điểm văn của
// một học sinh. Tính điểm trung bình và xuất kết quả ra màn hình.

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string sName;
	float fScoreMath, fScoreLiterature;
	cout << "Nhap ho ten: ";
	getline(cin, sName);
	cout << "Nhap diem toan: ";
	cin >> fScoreMath;
	cout << "Nhap diem van: ";
	cin >> fScoreLiterature;
	float fScoreAverage = (fScoreMath + fScoreLiterature) / 2;
	cout << "Ho ten: " << sName << endl;
	cout << "Diem trung binh: " << fScoreAverage << endl;

	return 0;
}