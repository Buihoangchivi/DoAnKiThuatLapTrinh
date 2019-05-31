#ifndef _MY_DAOHAM
#define _MY_DAOHAM

//Tìm đạo hàm và xét dấu các hàm số với các hệ số tương ứng
void DaoHam_XetDau(int k, float a, float b, float c, float d, float e);

//Xét dấu đạo hàm Hàm số hằng y = ax + b
void XetDau0(float a);

//Xét dấu đạo hàm Hàm số bậc nhất ax^2 + bx + c
void XetDau1(float a, float b);

//Xét dấu đạo hàm Hàm số bậc ba ax^3 + bx^2 + cx + d
//Và Xét dấu đạo hàm Hàm phân thức (ax^2 + bx + c) / (dx + e)
void XetDau2(float a, float b, float c);

//Xét dấu đạo hàm Hàm số bậc bốn ax^4 + bx^2 + c
void XetDau3(float a, float b);

//Xét dấu đạo hàm Hàm phân thức (ax + b) / (cx + d)
void XetDau4(float a, float c, float d);

//Xét dấu đạo hàm Hàm số [Ln(x)] ^ a
void XetDau11(float b);

//Xét dấu đạo hàm Hàm số LogA(x)
void XetDau12(float a);

//Xét dấu đạo hàm Sin(x)
void XetDau14();

//Xét dấu đạo hàm Cos(x)
void XetDau15();

//Xét dấu đạo hàm e ^ x
//Và xét dấu đạo hàm Tan(x)
void XetDau16();

//Xét dấu đạo hàm Cotan(x)
void XetDau17();

//Xét dấu đạo hàm căn thức Hàm số bậc nhất ax + b
void XetDau18(float a, float b);

//Xét dấu đạo hàm căn thức Hàm số bậc hai ax^2 + bx + c
void XetDau19(float a, float b, float c);

//Xét dấu đạo hàm căn thức Hàm số bậc ba ax^3 + bx^2 + cx + d
void XetDau20(float a, float b, float c, float d);

//Xét dấu đạo hàm căn thức Hàm số bậc bốn ax^4 + bx^2 + c
void XetDau21(float a, float b, float c);

//Xét dấu đạo hàm căn thức Hàm phân thức (ax + b) / (cx + d)
void XetDau22(float a, float b, float c, float d);

//Xét dấu đạo hàm căn thức Hàm phân thức (ax^2 + bx + c) / (dx + e)
void XetDau23(float a, float b, float c, float d, float e);

//Đạo hàm đạo hàm Hàm số bậc nhất ax + b
void DaoHam1(float a, float b);

//Đạo hàm Hàm số bậc nhất ax^2 + bx + c
void DaoHam2(float a, float b, float c);

//Đạo hàm Hàm số bậc ba ax^3 + bx^2 + cx + d
void DaoHam3(float a, float b, float c, float d);

//Đạo hàm Hàm số bậc bốn ax^4 + bx^2 + c
void DaoHam4(float a, float b, float c);

//Đạo hàm Hàm phân thức (ax + b) / (cx + d)
void DaoHam5(float a, float b, float c, float d);

//Đạo hàm Hàm phân thức (ax^2 + bx + c) / (dx + e)
void DaoHam6(float a, float b, float c, float d, float e);

//Đạo hàm Hàm số [Ln(x)] ^ a
void DaoHam11(float b);

//Đạo hàm Hàm số LogA(x)
void DaoHam12(float a);

//Đạo hàm e ^ x
void DaoHam13();

//Đạo hàm Sin(x)
void DaoHam14();

//Đạo hàm Cos(x)
void DaoHam15();

//Đạo hàm Tan(x)
void DaoHam16();

//Đạo hàm Cotan(x)
void DaoHam17();

//Đạo hàm căn thức Hàm số bậc nhất ax + b
void DaoHam18(float a, float b);

//Đạo hàm căn thức Hàm số bậc hai ax^2 + bx + c
void DaoHam19(float a, float b, float c);

//Đạo hàm căn thức Hàm số bậc ba ax^3 + bx^2 + cx + d
void DaoHam20(float a, float b, float c, float d);

//Đạo hàm căn thức Hàm số bậc bốn ax^4 + bx^2 + c
void DaoHam21(float a, float b, float c);

//Đạo hàm căn thức Hàm phân thức (ax + b) / (cx + d)
void DaoHam22(float a, float b, float c, float d);

//Đạo hàm căn thức Hàm phân thức (ax^2 + bx + c) / (dx + e) 
void DaoHam23(float a, float b, float c, float d, float e);

//Đạo hàm trị tuyệt đối Hàm số bậc nhất ax + b
void DaoHam24(float a, float b);

//Đạo hàm trị tuyệt đối Hàm số bậc hai ax^2 + bx + c 
void DaoHam25(float a, float b, float c);

//Đạo hàm trị tuyệt đối Hàm số bậc ba ax^3 + bx^2 + cx + d 
void DaoHam26(float a, float b, float c, float d);

//Đạo hàm trị tuyệt đối Hàm số bậc bốn ax^4 + bx^2 + c 
void DaoHam27(float a, float b, float c);

//Đạo hàm trị tuyệt đối Hàm phân thức (ax + b) / (cx + d) 
void DaoHam28(float a, float b, float c, float d);

//Đạo hàm trị tuyệt đối Hàm phân thức (ax^2 + bx + c) / (dx + e)  
void DaoHam29(float a, float b, float c, float d, float e);

//Đạo hàm Hàm phân thức (ax + b) / (cx + d)
void DH_4(float a, float b, float c, float d);

//Đạo hàm Hàm phân thức (ax^2 + bx + c) / (dx + e)
void DH_5(float a, float b, float c, float d, float e);


#endif
