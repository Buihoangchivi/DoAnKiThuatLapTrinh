#ifndef _MY_DRAW
#define _MY_DRAW

#define MAX 50

extern int arr_k[MAX];
extern float arr_a[MAX];
extern float arr_b[MAX];
extern float arr_c[MAX];
extern float arr_d[MAX];
extern float arr_e[MAX];
extern int NN;

void Sin();
void Cos();
void Tan();
void CoTan();
void PT1(float a, float b);
void PT2(float a, float b, float c);
void PT3(float a, float b, float c, float d);
void PT4(float a, float b, float c);
void PT5(float a, float b, float c, float d);
void PT6(float a, float b, float c, float d, float e);
void PT7(float a, float b, float c);
void PT8(float a, float b, float c);
void PT9(float a, float b, float c, float d);
void PT10(float a, float b, float c, float d, float e);
void PT11(float a);
void PT12(float a);
void PT13();
void PT18(float a, float b);
void PT19(float a, float b, float c);
void PT20(float a, float b, float c, float d);
void PT21(float a, float b, float c);
void PT22(float a, float b, float c, float d);
void PT23(float a, float b, float c, float d, float e);
void Display();
void Init();
void Draw(int argc, char **argv);

#endif