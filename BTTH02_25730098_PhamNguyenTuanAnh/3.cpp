// Mã số sinh viên: 25730098
// Họ và tên: Phạm Nguyễn Tuấn Anh
// Ngày sinh: 15/05/1996
// Lớp: CN1.K2025.2.CNTT

// 3. Cài đặt lớp biểu diễn khái niệm số phức với hai thành phần dữ liệu thực,
// ảo và các hàm thành phần xuất, nhập, định giá trị cho số phức, cộng, trừ,
// nhân, chia hai số phức. Viết chương trình cho phép nhập vào hai số phức, in
// ra kết quả các phép toán cộng, trừ, nhân, chia hai số phức kể trên. Ví dụ:
// Cho hai số phức A(a1, a2), B(b1, b2)  A + B = (a1+b1, a2+b2)  A - B
// = (a1-b1, a2-b2)  A * B = (a1*b1 – a2*b2, a1*b2+a2*b1)  A / B =

#include "3.h"

using namespace std;

int main()
{
    cout << "Nhap so phuc A: " << endl;
    cComplexNumber cA = cComplexNumber::InputFromConsole();
    cout << "Nhap so phuc B: " << endl;
    cComplexNumber cB = cComplexNumber::InputFromConsole();

    cout << "A = ";
    cA.OutputToConsole();
    cout << "B = ";
    cB.OutputToConsole();

    cout << "A + B = ";
    cA.Add(cB).OutputToConsole();
    cout << "A - B = ";
    cA.Subtract(cB).OutputToConsole();
    cout << "A * B = ";
    cA.Multiply(cB).OutputToConsole();
    cout << "A / B = ";
    cA.Divide(cB).OutputToConsole();

    return 0;
}

// Initialize the complex number with default values (0.0 for both real and
// imaginary parts).
cComplexNumber::cComplexNumber()
{
    cComplexNumber(0.0f, 0.0f);
}

// Initialize the complex number with the given real and imaginary parts.
cComplexNumber::cComplexNumber(float fReal, float fImaginary)
{
    this->fReal = fReal;
    this->fImaginary = fImaginary;
}

// Static method to input a complex number from the console.
cComplexNumber cComplexNumber::InputFromConsole()
{
    float fReal, fImaginary;

    cout << "\tNhap phan thuc: ";
    cin >> fReal;
    cout << "\tNhap phan ao: ";
    cin >> fImaginary;

    return cComplexNumber(fReal, fImaginary);
}

// Method to convert the complex number to a string representation "(real,
// imaginary)".
string cComplexNumber::ToString()
{
    return "(" + to_string(fReal) + ", " + to_string(fImaginary) + ")";
}

// Output the complex number to the console.
void cComplexNumber::OutputToConsole()
{
    cout << ToString() << endl;
}

// Set the real part of the complex number.
void cComplexNumber::setReal(float fReal)
{
    this->fReal = fReal;
}

// Set the imaginary part of the complex number.
void cComplexNumber::setImaginary(float fImaginary)
{
    this->fImaginary = fImaginary;
}

// Get the real part of the complex number.
float cComplexNumber::getReal()
{
    return fReal;
}

// Get the imaginary part of the complex number.
float cComplexNumber::getImaginary()
{
    return fImaginary;
}

// Adds two complex numbers and returns the result as a new complex number.
cComplexNumber cComplexNumber::Add(cComplexNumber cOther)
{
    return cComplexNumber(fReal + cOther.fReal, fImaginary + cOther.fImaginary);
}

// Subtracts another complex number from this complex number and returns the
// result as a new complex number.
cComplexNumber cComplexNumber::Subtract(cComplexNumber cOther)
{
    return cComplexNumber(fReal - cOther.fReal, fImaginary - cOther.fImaginary);
}

// Multiplies this complex number by another complex number and returns the
// result as a new complex number.
cComplexNumber cComplexNumber::Multiply(cComplexNumber cOther)
{
    float realPart = fReal * cOther.fReal - fImaginary * cOther.fImaginary;
    float imaginaryPart = fReal * cOther.fImaginary + fImaginary * cOther.fReal;
    return cComplexNumber(realPart, imaginaryPart);
}

// Divides this complex number by another complex number and returns the result
// as a new complex number.
cComplexNumber cComplexNumber::Divide(cComplexNumber cOther)
{
    float denominator =
        cOther.fReal * cOther.fReal + cOther.fImaginary * cOther.fImaginary;
    float realPart =
        (fReal * cOther.fReal + fImaginary * cOther.fImaginary) / denominator;
    float imaginaryPart =
        (fImaginary * cOther.fReal - fReal * cOther.fImaginary) / denominator;
    return cComplexNumber(realPart, imaginaryPart);
}
