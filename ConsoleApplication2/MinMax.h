#pragma once
#ifndef _MY_MINMAX
#define _MY_MINMAX

//Tìm cực trị của các hàm số với các hệ số tương ứng
void MinMax(int k, float a, float b, float c, float d, float e);

//Hàm số không có cực trị
void MinMax_1();

//Tìm cực trị của Hàm số bậc hai ax^2 + bx + c
void MinMax_2(float a, float b, float c);

//Tìm cực trị của Hàm số bậc ba ax^3 + bx^2 + cx + d
void MinMax_3(float a, float b, float  c, float  d);

//Tìm cực trị của Hàm số bậc bốn ax^4 + bx^2 + c
void MinMax_4(float a, float b, float c);

//Tìm cực trị của Hàm phân thức (ax^2 + bx + c) / (dx + e)
void MinMax_6(float a, float b, float c, float d, float e);

//Tìm cực trị của Hàm số Tan(x)
void MinMax_16();

//Tìm cực trị của Hàm số Cotan(x)
void MinMax_17();

//Tìm cực trị của hàm căn thức Hàm số bậc hai ax^2 + bx + c
void MinMax_19(float a, float b, float c);

//Tìm cực trị của Hàm số hàm căn thức Hàm số bậc ba ax^3 + bx^2 + cx + d
void MinMax_20(float a, float b, float c, float d);

//Tìm cực trị của Hàm số hàm căn thức Hàm số bậc bốn ax^4 + bx^2 + c
void MinMax_21(float a, float b, float c);

//Tìm cực trị của Hàm số hàm căn thức Hàm phân thức (ax + b) / (cx + d)
void MinMax_22(float a, float b, float c, float d);

#endif
#pragma once
