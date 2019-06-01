#ifndef _MY_EQUATION
#define _MY_EQUATION

//Tính giá trị tại x của Hàm số bậc nhất y = ax + b và trả về giá trị cho hàm
float Equa_1(float a, float b, float x);

//Tính giá trị tại x của Hàm số bậc hai ax^2 + bx + c và trả về giá trị cho hàm
float Equa_2(float a, float b, float c, float x);

//Tính giá trị tại x của Hàm số bậc ba ax^3 + bx^2 + cx + d và trả về giá trị cho hàm
float Equa_3(float a, float b, float c, float d, float x);

//Tính giá trị tại x của Hàm số bậc bốn ax^4 + bx^2 + c và trả về giá trị cho hàm
float Equa_4(float a, float b, float c, float x);

//Tính giá trị tại x của Hàm phân thức (ax + b) / (cx + d) và trả về giá trị cho hàm
float Equa_5(float a, float b, float c, float d, float x);

//Tính giá trị tại x của Hàm số bậc ba ax^3 + bx^2 + cx + d và trả về giá trị cho hàm
float Equa_6(float a, float b, float c, float d, float e, float x);

//Tính giá trị tại x của phương trình đường tròn (x - a)^2 + (y - b)^2 = r^2 và trả về giá trị cho y1, y2
void Equa_7(float a, float b, float r, float x, float& y1, float& y2);

//Tính giá trị tại x của phương trình Elips (x^2 / a^2) + (y^2 / b^2) = 1 và trả về giá trị cho y1, y2
void Equa_8(float a, float b, float x, float& y1, float& y2);

//Tính giá trị tại x của phương trình hyperbol (x - h)^2 / a^2 - (y - k)^2 / b^2 = 1 và trả về giá trị cho y1, y2
void Equa_9(float h, float k, float a, float b, float x, float &y1, float &y2);

//Tính giá trị tại x của phương trình parabol (ax + by)^2 + cx + dy + e = 0 và trả về giá trị cho y1, y2 tương ứng với số nghiệm k
void Equa_10(float a, float b, float c, float d, float e, float x, float &y1, float &y2, short& k);

//Hàm giải phương trình bậc 2 ax^2 + bx + c = 0 và trả về giá trị nghiệm cho x, y tương ứng với số nghiệm k
void GiaiPT_Bac2(float a, float b, float c, float &x, float &y, short &k);

//Hàm giải phương trình bậc 3 ax^3 + bx^2 + cx + d = 0 và trả về giá trị nghiệm cho x1, x2, x3 tương ứng với số nghiệm k
void GiaiPT_Bac3(float A, float B, float C, float D, float& X1, float& X2, float& X3, short& K);

//Hàm giải phương trình bậc 4 ax^4 + bx^3 + cx^2 + dx + e = 0 và trả về giá trị nghiệm cho x1, x2, x3, x4 tương ứng với số nghiệm k
void GiaiPT_Bac4(float A, float B, float C, float D, float E, float& X1, float& X2, float& X3, float& X4, short& K);

//Hàm tính giá trị biểu thức của bâc 4 đủ
float Equa_4s(float a, float b, float c, float d, float e, float x);

//Hàm tính giá ttrij biểu thức của bậc 5 đủ
float Equa_5s(float a, float b, float c, float d, float e, float f, float x);

//Hàm tìm nghiệm của phương trình bậc  trên đoạn [start; end] đồng biến
float FindSolution5_1(float a, float b, float c, float d, float e, float f, float start, float end);

//Hàm tìm nghiệm của phương trình bậc  trên đoạn [start; end] nghịch biến
float FindSolution5_2(float a, float b, float c, float d, float e, float f, float start, float end);

//Hàm giải phương trình bậc 5 ax^5 + bx^4 + cx^3 + dx^2 + ex + f = 0 
//và trả về giá trị nghiệm cho x1, x2, x3, x4, x5 tương ứng với số nghiệm k
void GiaiPT_Bac5(float a, float b, float c, float d, float e, float f, float& x1, float& x2, float& x3, float& x4, float& x5, short& k);

#endif
