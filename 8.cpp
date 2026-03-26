// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

/**
8. Viết chương trình cho phép người dùng nhập vào một ngày (ngày tháng năm).
Xuất ra thứ trong tuần của ngày đó
*/

#include <iostream>
#include <string>
#include "8.h"

using namespace std;

Date inputDate()
{
    uint iDay, iMonth, iYear;
    cout << "Nhap ngay thang nam (dd mm yyyy): ";
    cin >> iDay >> iMonth >> iYear;
    return Date(iDay, iMonth, iYear);
}

int main()
{
    Date date = inputDate();
    if (!date.IsValid())
    {
        cout << "Ngay thang nam khong hop le." << endl;
        return 1;
    }

    cout << "Ngay thang nam hop le: " << date.ToString() << endl;
    cout << "Thu trong tuan: " << date.DayOfWeek() << endl;
    return 0;
}

Date::Date(uint iDay, uint iMonth, uint iYear)
{
    this->iDay = iDay;
    this->iMonth = iMonth;
    this->iYear = iYear;
}

// Returns true if the date is valid.
bool Date::IsValid()
{
    if (this->iYear < 1)
        return false; // year must be positive

    switch (this->iMonth)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (this->iDay < 1 || this->iDay > 31)
                return false; // day must be between 1 and 31 for these months
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (this->iDay < 1 || this->iDay > 30)
                return false; // day must be between 1 and 30 for these months
            break;
        case 2:
            if (this -> iYear % 4 == 0 && (this -> iYear % 100 != 0 || this -> iYear % 400 == 0))
            {
                if (this -> iDay < 1 || this -> iDay > 29)
                    return false; // day must be between 1 and 29 for February in a leap year
            }
            else
            {
                if (this -> iDay < 1 || this -> iDay > 28)
                    return false; // day must be between 1 and 28 for February in a non-leap year
            }
            break;
        default:
            return false; // month must be between 1 and 12
    }
    return true;
}

// Returns the next day of the date using Zeller's congruence.
//
// For reference, see: https://en.wikipedia.org/wiki/Zeller%27s_congruence
string Date::DayOfWeek()
{
    int d = iDay;
    int m = iMonth;
    int y = iYear;
    if (m < 3)
    {
        m += 12;
        y--;
    }

    int h = (d + 13 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;

    string days[] = {"Thu Bay", "Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau"};
    return days[h];
}

// Returns the date as a string in the format of dd/mm/yyyy.
string Date::ToString()
{
    return to_string(this->iDay) + "/" + to_string(this->iMonth) + "/" + to_string(this->iYear);
}
