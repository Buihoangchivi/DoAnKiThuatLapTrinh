#ifndef _MY_DRAW
#define _MY_DRAW

#define MAX 50

//mảng hệ số k các hàm số
extern int arr_k[MAX];

//mảng hệ số a các hàm số
extern float arr_a[MAX];

//mảng hệ số b các hàm số
extern float arr_b[MAX];

//mảng hệ số c các hàm số
extern float arr_c[MAX];

//mảng hệ số d các hàm số
extern float arr_d[MAX];

//mảng hệ số e các hàm số
extern float arr_e[MAX];

//số lượng các hàm số lưu trong các mảng trên
extern int NN;

//Vẽ đồ thị Hàm số Sin(x)
void Sin();

//Vẽ đồ thị Hàm số Cos(x)
void Cos();

//Vẽ đồ thị Hàm số Tan(x)
void Tan();

//Vẽ đồ thị Hàm số Cotan(x)
void CoTan();

//Vẽ đồ thị Hàm số bậc nhất y = ax + b
void PT1(float a, float b);

//Vẽ đồ thị Hàm số bậc hai ax^2 + bx + c
void PT2(float a, float b, float c);

//Vẽ đồ thị Hàm số bậc ba ax^3 + bx^2 + cx + d
void PT3(float a, float b, float c, float d);

//Vẽ đồ thị Hàm số bậc bốn ax^4 + bx^2 + c
void PT4(float a, float b, float c);

//Vẽ đồ thị Hàm phân thức (ax + b) / (cx + d)
void PT5(float a, float b, float c, float d);

//Vẽ đồ thị Hàm phân thức (ax^2 + bx + c) / (dx + e)
void PT6(float a, float b, float c, float d, float e);

//Vẽ đồ thị phương trình đường tròn (x - a)^2 + (y - b)^2 = c^2
void PT7(float a, float b, float c);

//Vẽ đồ thị phương trình Elips (x^2 / a^2) + (y^2 / b^2) = 1
void PT8(float a, float b);

//Vẽ đồ thị phương trình hyperbol (x - h)^2 / a^2 - (y - k)^2 / b^2 = 1
void PT9(float a, float b, float c, float d);

//Vẽ đồ thị phương trình parabol (ax + by)^2 + cx + dy + e = 0
void PT10(float a, float b, float c, float d, float e);

//Vẽ đồ thị Hàm số [Ln(x)] ^ a
void PT11(float a);

//Vẽ đồ thị LogA(x)
void PT12(float a);

//Vẽ đồ thị e ^ x
void PT13();

//Vẽ đồ thị hàm căn thức Hàm số bậc nhất ax + b
void PT18(float a, float b);

//Vẽ đồ thị hàm căn thức Hàm số bậc hai ax^2 + bx + c
void PT19(float a, float b, float c);

//Vẽ đồ thị hàm căn thức Hàm số bậc ba ax^3 + bx^2 + cx + d
void PT20(float a, float b, float c, float d);

//Vẽ đồ thị hàm căn thức Hàm số bậc bốn ax^4 + bx^2 + c
void PT21(float a, float b, float c);

//Vẽ đồ thị hàm căn thức Hàm phân thức (ax + b) / (cx + d)
void PT22(float a, float b, float c, float d);

//Vẽ đồ thị hàm căn thức Hàm phân thức (ax^2 + bx + c) / (dx + e)
void PT23(float a, float b, float c, float d, float e);

//Vẽ đồ thị hàm trị tuyệt đối Hàm số bậc nhất ax + b
void PT24(float a, float b);

//Vẽ đồ thị hàm trị tuyệt đối Hàm số bậc hai ax^2 + bx + c
void PT25(float a, float b, float c);

//Vẽ đồ thị hàm trị tuyệt đối Hàm số bậc ba ax^3 + bx^2 + cx + d
void PT26(float a, float b, float c, float d);

//Vẽ đồ thị hàm trị tuyệt đối Hàm số bậc bốn ax^4 + bx^2 + c
void PT27(float a, float b, float c);

//Vẽ đồ thị hàm trị tuyệt đối Hàm phân thức (ax + b) / (cx + d)
void PT28(float a, float b, float c, float d);

//Vẽ đồ thị hàm trị tuyệt đối Hàm phân thức (ax^2 + bx + c) / (dx + e)
void PT29(float a, float b, float c, float d, float e);

//Tìm giá trị nhỏ hơn
float min(float a, float b);

//Vẽ đồ thị
void Display();

//Khởi tạo các chỉ số cho đồ thị(kích thước đồ thị, vị trí hiển thị, màu nền,...)
void Init();

//Hàm thực hiện các thao tác trên thư viện Open GL
void Draw(int argc, char **argv);

#endif
