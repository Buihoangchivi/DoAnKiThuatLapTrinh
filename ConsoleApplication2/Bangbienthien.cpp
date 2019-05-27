
#include "BangBienThien.h"
#include "Equation.h"
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>

extern FILE* input, * output;
using namespace std;

void BBT(int k, float a, float b, float c, float d, float e)
{
	fprintf(output, "Bang bien thien cua ham so tren la: \n\n");
	switch (k)
	{
	case 1:
		BBT1(a, b);
		break;
	case 2:
		BBT2(a, b, c);
		break;
	case 3:
		BBT3(a, b, c, d);
		break;
	case 4:
		BBT4(a, b, c);
		break;
	case 5:
		BBT5(a, b, c, d);
		break;
	case 6:
		BBT6(a, b, c, d, e);
		break;
	case 14:
		BBT14();
		break;
	case 15:
		BBT15();
		break;
	case 16:
		BBT16();
		break;
	case 17:
		BBT17();
		break;
	default:
		break;
	}
}

void BBT1(float a, float b)
{
	if (a > 0)
	{
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\t|  x  | -oo       +oo   |\n");
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\t|f'(x)|       +         |\n");
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\t|     |           +oo   |\n");
		fprintf(output, "\t|     |         /       |\n");
		fprintf(output, "\t|     |        /        |\n");
		fprintf(output, "\t|f(x) |       /         |\n");
		fprintf(output, "\t|     |      /          |\n");
		fprintf(output, "\t|     |     /           |\n");
		fprintf(output, "\t|     | -oo             |\n");
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\n");
	}
	else if (a < 0)
	{
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\t|  x  | -oo       +oo   |\n");
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\t|f'(x)|        -        |\n");
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\t|     | +oo             |\n");
		fprintf(output, "\t|     |      \\          |\n");
		fprintf(output, "\t|     |       \\         |\n");
		fprintf(output, "\t|f(x) |        \\        |\n");
		fprintf(output, "\t|     |         \\       |\n");
		fprintf(output, "\t|     |          \\      |\n");
		fprintf(output, "\t|     |          -oo    |\n");
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\n");
	}
}

void BBT2(float a, float b, float c)
{
	float x = -b / (2 * a);
	if (a < 0)
	{
		fprintf(output, "\t|-----|-----------------------------\n");
		fprintf(output, "\t|  x  |-oo        %.2f        +oo \n", x);
		fprintf(output, "\t|-----|-----------------------------\n");
		fprintf(output, "\t|f'(x)|      +     0     -        \n");
		fprintf(output, "\t|-----|-----------------------------\n");
		fprintf(output, "\t|     |          %.2f             \n", Equa_2(a, b, c, x));
		fprintf(output, "\t|     |        /       \\         \n");
		fprintf(output, "\t|     |       /         \\        \n");
		fprintf(output, "\t|f(x) |      / 	         \\      \n");
		fprintf(output, "\t|     |     /             \\      \n");
		fprintf(output, "\t|     |    /               \\     \n");
		fprintf(output, "\t|     |   /                 \\    \n");
		fprintf(output, "\t|     |-oo                    -oo \n");
		fprintf(output, "\t|-----|-----------------------------\n");
		fprintf(output, "\n");
	}
	else if (a > 0)
	{
		fprintf(output, "\t|-----|-----------------------------\n");
		fprintf(output, "\t|  x  |-oo        %.2f        +oo \n", x);
		fprintf(output, "\t|-----|-----------------------------\n");
		fprintf(output, "\t|f'(x)|      -     0     +        \n");
		fprintf(output, "\t|-----|-----------------------------\n");
		fprintf(output, "\t|     |+oo                    +oo \n");
		fprintf(output, "\t|     |    \\                /    \n");
		fprintf(output, "\t|     |     \\              /     \n");
		fprintf(output, "\t|f(x) |      \\            /      \n");
		fprintf(output, "\t|     |       \\          /       \n");
		fprintf(output, "\t|     |        \\        /        \n");
		fprintf(output, "\t|     |         \\      /         \n");
		fprintf(output, "\t|     |           %.2f           \n", Equa_2(a, b, c, x));
		fprintf(output, "\t|-----|-----------------------------\n");
		fprintf(output, "\n");
	}
}

