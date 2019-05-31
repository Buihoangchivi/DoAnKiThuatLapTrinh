#ifndef _MY_WRITE_PROPOSAL
#define _MY_WRITE_PROPOSAL

//Nhập loại hàm số từ màn hình
void Input_Equation_Console(int& k);

//Nhập loại hàm số từ file
void Input_Equation_File(int& k);

//Xuất hàm số với các hệ số tương ứng đã được chuẩn hóa
void Output_Equation(int& k, float& a, float& b, float& c, float& d, float& e);

//Xuất các hàm số nâng cao (không phải 6 hàm số cơ bản, căn thức và trị tuyệt đối 6 hàm số cơ bản)
void Output_Advanced_Equation(int& k, float& a, float& b, float& c, float& d, float& e);

//Nhập loại các hàm số là các hàm căn thức hoặc hàm trị tuyệt đối 
void Ham_Khac(int& k, int temp);

//Nhập loại các hàm số là các hàm đường tròn, elips, hypebol, parabol, 
//[Ln(x)]^a, LogA(x), e^x, Sin(x), Cos(x), Tan(x), Cotan(x) 
void CacHamSoKhac(int& k, float& a, float& b, float& c, float& d, float& e);

//Nhập một số nguyên
void Input(char ch, int& k);

//Nhập một số thực
void Input(char ch, float& k);

//Xuất Hàm số bậc nhất ax + b
void PT_1(float a, float b);

//Xuất Hàm số bậc hai ax^2 + bx + c
void PT_2(float a, float b, float c);

//Xuất Hàm số bậc ba ax^3 + bx^2 + cx + d
void PT_3(float a, float b, float c, float d);

//Xuất Hàm số bậc bốn ax^4 + bx^2 + c
void PT_4(float a, float b, float c);

//Xuất Hàm phân thức (ax + b) / (cx + d)
void PT_5(float a, float b, float c, float d);

//Xuất Hàm phân thức (ax^2 + bx + c) / (dx + e)
void PT_6(float a, float b, float c, float d, float e);

//Xuất phương trình đường tròn (x - a)^2 + (y - b)^2 = c^2
void PT_7(float a, float b, float c);

//Xuất phương trình Elips (x ^ 2) / a + (y ^ 2) / b = 1
void PT_8(float a, float b);

//Xuất phương trình Hyperbol (x - h) ^ 2 / a - (y - k) ^ 2 = 1
void PT_9(float h, float k, float a, float b);

//Xuất phương trình Parabol (ax + by) ^ 2 + cx + dy + e = 0
void PT_10(float a, float b, float c, float d, float e);

#endif