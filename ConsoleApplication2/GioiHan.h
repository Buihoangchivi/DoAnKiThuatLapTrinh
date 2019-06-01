#pragma once

//Tìm giới hạn của các hàm số với các hệ số tương ứng
//select = 1 nghĩa là tìm lim khi x -> +oo
//select = 2 nghĩa là tìm lim khi x -> -oo
//select = 3 nghĩa là tìm lim khi x -> x0
void GioiHan(int k, float a, float b, float c, float d, float e, int select);

//k <= 6: Tìm giới hạn của Hàm số bậc nhất y = ax + b
//k > 6 : Tìm giới hạn của trị tuyệt đối Hàm số bậc nhất y = ax + b
void GioiHan1(float a, float b, int select, int k);

//k <= 6: Tìm giới hạn của Hàm số bậc hai ax^2 + bx + c
//k > 6 : Tìm giới hạn của trị tuyệt đối Hàm số bậc hai ax^2 + bx + c 
void GioiHan2(float a, float b, float c, int select, int k);

//k <= 6: Tìm giới hạn của Hàm số bậc ba ax^3 + bx^2 + cx + d
//k > 6 : Tìm giới hạn của trị tuyệt đối Hàm số bậc ba ax^3 + bx^2 + cx + d
void GioiHan3(float a, float b, float c, float d, int select, int k);

//k <= 6: Tìm giới hạn của Hàm số bậc bốn ax^4 + bx^2 + c
//k > 6 : Tìm giới hạn của trị tuyệt đối Hàm số bậc bốn ax^4 + bx^2 + c
void GioiHan4(float a, float b, float c, int select, int k);

//k <= 6: Tìm giới hạn của Hàm phân thức (ax + b) / (cx + d)
//k > 6 : Tìm giới hạn của trị tuyệt đối Hàm phân thức (ax + b) / (cx + d)
void GioiHan5(float a, float b, float c, float d, int select, int k);

//k <= 6: Tìm giới hạn của Hàm phân thức (ax^2 + bx + c) / (dx + e)
//k > 6 : Tìm giới hạn của trị tuyệt đối Hàm phân thức (ax^2 + bx + c) / (dx + e)
void GioiHan6(float a, float b, float c, float d, float e, int select, int k);

//Tìm giới hạn của Hàm số [Ln(x)] ^ a
void GioiHan11(float b, int select);

//Tìm giới hạn của Hàm số LogA(x)
void GioiHan12(float a, int select);

//Tìm giới hạn của e ^ x
void GioiHan13(int select);

//Tìm giới hạn của Sin(x)
void GioiHan14(int select);

//Tìm giới hạn của Cos(x)
void GioiHan15(int select);

//Tìm giới hạn của Tan(x)
void GioiHan16(int select);

//Tìm giới hạn của Cotan(x)
void GioiHan17(int select);

//Tìm giới hạn của hàm căn thức Hàm số bậc nhất ax + b
void GioiHan18(float a, float b, int select);

//Tìm giới hạn của hàm căn thức Hàm số bậc hai ax^2 + bx + c
void GioiHan19(float a, float b, float c, int select);

//Tìm giới hạn của hàm căn thức Hàm số bậc ba ax^3 + bx^2 + cx + d
void GioiHan20(float a, float b, float c, float d, int select);

//Tìm giới hạn của hàm căn thức Hàm số bậc bốn ax^4 + bx^2 + c
void GioiHan21(float a, float b, float c, int select);

//Tìm giới hạn của hàm căn thức Hàm phân thức (ax + b) / (cx + d)
void GioiHan22(float a, float b, float c, float d, int select);

//Tìm giới hạn của hàm căn thức Hàm phân thức (ax^2 + bx + c) / (dx + e)
void GioiHan23(float a, float b, float c, float d, float e, int select);

//Chọn loại giới hạn và tìm giới hạn của các hàm số với hệ số tương ứng
void Choice_And_Lim(int k, float a, float b, float c, float d, float e);