void BBT3(float a, float b, float c, float d)
{
	float x, y; short k;
	GiaiPT_Bac2(3 * a, 2 * b, c, x, y, k);
	if (k == -1)
		BBT1(a, 0);
	else if (k == 0)
		if (a > 0)
		{
			fprintf(output, "\t|-----|-------------------\n");
			fprintf(output, "\t|  x  |-oo   %.2f   +oo \n", x);
			fprintf(output, "\t|-----|-------------------\n");
			fprintf(output, "\t|f'(x)|    +   0   +    \n");
			fprintf(output, "\t|-----|-------------------\n");
			fprintf(output, "\t|     |             +oo \n");
			fprintf(output, "\t|     |          /      \n");
			fprintf(output, "\t|     |         /       \n");
			fprintf(output, "\t|f(x) |      %.2f       \n", Equa_3(a, b, c, d, x));
			fprintf(output, "\t|     |       /         \n");
			fprintf(output, "\t|     |      /          \n");
			fprintf(output, "\t|     | -oo             \n");
			fprintf(output, "\t|-----|-------------------\n");
			fprintf(output, "\n");
		}
		else
		{
			fprintf(output, "\t|-----|-------------------\n");
			fprintf(output, "\t|  x  |-oo   %.2f   +oo \n", x);
			fprintf(output, "\t|-----|-------------------\n");
			fprintf(output, "\t|f'(x)|    -   0   -    \n");
			fprintf(output, "\t|-----|-------------------\n");
			fprintf(output, "\t|     | +oo             \n");
			fprintf(output, "\t|     |      \\         \n");
			fprintf(output, "\t|     |       \\        \n");
			fprintf(output, "\t|f(x) |      %.2f       \n", Equa_3(a, b, c, d, x));
			fprintf(output, "\t|     |         \\      \n");
			fprintf(output, "\t|     |          \\     \n");
			fprintf(output, "\t|     |            -oo  \n");
			fprintf(output, "\t|-----|-------------------\n");
			fprintf(output, "\n");
		}
	else if (k == 1)
		if (a > 0)
		{
			fprintf(output, "\t|-----|---------------------------------------\n");
			fprintf(output, "\t|  x  | -oo      %.2f        %.2f      +oo  \n", x, y);
			fprintf(output, "\t|-----|---------------------------------------\n");
			fprintf(output, "\t|f'(x)|      +     0     -     0    +       \n");
			fprintf(output, "\t|-----|---------------------------------------\n");
			fprintf(output, "\t|     |          %.2f                  +oo  \n", Equa_3(a, b, c, d, x));
			fprintf(output, "\t|     |        /      \\              /     \n");
			fprintf(output, "\t|     |       /        \\            /      \n");
			fprintf(output, "\t|f(x) |      / 	        \\          /       \n");
			fprintf(output, "\t|     |     /            \\        /        \n");
			fprintf(output, "\t|     |    /              \\      /         \n");
			fprintf(output, "\t|     |   /                \\    /          \n");
			fprintf(output, "\t|     | -oo                 %.2f           \n", Equa_3(a, b, c, d, y));
			fprintf(output, "\t|-----|---------------------------------------\n");
			fprintf(output, "\n");
		}
		else
		{
			fprintf(output, "\t|-----|---------------------------------------\n");
			fprintf(output, "\t|  x  | -oo      %.2f        %.2f      +oo  \n", x, y);
			fprintf(output, "\t|-----|---------------------------------------\n");
			fprintf(output, "\t|f'(x)|      -     0     +     0    -       \n");
			fprintf(output, "\t|-----|---------------------------------------\n");
			fprintf(output, "\t|     | +oo                  %.2f           \n", Equa_3(a, b, c, d, y));
			fprintf(output, "\t|     |    \\              /      \\        \n");
			fprintf(output, "\t|     |     \\            /        \\       \n");
			fprintf(output, "\t|f(x) |      \\          /          \\      \n");
			fprintf(output, "\t|     |       \\        /            \\     \n");
			fprintf(output, "\t|     |        \\      /              \\    \n");
			fprintf(output, "\t|     |         \\    /                \\   \n");
			fprintf(output, "\t|     |          %.2f                   +oo \n", Equa_3(a, b, c, d, x));
			fprintf(output, "\t|-----|---------------------------------------\n");
			fprintf(output, "\n");
		}
}

