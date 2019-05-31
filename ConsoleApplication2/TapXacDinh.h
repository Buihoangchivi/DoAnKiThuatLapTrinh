#ifndef _MY_TXD
#define _MY_TXD

<<<<<<< HEAD
//Xác định Tập xác định của các hàm số với các hệ số tương ứng
void TapXacDinh(int k, float a, float b, float c, float d, float e);

//Tập xác định là R
void TapXacDinh_1();

//Tập xác định của hàm phân thức (ax + b) / (cx + d) và hàm trị tuyệt đối của nó
void TapXacDinh_2(float a, float b, float c, float d);

//Tập xác định của hàm phân thức (ax^2 + bx + c) / (dx + e) và hàm trị tuyệt đối của nó
void TapXacDinh_3(float a, float b, float c, float d, float e);

//Tập xác định của hàm Tan(x)
=======
//k là loại hàm số; a, b, c, d, e là các hệ số của hàm số đó (nếu có).
void TapXacDinh(int k, float a, float b, float c, float d, float e); 
//Xuất ra tập xác định là R
void TapXacDinh_1(); 
//Tập xác định của hàm phân thức hữu tỉ (ax+b)/(cx+d)
void TapXacDinh_2(float a, float b, float c, float d); 
//Tập xác định của hàm phân thức (ax^2+bx+c)/(dx+e)
void TapXacDinh_3(float a, float b, float c, float d, float e); 
>>>>>>> 552c98105db49f4fc5e82d7f7596b52e5f1b32a0
void TapXacDinh_4();

//Tập xác định của hàm Cot(x)
void TapXacDinh_5();

//Tập xác định của hàm [Ln(x)] ^ a
void TapXacDinh_11(float a);

//Tập xác định của hàm LogA(x)
void TapXacDinh_12(float a);

//Tập xác định của hàm căn thức Hàm số bậc nhất ax + b
void TapXacDinh_18(float a, float b);

//Tập xác định của hàm căn thức Hàm số bậc hai ax^2 + bx + c
void TapXacDinh_19(float a, float b, float c);

//Tập xác định của hàm căn thức Hàm số bậc ba ax^3 + bx^2 + cx + d
void TapXacDinh_20(float a, float b, float c, float d);

//Tập xác định của hàm căn thức Hàm số bậc bốn ax^4 + bx^2 + c
void TapXacDinh_21(float a, float b, float c);

//Tập xác định của hàm căn thức Hàm phân thức (ax + b) / (cx + d)
void TapXacDinh_22(float a, float b, float c, float d);

//Tập xác định của hàm căn thức Hàm phân thức (ax^2 + bx + c) / (dx + e)
void TapXacDinh_23(float a, float b, float c, float d, float e);

#endif
