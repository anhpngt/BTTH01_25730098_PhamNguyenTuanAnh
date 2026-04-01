// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 3. Cài đặt lớp biểu diễn khái niệm số phức với hai thành phần dữ liệu thực,
// ảo và các hàm thành phần xuất, nhập, định giá trị cho số phức, cộng, trừ,
// nhân, chia hai số phức. Viết chương trình cho phép nhập vào hai số phức, in
// ra kết quả các phép toán cộng, trừ, nhân, chia hai số phức kể trên. Ví dụ:
// Cho hai số phức A(a1, a2), B(b1, b2)  A + B = (a1+b1, a2+b2)  A - B
// = (a1-b1, a2-b2)  A * B = (a1*b1 – a2*b2, a1*b2+a2*b1)  A / B = ...

#pragma once

#include <iostream>
#include <string>

using namespace std;

class cComplexNumber
{
  private:
    float fReal;
    float fImaginary;

    string ToString();

  public:
    cComplexNumber();
    cComplexNumber(float fReal, float fImaginary);

    static cComplexNumber InputFromConsole();
    void OutputToConsole();

    void setReal(float fReal);
    void setImaginary(float fImaginary);
    float getReal();
    float getImaginary();

    cComplexNumber Add(cComplexNumber cOther);
    cComplexNumber Subtract(cComplexNumber cOther);
    cComplexNumber Multiply(cComplexNumber cOther);
    cComplexNumber Divide(cComplexNumber cOther);
};
