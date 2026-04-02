// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 6. Cài đặt lớp String để biểu diễn khái niệm chuỗi ký tự với các phương thức thiết
// lập và hủy bỏ, các hàm thành phần xác định chiều dài chuỗi, nối hai chuỗi, đảo
// chuỗi, chuyển chuỗi hoa/thường, nhập và xuất chuỗi. Viết chương trình minh họa
// các chức năng đã cài đặt của lớp String.

#pragma once

#include <iostream>
#include <string>

using namespace std;

class cString
{
private:
    char *pData;
    int iLength;

public:
    cString();
    cString(string sString);
    cString(const cString& sOther);
    cString& operator=(const cString& sOther);
    ~cString();
    static cString InputFromConsole();
    void OutputToConsole();

    int Length();
    string ToString();
    cString Concat(cString sOther);
    cString Reversed();
    cString ToUpper();
    cString ToLower();
};
