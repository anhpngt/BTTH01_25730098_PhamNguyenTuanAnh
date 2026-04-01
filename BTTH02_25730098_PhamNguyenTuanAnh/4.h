// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 4. Cài đặt lớp biểu diễn khái niệm thời gian với các thành phần dữ liệu giờ,
// phút, giây và các thao tác thích hợp (nhập, xuất, thiết lập, thay đổi
// giờ/phút/giây, lấy giờ/phút/giây, tăng/giảm giờ/phút/giây,…). Viết chương
// trình minh họa các chức năng đã cài đặt của lớp Thời gian.

#pragma once

#include <iostream>
#include <string>

using namespace std;

class cTimestamp
{
  private:
    int iHour;
    int iMinute;
    int iSecond;

    bool IsValid();

  public:
    cTimestamp();
    cTimestamp(int iHour, int iMinute, int iSecond);
    static cTimestamp InputFromConsole();
    string ToString();
    void OutputToConsole();

    void SetHour(int iHour);
    void SetMinute(int iMinute);
    void SetSecond(int iSecond);
    int GetHour();
    int GetMinute();
    int GetSecond();

    cTimestamp AddSeconds(int iSeconds);
    cTimestamp AddMinutes(int iMinutes);
    cTimestamp AddHours(int iHours);
    cTimestamp AddTime(cTimestamp ts);
};