void BBT4(float a, float b, float c)
{
	if (a * b >= 0)
		if (a > 0)
		{
			fprintf(output, "\t|-----|-----------------------------\n");
			fprintf(output, "\t|  x  |-oo         0          +oo \n");
			fprintf(output, "\t|-----|-----------------------------\n");
			fprintf(output, "\t|f'(x)|      -     0     +        \n");
			fprintf(output, "\t|-----|-----------------------------\n");
			fprintf(output, "\t|     |+oo                    +oo \n");
			fprintf(output, "\t|     |    \\                /    \n");
			fprintf(output, "\t|     |     \\              /     \n");
			fprintf(output, "\t|f(x) |      \\            /      \n");
			fprintf(output, "\t|     |       \\          /       \n");
			fprintf(output, "\t|     |        \\        /        \n");
			fprintf(output, "\t|     |         \\      /         \n");
			fprintf(output, "\t|     |           %.2f            \n", Equa_4(a, b, c, 0));
			fprintf(output, "\t|-----|-----------------------------\n");
			fprintf(output, "\n");
		}
		else
		{
			fprintf(output, "\t|-----|-----------------------------\n");
			fprintf(output, "\t|  x  |-oo         0          +oo \n");
			fprintf(output, "\t|-----|-----------------------------\n");
			fprintf(output, "\t|f'(x)|      -     0     +        \n");
			fprintf(output, "\t|-----|-----------------------------\n");
			fprintf(output, "\t|     |          %.2f             \n", Equa_4(a, b, c, 0));
			fprintf(output, "\t|     |        /       \\         \n");
			fprintf(output, "\t|     |       /         \\        \n");
			fprintf(output, "\t|f(x) |      / 	         \\       \n");
			fprintf(output, "\t|     |     /             \\      \n");
			fprintf(output, "\t|     |    /               \\     \n");
			fprintf(output, "\t|     |   /                 \\    \n");
			fprintf(output, "\t|     |-oo                    -oo \n");
			fprintf(output, "\t|-----|-----------------------------\n");
			fprintf(output, "\n");
		}
	else
	{
		float x = -b / (2 * a), x1, x2;
		if (x < 0) { x1 = x; x2 = -x; }
		else if (x > 0) { x1 = -x; x2 = x; }
		if (a > 0)
		{
			fprintf(output, "\t|-----|-----------------------------------------------\n");
			fprintf(output, "\t|  x  | -oo      %.2f        0       %.2f       +oo \n", x1, x2);
			fprintf(output, "\t|-----|-----------------------------------------------\n");
			fprintf(output, "\t|f'(x)|      -     0    +    0    -    0    +       \n");
			fprintf(output, "\t|-----|-----------------------------------------------\n");
			fprintf(output, "\t|     | +oo                 0                   +oo \n");
			fprintf(output, "\t|     |    \\             /    \\              /    \n");
			fprintf(output, "\t|     |     \\           /      \\            /     \n");
			fprintf(output, "\t|f(x) |      \\         /        \\          /      \n");
			fprintf(output, "\t|     |       \\       /          \\        /       \n");
			fprintf(output, "\t|     |        \\     /            \\      /        \n");
			fprintf(output, "\t|     |         \\   /              \\    /         \n");
			fprintf(output, "\t|     |          %.2f               %.2f          \n", Equa_4(a, b, c, x1), Equa_4(a, b, c, x2));
			fprintf(output, "\t|-----|-----------------------------------------------\n");
			fprintf(output, "\n");
		}
		else
		{
			fprintf(output, "\t|-----|-----------------------------------------------\n");
			fprintf(output, "\t|  x  | -oo      %.2f        0       %.2f       +oo \n", x1, x2);
			fprintf(output, "\t|-----|-----------------------------------------------\n");
			fprintf(output, "\t|f'(x)|      +     0    -    0    +    0    -       \n");
			fprintf(output, "\t|-----|-----------------------------------------------\n");
			fprintf(output, "\t|     |          %.2f               %.2f          \n", Equa_4(a, b, c, x1), Equa_4(a, b, c, x2));
			fprintf(output, "\t|     |        /      \\             /    \\        \n");
			fprintf(output, "\t|     |       /        \\           /      \\       \n");
			fprintf(output, "\t|f(x) |      / 	        \\         /        \\      \n");
			fprintf(output, "\t|     |     /            \\       /          \\     \n");
			fprintf(output, "\t|     |    /              \\     /            \\    \n");
			fprintf(output, "\t|     |   /                \\   /              \\   \n");
			fprintf(output, "\t|     |-oo                   0                  -oo \n");
			fprintf(output, "\t|-----|-----------------------------------------------\n");
			fprintf(output, "\n");
		}
	}
}

