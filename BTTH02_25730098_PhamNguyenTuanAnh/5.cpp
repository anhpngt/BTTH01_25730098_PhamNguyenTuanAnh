// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 5. Cài đặt lớp biểu diễn khái niệm ngày tháng năm với các thành phần dữ liệu
// ngày, tháng, năm và các thao tác thích hợp (nhập, xuất, thiết lập, thay đổi
// ngày/tháng/năm, lấy ngày/tháng/năm, tăng/giảm ngày/tháng/năm, lấy thứ trong
// tuần, kiểm tra năm nhuận,…). Viết chương trình minh họa các chức năng đã cài
// đặt của lớp ngày tháng năm.

#include "5.h"

using namespace std;

int main()
{
    cout << "Nhap ngay thang nam:" << endl;
    cDate date = cDate::InputFromConsole();
    cout << "Ngay thang nam da nhap: ";
    date.OutputToConsole();

    cout << "Nhap lai ngay: ";
    int iDay;
    cin >> iDay;
    date.SetDay(iDay);
    cout << "Ngay thang nam sau khi nhap lai: ";
    date.OutputToConsole();

    cout << "Nhap lai thang: ";
    int iMonth;
    cin >> iMonth;
    date.SetMonth(iMonth);
    cout << "Ngay thang nam sau khi nhap lai: ";
    date.OutputToConsole();

    cout << "Nhap lai nam: ";
    int iYear;
    cin >> iYear;
    date.SetYear(iYear);
    cout << "Ngay thang nam sau khi nhap lai: ";
    date.OutputToConsole();

    cout << "Ket qua khi cong them 1 ngay: ";
    date.AddDays(1);
    date.OutputToConsole();

    cout << "Ket qua khi cong them 2 thang: ";
    date.AddMonths(2);
    date.OutputToConsole();

    cout << "Ket qua khi tru di 3 nam: ";
    date.AddYears(-3);
    date.OutputToConsole();

    cout << "Ket qua khi cong them 1 ngay, 2 thang, 3 nam: ";
    date.AddDate(cDate(1, 2, 3));
    date.OutputToConsole();

    cout << "Ngay trong tuan: " << date.GetDateOfWeek() << endl;

    cout << "Co phai la nam nhuan: " << (date.IsLeapYear() ? "Co" : "Khong") << endl;
    return 0;
}

// Initialize the date with default values (1 for day, 1 for month, and 1900 for
// year).
cDate::cDate()
{
    this->iDay = 1;
    this->iMonth = 1;
    this->iYear = 1;
}

// Initialize the date with the given day, month, and year.
cDate::cDate(int iDay, int iMonth, int iYear)
{
    this->iDay = iDay;
    this->iMonth = iMonth;
    this->iYear = iYear;
    if (!this->IsValid())
    {
        throw invalid_argument("Ngay thang nam khong hop le: " + this->ToString());
    }
}

// IsValid checks if the date is valid.
//
// For reference, see: https://en.wikipedia.org/wiki/Gregorian_calendar
bool cDate::IsValid()
{
    if (this->iYear < 1)
        return false;

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
            return false;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (this->iDay < 1 || this->iDay > 30)
            return false;
        break;
    case 2:
        if (this->iYear % 4 == 0 && (this->iYear % 100 != 0 || this->iYear % 400 == 0))
        {
            if (this->iDay < 1 || this->iDay > 29)
                return false;
        }
        else
        {
            if (this->iDay < 1 || this->iDay > 28)
                return false;
        }
        break;
    default:
        return false;
    }
    return true;
}

// Static method to input a date from the console.
cDate cDate::InputFromConsole()
{
    int iDay, iMonth, iYear;
    cout << "Nhap ngay thang nam (dd mm yyyy): ";
    cin >> iDay >> iMonth >> iYear;
    return cDate(iDay, iMonth, iYear);
}

// ToString converts the date to a string in the format of dd/mm/yyyy.
string cDate::ToString()
{
    return to_string(this->iDay) + "/" + to_string(this->iMonth) + "/" + to_string(this->iYear);
}

// OutputToConsole outputs the date to the console.
void cDate::OutputToConsole()
{
    cout << this->ToString() << endl;
}

// SetDay sets the day of the date.
void cDate::SetDay(int iDay)
{
    int iOldDay = this->iDay;
    this->iDay = iDay;
    if (!this->IsValid())
    {
        this->iDay = iOldDay;
        throw invalid_argument("Ngay khong hop le: " + to_string(iDay));
    }
}

// SetMonth sets the month of the date.
void cDate::SetMonth(int iMonth)
{
    int iOldMonth = this->iMonth;
    this->iMonth = iMonth;
    if (!this->IsValid())
    {
        this->iMonth = iOldMonth;
        throw invalid_argument("Thang khong hop le: " + to_string(iMonth));
    }
}

// SetYear sets the year of the date.
void cDate::SetYear(int iYear)
{
    int iOldYear = this->iYear;
    this->iYear = iYear;
    if (!this->IsValid())
    {
        this->iYear = iOldYear;
        throw invalid_argument("Nam khong hop le: " + to_string(iYear));
    }
}

// GetDay gets the day of the date.
int cDate::GetDay()
{
    return this->iDay;
}

// GetMonth gets the month of the date.
int cDate::GetMonth()
{
    return this->iMonth;
}

// GetYear gets the year of the date.
int cDate::GetYear()
{
    return this->iYear;
}

// DaysInMonth returns the number of days in the current month.
int cDate::DaysInMonth()
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (iMonth == 2 && IsLeapYear())
        return 29;
    return days[iMonth];
}

// AddDays adds the given days to the date.
void cDate::AddDays(int iDays)
{
    iDay += iDays;
    while (iDay > DaysInMonth())
    {
        iDay -= DaysInMonth();
        if (++iMonth > 12)
        {
            iMonth = 1;
            iYear++;
        }
    }
    while (iDay < 1)
    {
        if (--iMonth < 1)
        {
            iMonth = 12;
            iYear--;
        }
        iDay += DaysInMonth();
    }
}

// AddMonths adds the given months to the date.
void cDate::AddMonths(int iMonths)
{
    iMonth += iMonths;
    while (iMonth > 12)
    {
        iMonth -= 12;
        iYear++;
    }
    while (iMonth < 1)
    {
        iMonth += 12;
        iYear--;
    }
    if (iDay > DaysInMonth())
        iDay = DaysInMonth();
}

// AddYears adds the given years to the date.
void cDate::AddYears(int iYears)
{
    iYear += iYears;
    if (iDay > DaysInMonth())
        iDay = DaysInMonth();
}

// AddDate adds another date's day/month/year values to this date.
void cDate::AddDate(cDate date)
{
    AddYears(date.iYear);
    AddMonths(date.iMonth);
    AddDays(date.iDay);
}

// GetDateOfWeek returns the day of the week for the current date.
//
// For reference, see: https://en.wikipedia.org/wiki/Zeller%27s_congruence
int cDate::GetDateOfWeek()
{
    int m = iMonth, y = iYear;
    if (m < 3)
    {
        m += 12;
        y--;
    }
    int iDayOfWeek = (iDay + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return iDayOfWeek;
}

// IsLeapYear checks if the current year is a leap year.
//
// For reference, see: https://en.wikipedia.org/wiki/Leap_year
bool cDate::IsLeapYear()
{
    return (this->iYear % 4 == 0 && (this->iYear % 100 != 0 || this->iYear % 400 == 0));
}
