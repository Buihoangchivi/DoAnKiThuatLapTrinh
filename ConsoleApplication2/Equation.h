#ifndef _MY_EQUATION
#define _MY_EQUATION

float Equa_1(float a, float b, float x);
float Equa_2(float a, float b, float c, float x);
float Equa_3(float a, float b, float c, float d, float x);
float Equa_4(float a, float b, float c, float x);
float Equa_5(float a, float b, float c, float d, float x);
float Equa_6(float a, float b, float c, float d, float e, float x);
void Equa_7(float a, float b, float r, float x, float& y1, float& y2);
void Equa_8(float a, float b, float x, float& y1, float& y2);
void Equa_9(float h, float k, float a, float b, float x, float &y1, float &y2);
void Equa_10(float a, float b, float c, float d, float e, float x, float &y1, float &y2, short& k);
void GiaiPT_Bac2(float a, float b, float c, float &x, float &y, short &k);
void GiaiPT_Bac3(float A, float B, float C, float D, float& X1, float& X2, float& X3, short& K);
void GiaiPT_Bac4(float A, float B, float C, float D, float E, float& X1, float& X2, float& X3, float& X4, short& K);
float Equa_4s(float a, float b, float c, float d, float e, float x);
float Equa_5s(float a, float b, float c, float d, float e, float f, float x);
float FindSolution5_1(float a, float b, float c, float d, float e, float f, float start, float end);
float FindSolution5_2(float a, float b, float c, float d, float e, float f, float start, float end);
void GiaiPT_Bac5(float a, float b, float c, float d, float e, float f, float& x1, float& x2, float& x3, float& x4, float& x5, short& k);

#endif