void BBT5(float a, float b, float c, float d)
{
	if (a * d - b * c > 0)
	{
		fprintf(output, "\t|-----|-------------------------------\n");
		fprintf(output, "\t|  x  |-oo         %.2f         +oo \n", -d / c);
		fprintf(output, "\t|-----|-------------||----------------\n");
		fprintf(output, "\t|f'(x)|     +       ||     +        \n");
		fprintf(output, "\t|-----|-------------||----------------\n");
		fprintf(output, "\t|     |         +oo ||         %.2f \n", a / c);
		fprintf(output, "\t|     |        /    ||         /    \n");
		fprintf(output, "\t|     |       /     ||        /     \n");
		fprintf(output, "\t|f(x) |      / 	    ||       /      \n");
		fprintf(output, "\t|     |     /       ||      /       \n");
		fprintf(output, "\t|     |    /        ||     /        \n");
		fprintf(output, "\t|     |   /         ||    /         \n");
		fprintf(output, "\t|     |%.2f         ||-oo           \n", a / c);
		fprintf(output, "\t|-----|-------------||----------------\n");
		fprintf(output, "\n");
	}
	else
	{
		fprintf(output, "\t|-----|-------------------------------\n");
		fprintf(output, "\t|  x  |-oo         %.2f          +oo \n", -d / c);
		fprintf(output, "\t|-----|-------------||---------------\n");
		fprintf(output, "\t|f'(x)|      -      ||        -     \n");
		fprintf(output, "\t|-----|-------------||----------------\n");
		fprintf(output, "\t|     |%.2f         ||+oo           \n", a / c);
		fprintf(output, "\t|     |   \\         ||    \\        \n");
		fprintf(output, "\t|     |    \\        ||     \\       \n");
		fprintf(output, "\t|f(x) |     \\ 	    ||      \\      \n");
		fprintf(output, "\t|     |      \\      ||       \\     \n");
		fprintf(output, "\t|     |       \\     ||        \\    \n");
		fprintf(output, "\t|     |        \\    ||         \\   \n");
		fprintf(output, "\t|     |         -oo ||         %.2f \n", a / c);
		fprintf(output, "\t|-----|-------------||----------------\n");
		fprintf(output, "\n");
	}
}

