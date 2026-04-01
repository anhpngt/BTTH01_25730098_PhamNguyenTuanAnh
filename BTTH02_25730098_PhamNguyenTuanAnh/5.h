// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 5. Cài đặt lớp biểu diễn khái niệm ngày tháng năm với các thành phần dữ liệu
// ngày, tháng, năm và các thao tác thích hợp (nhập, xuất, thiết lập, thay đổi
// ngày/tháng/năm, lấy ngày/tháng/năm, tăng/giảm ngày/tháng/năm, lấy thứ trong
// tuần, kiểm tra năm nhuận,…). Viết chương trình minh họa các chức năng đã cài
// đặt của lớp ngày tháng năm.

#pragma once

#include <iostream>
#include <string>

using namespace std;

class cDate
{
  private:
    int iDay;
    int iMonth;
    int iYear;

    bool IsValid();
    int DaysInMonth();

  public:
    cDate();
    cDate(int iDay, int iMonth, int iYear);
    static cDate InputFromConsole();
    string ToString();
    void OutputToConsole();

    void SetDay(int iDay);
    void SetMonth(int iMonth);
    void SetYear(int iYear);
    int GetDay();
    int GetMonth();
    int GetYear();

    void AddDays(int iDays);
    void AddMonths(int iMonths);
    void AddYears(int iYears);
    void AddDate(cDate date);

    int GetDateOfWeek();
    bool IsLeapYear();
};