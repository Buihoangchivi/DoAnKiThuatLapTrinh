#pragma once
#ifndef _MY_BBT
#define _MY_BBT

//Vẽ bảng biến thiên của các hàm số với các hệ số tương ứng
void BBT(int k, float a, float b, float c, float d, float e);

//Vẽ bảng biến thiên của Hàm số bậc nhất y = ax + b
void BBT1(float a, float b);

//Vẽ bảng biến thiên của Hàm số bậc hai ax^2 + bx + c
void BBT2(float a, float b, float c);

//Vẽ bảng biến thiên của Hàm số bậc ba ax^3 + bx^2 + cx + d
void BBT3(float a, float b, float c, float d);

//Vẽ bảng biến thiên của Hàm số bậc bốn ax^4 + bx^2 + c
void BBT4(float a, float b, float c);

//Vẽ bảng biến thiên của Hàm phân thức (ax + b) / (cx + d)
void BBT5(float a, float b, float c, float d);

//Vẽ bảng biến thiên của Hàm phân thức (ax^2 + bx + c) / (dx + e)
void BBT6(float a, float b, float c, float d, float e);

//Vẽ bảng biến thiên của Hàm số Hàm số [Ln(x)] ^ a
void BBT11(float b);

//Vẽ bảng biến thiên của Hàm số LogA(x)
void BBT12(float a);

//Vẽ bảng biến thiên của Hàm số e ^ x
void BBT13();

//Vẽ bảng biến thiên của Hàm số Sin(x)
void BBT14();

//Vẽ bảng biến thiên của Hàm số Cos(x)
void BBT15();

//Vẽ bảng biến thiên của Hàm số Tan(x)
void BBT16();

//Vẽ bảng biến thiên của Hàm số Cotan(x)
void BBT17();

//Vẽ bảng biến thiên của căn thức Hàm số bậc nhất ax + b
void BBT18(float a, float b);

//Vẽ bảng biến thiên của căn thức Hàm số bậc hai ax^2 + bx + c
void BBT19(float a, float b, float c);

//Vẽ bảng biến thiên của căn thức Hàm số bậc ba ax^3 + bx^2 + cx + d
void BBT20(float a, float b, float c, float d);

//Vẽ bảng biến thiên của căn thức Hàm số bậc bốn ax^4 + bx^2 + c
void BBT21(float a, float b, float c);

//Vẽ bảng biến thiên của căn thức Hàm phân thức (ax + b) / (cx + d)
void BBT22(float a, float b, float c, float d);

#endif
