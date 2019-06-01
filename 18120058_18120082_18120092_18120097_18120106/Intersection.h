#pragma once
#ifndef _MY_INTER
#define _MY_INTER

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

//Hàm tìm giao điểm của lần lượt từng cặp đồ thị khác nhau từng đôi một với ii = arr_k[i], jj = arr_k[j]
void Inter(int ii, int jj, int i, int j);

//Hàm tìm giao điểm của Hàm số bậc nhất y = a1x + b1 và Hàm số bậc nhất y = a2x + b2
void Inter_1_1(float a1, float b1, float a2, float b2);

//Hàm tìm giao điểm của Hàm số bậc nhất y = ax + b và Hàm số bậc hai a1x^2 + b1x + c1
void Inter_1_2(float a, float b, float a1, float b1, float c1);

//Hàm tìm giao điểm của Hàm số bậc nhất y = ax + b và Hàm số bậc ba a1x^3 + b1x^2 + c1x + d1
void Inter_1_3(float a, float b, float a1, float b1, float c1, float d1);

//Hàm tìm giao điểm của Hàm số bậc nhất y = ax + b và Hàm số bậc bốn a1x^4 + b1x^2 + c1
void Inter_1_4(float a, float b, float a1, float b1, float c1);

//Hàm tìm giao điểm của Hàm số bậc nhất y = ax + b và Hàm phân thức (a1x + b1) / (c1x + d1)
void Inter_1_5(float a, float b, float a1, float b1, float c1, float d1);

//Hàm tìm giao điểm của Hàm số bậc nhất y = ax + b và Hàm phân thức (a1x^2 + b1x + c1) / (d1x + e1)
void Inter_1_6(float a, float b, float a1, float b1, float c1, float d1, float e1);

//Hàm tìm giao điểm của Hàm số bậc hai a1x^2 + b1x + c1 và Hàm số bậc hai a2x^2 + b2x + c2
void Inter_2_2(float a1, float b1, float c1, float a2, float b2, float c2);

//Hàm tìm giao điểm của Hàm số bậc hai a1x^2 + b1x + c1 và Hàm số bậc ba a2x^3 + b2x^2 + c2x + d2
void Inter_2_3(float a1, float b1, float c1, float a2, float b2, float c2, float d2);

//Hàm tìm giao điểm của Hàm số bậc hai ax^2 + bx + c và Hàm số bậc bốn a2x^4 + b2x^2 + c2
void Inter_2_4(float a1, float b1, float c1, float a2, float b2, float c2);

//Hàm tìm giao điểm của Hàm số bậc hai ax^2 + bx + c và Hàm phân thức (a2x + b2) / (c2x + d2)
void Inter_2_5(float a1, float b1, float c1, float a2, float b2, float c2, float d2);

//Hàm tìm giao điểm của Hàm số bậc hai ax^2 + bx + c và Hàm phân thức (a2x^2 + b2x + c2) / (d2x + e2)
void Inter_2_6(float a1, float b1, float c1, float a2, float b2, float c2, float d2, float e2);

//Hàm tìm giao điểm của Hàm số bậc ba a1x^3 + b1x^2 + c1x + d1 và Hàm số bậc ba a2x^3 + b2x^2 + c2x + d2
void Inter_3_3(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2);

//Hàm tìm giao điểm của Hàm số bậc ba a1x^3 + b1x^2 + c1x + d1 và Hàm số bậc bốn a2x^4 + b2x^2 + c2
void Inter_3_4(float a1, float b1, float c1, float d1, float a2, float b2, float c2);

//Hàm tìm giao điểm của Hàm số bậc ba a1x^3 + b1x^2 + c1x + d1 và Hàm phân thức (a2x + b2) / (c2x + d2)
void Inter_3_5(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2);

//Hàm tìm giao điểm của Hàm số bậc ba a1x^3 + b1x^2 + c1x + d1 và Hàm phân thức (a2x^2 + b2x + c2) / (d2x + e2)
void Inter_3_6(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float e2);

//Hàm tìm giao điểm của Hàm số bậc bốn a1x^4 + b1x^2 + c1 và Hàm số bậc bốn a2x^4 + b2x^2 + c2
void Inter_4_4(float a1, float b1, float c1, float a2, float b2, float c2);

//Hàm tìm giao điểm của Hàm số bậc bốn a1x^4 + b1x^2 + c1 và Hàm phân thức (a2x + b2) / (c2x + d2)
void Inter_4_5(float a1, float b1, float c1, float a2, float b2, float c2, float d2);

//Hàm tìm giao điểm của Hàm số bậc bốn a1x^4 + b1x^2 + c1 và Hàm phân thức (a2x^2 + b2x + c2) / (d2x + e2)
void Inter_4_6(float a1, float b1, float c1, float a2, float b2, float c2, float d2, float e2);

//Hàm tìm giao điểm của Hàm phân thức (a1x + b1) / (c1x + d1) và Hàm phân thức (a2x + b2) / (c2x + d2)
void Inter_5_5(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2);

//Hàm tìm giao điểm của Hàm phân thức (a1x + b1) / (c1x + d1) và Hàm phân thức (a2x^2 + b2x + c2) / (d2x + e2)
void Inter_5_6(float a1, float b1, float c1, float d1, float a2, float b2, float c2, float d2, float e2);

//Hàm tìm giao điểm của Hàm phân thức (a1x^2 + b1x + c1) / (d1x + e1) và Hàm phân thức (a2x^2 + b2x + c2) / (d2x + e2)
void Inter_6_6(float a1, float b1, float c1, float d1, float e1, float a2, float b2, float c2, float d2, float e2);

#endif
#pragma once