void BBT6(float a, float b, float c, float d, float e)
{
	float x, y; short k;
	GiaiPT_Bac2(a * d, 2 * a * e, b * e - c * d, x, y, k);
	if (k == 1)
		if (a * d > 0)
		{
			fprintf(output, "\t|-----|--------------------------------------------------\n");
			fprintf(output, "\t|  x  |-oo      %.2f        %.2f         %.2f      +oo \n", x, y, -e / d);
			fprintf(output, "\t|-----|----------------------||--------------------------\n");
			fprintf(output, "\t|f'(x)|     +     0    -     ||      -    0   +        \n");
			fprintf(output, "\t|-----|----------------------||--------------------------\n");
			fprintf(output, "\t|     |         %.2f        ||+oo                 +oo \n", Equa_6(a, b, c, d, e, x));
			fprintf(output, "\t|     |        /     \\       ||   \\              /    \n");
			fprintf(output, "\t|     |       /       \\      ||    \\            /     \n");
			fprintf(output, "\t|f(x) |      / 	       \\     ||     \\          /      \n");
			fprintf(output, "\t|     |     /           \\    ||      \\        /       \n");
			fprintf(output, "\t|     |    /             \\   ||       \\      /        \n");
			fprintf(output, "\t|     |   /               \\  ||        \\    /         \n");
			fprintf(output, "\t|     |-oo                -oo||         %.2f           \n", Equa_6(a, b, c, d, e, y));
			fprintf(output, "\t|-----|----------------------||--------------------------\n");
			fprintf(output, "\n");
		}
		else
		{
			fprintf(output, "\t|-----|---------------------------------------------------\n");
			fprintf(output, "\t|  x  |-oo      %.2f         %.2f         %.2f      +oo \n", x, y, -e / d);
			fprintf(output, "\t|-----|-----------------------||--------------------------\n");
			fprintf(output, "\t|f'(x)|     -     0    +      ||      +    0   -        \n");
			fprintf(output, "\t|-----|-----------------------||--------------------------\n");
			fprintf(output, "\t|     |+oo                 +oo||         %.2f           \n", Equa_6(a, b, c, d, e, x));
			fprintf(output, "\t|     |   \\              /    ||        /     \\        \n");
			fprintf(output, "\t|     |    \\            /     ||       /       \\       \n");
			fprintf(output, "\t|f(x) |     \\          /      ||      /         \\      \n");
			fprintf(output, "\t|     |      \\        /       ||     /           \\     \n");
			fprintf(output, "\t|     |       \\      /        ||    /             \\    \n");
			fprintf(output, "\t|     |        \\    /         ||   /               \\   \n");
			fprintf(output, "\t|     |         %.2f         ||-oo                 +oo \n", Equa_6(a, b, c, d, e, y));
			fprintf(output, "\t|-----|-----------------------||--------------------------\n");
			fprintf(output, "\n");
		}
	else
		if (a * d > 0)
		{
			fprintf(output, "\t|-----|-------------------------------\n");
			fprintf(output, "\t|  x  |-oo         %.2f          +oo \n", -e / d);
			fprintf(output, "\t|-----|-------------||----------------\n");
			fprintf(output, "\t|f'(x)|     +       ||     +        \n");
			fprintf(output, "\t|-----|-------------||----------------\n");
			fprintf(output, "\t|     |         +oo ||          +oo \n");
			fprintf(output, "\t|     |        /    ||         /    \n");
			fprintf(output, "\t|     |       /     ||        /     \n");
			fprintf(output, "\t|f(x) |      /  	    ||       /      \n");
			fprintf(output, "\t|     |     /       ||      /       \n");
			fprintf(output, "\t|     |    /        ||     /        \n");
			fprintf(output, "\t|     |   /         ||    /         \n");
			fprintf(output, "\t|     |-oo          || -oo          \n");
			fprintf(output, "\t|-----|-------------||----------------\n");
			fprintf(output, "\n");
		}
		else
		{
			fprintf(output, "\t|-----|-------------------------------\n");
			fprintf(output, "\t|  x  |-oo         %.2f          +oo \n", -e / d);
			fprintf(output, "\t|-----|-------------||----------------\n");
			fprintf(output, "\t|f'(x)|      -      ||     -        \n");
			fprintf(output, "\t|-----|-------------||----------------\n");
			fprintf(output, "\t|     |+oo          ||+oo           \n");
			fprintf(output, "\t|     |   \\         ||    \\        \n");
			fprintf(output, "\t|     |    \\        ||     \\       \n");
			fprintf(output, "\t|f(x) |     \\ 	    ||      \\      \n");
			fprintf(output, "\t|     |      \\      ||       \\     \n");
			fprintf(output, "\t|     |       \\     ||        \\    \n");
			fprintf(output, "\t|     |        \\    ||         \\   \n");
			fprintf(output, "\t|     |         -oo ||          -oo \n");
			fprintf(output, "\t|-----|-------------||----------------\n");
			fprintf(output, "\n");
		}
}

void BBT14()
{
	fprintf(output, "|=====|===================================================================================\n");
	fprintf(output, "|  x  |-2* Pi       -3* Pi/2          -Pi/2            Pi/2            3* Pi/2        2* Pi\n");
	fprintf(output, "|-----|-----------------------------------------------------------------------------------\n");
	fprintf(output, "|f'(x)|       +             -                 +               -                +          \n");
	fprintf(output, "|-----|-----------------------------------------------------------------------------------\n");
	fprintf(output, "|     |              1                                 1                                 0\n");
	fprintf(output, "| f(x)|           /      \\                         /        \\                          /  \n");
	fprintf(output, "|     |          /        \\                       /          \\                        /   \n");
	fprintf(output, "|     |         /          \\                     /            \\                      /    \n");
	fprintf(output, "|     |        /            \\                   /              \\                    /     \n");
	fprintf(output, "|     |       /              \\                 /                \\                  /      \n");
	fprintf(output, "|     |      /                \\               /                  \\                /       \n");
	fprintf(output, "|     |     /                  \\             /                    \\              /        \n");
	fprintf(output, "|     |    /                    \\           /                      \\            /         \n");
	fprintf(output, "|     |   /                      \\         /                        \\          /          \n");
	fprintf(output, "|     |  /                        \\       /                          \\        /           \n");
	fprintf(output, "|     | /                          \\     /                            \\      /            \n");
	fprintf(output, "|     |0                              -1                                  -1              \n");
	fprintf(output, "|=====|===================================================================================\n");
}

