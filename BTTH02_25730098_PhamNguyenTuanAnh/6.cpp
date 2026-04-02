// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 6. Cài đặt lớp String để biểu diễn khái niệm chuỗi ký tự với các phương thức thiết
// lập và hủy bỏ, các hàm thành phần xác định chiều dài chuỗi, nối hai chuỗi, đảo
// chuỗi, chuyển chuỗi hoa/thường, nhập và xuất chuỗi. Viết chương trình minh họa
// các chức năng đã cài đặt của lớp String.

#include "6.h"
#include <cstring>

using namespace std;

int main()
{
    cString s1 = cString::InputFromConsole();

    cout << "Chuoi ky tu vua nhap: ";
    s1.OutputToConsole();

    cout << "Chieu dai cuoi ky tu: " << s1.Length() << endl;
    cout << "Chuoi ky tu viet hoa: " << s1.ToUpper().ToString() << endl;
    cout << "Chuoi ky tu viet thuong: " << s1.ToLower().ToString() << endl;
    cout << "Chuoi ky tu dao nguoc: " << s1.Reversed().ToString() << endl;

    cString s2 = cString::InputFromConsole();
    cout << "Chuoi ky tu duoc noi tu hai chuoi vua nhap: " << s1.Concat(s2).ToString() << endl;

    return 0;
}

cString::cString()
{
    this->iLength = 0;
    this->pData = nullptr;
}

cString::cString(string sString)
{
    this->iLength = sString.length();
    this->pData = new char[this->iLength + 1];
    strcpy(this->pData, sString.c_str());
}

cString::cString(const cString &sOther)
{
    this->iLength = sOther.iLength;
    if (sOther.pData != nullptr)
    {
        this->pData = new char[this->iLength + 1];
        strcpy(this->pData, sOther.pData);
    }
    else
    {
        this->pData = nullptr;
    }
}

cString::~cString()
{
    delete[] this->pData;
}

cString cString::InputFromConsole()
{
    string sNhap;
    cout << "Nhap chuoi ky tu: ";
    getline(cin, sNhap);
    return cString(sNhap);
}

void cString::OutputToConsole()
{
    cout << this->ToString() << endl;
}

string cString::ToString()
{
    if (this->pData == nullptr)
        return "";
    return string(this->pData);
}

int cString::Length()
{
    return this->iLength;
}

cString cString::ToUpper()
{
    cString sUpper = cString();
    sUpper.iLength = this->iLength;
    sUpper.pData = new char[this->iLength + 1];
    for (int i = 0; i < sUpper.iLength; i++) // or we could've used toupper()
    {
        if (this->pData[i] >= 'a' && this->pData[i] <= 'z')
            sUpper.pData[i] = (this->pData[i] - 32);
        else
            sUpper.pData[i] = this->pData[i];
    }
    sUpper.pData[sUpper.iLength] = '\0';
    return sUpper;
}

cString cString::ToLower()
{
    cString sLower = cString();
    sLower.iLength = this->iLength;
    sLower.pData = new char[this->iLength + 1];
    for (int i = 0; i < sLower.iLength; i++)
    {
        if (this->pData[i] >= 'A' && this->pData[i] <= 'Z')
            sLower.pData[i] = (this->pData[i] + 32);
        else
            sLower.pData[i] = this->pData[i];
    }
    sLower.pData[sLower.iLength] = '\0';
    return sLower;
}

cString cString::Concat(cString sOther)
{
    cString sCombined = cString();
    sCombined.iLength = this->iLength + sOther.iLength;
    sCombined.pData = new char[sCombined.iLength + 1];
    strcpy(sCombined.pData, this->pData);
    strcpy(sCombined.pData + iLength, sOther.pData);
    return sCombined;
}

cString cString::Reversed()
{
    cString sReversed = cString();
    sReversed.iLength = this->iLength;
    sReversed.pData = new char[sReversed.iLength + 1];
    for (int i = 0; i < this->iLength; i++)
    {
        sReversed.pData[this->iLength - 1 - i] = this->pData[i];
    }
    sReversed.pData[this->iLength] = '\0';
    return sReversed;
}