void BBT15()
{
	fprintf(output, "\t|=====|====================================================================\n");
	fprintf(output, "\t|  x  |-2* Pi          -Pi                0               -Pi         2* Pi\n");
	fprintf(output, "\t|-----|--------------------------------------------------------------------\n");
	fprintf(output, "\t|f'(x)|       -             +                     -              +         \n");
	fprintf(output, "\t|-----|--------------------------------------------------------------------\n");
	fprintf(output, "\t|     |  1                               1                               1  \n");
	fprintf(output, "\t| f(x)|    \\                         /      \\                         /    \n");
	fprintf(output, "\t|     |     \\                       /        \\                       /     \n");
	fprintf(output, "\t|     |      \\                     /          \\                     /      \n");
	fprintf(output, "\t|     |       \\                   /            \\                   /       \n");
	fprintf(output, "\t|     |        \\                 /              \\                 /        \n");
	fprintf(output, "\t|     |         \\               /                \\               /         \n");
	fprintf(output, "\t|     |          \\             /                  \\             /          \n");
	fprintf(output, "\t|     |           \\           /                    \\           /           \n");
	fprintf(output, "\t|     |            \\         /                      \\         /            \n");
	fprintf(output, "\t|     |             \\       /                        \\       /             \n");
	fprintf(output, "\t|     |              \\     /                          \\     /              \n");
	fprintf(output, "\t|     |                -1                               -1                 \n");
	fprintf(output, "\t|=====|====================================================================\n");
}

void BBT16()
{
	fprintf(output, "|=====|=======================|\n");
	fprintf(output, "|  x  | -Pi/2            Pi/2 |\n");
	fprintf(output, "|-----|-----------------------|\n");
	fprintf(output, "|f'(x)|                       |\n");
	fprintf(output, "|-----|-----------------------|\n");
	fprintf(output, "|-----|                  +oo  |\n");
	fprintf(output, "|-----|                 /     |\n");
	fprintf(output, "|-----|                /      |\n");
	fprintf(output, "|-----|               /       |\n");
	fprintf(output, "|-----|              /        |\n");
	fprintf(output, "|-----|             /         |\n");
	fprintf(output, "|-----|            /          |\n");
	fprintf(output, "|-----|           /           |\n");
	fprintf(output, "|-----|          /            |\n");
	fprintf(output, "|-----|         /             |\n");
	fprintf(output, "|-----|        /              |\n");
	fprintf(output, "|-----|       /               |\n");
	fprintf(output, "|-----|      /                |\n");
	fprintf(output, "|-----|     /                 |\n");
	fprintf(output, "|-----|    /                  |\n");
	fprintf(output, "|-----| -oo                   |\n");
	fprintf(output, "|=====|=======================|\n");
}

void BBT17()
{
	fprintf(output, "\t|=====|======================|\n");
	fprintf(output, "\t|  x  | 0               Pi   |\n");
	fprintf(output, "\t|-----|----------------------|\n");
	fprintf(output, "\t|f'(x)|          -           |\n");
	fprintf(output, "\t|-----|----------------------|\n");
	fprintf(output, "\t|     |  +oo                 |\n");
	fprintf(output, "\t| f(x)|     \\               |\n");
	fprintf(output, "\t|     |      \\              |\n");
	fprintf(output, "\t|     |       \\             |\n");
	fprintf(output, "\t|     |        \\            |\n");
	fprintf(output, "\t|     |         \\           |\n");
	fprintf(output, "\t|     |          \\          |\n");
	fprintf(output, "\t|     |           \\         |\n");
	fprintf(output, "\t|     |            \\        |\n");
	fprintf(output, "\t|     |             \\       |\n");
	fprintf(output, "\t|     |              \\      |\n");
	fprintf(output, "\t|     |               \\     |\n");
	fprintf(output, "\t|     |                -oo   |\n");
	fprintf(output, "\t|=====|======================|\n");
}