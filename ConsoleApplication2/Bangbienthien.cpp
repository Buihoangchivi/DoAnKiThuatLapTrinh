
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
	case 11:
		BBT11(a);
		break;
	case 12:
		BBT12(a);
		break;
	case 13:
		BBT13();
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
	case 18:
		BBT18(a, b);
		break;
	case 19:
		BBT19(a, b, c);
		break;
	case 20:
		BBT20(a, b, c, d);
		break;
	case 21:
		BBT21(a, b, c);
		break;
	case 22:
		BBT22(a, b, c, d);
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

void BBT11(float b)
{
	if (b > 0)
	{
		if ((int)b % 2 != 0)
		{
			fprintf(output, "\t|-----|-----------------|\n");
			fprintf(output, "\t|  x  | 0     1   +oo   |\n");
			fprintf(output, "\t|-----|-----------------|\n");
			fprintf(output, "\t|f'(x)|   +   0   +     |\n");
			fprintf(output, "\t|-----|-----------------|\n");
			fprintf(output, "\t|     |           +oo   |\n");
			fprintf(output, "\t|     |         /       |\n");
			fprintf(output, "\t|     |        /        |\n");
			fprintf(output, "\t|f(x) |       0         |\n");
			fprintf(output, "\t|     |      /          |\n");
			fprintf(output, "\t|     |     /           |\n");
			fprintf(output, "\t|     | -oo             |\n");
			fprintf(output, "\t|-----|-----------------|\n");
			fprintf(output, "\n");
		}
		else
		{
			fprintf(output, "\t|-----|---------------------------|\n");
			fprintf(output, "\t|  x  | 0          1          +oo |\n");
			fprintf(output, "\t|-----|---------------------------|\n");
			fprintf(output, "\t|f'(x)|      -     0      +       |\n");
			fprintf(output, "\t|-----|---------------------------|\n");
			fprintf(output, "\t|     |+oo                    +oo |\n");
			fprintf(output, "\t|     |    \\                 /    |\n");
			fprintf(output, "\t|     |     \\               /     |\n");
			fprintf(output, "\t|f(x) |      \\             /      |\n");
			fprintf(output, "\t|     |       \\           /       |\n");
			fprintf(output, "\t|     |        \\         /        |\n");
			fprintf(output, "\t|     |         \\       /         |\n");
			fprintf(output, "\t|     |             0             |\n");
			fprintf(output, "\t|-----|---------------------------|\n");
			fprintf(output, "\n");
		}
	}
	else if (b < 0)
	{
		if ((int)b % 2 != 0)
		{
			fprintf(output, "\t|-----|-----------------------------|\n");
			fprintf(output, "\t|  x  | 0            1          +oo |\n");
			fprintf(output, "\t|-----|-------------||--------------|\n");
			fprintf(output, "\t|f'(x)|      -      ||     -        |\n");
			fprintf(output, "\t|-----|-------------||--------------|\n");
			fprintf(output, "\t|     | 0           ||+oo           |\n");
			fprintf(output, "\t|     |   \\         ||    \\         |\n");
			fprintf(output, "\t|     |    \\        ||     \\        |\n");
			fprintf(output, "\t|f(x) |     \\  	    ||      \\       |\n");
			fprintf(output, "\t|     |      \\      ||       \\      |\n");
			fprintf(output, "\t|     |       \\     ||        \\     |\n");
			fprintf(output, "\t|     |        \\    ||         \\    |\n");
			fprintf(output, "\t|     |         -oo ||            0 |\n");
			fprintf(output, "\t|-----|-------------||--------------|\n");
			fprintf(output, "\n");
		}
		else
		{
			fprintf(output, "\t|-----|-----------------------------|\n");
			fprintf(output, "\t|  x  | 0            1          +oo |\n");
			fprintf(output, "\t|-----|-------------||--------------|\n");
			fprintf(output, "\t|f'(x)|     +       ||     -        |\n");
			fprintf(output, "\t|-----|-------------||--------------|\n");
			fprintf(output, "\t|     |         +oo || +oo          |\n");
			fprintf(output, "\t|     |        /    ||    \\         |\n");
			fprintf(output, "\t|     |       /     ||     \\        |\n");
			fprintf(output, "\t|f(x) |      / 	   ||      \\       |\n");
			fprintf(output, "\t|     |     /       ||       \\      |\n");
			fprintf(output, "\t|     |    /        ||        \\     |\n");
			fprintf(output, "\t|     |   /         ||         \\    |\n");
			fprintf(output, "\t|     | 0           ||           0  |\n");
			fprintf(output, "\t|-----|-------------||--------------|\n");
			fprintf(output, "\n");
		}
	}
}

void BBT12(float a)
{
	if (a > 1)
	{
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\t|  x  | 0         +oo   |\n");
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
	else if (a > 0 && a < 1)
	{
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\t|  x  |  0        +oo   |\n");
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\t|f'(x)|        -        |\n");
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\t|     | +oo             |\n");
		fprintf(output, "\t|     |     \\          |\n");
		fprintf(output, "\t|     |      \\         |\n");
		fprintf(output, "\t|f(x) |       \\        |\n");
		fprintf(output, "\t|     |        \\       |\n");
		fprintf(output, "\t|     |         \\      |\n");
		fprintf(output, "\t|     |          -oo    |\n");
		fprintf(output, "\t|-----|-----------------|\n");
		fprintf(output, "\n");
	}
}

void BBT13()
{
	fprintf(output, "|=====|===========================|\n");
	fprintf(output, "|  x  |-oo                     +oo|\n");
	fprintf(output, "|-----|---------------------------|\n");
	fprintf(output, "|f'(x)|             +             |\n");
	fprintf(output, "|-----|---------------------------|\n");
	fprintf(output, "|     |                      +oo  |\n");
	fprintf(output, "|     |                     /     |\n");
	fprintf(output, "|     |                    /      |\n");
	fprintf(output, "|     |                   /       |\n");
	fprintf(output, "|     |                  /        |\n");
	fprintf(output, "|     |                 /         |\n");
	fprintf(output, "|     |                /          |\n");
	fprintf(output, "|     |               /           |\n");
	fprintf(output, "| f(x)|              /            |\n");
	fprintf(output, "|     |             /             |\n");
	fprintf(output, "|     |            /              |\n");
	fprintf(output, "|     |           /               |\n");
	fprintf(output, "|     |          /                |\n");
	fprintf(output, "|     |         /                 |\n");
	fprintf(output, "|     |        /                  |\n");
	fprintf(output, "|     |       /                   |\n");
	fprintf(output, "|     |      /                    |\n");
	fprintf(output, "|     |     /                     |\n");
	fprintf(output, "|     |    /                      |\n");
	fprintf(output, "|     |  0                        |\n");
	fprintf(output, "|=====|===========================|\n");
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

void BBT18(float a, float b) {
	if (a > 0) {
		fprintf(output, "|=====|===========================|\n");
		fprintf(output, "|  x  | %.2f                  +oo|\n", -b / a);
		fprintf(output, "|-----|---------------------------|\n");
		fprintf(output, "|f'(x)|             +             |\n");
		fprintf(output, "|-----|---------------------------|\n");
		fprintf(output, "|     |                      +oo  |\n");
		fprintf(output, "|     |                     /     |\n");
		fprintf(output, "|     |                    /      |\n");
		fprintf(output, "|     |                   /       |\n");
		fprintf(output, "|     |                  /        |\n");
		fprintf(output, "|     |                 /         |\n");
		fprintf(output, "|     |                /          |\n");
		fprintf(output, "|     |               /           |\n");
		fprintf(output, "| f(x)|              /            |\n");
		fprintf(output, "|     |             /             |\n");
		fprintf(output, "|     |            /              |\n");
		fprintf(output, "|     |           /               |\n");
		fprintf(output, "|     |          /                |\n");
		fprintf(output, "|     |         /                 |\n");
		fprintf(output, "|     |        /                  |\n");
		fprintf(output, "|     |       /                   |\n");
		fprintf(output, "|     |      /                    |\n");
		fprintf(output, "|     |     /                     |\n");
		fprintf(output, "|     |    /                      |\n");
		fprintf(output, "|     |   0                       |\n");
		fprintf(output, "|=====|===========================|\n");
	}
	else {
		if (a != 0) {
			fprintf(output, "|=====|===========================|\n");
			fprintf(output, "|  x  | -oo                  %.2f|\n", -b / a);
			fprintf(output, "|-----|---------------------------|\n");
			fprintf(output, "|f'(x)|             -             |\n");
			fprintf(output, "|-----|---------------------------|\n");
			fprintf(output, "|     |   0                       |\n");
			fprintf(output, "|     |     \\                     |\n");
			fprintf(output, "|     |      \\                    |\n");
			fprintf(output, "|     |       \\                   |\n");
			fprintf(output, "|     |        \\                  |\n");
			fprintf(output, "|     |         \\                 |\n");
			fprintf(output, "|     |          \\                |\n");
			fprintf(output, "|     |           \\               |\n");
			fprintf(output, "| f(x)|            \\              |\n");
			fprintf(output, "|     |             \\             |\n");
			fprintf(output, "|     |              \\            |\n");
			fprintf(output, "|     |               \\           |\n");
			fprintf(output, "|     |                \\          |\n");
			fprintf(output, "|     |                 \\         |\n");
			fprintf(output, "|     |                  \\        |\n");
			fprintf(output, "|     |                   \\       |\n");
			fprintf(output, "|     |                    \\      |\n");
			fprintf(output, "|     |                     \\     |\n");
			fprintf(output, "|     |                      \\    |\n");
			fprintf(output, "|     |                       -oo |\n");
			fprintf(output, "|=====|===========================|\n");
		}
		else
			fprintf(output, "Ham so khong co bang bien thien\n");
	}
}

void BBT19(float a, float b, float c) {
	if (a == 0) {
		BBT1(b, c);
	}
	else {
		float x, y;
		short k;
		GiaiPT_Bac2(a, b, c, x, y, k);
		if (k == -1 || k == 0) {
			if (a > 0) {
				fprintf(output, "|=====|================================================|\n");
				fprintf(output, "|  x  | -oo                  %.2f                  +oo|\n", -b / 2 * a);
				fprintf(output, "|-----|------------------------------------------------|\n");
				fprintf(output, "|f'(x)|             -                        +         |\n");
				fprintf(output, "|-----|------------------------------------------------|\n");
				fprintf(output, "|     |   +oo                                      +oo |\n");
				fprintf(output, "|     |     \\                                    /     |\n");
				fprintf(output, "|     |      \\                                  /      |\n");
				fprintf(output, "|     |       \\                                /       |\n");
				fprintf(output, "|     |        \\                              /        |\n");
				fprintf(output, "|     |         \\                            /         |\n");
				fprintf(output, "|     |          \\                          /          |\n");
				fprintf(output, "|     |           \\                        /           |\n");
				fprintf(output, "| f(x)|            \\                      /            |\n");
				fprintf(output, "|     |             \\                    /             |\n");
				fprintf(output, "|     |              \\                  /              |\n");
				fprintf(output, "|     |               \\                /               |\n");
				fprintf(output, "|     |                \\              /                |\n");
				fprintf(output, "|     |                 \\            /                 |\n");
				fprintf(output, "|     |                  \\          /                  |\n");
				fprintf(output, "|     |                   \\        /                   |\n");
				fprintf(output, "|     |                    \\      /                    |\n");
				fprintf(output, "|     |                     \\    /                     |\n");
				fprintf(output, "|     |                      \\  /                      |\n");
				fprintf(output, "|     |                       0                        |\n");
				fprintf(output, "|=====|================================================|\n");
			}
			else
			{
				fprintf(output, "Ham so khong co bang bien thien\n");
			}
		}
		else
		{
			if (a > 0) {
				if (-b / 2 * a < x) {
					fprintf(output, "|=====|=================================================================================|\n");
					fprintf(output, "|  x  | -oo                 %.2f                      %.2f   %.2f                   +oo|\n", -b / 2 * a, x, y);
					fprintf(output, "|-----|---------------------------------------------------------------------------------|\n");
					fprintf(output, "|f'(x)|             -                 +                ||     ||    +                   |\n");
					fprintf(output, "|-----|------------------------------------------------||-----||------------------------|\n");
					fprintf(output, "|     |   +oo                                      +oo ||     ||                    +oo |\n");
					fprintf(output, "|     |     \\                                    /     ||     ||                     /  |\n");
					fprintf(output, "|     |      \\                                  /      ||     ||                    /   |\n");
					fprintf(output, "|     |       \\                                /       ||     ||                   /    |\n");
					fprintf(output, "|     |        \\                              /        ||     ||                  /     |\n");
					fprintf(output, "|     |         \\                            /         ||     ||                 /      |\n");
					fprintf(output, "|     |          \\                          /          ||     ||                /       |\n");
					fprintf(output, "|     |           \\                        /           ||     ||               /        |\n");
					fprintf(output, "| f(x)|            \\                      /            ||     ||              /         |\n");
					fprintf(output, "|     |             \\                    /             ||     ||             /          |\n");
					fprintf(output, "|     |              \\                  /              ||     ||            /           |\n");
					fprintf(output, "|     |               \\                /               ||     ||           /            |\n");
					fprintf(output, "|     |                \\              /                ||     ||          /             |\n");
					fprintf(output, "|     |                 \\            /                 ||     ||         /              |\n");
					fprintf(output, "|     |                  \\          /                  ||     ||        /               |\n");
					fprintf(output, "|     |                   \\        /                   ||     ||       /                |\n");
					fprintf(output, "|     |                    \\      /                    ||     ||      /                 |\n");
					fprintf(output, "|     |                     \\    /                     ||     ||     /                  |\n");
					fprintf(output, "|     |                      \\  /                      ||     ||    /                   |\n");
					fprintf(output, "|     |                       0                        ||     ||   0                    |\n");
					fprintf(output, "|=====|=================================================================================|\n");
				}
				else {
					if (-b / 2 * a > y) {
						fprintf(output, "|=====|=================================================================================|\n");
						fprintf(output, "|  x  | -oo                     %.2f   %.2f                   %.2f                  +oo|\n", x, y, -b / 2 * a);
						fprintf(output, "|-----|---------------------------------------------------------------------------------|\n");
						fprintf(output, "|f'(x)|             -            ||     ||      -                           +           |\n");
						fprintf(output, "|-----|--------------------------||-----||----------------------------------------------|\n");
						fprintf(output, "|     |   +oo                    ||     || 0                                        +oo |\n");
						fprintf(output, "|     |     \\                    ||     ||  \\                                       /   |\n");
						fprintf(output, "|     |      \\                   ||     ||   \\                                     /    |\n");
						fprintf(output, "|     |       \\                  ||     ||    \\                                   /     |\n");
						fprintf(output, "|     |        \\                 ||     ||     \\                                 /      |\n");
						fprintf(output, "|     |         \\                ||     ||      \\                               /       |\n");
						fprintf(output, "|     |          \\               ||     ||       \\                             /        |\n");
						fprintf(output, "|     |           \\              ||     ||        \\                           /         |\n");
						fprintf(output, "| f(x)|            \\             ||     ||         \\                         /          |\n");
						fprintf(output, "|     |             \\            ||     ||          \\                       /           |\n");
						fprintf(output, "|     |              \\           ||     ||           \\                     /            |\n");
						fprintf(output, "|     |               \\          ||     ||            \\                   /             |\n");
						fprintf(output, "|     |                \\         ||     ||             \\                 /              |\n");
						fprintf(output, "|     |                 \\        ||     ||              \\               /               |\n");
						fprintf(output, "|     |                  \\       ||     ||               \\             /                |\n");
						fprintf(output, "|     |                   \\      ||     ||                \\           /                 |\n");
						fprintf(output, "|     |                    \\     ||     ||                 \\         /                  |\n");
						fprintf(output, "|     |                     \\    ||     ||                  \\       /                   |\n");
						fprintf(output, "|     |                      \\   ||     ||                   \\     /                    |\n");
						fprintf(output, "|     |                       0  ||     ||                    %.2f                      |\n", Equa_2(a, b, c, -b / 2 * a));
						fprintf(output, "|=====|=================================================================================|\n");
					}
					else {
						fprintf(output, "|=====|============================================================|\n");
						fprintf(output, "|  x  | -oo                     %.2f    %.2f                    +oo|\n", x, y);
						fprintf(output, "|-----|------------------------------------------------------------|\n");
						fprintf(output, "|f'(x)|           -              ||      ||          +             |\n");
						fprintf(output, "|-----|--------------------------||------||------------------------|\n");
						fprintf(output, "|     |   +oo                    ||      ||                    +oo |\n");
						fprintf(output, "|     |     \\                    ||      ||                    /   |\n");
						fprintf(output, "|     |      \\                   ||      ||                   /    |\n");
						fprintf(output, "|     |       \\                  ||      ||                  /     |\n");
						fprintf(output, "|     |        \\                 ||      ||                 /      |\n");
						fprintf(output, "|     |         \\                ||      ||                /       |\n");
						fprintf(output, "|     |          \\               ||      ||               /        |\n");
						fprintf(output, "|     |           \\              ||      ||              /         |\n");
						fprintf(output, "| f(x)|            \\             ||      ||             /          |\n");
						fprintf(output, "|     |             \\            ||      ||            /           |\n");
						fprintf(output, "|     |              \\           ||      ||           /            |\n");
						fprintf(output, "|     |               \\          ||      ||          /             |\n");
						fprintf(output, "|     |                \\         ||      ||         /              |\n");
						fprintf(output, "|     |                 \\        ||      ||        /               |\n");
						fprintf(output, "|     |                  \\       ||      ||       /                |\n");
						fprintf(output, "|     |                   \\      ||      ||      /                 |\n");
						fprintf(output, "|     |                    \\     ||      ||     /                  |\n");
						fprintf(output, "|     |                     \\    ||      ||    /                   |\n");
						fprintf(output, "|     |                      \\   ||      ||   /                    |\n");
						fprintf(output, "|     |                       0  ||      || 0                      |\n");
						fprintf(output, "|=====|============================================================|\n");
					}
				}
			}
			else
				if (-b / 2 * a > x && -b / 2 * a < y) {
					fprintf(output, "|=====|================================================|\n");
					fprintf(output, "|  x  | %.2f                  %.2f                 %.2f|\n", x, -b / 2 * a, y);
					fprintf(output, "|-----|------------------------------------------------|\n");
					fprintf(output, "|f'(x)|             -                        +         |\n");
					fprintf(output, "|-----|------------------------------------------------|\n");
					fprintf(output, "|     |   +oo                                      +oo |\n");
					fprintf(output, "|     |     \\                                    /     |\n");
					fprintf(output, "|     |      \\                                  /      |\n");
					fprintf(output, "|     |       \\                                /       |\n");
					fprintf(output, "|     |        \\                              /        |\n");
					fprintf(output, "|     |         \\                            /         |\n");
					fprintf(output, "|     |          \\                          /          |\n");
					fprintf(output, "|     |           \\                        /           |\n");
					fprintf(output, "| f(x)|            \\                      /            |\n");
					fprintf(output, "|     |             \\                    /             |\n");
					fprintf(output, "|     |              \\                  /              |\n");
					fprintf(output, "|     |               \\                /               |\n");
					fprintf(output, "|     |                \\              /                |\n");
					fprintf(output, "|     |                 \\            /                 |\n");
					fprintf(output, "|     |                  \\          /                  |\n");
					fprintf(output, "|     |                   \\        /                   |\n");
					fprintf(output, "|     |                    \\      /                    |\n");
					fprintf(output, "|     |                     \\    /                     |\n");
					fprintf(output, "|     |                      \\  /                      |\n");
					fprintf(output, "|     |                       0                        |\n");
					fprintf(output, "|=====|================================================|\n");
				}
				else
					if (-b / 2 * a < x) {
						fprintf(output, "|=====|===========================|\n");
						fprintf(output, "|  x  | %.2f                  %.2f|\n", x, y);
						fprintf(output, "|-----|---------------------------|\n");
						fprintf(output, "|f'(x)|             +             |\n");
						fprintf(output, "|-----|---------------------------|\n");
						fprintf(output, "|     |                      0    |\n");
						fprintf(output, "|     |                     /     |\n");
						fprintf(output, "|     |                    /      |\n");
						fprintf(output, "|     |                   /       |\n");
						fprintf(output, "|     |                  /        |\n");
						fprintf(output, "|     |                 /         |\n");
						fprintf(output, "|     |                /          |\n");
						fprintf(output, "|     |               /           |\n");
						fprintf(output, "| f(x)|              /            |\n");
						fprintf(output, "|     |             /             |\n");
						fprintf(output, "|     |            /              |\n");
						fprintf(output, "|     |           /               |\n");
						fprintf(output, "|     |          /                |\n");
						fprintf(output, "|     |         /                 |\n");
						fprintf(output, "|     |        /                  |\n");
						fprintf(output, "|     |       /                   |\n");
						fprintf(output, "|     |      /                    |\n");
						fprintf(output, "|     |     /                     |\n");
						fprintf(output, "|     |    /                      |\n");
						fprintf(output, "|     | -oo                       |\n");
						fprintf(output, "|=====|===========================|\n");
					}
					else {
						fprintf(output, "|=====|===========================|\n");
						fprintf(output, "|  x  | %.2f                  %.2f|\n", x, y);
						fprintf(output, "|-----|---------------------------|\n");
						fprintf(output, "|f'(x)|             -             |\n");
						fprintf(output, "|-----|---------------------------|\n");
						fprintf(output, "|     |   0                       |\n");
						fprintf(output, "|     |     \\                     |\n");
						fprintf(output, "|     |      \\                    |\n");
						fprintf(output, "|     |       \\                   |\n");
						fprintf(output, "|     |        \\                  |\n");
						fprintf(output, "|     |         \\                 |\n");
						fprintf(output, "|     |          \\                |\n");
						fprintf(output, "|     |           \\               |\n");
						fprintf(output, "| f(x)|            \\              |\n");
						fprintf(output, "|     |             \\             |\n");
						fprintf(output, "|     |              \\            |\n");
						fprintf(output, "|     |               \\           |\n");
						fprintf(output, "|     |                \\          |\n");
						fprintf(output, "|     |                 \\         |\n");
						fprintf(output, "|     |                  \\        |\n");
						fprintf(output, "|     |                   \\       |\n");
						fprintf(output, "|     |                    \\      |\n");
						fprintf(output, "|     |                     \\     |\n");
						fprintf(output, "|     |                      \\    |\n");
						fprintf(output, "|     |                       -oo |\n");
						fprintf(output, "|=====|===========================|\n");
					}
		}
	}
}

void BBT20(float a, float b, float c, float d)
{
	if (a == 0)
		BBT19(b, c, d);
	else
	{
		float x1, x2, x3, x, y;
		short k, l;
		GiaiPT_Bac3(a, b, c, d, x1, x2, x3, k);
		GiaiPT_Bac2(3 * a, 2 * b, c, x, y, l);
		if (l == -1) {
			switch (k)
			{
			case 1:
				if (a > 0)
				{
					fprintf(output, "|=====|===========================|\n");
					fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
					fprintf(output, "|-----|---------------------------|\n");
					fprintf(output, "|f'(x)|             +             |\n");
					fprintf(output, "|-----|---------------------------|\n");
					fprintf(output, "|     |                      +oo  |\n");
					fprintf(output, "|     |                     /     |\n");
					fprintf(output, "|     |                    /      |\n");
					fprintf(output, "|     |                   /       |\n");
					fprintf(output, "|     |                  /        |\n");
					fprintf(output, "|     |                 /         |\n");
					fprintf(output, "|     |                /          |\n");
					fprintf(output, "|     |               /           |\n");
					fprintf(output, "| f(x)|              /            |\n");
					fprintf(output, "|     |             /             |\n");
					fprintf(output, "|     |            /              |\n");
					fprintf(output, "|     |           /               |\n");
					fprintf(output, "|     |          /                |\n");
					fprintf(output, "|     |         /                 |\n");
					fprintf(output, "|     |        /                  |\n");
					fprintf(output, "|     |       /                   |\n");
					fprintf(output, "|     |      /                    |\n");
					fprintf(output, "|     |     /                     |\n");
					fprintf(output, "|     |    /                      |\n");
					fprintf(output, "|     |   0                       |\n");
					fprintf(output, "|=====|===========================|\n");
				}
				else {
					fprintf(output, "|=====|===========================|\n");
					fprintf(output, "|  x  | -oo                  %.2f|\n", x1);
					fprintf(output, "|-----|---------------------------|\n");
					fprintf(output, "|f'(x)|             +             |\n");
					fprintf(output, "|-----|---------------------------|\n");
					fprintf(output, "|     |                      0    |\n");
					fprintf(output, "|     |                     /     |\n");
					fprintf(output, "|     |                    /      |\n");
					fprintf(output, "|     |                   /       |\n");
					fprintf(output, "|     |                  /        |\n");
					fprintf(output, "|     |                 /         |\n");
					fprintf(output, "|     |                /          |\n");
					fprintf(output, "|     |               /           |\n");
					fprintf(output, "| f(x)|              /            |\n");
					fprintf(output, "|     |             /             |\n");
					fprintf(output, "|     |            /              |\n");
					fprintf(output, "|     |           /               |\n");
					fprintf(output, "|     |          /                |\n");
					fprintf(output, "|     |         /                 |\n");
					fprintf(output, "|     |        /                  |\n");
					fprintf(output, "|     |       /                   |\n");
					fprintf(output, "|     |      /                    |\n");
					fprintf(output, "|     |     /                     |\n");
					fprintf(output, "|     |    /                      |\n");
					fprintf(output, "|     | -oo                       |\n");
					fprintf(output, "|=====|===========================|\n");
				}
				break;
			case 3:
				if (a > 0)
				{
					if (x1 == x2 && x2 == x3) {
						fprintf(output, "|=====|===========================|\n");
						fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
						fprintf(output, "|-----|---------------------------|\n");
						fprintf(output, "|f'(x)|             +             |\n");
						fprintf(output, "|-----|---------------------------|\n");
						fprintf(output, "|     |                      +oo  |\n");
						fprintf(output, "|     |                     /     |\n");
						fprintf(output, "|     |                    /      |\n");
						fprintf(output, "|     |                   /       |\n");
						fprintf(output, "|     |                  /        |\n");
						fprintf(output, "|     |                 /         |\n");
						fprintf(output, "|     |                /          |\n");
						fprintf(output, "|     |               /           |\n");
						fprintf(output, "| f(x)|              /            |\n");
						fprintf(output, "|     |             /             |\n");
						fprintf(output, "|     |            /              |\n");
						fprintf(output, "|     |           /               |\n");
						fprintf(output, "|     |          /                |\n");
						fprintf(output, "|     |         /                 |\n");
						fprintf(output, "|     |        /                  |\n");
						fprintf(output, "|     |       /                   |\n");
						fprintf(output, "|     |      /                    |\n");
						fprintf(output, "|     |     /                     |\n");
						fprintf(output, "|     |    /                      |\n");
						fprintf(output, "|     |   0                       |\n");
						fprintf(output, "|=====|===========================|\n");
					}
					else
					{
						if (x1 == x2) {
							fprintf(output, "|=====|===========================|\n");
							fprintf(output, "|  x  | %.2f                  +oo|\n", x3);
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|f'(x)|             +             |\n");
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|     |                      +oo  |\n");
							fprintf(output, "|     |                     /     |\n");
							fprintf(output, "|     |                    /      |\n");
							fprintf(output, "|     |                   /       |\n");
							fprintf(output, "|     |                  /        |\n");
							fprintf(output, "|     |                 /         |\n");
							fprintf(output, "|     |                /          |\n");
							fprintf(output, "|     |               /           |\n");
							fprintf(output, "| f(x)|              /            |\n");
							fprintf(output, "|     |             /             |\n");
							fprintf(output, "|     |            /              |\n");
							fprintf(output, "|     |           /               |\n");
							fprintf(output, "|     |          /                |\n");
							fprintf(output, "|     |         /                 |\n");
							fprintf(output, "|     |        /                  |\n");
							fprintf(output, "|     |       /                   |\n");
							fprintf(output, "|     |      /                    |\n");
							fprintf(output, "|     |     /                     |\n");
							fprintf(output, "|     |    /                      |\n");
							fprintf(output, "|     |   0                       |\n");
							fprintf(output, "|=====|===========================|\n");
						}
						else
						{
							if (x2 == x3) {
								fprintf(output, "|=====|===========================|\n");
								fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|f'(x)|             +             |\n");
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|     |                      +oo  |\n");
								fprintf(output, "|     |                     /     |\n");
								fprintf(output, "|     |                    /      |\n");
								fprintf(output, "|     |                   /       |\n");
								fprintf(output, "|     |                  /        |\n");
								fprintf(output, "|     |                 /         |\n");
								fprintf(output, "|     |                /          |\n");
								fprintf(output, "|     |               /           |\n");
								fprintf(output, "| f(x)|              /            |\n");
								fprintf(output, "|     |             /             |\n");
								fprintf(output, "|     |            /              |\n");
								fprintf(output, "|     |           /               |\n");
								fprintf(output, "|     |          /                |\n");
								fprintf(output, "|     |         /                 |\n");
								fprintf(output, "|     |        /                  |\n");
								fprintf(output, "|     |       /                   |\n");
								fprintf(output, "|     |      /                    |\n");
								fprintf(output, "|     |     /                     |\n");
								fprintf(output, "|     |    /                      |\n");
								fprintf(output, "|     |   0                       |\n");
								fprintf(output, "|=====|===========================|\n");
							}
							else
							{
								fprintf(output, "|=====|=========================================================|\n");
								fprintf(output, "|  x  | %.2f                  %.2f     %.2f                  +oo|\n", x1, x2, x3);
								fprintf(output, "|-----|---------------------------------------------------------|\n");
								fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
								fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
								fprintf(output, "|     |                      0||        ||                  +oo |\n");
								fprintf(output, "|     |                     / ||        ||                  /   |\n");
								fprintf(output, "|     |                    /  ||        ||                 /    |\n");
								fprintf(output, "|     |                   /   ||        ||                /     |\n");
								fprintf(output, "|     |                  /    ||        ||               /      |\n");
								fprintf(output, "|     |                 /     ||        ||              /       |\n");
								fprintf(output, "|     |                /      ||        ||             /        |\n");
								fprintf(output, "|     |               /       ||        ||            /         |\n");
								fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
								fprintf(output, "|     |             /         ||        ||          /           |\n");
								fprintf(output, "|     |            /          ||        ||         /            |\n");
								fprintf(output, "|     |           /           ||        ||        /             |\n");
								fprintf(output, "|     |          /            ||        ||       /              |\n");
								fprintf(output, "|     |         /             ||        ||      /               |\n");
								fprintf(output, "|     |        /              ||        ||     /                |\n");
								fprintf(output, "|     |       /               ||        ||    /                 |\n");
								fprintf(output, "|     |      /                ||        ||   /                  |\n");
								fprintf(output, "|     |     /                 ||        ||  /                   |\n");
								fprintf(output, "|     |    /                  ||        || /                    |\n");
								fprintf(output, "|     | -oo                   ||        ||0                     |\n");
								fprintf(output, "|=====|=========================================================|\n");
							}
						}
					}
				}
				else
				{
					if (x1 == x2 && x2 == x3)
					{
						fprintf(output, "|=====|===========================|\n");
						fprintf(output, "|  x  | -oo                  %.2f|\n", x1);
						fprintf(output, "|-----|---------------------------|\n");
						fprintf(output, "|f'(x)|             +             |\n");
						fprintf(output, "|-----|---------------------------|\n");
						fprintf(output, "|     |                      0    |\n");
						fprintf(output, "|     |                     /     |\n");
						fprintf(output, "|     |                    /      |\n");
						fprintf(output, "|     |                   /       |\n");
						fprintf(output, "|     |                  /        |\n");
						fprintf(output, "|     |                 /         |\n");
						fprintf(output, "|     |                /          |\n");
						fprintf(output, "|     |               /           |\n");
						fprintf(output, "| f(x)|              /            |\n");
						fprintf(output, "|     |             /             |\n");
						fprintf(output, "|     |            /              |\n");
						fprintf(output, "|     |           /               |\n");
						fprintf(output, "|     |          /                |\n");
						fprintf(output, "|     |         /                 |\n");
						fprintf(output, "|     |        /                  |\n");
						fprintf(output, "|     |       /                   |\n");
						fprintf(output, "|     |      /                    |\n");
						fprintf(output, "|     |     /                     |\n");
						fprintf(output, "|     |    /                      |\n");
						fprintf(output, "|     | -oo                       |\n");
						fprintf(output, "|=====|===========================|\n");
					}
					else
					{
						if (x1 == x2)
						{
							fprintf(output, "|=====|===========================|\n");
							fprintf(output, "|  x  | -oo                  %.2f|\n", x3);
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|f'(x)|             +             |\n");
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|     |                      0    |\n");
							fprintf(output, "|     |                     /     |\n");
							fprintf(output, "|     |                    /      |\n");
							fprintf(output, "|     |                   /       |\n");
							fprintf(output, "|     |                  /        |\n");
							fprintf(output, "|     |                 /         |\n");
							fprintf(output, "|     |                /          |\n");
							fprintf(output, "|     |               /           |\n");
							fprintf(output, "| f(x)|              /            |\n");
							fprintf(output, "|     |             /             |\n");
							fprintf(output, "|     |            /              |\n");
							fprintf(output, "|     |           /               |\n");
							fprintf(output, "|     |          /                |\n");
							fprintf(output, "|     |         /                 |\n");
							fprintf(output, "|     |        /                  |\n");
							fprintf(output, "|     |       /                   |\n");
							fprintf(output, "|     |      /                    |\n");
							fprintf(output, "|     |     /                     |\n");
							fprintf(output, "|     |    /                      |\n");
							fprintf(output, "|     | -oo                       |\n");
							fprintf(output, "|=====|===========================|\n");
						}
						else
						{
							if (x2 == x3)
							{
								fprintf(output, "|=====|===========================|\n");
								fprintf(output, "|  x  | -oo                  %.2f|\n", x1);
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|f'(x)|             +             |\n");
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|     |                      0    |\n");
								fprintf(output, "|     |                     /     |\n");
								fprintf(output, "|     |                    /      |\n");
								fprintf(output, "|     |                   /       |\n");
								fprintf(output, "|     |                  /        |\n");
								fprintf(output, "|     |                 /         |\n");
								fprintf(output, "|     |                /          |\n");
								fprintf(output, "|     |               /           |\n");
								fprintf(output, "| f(x)|              /            |\n");
								fprintf(output, "|     |             /             |\n");
								fprintf(output, "|     |            /              |\n");
								fprintf(output, "|     |           /               |\n");
								fprintf(output, "|     |          /                |\n");
								fprintf(output, "|     |         /                 |\n");
								fprintf(output, "|     |        /                  |\n");
								fprintf(output, "|     |       /                   |\n");
								fprintf(output, "|     |      /                    |\n");
								fprintf(output, "|     |     /                     |\n");
								fprintf(output, "|     |    /                      |\n");
								fprintf(output, "|     | -oo                       |\n");
								fprintf(output, "|=====|===========================|\n");
							}
							else
							{
								fprintf(output, "|=====|=========================================================|\n");
								fprintf(output, "|  x  | -oo                  %.2f     %.2f                  %.2f|\n", x1, x2, x3);
								fprintf(output, "|-----|---------------------------------------------------------|\n");
								fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
								fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
								fprintf(output, "|     |                      0||        ||                  %.2f|\n", Equa_3(a, b, c, d, x3));
								fprintf(output, "|     |                     / ||        ||                  /   |\n");
								fprintf(output, "|     |                    /  ||        ||                 /    |\n");
								fprintf(output, "|     |                   /   ||        ||                /     |\n");
								fprintf(output, "|     |                  /    ||        ||               /      |\n");
								fprintf(output, "|     |                 /     ||        ||              /       |\n");
								fprintf(output, "|     |                /      ||        ||             /        |\n");
								fprintf(output, "|     |               /       ||        ||            /         |\n");
								fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
								fprintf(output, "|     |             /         ||        ||          /           |\n");
								fprintf(output, "|     |            /          ||        ||         /            |\n");
								fprintf(output, "|     |           /           ||        ||        /             |\n");
								fprintf(output, "|     |          /            ||        ||       /              |\n");
								fprintf(output, "|     |         /             ||        ||      /               |\n");
								fprintf(output, "|     |        /              ||        ||     /                |\n");
								fprintf(output, "|     |       /               ||        ||    /                 |\n");
								fprintf(output, "|     |      /                ||        ||   /                  |\n");
								fprintf(output, "|     |     /                 ||        ||  /                   |\n");
								fprintf(output, "|     |    /                  ||        || /                    |\n");
								fprintf(output, "|     | -oo                   ||        ||0                     |\n");
								fprintf(output, "|=====|=========================================================|\n");
							}
						}
					}
				}
			}
		}
		else
		{
			if (l == 0) {
				switch (k)
				{
				case 1:
					if (a > 0)
					{
						if (x > x1) {
							fprintf(output, "|=====|===========================|\n");
							fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|f'(x)|             +             |\n");
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|     |                      +oo  |\n");
							fprintf(output, "|     |                     /     |\n");
							fprintf(output, "|     |                    /      |\n");
							fprintf(output, "|     |                   /       |\n");
							fprintf(output, "|     |                  /        |\n");
							fprintf(output, "|     |                 /         |\n");
							fprintf(output, "|     |                /          |\n");
							fprintf(output, "|     |               /           |\n");
							fprintf(output, "| f(x)|              /            |\n");
							fprintf(output, "|     |             /             |\n");
							fprintf(output, "|     |            /              |\n");
							fprintf(output, "|     |           /               |\n");
							fprintf(output, "|     |          /                |\n");
							fprintf(output, "|     |         /                 |\n");
							fprintf(output, "|     |        /                  |\n");
							fprintf(output, "|     |       /                   |\n");
							fprintf(output, "|     |      /                    |\n");
							fprintf(output, "|     |     /                     |\n");
							fprintf(output, "|     |    /                      |\n");
							fprintf(output, "|     |   0                       |\n");
							fprintf(output, "|=====|===========================|\n");
						}
						else
						{
							fprintf(output, "|=====|===========================|\n");
							fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|f'(x)|             +             |\n");
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|     |                      +oo  |\n");
							fprintf(output, "|     |                     /     |\n");
							fprintf(output, "|     |                    /      |\n");
							fprintf(output, "|     |                   /       |\n");
							fprintf(output, "|     |                  /        |\n");
							fprintf(output, "|     |                 /         |\n");
							fprintf(output, "|     |                /          |\n");
							fprintf(output, "|     |               /           |\n");
							fprintf(output, "| f(x)|              /            |\n");
							fprintf(output, "|     |             /             |\n");
							fprintf(output, "|     |            /              |\n");
							fprintf(output, "|     |           /               |\n");
							fprintf(output, "|     |          /                |\n");
							fprintf(output, "|     |         /                 |\n");
							fprintf(output, "|     |        /                  |\n");
							fprintf(output, "|     |       /                   |\n");
							fprintf(output, "|     |      /                    |\n");
							fprintf(output, "|     |     /                     |\n");
							fprintf(output, "|     |    /                      |\n");
							fprintf(output, "|     |   0                       |\n");
							fprintf(output, "|=====|===========================|\n");
						}
					}
					else {
						if (x > x1)
						{
							fprintf(output, "|=====|===========================|\n");
							fprintf(output, "|  x  | -oo                  %.2f|\n", x1);
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|f'(x)|             +             |\n");
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|     |                      0    |\n");
							fprintf(output, "|     |                     /     |\n");
							fprintf(output, "|     |                    /      |\n");
							fprintf(output, "|     |                   /       |\n");
							fprintf(output, "|     |                  /        |\n");
							fprintf(output, "|     |                 /         |\n");
							fprintf(output, "|     |                /          |\n");
							fprintf(output, "|     |               /           |\n");
							fprintf(output, "| f(x)|              /            |\n");
							fprintf(output, "|     |             /             |\n");
							fprintf(output, "|     |            /              |\n");
							fprintf(output, "|     |           /               |\n");
							fprintf(output, "|     |          /                |\n");
							fprintf(output, "|     |         /                 |\n");
							fprintf(output, "|     |        /                  |\n");
							fprintf(output, "|     |       /                   |\n");
							fprintf(output, "|     |      /                    |\n");
							fprintf(output, "|     |     /                     |\n");
							fprintf(output, "|     |    /                      |\n");
							fprintf(output, "|     | -oo                       |\n");
							fprintf(output, "|=====|===========================|\n");
						}
						else {
							fprintf(output, "|=====|===========================|\n");
							fprintf(output, "|  x  | -oo                  %.2f|\n", x1);
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|f'(x)|             +             |\n");
							fprintf(output, "|-----|---------------------------|\n");
							fprintf(output, "|     |                      0    |\n");
							fprintf(output, "|     |                     /     |\n");
							fprintf(output, "|     |                    /      |\n");
							fprintf(output, "|     |                   /       |\n");
							fprintf(output, "|     |                  /        |\n");
							fprintf(output, "|     |                 /         |\n");
							fprintf(output, "|     |                /          |\n");
							fprintf(output, "|     |               /           |\n");
							fprintf(output, "| f(x)|              /            |\n");
							fprintf(output, "|     |             /             |\n");
							fprintf(output, "|     |            /              |\n");
							fprintf(output, "|     |           /               |\n");
							fprintf(output, "|     |          /                |\n");
							fprintf(output, "|     |         /                 |\n");
							fprintf(output, "|     |        /                  |\n");
							fprintf(output, "|     |       /                   |\n");
							fprintf(output, "|     |      /                    |\n");
							fprintf(output, "|     |     /                     |\n");
							fprintf(output, "|     |    /                      |\n");
							fprintf(output, "|     | -oo                       |\n");
							fprintf(output, "|=====|===========================|\n");
						}
					}
					break;
				case 3:
					if (a > 0)
					{
						if (x1 == x2 && x2 == x3) {
							if (x < x1)
							{
								fprintf(output, "|=====|===========================|\n");
								fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|f'(x)|             +             |\n");
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|     |                      +oo  |\n");
								fprintf(output, "|     |                     /     |\n");
								fprintf(output, "|     |                    /      |\n");
								fprintf(output, "|     |                   /       |\n");
								fprintf(output, "|     |                  /        |\n");
								fprintf(output, "|     |                 /         |\n");
								fprintf(output, "|     |                /          |\n");
								fprintf(output, "|     |               /           |\n");
								fprintf(output, "| f(x)|              /            |\n");
								fprintf(output, "|     |             /             |\n");
								fprintf(output, "|     |            /              |\n");
								fprintf(output, "|     |           /               |\n");
								fprintf(output, "|     |          /                |\n");
								fprintf(output, "|     |         /                 |\n");
								fprintf(output, "|     |        /                  |\n");
								fprintf(output, "|     |       /                   |\n");
								fprintf(output, "|     |      /                    |\n");
								fprintf(output, "|     |     /                     |\n");
								fprintf(output, "|     |    /                      |\n");
								fprintf(output, "|     |   0                       |\n");
								fprintf(output, "|=====|===========================|\n");
							}
							else {
								fprintf(output, "|=====|===========================|\n");
								fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|f'(x)|             +             |\n");
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|     |                      +oo  |\n");
								fprintf(output, "|     |                     /     |\n");
								fprintf(output, "|     |                    /      |\n");
								fprintf(output, "|     |                   /       |\n");
								fprintf(output, "|     |                  /        |\n");
								fprintf(output, "|     |                 /         |\n");
								fprintf(output, "|     |                /          |\n");
								fprintf(output, "|     |               /           |\n");
								fprintf(output, "| f(x)|              /            |\n");
								fprintf(output, "|     |             /             |\n");
								fprintf(output, "|     |            /              |\n");
								fprintf(output, "|     |           /               |\n");
								fprintf(output, "|     |          /                |\n");
								fprintf(output, "|     |         /                 |\n");
								fprintf(output, "|     |        /                  |\n");
								fprintf(output, "|     |       /                   |\n");
								fprintf(output, "|     |      /                    |\n");
								fprintf(output, "|     |     /                     |\n");
								fprintf(output, "|     |    /                      |\n");
								fprintf(output, "|     |   0                       |\n");
								fprintf(output, "|=====|===========================|\n");
							}
						}
						else
						{
							if (x1 == x2) {
								if (x < x3)
								{
									fprintf(output, "|=====|===========================|\n");
									fprintf(output, "|  x  | %.2f                  +oo|\n", x3);
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|f'(x)|             +             |\n");
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|     |                      +oo  |\n");
									fprintf(output, "|     |                     /     |\n");
									fprintf(output, "|     |                    /      |\n");
									fprintf(output, "|     |                   /       |\n");
									fprintf(output, "|     |                  /        |\n");
									fprintf(output, "|     |                 /         |\n");
									fprintf(output, "|     |                /          |\n");
									fprintf(output, "|     |               /           |\n");
									fprintf(output, "| f(x)|              /            |\n");
									fprintf(output, "|     |             /             |\n");
									fprintf(output, "|     |            /              |\n");
									fprintf(output, "|     |           /               |\n");
									fprintf(output, "|     |          /                |\n");
									fprintf(output, "|     |         /                 |\n");
									fprintf(output, "|     |        /                  |\n");
									fprintf(output, "|     |       /                   |\n");
									fprintf(output, "|     |      /                    |\n");
									fprintf(output, "|     |     /                     |\n");
									fprintf(output, "|     |    /                      |\n");
									fprintf(output, "|     |   0                       |\n");
									fprintf(output, "|=====|===========================|\n");
								}
								else {
									fprintf(output, "|=====|===========================|\n");
									fprintf(output, "|  x  | %.2f                  +oo|\n", x3);
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|f'(x)|             +             |\n");
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|     |                      +oo  |\n");
									fprintf(output, "|     |                     /     |\n");
									fprintf(output, "|     |                    /      |\n");
									fprintf(output, "|     |                   /       |\n");
									fprintf(output, "|     |                  /        |\n");
									fprintf(output, "|     |                 /         |\n");
									fprintf(output, "|     |                /          |\n");
									fprintf(output, "|     |               /           |\n");
									fprintf(output, "| f(x)|              /            |\n");
									fprintf(output, "|     |             /             |\n");
									fprintf(output, "|     |            /              |\n");
									fprintf(output, "|     |           /               |\n");
									fprintf(output, "|     |          /                |\n");
									fprintf(output, "|     |         /                 |\n");
									fprintf(output, "|     |        /                  |\n");
									fprintf(output, "|     |       /                   |\n");
									fprintf(output, "|     |      /                    |\n");
									fprintf(output, "|     |     /                     |\n");
									fprintf(output, "|     |    /                      |\n");
									fprintf(output, "|     |   0                       |\n");
									fprintf(output, "|=====|===========================|\n");
								}
							}
							else
							{
								if (x2 == x3) {
									if (x < x1)
									{
										fprintf(output, "|=====|===========================|\n");
										fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|f'(x)|             +             |\n");
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|     |                      +oo  |\n");
										fprintf(output, "|     |                     /     |\n");
										fprintf(output, "|     |                    /      |\n");
										fprintf(output, "|     |                   /       |\n");
										fprintf(output, "|     |                  /        |\n");
										fprintf(output, "|     |                 /         |\n");
										fprintf(output, "|     |                /          |\n");
										fprintf(output, "|     |               /           |\n");
										fprintf(output, "| f(x)|              /            |\n");
										fprintf(output, "|     |             /             |\n");
										fprintf(output, "|     |            /              |\n");
										fprintf(output, "|     |           /               |\n");
										fprintf(output, "|     |          /                |\n");
										fprintf(output, "|     |         /                 |\n");
										fprintf(output, "|     |        /                  |\n");
										fprintf(output, "|     |       /                   |\n");
										fprintf(output, "|     |      /                    |\n");
										fprintf(output, "|     |     /                     |\n");
										fprintf(output, "|     |    /                      |\n");
										fprintf(output, "|     |   0                       |\n");
										fprintf(output, "|=====|===========================|\n");
									}
									else {
										fprintf(output, "|=====|===========================|\n");
										fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|f'(x)|             +             |\n");
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|     |                      +oo  |\n");
										fprintf(output, "|     |                     /     |\n");
										fprintf(output, "|     |                    /      |\n");
										fprintf(output, "|     |                   /       |\n");
										fprintf(output, "|     |                  /        |\n");
										fprintf(output, "|     |                 /         |\n");
										fprintf(output, "|     |                /          |\n");
										fprintf(output, "|     |               /           |\n");
										fprintf(output, "| f(x)|              /            |\n");
										fprintf(output, "|     |             /             |\n");
										fprintf(output, "|     |            /              |\n");
										fprintf(output, "|     |           /               |\n");
										fprintf(output, "|     |          /                |\n");
										fprintf(output, "|     |         /                 |\n");
										fprintf(output, "|     |        /                  |\n");
										fprintf(output, "|     |       /                   |\n");
										fprintf(output, "|     |      /                    |\n");
										fprintf(output, "|     |     /                     |\n");
										fprintf(output, "|     |    /                      |\n");
										fprintf(output, "|     |   0                       |\n");
										fprintf(output, "|=====|===========================|\n");
									}
								}
								else {
									if (x < x1) {
										fprintf(output, "|=====|=========================================================|\n");
										fprintf(output, "|  x  | %.2f                  %.2f     %.2f                  +oo|\n", x1, x2, x3);
										fprintf(output, "|-----|---------------------------------------------------------|\n");
										fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
										fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
										fprintf(output, "|     |                      0||        ||                  +oo |\n");
										fprintf(output, "|     |                     / ||        ||                  /   |\n");
										fprintf(output, "|     |                    /  ||        ||                 /    |\n");
										fprintf(output, "|     |                   /   ||        ||                /     |\n");
										fprintf(output, "|     |                  /    ||        ||               /      |\n");
										fprintf(output, "|     |                 /     ||        ||              /       |\n");
										fprintf(output, "|     |                /      ||        ||             /        |\n");
										fprintf(output, "|     |               /       ||        ||            /         |\n");
										fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
										fprintf(output, "|     |             /         ||        ||          /           |\n");
										fprintf(output, "|     |            /          ||        ||         /            |\n");
										fprintf(output, "|     |           /           ||        ||        /             |\n");
										fprintf(output, "|     |          /            ||        ||       /              |\n");
										fprintf(output, "|     |         /             ||        ||      /               |\n");
										fprintf(output, "|     |        /              ||        ||     /                |\n");
										fprintf(output, "|     |       /               ||        ||    /                 |\n");
										fprintf(output, "|     |      /                ||        ||   /                  |\n");
										fprintf(output, "|     |     /                 ||        ||  /                   |\n");
										fprintf(output, "|     |    /                  ||        || /                    |\n");
										fprintf(output, "|     | -oo                   ||        ||0                     |\n");
										fprintf(output, "|=====|=========================================================|\n");
									}
									else {
										if (x > x1 && x < x2) {
											fprintf(output, "|=====|=========================================================|\n");
											fprintf(output, "|  x  | %.2f                  %.2f     %.2f                  +oo|\n", x1, x2, x3);
											fprintf(output, "|-----|---------------------------------------------------------|\n");
											fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
											fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
											fprintf(output, "|     |                      0||        ||                   +oo|\n");
											fprintf(output, "|     |                     / ||        ||                  /   |\n");
											fprintf(output, "|     |                    /  ||        ||                 /    |\n");
											fprintf(output, "|     |                   /   ||        ||                /     |\n");
											fprintf(output, "|     |                  /    ||        ||               /      |\n");
											fprintf(output, "|     |                 /     ||        ||              /       |\n");
											fprintf(output, "|     |                /      ||        ||             /        |\n");
											fprintf(output, "|     |               /       ||        ||            /         |\n");
											fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
											fprintf(output, "|     |             /         ||        ||          /           |\n");
											fprintf(output, "|     |            /          ||        ||         /            |\n");
											fprintf(output, "|     |           /           ||        ||        /             |\n");
											fprintf(output, "|     |          /            ||        ||       /              |\n");
											fprintf(output, "|     |         /             ||        ||      /               |\n");
											fprintf(output, "|     |        /              ||        ||     /                |\n");
											fprintf(output, "|     |       /               ||        ||    /                 |\n");
											fprintf(output, "|     |      /                ||        ||   /                  |\n");
											fprintf(output, "|     |     /                 ||        ||  /                   |\n");
											fprintf(output, "|     |    /                  ||        || /                    |\n");
											fprintf(output, "|     | -oo                   ||        ||0                     |\n");
											fprintf(output, "|=====|=========================================================|\n");
										}
										else {
											if (x > x2 && x < x3) {
												fprintf(output, "|=====|=========================================================|\n");
												fprintf(output, "|  x  | %.2f                  %.2f     %.2f                  +oo|\n", x1, x2, x3);
												fprintf(output, "|-----|---------------------------------------------------------|\n");
												fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
												fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
												fprintf(output, "|     |                      0||        ||                   +oo|\n");
												fprintf(output, "|     |                     / ||        ||                  /   |\n");
												fprintf(output, "|     |                    /  ||        ||                 /    |\n");
												fprintf(output, "|     |                   /   ||        ||                /     |\n");
												fprintf(output, "|     |                  /    ||        ||               /      |\n");
												fprintf(output, "|     |                 /     ||        ||              /       |\n");
												fprintf(output, "|     |                /      ||        ||             /        |\n");
												fprintf(output, "|     |               /       ||        ||            /         |\n");
												fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
												fprintf(output, "|     |             /         ||        ||          /           |\n");
												fprintf(output, "|     |            /          ||        ||         /            |\n");
												fprintf(output, "|     |           /           ||        ||        /             |\n");
												fprintf(output, "|     |          /            ||        ||       /              |\n");
												fprintf(output, "|     |         /             ||        ||      /               |\n");
												fprintf(output, "|     |        /              ||        ||     /                |\n");
												fprintf(output, "|     |       /               ||        ||    /                 |\n");
												fprintf(output, "|     |      /                ||        ||   /                  |\n");
												fprintf(output, "|     |     /                 ||        ||  /                   |\n");
												fprintf(output, "|     |    /                  ||        || /                    |\n");
												fprintf(output, "|     | -oo                   ||        ||0                     |\n");
												fprintf(output, "|=====|=========================================================|\n");
											}
											else {
												fprintf(output, "|=====|=========================================================|\n");
												fprintf(output, "|  x  | %.2f                  %.2f     %.2f                  +oo|\n", x1, x2, x3);
												fprintf(output, "|-----|---------------------------------------------------------|\n");
												fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
												fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
												fprintf(output, "|     |                      0||        ||                   +oo|\n");
												fprintf(output, "|     |                     / ||        ||                  /   |\n");
												fprintf(output, "|     |                    /  ||        ||                 /    |\n");
												fprintf(output, "|     |                   /   ||        ||                /     |\n");
												fprintf(output, "|     |                  /    ||        ||               /      |\n");
												fprintf(output, "|     |                 /     ||        ||              /       |\n");
												fprintf(output, "|     |                /      ||        ||             /        |\n");
												fprintf(output, "|     |               /       ||        ||            /         |\n");
												fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
												fprintf(output, "|     |             /         ||        ||          /           |\n");
												fprintf(output, "|     |            /          ||        ||         /            |\n");
												fprintf(output, "|     |           /           ||        ||        /             |\n");
												fprintf(output, "|     |          /            ||        ||       /              |\n");
												fprintf(output, "|     |         /             ||        ||      /               |\n");
												fprintf(output, "|     |        /              ||        ||     /                |\n");
												fprintf(output, "|     |       /               ||        ||    /                 |\n");
												fprintf(output, "|     |      /                ||        ||   /                  |\n");
												fprintf(output, "|     |     /                 ||        ||  /                   |\n");
												fprintf(output, "|     |    /                  ||        || /                    |\n");
												fprintf(output, "|     | -oo                   ||        ||0                     |\n");
												fprintf(output, "|=====|=========================================================|\n");
											}

										}
									}
								}
							}
						}
					}
					else
					{
						if (x1 == x2 && x2 == x3) {
							if (x > x1)
							{
								fprintf(output, "|=====|===========================|\n");
								fprintf(output, "|  x  | -oo                  %.2f|\n", x1);
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|f'(x)|             +             |\n");
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|     |                      0    |\n");
								fprintf(output, "|     |                     /     |\n");
								fprintf(output, "|     |                    /      |\n");
								fprintf(output, "|     |                   /       |\n");
								fprintf(output, "|     |                  /        |\n");
								fprintf(output, "|     |                 /         |\n");
								fprintf(output, "|     |                /          |\n");
								fprintf(output, "|     |               /           |\n");
								fprintf(output, "| f(x)|              /            |\n");
								fprintf(output, "|     |             /             |\n");
								fprintf(output, "|     |            /              |\n");
								fprintf(output, "|     |           /               |\n");
								fprintf(output, "|     |          /                |\n");
								fprintf(output, "|     |         /                 |\n");
								fprintf(output, "|     |        /                  |\n");
								fprintf(output, "|     |       /                   |\n");
								fprintf(output, "|     |      /                    |\n");
								fprintf(output, "|     |     /                     |\n");
								fprintf(output, "|     |    /                      |\n");
								fprintf(output, "|     | -oo                       |\n");
								fprintf(output, "|=====|===========================|\n");
							}
							else {
								fprintf(output, "|=====|===========================|\n");
								fprintf(output, "|  x  | -oo                  %.2f|\n", x1);
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|f'(x)|             +             |\n");
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|     |                      0    |\n");
								fprintf(output, "|     |                     /     |\n");
								fprintf(output, "|     |                    /      |\n");
								fprintf(output, "|     |                   /       |\n");
								fprintf(output, "|     |                  /        |\n");
								fprintf(output, "|     |                 /         |\n");
								fprintf(output, "|     |                /          |\n");
								fprintf(output, "|     |               /           |\n");
								fprintf(output, "| f(x)|              /            |\n");
								fprintf(output, "|     |             /             |\n");
								fprintf(output, "|     |            /              |\n");
								fprintf(output, "|     |           /               |\n");
								fprintf(output, "|     |          /                |\n");
								fprintf(output, "|     |         /                 |\n");
								fprintf(output, "|     |        /                  |\n");
								fprintf(output, "|     |       /                   |\n");
								fprintf(output, "|     |      /                    |\n");
								fprintf(output, "|     |     /                     |\n");
								fprintf(output, "|     |    /                      |\n");
								fprintf(output, "|     | -oo                       |\n");
								fprintf(output, "|=====|===========================|\n");
							}
						}
						else
						{
							if (x1 == x2)
							{
								if (x > x3)
								{
									fprintf(output, "|=====|===========================|\n");
									fprintf(output, "|  x  | -oo                  %.2f|\n", x3);
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|f'(x)|             +             |\n");
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|     |                      0    |\n");
									fprintf(output, "|     |                     /     |\n");
									fprintf(output, "|     |                    /      |\n");
									fprintf(output, "|     |                   /       |\n");
									fprintf(output, "|     |                  /        |\n");
									fprintf(output, "|     |                 /         |\n");
									fprintf(output, "|     |                /          |\n");
									fprintf(output, "|     |               /           |\n");
									fprintf(output, "| f(x)|              /            |\n");
									fprintf(output, "|     |             /             |\n");
									fprintf(output, "|     |            /              |\n");
									fprintf(output, "|     |           /               |\n");
									fprintf(output, "|     |          /                |\n");
									fprintf(output, "|     |         /                 |\n");
									fprintf(output, "|     |        /                  |\n");
									fprintf(output, "|     |       /                   |\n");
									fprintf(output, "|     |      /                    |\n");
									fprintf(output, "|     |     /                     |\n");
									fprintf(output, "|     |    /                      |\n");
									fprintf(output, "|     | -oo                       |\n");
									fprintf(output, "|=====|===========================|\n");
								}
								else {

									fprintf(output, "|=====|===========================|\n");
									fprintf(output, "|  x  | -oo                  %.2f|\n", x3);
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|f'(x)|             +             |\n");
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|     |                      0    |\n");
									fprintf(output, "|     |                     /     |\n");
									fprintf(output, "|     |                    /      |\n");
									fprintf(output, "|     |                   /       |\n");
									fprintf(output, "|     |                  /        |\n");
									fprintf(output, "|     |                 /         |\n");
									fprintf(output, "|     |                /          |\n");
									fprintf(output, "|     |               /           |\n");
									fprintf(output, "| f(x)|              /            |\n");
									fprintf(output, "|     |             /             |\n");
									fprintf(output, "|     |            /              |\n");
									fprintf(output, "|     |           /               |\n");
									fprintf(output, "|     |          /                |\n");
									fprintf(output, "|     |         /                 |\n");
									fprintf(output, "|     |        /                  |\n");
									fprintf(output, "|     |       /                   |\n");
									fprintf(output, "|     |      /                    |\n");
									fprintf(output, "|     |     /                     |\n");
									fprintf(output, "|     |    /                      |\n");
									fprintf(output, "|     | -oo                       |\n");
									fprintf(output, "|=====|===========================|\n");
								}
							}
							else
							{
								if (x2 == x3)
								{
									if (x > x1)
									{

										fprintf(output, "|=====|===========================|\n");
										fprintf(output, "|  x  | -oo                  %.2f|\n", x1);
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|f'(x)|             +             |\n");
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|     |                      0    |\n");
										fprintf(output, "|     |                     /     |\n");
										fprintf(output, "|     |                    /      |\n");
										fprintf(output, "|     |                   /       |\n");
										fprintf(output, "|     |                  /        |\n");
										fprintf(output, "|     |                 /         |\n");
										fprintf(output, "|     |                /          |\n");
										fprintf(output, "|     |               /           |\n");
										fprintf(output, "| f(x)|              /            |\n");
										fprintf(output, "|     |             /             |\n");
										fprintf(output, "|     |            /              |\n");
										fprintf(output, "|     |           /               |\n");
										fprintf(output, "|     |          /                |\n");
										fprintf(output, "|     |         /                 |\n");
										fprintf(output, "|     |        /                  |\n");
										fprintf(output, "|     |       /                   |\n");
										fprintf(output, "|     |      /                    |\n");
										fprintf(output, "|     |     /                     |\n");
										fprintf(output, "|     |    /                      |\n");
										fprintf(output, "|     | -oo                       |\n");
										fprintf(output, "|=====|===========================|\n");
									}
									else {
										fprintf(output, "|=====|===========================|\n");
										fprintf(output, "|  x  | -oo                  %.2f|\n", x1);
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|f'(x)|             +             |\n");
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|     |                      0    |\n");
										fprintf(output, "|     |                     /     |\n");
										fprintf(output, "|     |                    /      |\n");
										fprintf(output, "|     |                   /       |\n");
										fprintf(output, "|     |                  /        |\n");
										fprintf(output, "|     |                 /         |\n");
										fprintf(output, "|     |                /          |\n");
										fprintf(output, "|     |               /           |\n");
										fprintf(output, "| f(x)|              /            |\n");
										fprintf(output, "|     |             /             |\n");
										fprintf(output, "|     |            /              |\n");
										fprintf(output, "|     |           /               |\n");
										fprintf(output, "|     |          /                |\n");
										fprintf(output, "|     |         /                 |\n");
										fprintf(output, "|     |        /                  |\n");
										fprintf(output, "|     |       /                   |\n");
										fprintf(output, "|     |      /                    |\n");
										fprintf(output, "|     |     /                     |\n");
										fprintf(output, "|     |    /                      |\n");
										fprintf(output, "|     | -oo                       |\n");
										fprintf(output, "|=====|===========================|\n");
									}
								}
								else
								{
									fprintf(output, "|=====|=========================================================|\n");
									fprintf(output, "|  x  | -oo                  %.2f     %.2f                  %.2f|\n", x1, x2, x3);
									fprintf(output, "|-----|---------------------------------------------------------|\n");
									fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
									fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
									fprintf(output, "|     |                      0||        ||                  %.2f|\n", Equa_3(a, b, c, d, x3));
									fprintf(output, "|     |                     / ||        ||                  /   |\n");
									fprintf(output, "|     |                    /  ||        ||                 /    |\n");
									fprintf(output, "|     |                   /   ||        ||                /     |\n");
									fprintf(output, "|     |                  /    ||        ||               /      |\n");
									fprintf(output, "|     |                 /     ||        ||              /       |\n");
									fprintf(output, "|     |                /      ||        ||             /        |\n");
									fprintf(output, "|     |               /       ||        ||            /         |\n");
									fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
									fprintf(output, "|     |             /         ||        ||          /           |\n");
									fprintf(output, "|     |            /          ||        ||         /            |\n");
									fprintf(output, "|     |           /           ||        ||        /             |\n");
									fprintf(output, "|     |          /            ||        ||       /              |\n");
									fprintf(output, "|     |         /             ||        ||      /               |\n");
									fprintf(output, "|     |        /              ||        ||     /                |\n");
									fprintf(output, "|     |       /               ||        ||    /                 |\n");
									fprintf(output, "|     |      /                ||        ||   /                  |\n");
									fprintf(output, "|     |     /                 ||        ||  /                   |\n");
									fprintf(output, "|     |    /                  ||        || /                    |\n");
									fprintf(output, "|     | -oo                   ||        ||0                     |\n");
									fprintf(output, "|=====|=========================================================|\n");
									if (x > x3) {
										fprintf(output, "|=====|=========================================================|\n");
										fprintf(output, "|  x  | -oo                  %.2f     %.2f                  %.2f|\n", x1, x2, x3);
										fprintf(output, "|-----|---------------------------------------------------------|\n");
										fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
										fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
										fprintf(output, "|     |                      0||        ||                  %.2f|\n", Equa_3(a, b, c, d, x3));
										fprintf(output, "|     |                     / ||        ||                  /   |\n");
										fprintf(output, "|     |                    /  ||        ||                 /    |\n");
										fprintf(output, "|     |                   /   ||        ||                /     |\n");
										fprintf(output, "|     |                  /    ||        ||               /      |\n");
										fprintf(output, "|     |                 /     ||        ||              /       |\n");
										fprintf(output, "|     |                /      ||        ||             /        |\n");
										fprintf(output, "|     |               /       ||        ||            /         |\n");
										fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
										fprintf(output, "|     |             /         ||        ||          /           |\n");
										fprintf(output, "|     |            /          ||        ||         /            |\n");
										fprintf(output, "|     |           /           ||        ||        /             |\n");
										fprintf(output, "|     |          /            ||        ||       /              |\n");
										fprintf(output, "|     |         /             ||        ||      /               |\n");
										fprintf(output, "|     |        /              ||        ||     /                |\n");
										fprintf(output, "|     |       /               ||        ||    /                 |\n");
										fprintf(output, "|     |      /                ||        ||   /                  |\n");
										fprintf(output, "|     |     /                 ||        ||  /                   |\n");
										fprintf(output, "|     |    /                  ||        || /                    |\n");
										fprintf(output, "|     | -oo                   ||        ||0                     |\n");
										fprintf(output, "|=====|=========================================================|\n");
									}
									else {
										if (x > x2 && x < x3) {
											fprintf(output, "|=====|=========================================================|\n");
											fprintf(output, "|  x  | -oo                  %.2f     %.2f                  %.2f|\n", x1, x2, x3);
											fprintf(output, "|-----|---------------------------------------------------------|\n");
											fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
											fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
											fprintf(output, "|     |                      0||        ||                  %.2f|\n", Equa_3(a, b, c, d, x3));
											fprintf(output, "|     |                     / ||        ||                  /   |\n");
											fprintf(output, "|     |                    /  ||        ||                 /    |\n");
											fprintf(output, "|     |                   /   ||        ||                /     |\n");
											fprintf(output, "|     |                  /    ||        ||               /      |\n");
											fprintf(output, "|     |                 /     ||        ||              /       |\n");
											fprintf(output, "|     |                /      ||        ||             /        |\n");
											fprintf(output, "|     |               /       ||        ||            /         |\n");
											fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
											fprintf(output, "|     |             /         ||        ||          /           |\n");
											fprintf(output, "|     |            /          ||        ||         /            |\n");
											fprintf(output, "|     |           /           ||        ||        /             |\n");
											fprintf(output, "|     |          /            ||        ||       /              |\n");
											fprintf(output, "|     |         /             ||        ||      /               |\n");
											fprintf(output, "|     |        /              ||        ||     /                |\n");
											fprintf(output, "|     |       /               ||        ||    /                 |\n");
											fprintf(output, "|     |      /                ||        ||   /                  |\n");
											fprintf(output, "|     |     /                 ||        ||  /                   |\n");
											fprintf(output, "|     |    /                  ||        || /                    |\n");
											fprintf(output, "|     | -oo                   ||        ||0                     |\n");
											fprintf(output, "|=====|=========================================================|\n");
										}
										else {
											if (x > x1 && x < x2) {
												fprintf(output, "|=====|=========================================================|\n");
												fprintf(output, "|  x  | -oo                  %.2f     %.2f                  %.2f|\n", x1, x2, x3);
												fprintf(output, "|-----|---------------------------------------------------------|\n");
												fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
												fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
												fprintf(output, "|     |                      0||        ||                  %.2f|\n", Equa_3(a, b, c, d, x3));
												fprintf(output, "|     |                     / ||        ||                  /   |\n");
												fprintf(output, "|     |                    /  ||        ||                 /    |\n");
												fprintf(output, "|     |                   /   ||        ||                /     |\n");
												fprintf(output, "|     |                  /    ||        ||               /      |\n");
												fprintf(output, "|     |                 /     ||        ||              /       |\n");
												fprintf(output, "|     |                /      ||        ||             /        |\n");
												fprintf(output, "|     |               /       ||        ||            /         |\n");
												fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
												fprintf(output, "|     |             /         ||        ||          /           |\n");
												fprintf(output, "|     |            /          ||        ||         /            |\n");
												fprintf(output, "|     |           /           ||        ||        /             |\n");
												fprintf(output, "|     |          /            ||        ||       /              |\n");
												fprintf(output, "|     |         /             ||        ||      /               |\n");
												fprintf(output, "|     |        /              ||        ||     /                |\n");
												fprintf(output, "|     |       /               ||        ||    /                 |\n");
												fprintf(output, "|     |      /                ||        ||   /                  |\n");
												fprintf(output, "|     |     /                 ||        ||  /                   |\n");
												fprintf(output, "|     |    /                  ||        || /                    |\n");
												fprintf(output, "|     | -oo                   ||        ||0                     |\n");
												fprintf(output, "|=====|=========================================================|\n");
											}
											else {
												fprintf(output, "|=====|=========================================================|\n");
												fprintf(output, "|  x  | -oo                  %.2f     %.2f                  %.2f|\n", x1, x2, x3);
												fprintf(output, "|-----|---------------------------------------------------------|\n");
												fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
												fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
												fprintf(output, "|     |                      0||        ||                  %.2f|\n", Equa_3(a, b, c, d, x3));
												fprintf(output, "|     |                     / ||        ||                  /   |\n");
												fprintf(output, "|     |                    /  ||        ||                 /    |\n");
												fprintf(output, "|     |                   /   ||        ||                /     |\n");
												fprintf(output, "|     |                  /    ||        ||               /      |\n");
												fprintf(output, "|     |                 /     ||        ||              /       |\n");
												fprintf(output, "|     |                /      ||        ||             /        |\n");
												fprintf(output, "|     |               /       ||        ||            /         |\n");
												fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
												fprintf(output, "|     |             /         ||        ||          /           |\n");
												fprintf(output, "|     |            /          ||        ||         /            |\n");
												fprintf(output, "|     |           /           ||        ||        /             |\n");
												fprintf(output, "|     |          /            ||        ||       /              |\n");
												fprintf(output, "|     |         /             ||        ||      /               |\n");
												fprintf(output, "|     |        /              ||        ||     /                |\n");
												fprintf(output, "|     |       /               ||        ||    /                 |\n");
												fprintf(output, "|     |      /                ||        ||   /                  |\n");
												fprintf(output, "|     |     /                 ||        ||  /                   |\n");
												fprintf(output, "|     |    /                  ||        || /                    |\n");
												fprintf(output, "|     | -oo                   ||        ||0                     |\n");
												fprintf(output, "|=====|=========================================================|\n");
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else {
				switch (k)
				{
				case 1:
					if (a > 0)
					{
						if (x > x1 && y > x1) {
							fprintf(output, "|=====|======================================================================|\n");
							fprintf(output, "|  x  | %.2f                 %.2f                     %.2f                +oo|\n", x1, x, y);
							fprintf(output, "|-----|----------------------------------------------------------------------|\n");
							fprintf(output, "|f'(x)|            +                      -                      +           |\n");
							fprintf(output, "|-----|----------------------------------------------------------------------|\n");
							fprintf(output, "|     |                      %.2f                                         +oo|\n", Equa_3(a, b, c, d, x));
							fprintf(output, "|     |                     /    \\                                        /  |\n");
							fprintf(output, "|     |                    /      \\                                      /   |\n");
							fprintf(output, "|     |                   /        \\                                    /    |\n");
							fprintf(output, "|     |                  /          \\                                  /     |\n");
							fprintf(output, "|     |                 /            \\                                /      |\n");
							fprintf(output, "|     |                /              \\                              /       |\n");
							fprintf(output, "|     |               /                \\                            /        |\n");
							fprintf(output, "| f(x)|              /                  \\                          /         |\n");
							fprintf(output, "|     |             /                    \\                        /          |\n");
							fprintf(output, "|     |            /                      \\                      /           |\n");
							fprintf(output, "|     |           /                        \\                    /            |\n");
							fprintf(output, "|     |          /                          \\                  /             |\n");
							fprintf(output, "|     |         /                            \\                /              |\n");
							fprintf(output, "|     |        /                              \\              /               |\n");
							fprintf(output, "|     |       /                                \\            /                |\n");
							fprintf(output, "|     |      /                                  \\          /                 |\n");
							fprintf(output, "|     |     /                                    \\        /                  |\n");
							fprintf(output, "|     |    /                                      \\      /                   |\n");
							fprintf(output, "|     |  0                                         \\ %.2f                    |\n", Equa_3(a, b, c, d, y));
							fprintf(output, "|=====|======================================================================|\n");
						}
						else {
							if (x < x1 && y>x1) {
								fprintf(output, "|=====|================================================|\n");
								fprintf(output, "|  x  |%.2f                     %.2f                +oo|\n", x1, y);
								fprintf(output, "|-----|------------------------------------------------|\n");
								fprintf(output, "|f'(x)|             -                       +          |\n");
								fprintf(output, "|-----|------------------------------------------------|\n");
								fprintf(output, "|     |   0                                         +oo|\n");
								fprintf(output, "|     |   \\                                        /   |\n");
								fprintf(output, "|     |    \\                                      /    |\n");
								fprintf(output, "|     |     \\                                    /     |\n");
								fprintf(output, "|     |      \\                                  /      |\n");
								fprintf(output, "|     |       \\                                /       |\n");
								fprintf(output, "|     |        \\                              /        |\n");
								fprintf(output, "|     |         \\                            /         |\n");
								fprintf(output, "| f(x)|          \\                          /          |\n");
								fprintf(output, "|     |           \\                        /           |\n");
								fprintf(output, "|     |            \\                      /            |\n");
								fprintf(output, "|     |             \\                    /             |\n");
								fprintf(output, "|     |              \\                  /              |\n");
								fprintf(output, "|     |               \\                /               |\n");
								fprintf(output, "|     |                \\              /                |\n");
								fprintf(output, "|     |                 \\            /                 |\n");
								fprintf(output, "|     |                  \\          /                  |\n");
								fprintf(output, "|     |                   \\        /                   |\n");
								fprintf(output, "|     |                    \\      /                    |\n");
								fprintf(output, "|     |                      %.2f                      |\n", Equa_3(a, b, c, d, y));
								fprintf(output, "|=====|================================================|\n");

							}
							else
							{
								fprintf(output, "|=====|===========================|\n");
								fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|f'(x)|             +             |\n");
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|     |                      +oo  |\n");
								fprintf(output, "|     |                     /     |\n");
								fprintf(output, "|     |                    /      |\n");
								fprintf(output, "|     |                   /       |\n");
								fprintf(output, "|     |                  /        |\n");
								fprintf(output, "|     |                 /         |\n");
								fprintf(output, "|     |                /          |\n");
								fprintf(output, "|     |               /           |\n");
								fprintf(output, "| f(x)|              /            |\n");
								fprintf(output, "|     |             /             |\n");
								fprintf(output, "|     |            /              |\n");
								fprintf(output, "|     |           /               |\n");
								fprintf(output, "|     |          /                |\n");
								fprintf(output, "|     |         /                 |\n");
								fprintf(output, "|     |        /                  |\n");
								fprintf(output, "|     |       /                   |\n");
								fprintf(output, "|     |      /                    |\n");
								fprintf(output, "|     |     /                     |\n");
								fprintf(output, "|     |    /                      |\n");
								fprintf(output, "|     |   0                       |\n");
								fprintf(output, "|=====|===========================|\n");
							}
						}
					}
					else {
						if (x < x1 && y < x1) {
							fprintf(output, "|=====|==========================================================================|\n");
							fprintf(output, "|  x  | -oo                    %.2f                    %.2f                 %.2f |\n", x, y, x1);
							fprintf(output, "|-----|--------------------------------------------------------------------------|\n");
							fprintf(output, "|f'(x)|             -                        +                       -           |\n");
							fprintf(output, "|-----|--------------------------------------------------------------------------|\n");
							fprintf(output, "|     |  -oo                                         %.2f                        |\n", Equa_3(a, b, c, d, y));
							fprintf(output, "|     |    \\                                        /   \\                        |\n");
							fprintf(output, "|     |     \\                                      /     \\                       |\n");
							fprintf(output, "|     |      \\                                    /       \\                      |\n");
							fprintf(output, "|     |       \\                                  /         \\                     |\n");
							fprintf(output, "|     |        \\                                /           \\                    |\n");
							fprintf(output, "|     |         \\                              /             \\                   |\n");
							fprintf(output, "|     |          \\                            /               \\                  |\n");
							fprintf(output, "| f(x)|           \\                          /                 \\                 |\n");
							fprintf(output, "|     |            \\                        /                   \\                |\n");
							fprintf(output, "|     |             \\                      /                     \\               |\n");
							fprintf(output, "|     |              \\                    /                       \\              |\n");
							fprintf(output, "|     |               \\                  /                         \\             |\n");
							fprintf(output, "|     |                \\                /                           \\            |\n");
							fprintf(output, "|     |                 \\              /                             \\           |\n");
							fprintf(output, "|     |                  \\            /                               \\          |\n");
							fprintf(output, "|     |                   \\          /                                 \\         |\n");
							fprintf(output, "|     |                    \\        /                                   \\        |\n");
							fprintf(output, "|     |                     \\      /                                     \\       |\n");
							fprintf(output, "|     |                       %.2f                                          0    |\n", Equa_3(a, b, c, d, x));
							fprintf(output, "|=====|==========================================================================|\n");
						}
						else {
							if (x<x1 && y>x1) {
								fprintf(output, "|=====|==================================================|\n");
								fprintf(output, "|  x  | -oo                 %.2f                     %.2f|\n", x, x1);
								fprintf(output, "|-----|--------------------------------------------------|\n");
								fprintf(output, "|f'(x)|            +                      -              |\n");
								fprintf(output, "|-----|--------------------------------------------------|\n");
								fprintf(output, "|     |                      %.2f                        |\n", Equa_3(a, b, c, d, x));
								fprintf(output, "|     |                     /    \\                       |\n");
								fprintf(output, "|     |                    /      \\                      |\n");
								fprintf(output, "|     |                   /        \\                     |\n");
								fprintf(output, "|     |                  /          \\                    |\n");
								fprintf(output, "|     |                 /            \\                   |\n");
								fprintf(output, "|     |                /              \\                  |\n");
								fprintf(output, "|     |               /                \\                 |\n");
								fprintf(output, "| f(x)|              /                  \\                |\n");
								fprintf(output, "|     |             /                    \\               |\n");
								fprintf(output, "|     |            /                      \\              |\n");
								fprintf(output, "|     |           /                        \\             |\n");
								fprintf(output, "|     |          /                          \\            |\n");
								fprintf(output, "|     |         /                            \\           |\n");
								fprintf(output, "|     |        /                              \\          |\n");
								fprintf(output, "|     |       /                                \\         |\n");
								fprintf(output, "|     |      /                                  \\        |\n");
								fprintf(output, "|     |     /                                    \\       |\n");
								fprintf(output, "|     |    /                                      \\      |\n");
								fprintf(output, "|     | -oo                                         0    |\n");
								fprintf(output, "|=====|==================================================|\n");
							}
							else {
								fprintf(output, "|=====|===========================|\n");
								fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|f'(x)|             +             |\n");
								fprintf(output, "|-----|---------------------------|\n");
								fprintf(output, "|     |                      +oo  |\n");
								fprintf(output, "|     |                     /     |\n");
								fprintf(output, "|     |                    /      |\n");
								fprintf(output, "|     |                   /       |\n");
								fprintf(output, "|     |                  /        |\n");
								fprintf(output, "|     |                 /         |\n");
								fprintf(output, "|     |                /          |\n");
								fprintf(output, "|     |               /           |\n");
								fprintf(output, "| f(x)|              /            |\n");
								fprintf(output, "|     |             /             |\n");
								fprintf(output, "|     |            /              |\n");
								fprintf(output, "|     |           /               |\n");
								fprintf(output, "|     |          /                |\n");
								fprintf(output, "|     |         /                 |\n");
								fprintf(output, "|     |        /                  |\n");
								fprintf(output, "|     |       /                   |\n");
								fprintf(output, "|     |      /                    |\n");
								fprintf(output, "|     |     /                     |\n");
								fprintf(output, "|     |    /                      |\n");
								fprintf(output, "|     |   0                       |\n");
								fprintf(output, "|=====|===========================|\n");
							}
						}
					}
					break;
				case 3:
					if (a > 0)
					{
						if (x1 == x2 && x2 == x3) {
							if (x > x1 && y > x1) {
								fprintf(output, "|=====|======================================================================|\n");
								fprintf(output, "|  x  | %.2f                 %.2f                     %.2f                +oo|\n", x1, x, y);
								fprintf(output, "|-----|----------------------------------------------------------------------|\n");
								fprintf(output, "|f'(x)|            +                      -                      +           |\n");
								fprintf(output, "|-----|----------------------------------------------------------------------|\n");
								fprintf(output, "|     |                      %.2f                                         +oo|\n", Equa_3(a, b, c, d, x));
								fprintf(output, "|     |                     /    \\                                        /  |\n");
								fprintf(output, "|     |                    /      \\                                      /   |\n");
								fprintf(output, "|     |                   /        \\                                    /    |\n");
								fprintf(output, "|     |                  /          \\                                  /     |\n");
								fprintf(output, "|     |                 /            \\                                /      |\n");
								fprintf(output, "|     |                /              \\                              /       |\n");
								fprintf(output, "|     |               /                \\                            /        |\n");
								fprintf(output, "| f(x)|              /                  \\                          /         |\n");
								fprintf(output, "|     |             /                    \\                        /          |\n");
								fprintf(output, "|     |            /                      \\                      /           |\n");
								fprintf(output, "|     |           /                        \\                    /            |\n");
								fprintf(output, "|     |          /                          \\                  /             |\n");
								fprintf(output, "|     |         /                            \\                /              |\n");
								fprintf(output, "|     |        /                              \\              /               |\n");
								fprintf(output, "|     |       /                                \\            /                |\n");
								fprintf(output, "|     |      /                                  \\          /                 |\n");
								fprintf(output, "|     |     /                                    \\        /                  |\n");
								fprintf(output, "|     |    /                                      \\      /                   |\n");
								fprintf(output, "|     |  0                                         \\ %.2f                    |\n", Equa_3(a, b, c, d, y));
								fprintf(output, "|=====|======================================================================|\n");
							}
							else {
								if (x < x1 && y>x1) {
									fprintf(output, "|=====|================================================|\n");
									fprintf(output, "|  x  |%.2f                     %.2f                +oo|\n", x1, y);
									fprintf(output, "|-----|------------------------------------------------|\n");
									fprintf(output, "|f'(x)|             -                       +          |\n");
									fprintf(output, "|-----|------------------------------------------------|\n");
									fprintf(output, "|     |   0                                         +oo|\n");
									fprintf(output, "|     |   \\                                        /   |\n");
									fprintf(output, "|     |    \\                                      /    |\n");
									fprintf(output, "|     |     \\                                    /     |\n");
									fprintf(output, "|     |      \\                                  /      |\n");
									fprintf(output, "|     |       \\                                /       |\n");
									fprintf(output, "|     |        \\                              /        |\n");
									fprintf(output, "|     |         \\                            /         |\n");
									fprintf(output, "| f(x)|          \\                          /          |\n");
									fprintf(output, "|     |           \\                        /           |\n");
									fprintf(output, "|     |            \\                      /            |\n");
									fprintf(output, "|     |             \\                    /             |\n");
									fprintf(output, "|     |              \\                  /              |\n");
									fprintf(output, "|     |               \\                /               |\n");
									fprintf(output, "|     |                \\              /                |\n");
									fprintf(output, "|     |                 \\            /                 |\n");
									fprintf(output, "|     |                  \\          /                  |\n");
									fprintf(output, "|     |                   \\        /                   |\n");
									fprintf(output, "|     |                    \\      /                    |\n");
									fprintf(output, "|     |                      %.2f                      |\n", Equa_3(a, b, c, d, y));
									fprintf(output, "|=====|================================================|\n");
								}
								else
								{
									fprintf(output, "|=====|===========================|\n");
									fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|f'(x)|             +             |\n");
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|     |                      +oo  |\n");
									fprintf(output, "|     |                     /     |\n");
									fprintf(output, "|     |                    /      |\n");
									fprintf(output, "|     |                   /       |\n");
									fprintf(output, "|     |                  /        |\n");
									fprintf(output, "|     |                 /         |\n");
									fprintf(output, "|     |                /          |\n");
									fprintf(output, "|     |               /           |\n");
									fprintf(output, "| f(x)|              /            |\n");
									fprintf(output, "|     |             /             |\n");
									fprintf(output, "|     |            /              |\n");
									fprintf(output, "|     |           /               |\n");
									fprintf(output, "|     |          /                |\n");
									fprintf(output, "|     |         /                 |\n");
									fprintf(output, "|     |        /                  |\n");
									fprintf(output, "|     |       /                   |\n");
									fprintf(output, "|     |      /                    |\n");
									fprintf(output, "|     |     /                     |\n");
									fprintf(output, "|     |    /                      |\n");
									fprintf(output, "|     |   0                       |\n");
									fprintf(output, "|=====|===========================|\n");
								}
							}
						}
						else
						{
							if (x1 == x2) {
								if (x < x3 && y < x3)
								{
									fprintf(output, "|=====|===========================|\n");
									fprintf(output, "|  x  | %.2f                  +oo|\n", x3);
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|f'(x)|             +             |\n");
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|     |                      +oo  |\n");
									fprintf(output, "|     |                     /     |\n");
									fprintf(output, "|     |                    /      |\n");
									fprintf(output, "|     |                   /       |\n");
									fprintf(output, "|     |                  /        |\n");
									fprintf(output, "|     |                 /         |\n");
									fprintf(output, "|     |                /          |\n");
									fprintf(output, "|     |               /           |\n");
									fprintf(output, "| f(x)|              /            |\n");
									fprintf(output, "|     |             /             |\n");
									fprintf(output, "|     |            /              |\n");
									fprintf(output, "|     |           /               |\n");
									fprintf(output, "|     |          /                |\n");
									fprintf(output, "|     |         /                 |\n");
									fprintf(output, "|     |        /                  |\n");
									fprintf(output, "|     |       /                   |\n");
									fprintf(output, "|     |      /                    |\n");
									fprintf(output, "|     |     /                     |\n");
									fprintf(output, "|     |    /                      |\n");
									fprintf(output, "|     |   0                       |\n");
									fprintf(output, "|=====|===========================|\n");
								}
								else {
									if (x<x3 && y>x3) {
										fprintf(output, "|=====|===========================|\n");
										fprintf(output, "|  x  | %.2f                  +oo|\n", x3);
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|f'(x)|             +             |\n");
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|     |                      +oo  |\n");
										fprintf(output, "|     |                     /     |\n");
										fprintf(output, "|     |                    /      |\n");
										fprintf(output, "|     |                   /       |\n");
										fprintf(output, "|     |                  /        |\n");
										fprintf(output, "|     |                 /         |\n");
										fprintf(output, "|     |                /          |\n");
										fprintf(output, "|     |               /           |\n");
										fprintf(output, "| f(x)|              /            |\n");
										fprintf(output, "|     |             /             |\n");
										fprintf(output, "|     |            /              |\n");
										fprintf(output, "|     |           /               |\n");
										fprintf(output, "|     |          /                |\n");
										fprintf(output, "|     |         /                 |\n");
										fprintf(output, "|     |        /                  |\n");
										fprintf(output, "|     |       /                   |\n");
										fprintf(output, "|     |      /                    |\n");
										fprintf(output, "|     |     /                     |\n");
										fprintf(output, "|     |    /                      |\n");
										fprintf(output, "|     |   0                       |\n");
										fprintf(output, "|=====|===========================|\n");
									}
									else {
										fprintf(output, "|=====|===========================|\n");
										fprintf(output, "|  x  | %.2f                  +oo|\n", x3);
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|f'(x)|             +             |\n");
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|     |                      +oo  |\n");
										fprintf(output, "|     |                     /     |\n");
										fprintf(output, "|     |                    /      |\n");
										fprintf(output, "|     |                   /       |\n");
										fprintf(output, "|     |                  /        |\n");
										fprintf(output, "|     |                 /         |\n");
										fprintf(output, "|     |                /          |\n");
										fprintf(output, "|     |               /           |\n");
										fprintf(output, "| f(x)|              /            |\n");
										fprintf(output, "|     |             /             |\n");
										fprintf(output, "|     |            /              |\n");
										fprintf(output, "|     |           /               |\n");
										fprintf(output, "|     |          /                |\n");
										fprintf(output, "|     |         /                 |\n");
										fprintf(output, "|     |        /                  |\n");
										fprintf(output, "|     |       /                   |\n");
										fprintf(output, "|     |      /                    |\n");
										fprintf(output, "|     |     /                     |\n");
										fprintf(output, "|     |    /                      |\n");
										fprintf(output, "|     |   0                       |\n");
										fprintf(output, "|=====|===========================|\n");
									}
								}
							}
							else
							{
								if (x2 == x3) {
									if (x < x1 && y < x1)
									{
										fprintf(output, "|=====|===========================|\n");
										fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|f'(x)|             +             |\n");
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|     |                      +oo  |\n");
										fprintf(output, "|     |                     /     |\n");
										fprintf(output, "|     |                    /      |\n");
										fprintf(output, "|     |                   /       |\n");
										fprintf(output, "|     |                  /        |\n");
										fprintf(output, "|     |                 /         |\n");
										fprintf(output, "|     |                /          |\n");
										fprintf(output, "|     |               /           |\n");
										fprintf(output, "| f(x)|              /            |\n");
										fprintf(output, "|     |             /             |\n");
										fprintf(output, "|     |            /              |\n");
										fprintf(output, "|     |           /               |\n");
										fprintf(output, "|     |          /                |\n");
										fprintf(output, "|     |         /                 |\n");
										fprintf(output, "|     |        /                  |\n");
										fprintf(output, "|     |       /                   |\n");
										fprintf(output, "|     |      /                    |\n");
										fprintf(output, "|     |     /                     |\n");
										fprintf(output, "|     |    /                      |\n");
										fprintf(output, "|     |   0                       |\n");
										fprintf(output, "|=====|===========================|\n");
									}
									else {
										if (x<x1 && y>x1) {
											fprintf(output, "|=====|===========================|\n");
											fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
											fprintf(output, "|-----|---------------------------|\n");
											fprintf(output, "|f'(x)|             +             |\n");
											fprintf(output, "|-----|---------------------------|\n");
											fprintf(output, "|     |                      +oo  |\n");
											fprintf(output, "|     |                     /     |\n");
											fprintf(output, "|     |                    /      |\n");
											fprintf(output, "|     |                   /       |\n");
											fprintf(output, "|     |                  /        |\n");
											fprintf(output, "|     |                 /         |\n");
											fprintf(output, "|     |                /          |\n");
											fprintf(output, "|     |               /           |\n");
											fprintf(output, "| f(x)|              /            |\n");
											fprintf(output, "|     |             /             |\n");
											fprintf(output, "|     |            /              |\n");
											fprintf(output, "|     |           /               |\n");
											fprintf(output, "|     |          /                |\n");
											fprintf(output, "|     |         /                 |\n");
											fprintf(output, "|     |        /                  |\n");
											fprintf(output, "|     |       /                   |\n");
											fprintf(output, "|     |      /                    |\n");
											fprintf(output, "|     |     /                     |\n");
											fprintf(output, "|     |    /                      |\n");
											fprintf(output, "|     |   0                       |\n");
											fprintf(output, "|=====|===========================|\n");
										}
										else {
											fprintf(output, "|=====|===========================|\n");
											fprintf(output, "|  x  | %.2f                  +oo|\n", x1);
											fprintf(output, "|-----|---------------------------|\n");
											fprintf(output, "|f'(x)|             +             |\n");
											fprintf(output, "|-----|---------------------------|\n");
											fprintf(output, "|     |                      +oo  |\n");
											fprintf(output, "|     |                     /     |\n");
											fprintf(output, "|     |                    /      |\n");
											fprintf(output, "|     |                   /       |\n");
											fprintf(output, "|     |                  /        |\n");
											fprintf(output, "|     |                 /         |\n");
											fprintf(output, "|     |                /          |\n");
											fprintf(output, "|     |               /           |\n");
											fprintf(output, "| f(x)|              /            |\n");
											fprintf(output, "|     |             /             |\n");
											fprintf(output, "|     |            /              |\n");
											fprintf(output, "|     |           /               |\n");
											fprintf(output, "|     |          /                |\n");
											fprintf(output, "|     |         /                 |\n");
											fprintf(output, "|     |        /                  |\n");
											fprintf(output, "|     |       /                   |\n");
											fprintf(output, "|     |      /                    |\n");
											fprintf(output, "|     |     /                     |\n");
											fprintf(output, "|     |    /                      |\n");
											fprintf(output, "|     |   0                       |\n");
											fprintf(output, "|=====|===========================|\n");
										}
									}
								}
								else {
									if (x < x1 && y < x1) {
										fprintf(output, "|=====|=========================================================|\n");
										fprintf(output, "|  x  | %.2f                  %.2f     %.2f                  +oo|\n", x1, x2, x3);
										fprintf(output, "|-----|---------------------------------------------------------|\n");
										fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
										fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
										fprintf(output, "|     |                      0||        ||                  +oo |\n");
										fprintf(output, "|     |                     / ||        ||                  /   |\n");
										fprintf(output, "|     |                    /  ||        ||                 /    |\n");
										fprintf(output, "|     |                   /   ||        ||                /     |\n");
										fprintf(output, "|     |                  /    ||        ||               /      |\n");
										fprintf(output, "|     |                 /     ||        ||              /       |\n");
										fprintf(output, "|     |                /      ||        ||             /        |\n");
										fprintf(output, "|     |               /       ||        ||            /         |\n");
										fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
										fprintf(output, "|     |             /         ||        ||          /           |\n");
										fprintf(output, "|     |            /          ||        ||         /            |\n");
										fprintf(output, "|     |           /           ||        ||        /             |\n");
										fprintf(output, "|     |          /            ||        ||       /              |\n");
										fprintf(output, "|     |         /             ||        ||      /               |\n");
										fprintf(output, "|     |        /              ||        ||     /                |\n");
										fprintf(output, "|     |       /               ||        ||    /                 |\n");
										fprintf(output, "|     |      /                ||        ||   /                  |\n");
										fprintf(output, "|     |     /                 ||        ||  /                   |\n");
										fprintf(output, "|     |    /                  ||        || /                    |\n");
										fprintf(output, "|     | -oo                   ||        ||0                     |\n");
										fprintf(output, "|=====|=========================================================|\n");
									}
									else {
										if (x<x1 && x >x1) {
											fprintf(output, "|=====|====================================================================================|\n");
											fprintf(output, "|  x  | %.2f                    %.2f                    %.2f     %.2f                   +oo|\n", x1, y, x2, x3);
											fprintf(output, "|-----|------------------------------------------------------------------------------------|\n");
											fprintf(output, "|f'(x)|              -                         +         ||        ||             +        |\n");
											fprintf(output, "|-----|--------------------------------------------------||--------||----------------------|\n");
											fprintf(output, "|     |  0                                             0 ||        ||                  +oo |\n");
											fprintf(output, "|     |    \\                                        /    ||        ||                  /   |\n");
											fprintf(output, "|     |     \\                                      /     ||        ||                 /    |\n");
											fprintf(output, "|     |      \\                                    /      ||        ||                /     |\n");
											fprintf(output, "|     |       \\                                  /       ||        ||               /      |\n");
											fprintf(output, "|     |        \\                                /        ||        ||              /       |\n");
											fprintf(output, "|     |         \\                              /         ||        ||             /        |\n");
											fprintf(output, "|     |          \\                            /          ||        ||            /         |\n");
											fprintf(output, "| f(x)|           \\                          /           ||        ||           /          |\n");
											fprintf(output, "|     |            \\                        /            ||        ||          /           |\n");
											fprintf(output, "|     |             \\                      /             ||        ||         /            |\n");
											fprintf(output, "|     |              \\                    /              ||        ||        /             |\n");
											fprintf(output, "|     |               \\                  /               ||        ||       /              |\n");
											fprintf(output, "|     |                \\                /                ||        ||      /               |\n");
											fprintf(output, "|     |                 \\              /                 ||        ||     /                |\n");
											fprintf(output, "|     |                  \\            /                  ||        ||    /                 |\n");
											fprintf(output, "|     |                   \\          /                   ||        ||   /                  |\n");
											fprintf(output, "|     |                    \\        /                    ||        ||  /                   |\n");
											fprintf(output, "|     |                     \\      /                     ||        || /                    |\n");
											fprintf(output, "|     |                        %.2f                      ||        ||0                     |\n", Equa_3(a, b, c, d, y));
											fprintf(output, "|=====|====================================================================================|\n");
										}
										else {
											if (x < x2 && y < x2) {
												fprintf(output, "|=====|=========================================================================================================|\n");
												fprintf(output, "|  x  | %.2f                 %.2f                    %.2f                    %.2f     %.2f                   +oo|\n", x1, x, y, x2, x3);
												fprintf(output, "|-----|---------------------------------------------------------------------------------------------------------|\n");
												fprintf(output, "|f'(x)|            +                      -                      +            ||        ||             +        |\n");
												fprintf(output, "|-----|-----------------------------------------------------------------------||--------||----------------------|\n");
												fprintf(output, "|     |                      %.2f                                           0 ||        ||                  +oo |\n", Equa_3(a, b, c, d, x));
												fprintf(output, "|     |                     /    \\                                        /   ||        ||                  /   |\n");
												fprintf(output, "|     |                    /      \\                                      /    ||        ||                 /    |\n");
												fprintf(output, "|     |                   /        \\                                    /     ||        ||                /     |\n");
												fprintf(output, "|     |                  /          \\                                  /      ||        ||               /      |\n");
												fprintf(output, "|     |                 /            \\                                /       ||        ||              /       |\n");
												fprintf(output, "|     |                /              \\                              /        ||        ||             /        |\n");
												fprintf(output, "|     |               /                \\                            /         ||        ||            /         |\n");
												fprintf(output, "| f(x)|              /                  \\                          /          ||        ||           /          |\n");
												fprintf(output, "|     |             /                    \\                        /           ||        ||          /           |\n");
												fprintf(output, "|     |            /                      \\                      /            ||        ||         /            |\n");
												fprintf(output, "|     |           /                        \\                    /             ||        ||        /             |\n");
												fprintf(output, "|     |          /                          \\                  /              ||        ||       /              |\n");
												fprintf(output, "|     |         /                            \\                /               ||        ||      /               |\n");
												fprintf(output, "|     |        /                              \\              /                ||        ||     /                |\n");
												fprintf(output, "|     |       /                                \\            /                 ||        ||    /                 |\n");
												fprintf(output, "|     |      /                                  \\          /                  ||        ||   /                  |\n");
												fprintf(output, "|     |     /                                    \\        /                   ||        ||  /                   |\n");
												fprintf(output, "|     |    /                                      \\      /                    ||        || /                    |\n");
												fprintf(output, "|     |  0                                         \\ %.2f                     ||        ||0                     |\n", Equa_3(a, b, c, d, y));
												fprintf(output, "|=====|=========================================================================================================|\n");
											}
											else {
												if (x<x2 && y>x2) {
													fprintf(output, "|=====|==================================================================================|\n");
													fprintf(output, "|  x  | %.2f                 %.2f                    %.2f       %.2f                  +oo|\n", x1, x, x2, x3);
													fprintf(output, "|-----|----------------------------------------------------------------------------------|\n");
													fprintf(output, "|f'(x)|            +                      -            ||        ||             +        |\n");
													fprintf(output, "|-----|------------------------------------------------||--------||----------------------|\n");
													fprintf(output, "|     |                      %.2f                      ||        ||                  +oo |\n", Equa_3(a, b, c, d, x));
													fprintf(output, "|     |                     /    \\                     ||        ||                  /   |\n");
													fprintf(output, "|     |                    /      \\                    ||        ||                 /    |\n");
													fprintf(output, "|     |                   /        \\                   ||        ||                /     |\n");
													fprintf(output, "|     |                  /          \\                  ||        ||               /      |\n");
													fprintf(output, "|     |                 /            \\                 ||        ||              /       |\n");
													fprintf(output, "|     |                /              \\                ||        ||             /        |\n");
													fprintf(output, "|     |               /                \\               ||        ||            /         |\n");
													fprintf(output, "| f(x)|              /                  \\              ||        ||           /          |\n");
													fprintf(output, "|     |             /                    \\             ||        ||          /           |\n");
													fprintf(output, "|     |            /                      \\            ||        ||         /            |\n");
													fprintf(output, "|     |           /                        \\           ||        ||        /             |\n");
													fprintf(output, "|     |          /                          \\          ||        ||       /              |\n");
													fprintf(output, "|     |         /                            \\         ||        ||      /               |\n");
													fprintf(output, "|     |        /                              \\        ||        ||     /                |\n");
													fprintf(output, "|     |       /                                \\       ||        ||    /                 |\n");
													fprintf(output, "|     |      /                                  \\      ||        ||   /                  |\n");
													fprintf(output, "|     |     /                                    \\     ||        ||  /                   |\n");
													fprintf(output, "|     |    /                                      \\    ||        || /                    |\n");
													fprintf(output, "|     |  0                                          0  ||        ||0                     |\n");
													fprintf(output, "|=====|==================================================================================|\n");
												}
												else {
													if (x < x3 && y < x3) {
														fprintf(output, "|=====|=========================================================|\n");
														fprintf(output, "|  x  | %.2f                  %.2f     %.2f                  +oo|\n", x1, x2, x3);
														fprintf(output, "|-----|---------------------------------------------------------|\n");
														fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
														fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
														fprintf(output, "|     |                      0||        ||                  +oo |\n");
														fprintf(output, "|     |                     / ||        ||                  /   |\n");
														fprintf(output, "|     |                    /  ||        ||                 /    |\n");
														fprintf(output, "|     |                   /   ||        ||                /     |\n");
														fprintf(output, "|     |                  /    ||        ||               /      |\n");
														fprintf(output, "|     |                 /     ||        ||              /       |\n");
														fprintf(output, "|     |                /      ||        ||             /        |\n");
														fprintf(output, "|     |               /       ||        ||            /         |\n");
														fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
														fprintf(output, "|     |             /         ||        ||          /           |\n");
														fprintf(output, "|     |            /          ||        ||         /            |\n");
														fprintf(output, "|     |           /           ||        ||        /             |\n");
														fprintf(output, "|     |          /            ||        ||       /              |\n");
														fprintf(output, "|     |         /             ||        ||      /               |\n");
														fprintf(output, "|     |        /              ||        ||     /                |\n");
														fprintf(output, "|     |       /               ||        ||    /                 |\n");
														fprintf(output, "|     |      /                ||        ||   /                  |\n");
														fprintf(output, "|     |     /                 ||        ||  /                   |\n");
														fprintf(output, "|     |    /                  ||        || /                    |\n");
														fprintf(output, "|     | -oo                   ||        ||0                     |\n");
														fprintf(output, "|=====|=========================================================|\n");
													}
													else {
														if (x<x3 && y>x3) {
															fprintf(output, "|=====|==================================================================================|\n");
															fprintf(output, "|  x  | %.2f                  %.2f     %.2f                     %.2f                  +oo|\n", x1, x2, x3, y);
															fprintf(output, "|-----|----------------------------------------------------------------------------------|\n");
															fprintf(output, "|f'(x)|             +         ||        ||            -                      +           |\n");
															fprintf(output, "|-----|-----------------------||--------||-----------------------------------------------|\n");
															fprintf(output, "|     |                      0||        || 0                                          +oo|\n");
															fprintf(output, "|     |                     / ||        ||  \\                                        /   |\n");
															fprintf(output, "|     |                    /  ||        ||   \\                                      /    |\n");
															fprintf(output, "|     |                   /   ||        ||    \\                                    /     |\n");
															fprintf(output, "|     |                  /    ||        ||     \\                                  /      |\n");
															fprintf(output, "|     |                 /     ||        ||      \\                                /       |\n");
															fprintf(output, "|     |                /      ||        ||       \\                              /        |\n");
															fprintf(output, "|     |               /       ||        ||        \\                            /         |\n");
															fprintf(output, "| f(x)|              /        ||        ||         \\                          /          |\n");
															fprintf(output, "|     |             /         ||        ||          \\                        /           |\n");
															fprintf(output, "|     |            /          ||        ||           \\                      /            |\n");
															fprintf(output, "|     |           /           ||        ||            \\                    /             |\n");
															fprintf(output, "|     |          /            ||        ||             \\                  /              |\n");
															fprintf(output, "|     |         /             ||        ||              \\                /               |\n");
															fprintf(output, "|     |        /              ||        ||               \\              /                |\n");
															fprintf(output, "|     |       /               ||        ||                \\            /                 |\n");
															fprintf(output, "|     |      /                ||        ||                 \\          /                  |\n");
															fprintf(output, "|     |     /                 ||        ||                  \\        /                   |\n");
															fprintf(output, "|     |    /                  ||        ||                   \\      /                    |\n");
															fprintf(output, "|     | -oo                   ||        ||                      %.2f                     |\n");
															fprintf(output, "|=====|==================================================================================|\n");
														}
														else {
															fprintf(output, "|=====|=====================================================================================================|\n");
															fprintf(output, "|  x  | %.2f                  %.2f     %.2f                 %.2f                  %.2f                   +oo|\n", x1, x2, x3, x, y);
															fprintf(output, "|-----|-----------------------------------------------------------------------------------------------------|\n");
															fprintf(output, "|f'(x)|             +         ||        ||         +                     -                     +            |\n");
															fprintf(output, "|-----|-----------------------||--------||------------------------------------------------------------------|\n");
															fprintf(output, "|     |                      0||        ||                  %.2f                                         +oo|\n", Equa_3(a, b, c, d, x));
															fprintf(output, "|     |                     / ||        ||                  /  \\                                      /     |\n");
															fprintf(output, "|     |                    /  ||        ||                 /    \\                                    /      |\n");
															fprintf(output, "|     |                   /   ||        ||                /      \\                                  /       |\n");
															fprintf(output, "|     |                  /    ||        ||               /        \\                                /        |\n");
															fprintf(output, "|     |                 /     ||        ||              /          \\                              /         |\n");
															fprintf(output, "|     |                /      ||        ||             /            \\                            /          |\n");
															fprintf(output, "|     |               /       ||        ||            /              \\                          /           |\n");
															fprintf(output, "| f(x)|              /        ||        ||           /                \\                        /            |\n");
															fprintf(output, "|     |             /         ||        ||          /                  \\                      /             |\n");
															fprintf(output, "|     |            /          ||        ||         /                    \\                    /              |\n");
															fprintf(output, "|     |           /           ||        ||        /                      \\                  /               |\n");
															fprintf(output, "|     |          /            ||        ||       /                        \\                /                |\n");
															fprintf(output, "|     |         /             ||        ||      /                          \\              /                 |\n");
															fprintf(output, "|     |        /              ||        ||     /                            \\            /                  |\n");
															fprintf(output, "|     |       /               ||        ||    /                              \\          /                   |\n");
															fprintf(output, "|     |      /                ||        ||   /                                \\        /                    |\n");
															fprintf(output, "|     |     /                 ||        ||  /                                  \\      /                     |\n");
															fprintf(output, "|     |    /                  ||        || /                                    \\    /                      |\n");
															fprintf(output, "|     | -oo                   ||        ||0                                       %.2f                      |\n", Equa_3(a, b, c, d, y));
															fprintf(output, "|=====|=====================================================================================================|\n");
														}
													}
												}

											}

										}
									}
								}
							}
						}
					}
					else
					{
						if (x1 == x2 && x2 == x3) {
							if (x < x1 && y < x1) {
								fprintf(output, "|=====|======================================================================|\n");
								fprintf(output, "|  x  | -oo                 %.2f                     %.2f                %.2f|\n", x, y, x1);
								fprintf(output, "|-----|----------------------------------------------------------------------|\n");
								fprintf(output, "|f'(x)|            +                      -                      +           |\n");
								fprintf(output, "|-----|----------------------------------------------------------------------|\n");
								fprintf(output, "|     |                      %.2f                                         %.2f|\n", Equa_3(a, b, c, d, x), Equa_3(a, b, c, d, x1));
								fprintf(output, "|     |                     /    \\                                        /  |\n");
								fprintf(output, "|     |                    /      \\                                      /   |\n");
								fprintf(output, "|     |                   /        \\                                    /    |\n");
								fprintf(output, "|     |                  /          \\                                  /     |\n");
								fprintf(output, "|     |                 /            \\                                /      |\n");
								fprintf(output, "|     |                /              \\                              /       |\n");
								fprintf(output, "|     |               /                \\                            /        |\n");
								fprintf(output, "| f(x)|              /                  \\                          /         |\n");
								fprintf(output, "|     |             /                    \\                        /          |\n");
								fprintf(output, "|     |            /                      \\                      /           |\n");
								fprintf(output, "|     |           /                        \\                    /            |\n");
								fprintf(output, "|     |          /                          \\                  /             |\n");
								fprintf(output, "|     |         /                            \\                /              |\n");
								fprintf(output, "|     |        /                              \\              /               |\n");
								fprintf(output, "|     |       /                                \\            /                |\n");
								fprintf(output, "|     |      /                                  \\          /                 |\n");
								fprintf(output, "|     |     /                                    \\        /                  |\n");
								fprintf(output, "|     |    /                                      \\      /                   |\n");
								fprintf(output, "|     | -oo                                        \\ %.2f                    |\n", Equa_3(a, b, c, d, y));
								fprintf(output, "|=====|======================================================================|\n");
							}
							else {
								if (x<x1 && y>x1) {
									fprintf(output, "|=====|==================================================|\n");
									fprintf(output, "|  x  | -oo                 %.2f                     %.2f|\n", x, x1);
									fprintf(output, "|-----|--------------------------------------------------|\n");
									fprintf(output, "|f'(x)|            +                      -              |\n");
									fprintf(output, "|-----|--------------------------------------------------|\n");
									fprintf(output, "|     |                      %.2f                        |\n", Equa_3(a, b, c, d, x));
									fprintf(output, "|     |                     /    \\                       |\n");
									fprintf(output, "|     |                    /      \\                      |\n");
									fprintf(output, "|     |                   /        \\                     |\n");
									fprintf(output, "|     |                  /          \\                    |\n");
									fprintf(output, "|     |                 /            \\                   |\n");
									fprintf(output, "|     |                /              \\                  |\n");
									fprintf(output, "|     |               /                \\                 |\n");
									fprintf(output, "| f(x)|              /                  \\                |\n");
									fprintf(output, "|     |             /                    \\               |\n");
									fprintf(output, "|     |            /                      \\              |\n");
									fprintf(output, "|     |           /                        \\             |\n");
									fprintf(output, "|     |          /                          \\            |\n");
									fprintf(output, "|     |         /                            \\           |\n");
									fprintf(output, "|     |        /                              \\          |\n");
									fprintf(output, "|     |       /                                \\         |\n");
									fprintf(output, "|     |      /                                  \\        |\n");
									fprintf(output, "|     |     /                                    \\       |\n");
									fprintf(output, "|     |    /                                      \\      |\n");
									fprintf(output, "|     | -oo                                         0    |\n");
									fprintf(output, "|=====|==================================================|\n");
								}
								else
								{
									fprintf(output, "|=====|===========================|\n");
									fprintf(output, "|  x  | -oo                  %.2f|\n", x1);
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|f'(x)|             +             |\n");
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|     |                      0    |\n");
									fprintf(output, "|     |                     /     |\n");
									fprintf(output, "|     |                    /      |\n");
									fprintf(output, "|     |                   /       |\n");
									fprintf(output, "|     |                  /        |\n");
									fprintf(output, "|     |                 /         |\n");
									fprintf(output, "|     |                /          |\n");
									fprintf(output, "|     |               /           |\n");
									fprintf(output, "| f(x)|              /            |\n");
									fprintf(output, "|     |             /             |\n");
									fprintf(output, "|     |            /              |\n");
									fprintf(output, "|     |           /               |\n");
									fprintf(output, "|     |          /                |\n");
									fprintf(output, "|     |         /                 |\n");
									fprintf(output, "|     |        /                  |\n");
									fprintf(output, "|     |       /                   |\n");
									fprintf(output, "|     |      /                    |\n");
									fprintf(output, "|     |     /                     |\n");
									fprintf(output, "|     |    /                      |\n");
									fprintf(output, "|     | -oo                       |\n");
									fprintf(output, "|=====|===========================|\n");
								}
							}
						}
						else
						{
							if (x1 == x2)
							{
								if (x > x3 && y > x3)
								{
									fprintf(output, "|=====|===========================|\n");
									fprintf(output, "|  x  | -oo                  %.2f|\n", x3);
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|f'(x)|             +             |\n");
									fprintf(output, "|-----|---------------------------|\n");
									fprintf(output, "|     |                      0    |\n");
									fprintf(output, "|     |                     /     |\n");
									fprintf(output, "|     |                    /      |\n");
									fprintf(output, "|     |                   /       |\n");
									fprintf(output, "|     |                  /        |\n");
									fprintf(output, "|     |                 /         |\n");
									fprintf(output, "|     |                /          |\n");
									fprintf(output, "|     |               /           |\n");
									fprintf(output, "| f(x)|              /            |\n");
									fprintf(output, "|     |             /             |\n");
									fprintf(output, "|     |            /              |\n");
									fprintf(output, "|     |           /               |\n");
									fprintf(output, "|     |          /                |\n");
									fprintf(output, "|     |         /                 |\n");
									fprintf(output, "|     |        /                  |\n");
									fprintf(output, "|     |       /                   |\n");
									fprintf(output, "|     |      /                    |\n");
									fprintf(output, "|     |     /                     |\n");
									fprintf(output, "|     |    /                      |\n");
									fprintf(output, "|     | -oo                       |\n");
									fprintf(output, "|=====|===========================|\n");
								}
								else {
									if (x<x3 && y>x3) {
										fprintf(output, "|=====|==================================================|\n");
										fprintf(output, "|  x  | -oo                 %.2f                     %.2f|\n", x, x3);
										fprintf(output, "|-----|--------------------------------------------------|\n");
										fprintf(output, "|f'(x)|            +                      -              |\n");
										fprintf(output, "|-----|--------------------------------------------------|\n");
										fprintf(output, "|     |                      %.2f                        |\n", Equa_3(a, b, c, d, x));
										fprintf(output, "|     |                     /    \\                       |\n");
										fprintf(output, "|     |                    /      \\                      |\n");
										fprintf(output, "|     |                   /        \\                     |\n");
										fprintf(output, "|     |                  /          \\                    |\n");
										fprintf(output, "|     |                 /            \\                   |\n");
										fprintf(output, "|     |                /              \\                  |\n");
										fprintf(output, "|     |               /                \\                 |\n");
										fprintf(output, "| f(x)|              /                  \\                |\n");
										fprintf(output, "|     |             /                    \\               |\n");
										fprintf(output, "|     |            /                      \\              |\n");
										fprintf(output, "|     |           /                        \\             |\n");
										fprintf(output, "|     |          /                          \\            |\n");
										fprintf(output, "|     |         /                            \\           |\n");
										fprintf(output, "|     |        /                              \\          |\n");
										fprintf(output, "|     |       /                                \\         |\n");
										fprintf(output, "|     |      /                                  \\        |\n");
										fprintf(output, "|     |     /                                    \\       |\n");
										fprintf(output, "|     |    /                                      \\      |\n");
										fprintf(output, "|     | -oo                                         0    |\n");
										fprintf(output, "|=====|==================================================|\n");
									}
									else {
										fprintf(output, "|=====|======================================================================|\n");
										fprintf(output, "|  x  | -oo                 %.2f                     %.2f                %.2f|\n", x, y, x3);
										fprintf(output, "|-----|----------------------------------------------------------------------|\n");
										fprintf(output, "|f'(x)|            +                      -                      +           |\n");
										fprintf(output, "|-----|----------------------------------------------------------------------|\n");
										fprintf(output, "|     |                      %.2f                                         %.2f|\n", Equa_3(a, b, c, d, x), Equa_3(a, b, c, d, x3));
										fprintf(output, "|     |                     /    \\                                        /  |\n");
										fprintf(output, "|     |                    /      \\                                      /   |\n");
										fprintf(output, "|     |                   /        \\                                    /    |\n");
										fprintf(output, "|     |                  /          \\                                  /     |\n");
										fprintf(output, "|     |                 /            \\                                /      |\n");
										fprintf(output, "|     |                /              \\                              /       |\n");
										fprintf(output, "|     |               /                \\                            /        |\n");
										fprintf(output, "| f(x)|              /                  \\                          /         |\n");
										fprintf(output, "|     |             /                    \\                        /          |\n");
										fprintf(output, "|     |            /                      \\                      /           |\n");
										fprintf(output, "|     |           /                        \\                    /            |\n");
										fprintf(output, "|     |          /                          \\                  /             |\n");
										fprintf(output, "|     |         /                            \\                /              |\n");
										fprintf(output, "|     |        /                              \\              /               |\n");
										fprintf(output, "|     |       /                                \\            /                |\n");
										fprintf(output, "|     |      /                                  \\          /                 |\n");
										fprintf(output, "|     |     /                                    \\        /                  |\n");
										fprintf(output, "|     |    /                                      \\      /                   |\n");
										fprintf(output, "|     | -oo                                        \\ %.2f                    |\n", Equa_3(a, b, c, d, y));
										fprintf(output, "|=====|======================================================================|\n");
									}

								}
							}
							else
							{
								if (x2 == x3)
								{
									if (x > x1 && y > x1)
									{
										fprintf(output, "|=====|===========================|\n");
										fprintf(output, "|  x  | -oo                  %.2f|\n", x1);
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|f'(x)|             +             |\n");
										fprintf(output, "|-----|---------------------------|\n");
										fprintf(output, "|     |                      0    |\n");
										fprintf(output, "|     |                     /     |\n");
										fprintf(output, "|     |                    /      |\n");
										fprintf(output, "|     |                   /       |\n");
										fprintf(output, "|     |                  /        |\n");
										fprintf(output, "|     |                 /         |\n");
										fprintf(output, "|     |                /          |\n");
										fprintf(output, "|     |               /           |\n");
										fprintf(output, "| f(x)|              /            |\n");
										fprintf(output, "|     |             /             |\n");
										fprintf(output, "|     |            /              |\n");
										fprintf(output, "|     |           /               |\n");
										fprintf(output, "|     |          /                |\n");
										fprintf(output, "|     |         /                 |\n");
										fprintf(output, "|     |        /                  |\n");
										fprintf(output, "|     |       /                   |\n");
										fprintf(output, "|     |      /                    |\n");
										fprintf(output, "|     |     /                     |\n");
										fprintf(output, "|     |    /                      |\n");
										fprintf(output, "|     | -oo                       |\n");
										fprintf(output, "|=====|===========================|\n");
									}
									else {
										if (x<x3 && y>x3) {
											fprintf(output, "|=====|==================================================|\n");
											fprintf(output, "|  x  | -oo                 %.2f                     %.2f|\n", x, x1);
											fprintf(output, "|-----|--------------------------------------------------|\n");
											fprintf(output, "|f'(x)|            +                      -              |\n");
											fprintf(output, "|-----|--------------------------------------------------|\n");
											fprintf(output, "|     |                      %.2f                        |\n", Equa_3(a, b, c, d, x));
											fprintf(output, "|     |                     /    \\                       |\n");
											fprintf(output, "|     |                    /      \\                      |\n");
											fprintf(output, "|     |                   /        \\                     |\n");
											fprintf(output, "|     |                  /          \\                    |\n");
											fprintf(output, "|     |                 /            \\                   |\n");
											fprintf(output, "|     |                /              \\                  |\n");
											fprintf(output, "|     |               /                \\                 |\n");
											fprintf(output, "| f(x)|              /                  \\                |\n");
											fprintf(output, "|     |             /                    \\               |\n");
											fprintf(output, "|     |            /                      \\              |\n");
											fprintf(output, "|     |           /                        \\             |\n");
											fprintf(output, "|     |          /                          \\            |\n");
											fprintf(output, "|     |         /                            \\           |\n");
											fprintf(output, "|     |        /                              \\          |\n");
											fprintf(output, "|     |       /                                \\         |\n");
											fprintf(output, "|     |      /                                  \\        |\n");
											fprintf(output, "|     |     /                                    \\       |\n");
											fprintf(output, "|     |    /                                      \\      |\n");
											fprintf(output, "|     | -oo                                         0    |\n");
											fprintf(output, "|=====|==================================================|\n");
										}
										else {
											fprintf(output, "|=====|======================================================================|\n");
											fprintf(output, "|  x  | -oo                 %.2f                     %.2f                %.2f|\n", x, y, x1);
											fprintf(output, "|-----|----------------------------------------------------------------------|\n");
											fprintf(output, "|f'(x)|            +                      -                      +           |\n");
											fprintf(output, "|-----|----------------------------------------------------------------------|\n");
											fprintf(output, "|     |                      %.2f                                         %.2f|\n", Equa_3(a, b, c, d, x), Equa_3(a, b, c, d, x1));
											fprintf(output, "|     |                     /    \\                                        /  |\n");
											fprintf(output, "|     |                    /      \\                                      /   |\n");
											fprintf(output, "|     |                   /        \\                                    /    |\n");
											fprintf(output, "|     |                  /          \\                                  /     |\n");
											fprintf(output, "|     |                 /            \\                                /      |\n");
											fprintf(output, "|     |                /              \\                              /       |\n");
											fprintf(output, "|     |               /                \\                            /        |\n");
											fprintf(output, "| f(x)|              /                  \\                          /         |\n");
											fprintf(output, "|     |             /                    \\                        /          |\n");
											fprintf(output, "|     |            /                      \\                      /           |\n");
											fprintf(output, "|     |           /                        \\                    /            |\n");
											fprintf(output, "|     |          /                          \\                  /             |\n");
											fprintf(output, "|     |         /                            \\                /              |\n");
											fprintf(output, "|     |        /                              \\              /               |\n");
											fprintf(output, "|     |       /                                \\            /                |\n");
											fprintf(output, "|     |      /                                  \\          /                 |\n");
											fprintf(output, "|     |     /                                    \\        /                  |\n");
											fprintf(output, "|     |    /                                      \\      /                   |\n");
											fprintf(output, "|     | -oo                                        \\ %.2f                    |\n", Equa_3(a, b, c, d, y));
											fprintf(output, "|=====|======================================================================|\n");
										}
									}
								}
								else
								{
									if (x > x3 && y > x3) {
										fprintf(output, "|=====|=========================================================|\n");
										fprintf(output, "|  x  | -oo                  %.2f     %.2f                  %.2f|\n", x1, x2, x3);
										fprintf(output, "|-----|---------------------------------------------------------|\n");
										fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
										fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
										fprintf(output, "|     |                      0||        ||                 %.2f |\n", Equa_3(a, b, c, d, x3));
										fprintf(output, "|     |                     / ||        ||                  /   |\n");
										fprintf(output, "|     |                    /  ||        ||                 /    |\n");
										fprintf(output, "|     |                   /   ||        ||                /     |\n");
										fprintf(output, "|     |                  /    ||        ||               /      |\n");
										fprintf(output, "|     |                 /     ||        ||              /       |\n");
										fprintf(output, "|     |                /      ||        ||             /        |\n");
										fprintf(output, "|     |               /       ||        ||            /         |\n");
										fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
										fprintf(output, "|     |             /         ||        ||          /           |\n");
										fprintf(output, "|     |            /          ||        ||         /            |\n");
										fprintf(output, "|     |           /           ||        ||        /             |\n");
										fprintf(output, "|     |          /            ||        ||       /              |\n");
										fprintf(output, "|     |         /             ||        ||      /               |\n");
										fprintf(output, "|     |        /              ||        ||     /                |\n");
										fprintf(output, "|     |       /               ||        ||    /                 |\n");
										fprintf(output, "|     |      /                ||        ||   /                  |\n");
										fprintf(output, "|     |     /                 ||        ||  /                   |\n");
										fprintf(output, "|     |    /                  ||        || /                    |\n");
										fprintf(output, "|     | -oo                   ||        ||0                     |\n");
										fprintf(output, "|=====|=========================================================|\n");
									}
									else {
										if (x<x3 && y >x3) {
											fprintf(output, "|=====|====================================================================================|\n");
											fprintf(output, "|  x  | -oo                  %.2f     %.2f                  %.2f                 %.2f      |\n", x1, x2, x, x3);
											fprintf(output, "|-----|------------------------------------------------------------------------------------|\n");
											fprintf(output, "|f'(x)|             +         ||        ||             +                                   |\n");
											fprintf(output, "|-----|-----------------------||--------||-------------------------------------------------|\n");
											fprintf(output, "|     |                      0||        ||                 %.2f                            |\n", Equa_3(a, b, c, d, x3));
											fprintf(output, "|     |                     / ||        ||                  /   \\                          |\n");
											fprintf(output, "|     |                    /  ||        ||                 /     \\                         |\n");
											fprintf(output, "|     |                   /   ||        ||                /       \\                        |\n");
											fprintf(output, "|     |                  /    ||        ||               /         \\                       |\n");
											fprintf(output, "|     |                 /     ||        ||              /           \\\                     |\n");
											fprintf(output, "|     |                /      ||        ||             /             \\                     |\n");
											fprintf(output, "|     |               /       ||        ||            /               \\                    |\n");
											fprintf(output, "| f(x)|              /        ||        ||           /                 \\                   |\n");
											fprintf(output, "|     |             /         ||        ||          /                   \\                  |\n");
											fprintf(output, "|     |            /          ||        ||         /                     \\                 |\n");
											fprintf(output, "|     |           /           ||        ||        /                       \\                |\n");
											fprintf(output, "|     |          /            ||        ||       /                         \\               |\n");
											fprintf(output, "|     |         /             ||        ||      /                           \\              |\n");
											fprintf(output, "|     |        /              ||        ||     /                             \\             |\n");
											fprintf(output, "|     |       /               ||        ||    /                               \\            |\n");
											fprintf(output, "|     |      /                ||        ||   /                                 \\           |\n");
											fprintf(output, "|     |     /                 ||        ||  /                                   \\          |\n");
											fprintf(output, "|     |    /                  ||        || /                                     \\         |\n");
											fprintf(output, "|     | -oo                   ||        ||0                                        %.2f    |\n", Equa_3(a, b, c, d, x3));
											fprintf(output, "|=====|====================================================================================|\n");
										}
										else {
											if (x < x3 && y < x3) {
												fprintf(output, "|=====|=====================================================================================================|\n");
												fprintf(output, "|  x  | -oo                   %.2f     %.2f                 %.2f                  %.2f                  %.2f|\n", x1, x2, x, y, x3);
												fprintf(output, "|-----|-----------------------------------------------------------------------------------------------------|\n");
												fprintf(output, "|f'(x)|             +         ||        ||         +                     -                     +            |\n");
												fprintf(output, "|-----|-----------------------||--------||------------------------------------------------------------------|\n");
												fprintf(output, "|     |                      0||        ||                  %.2f                                        %.2f|\n", Equa_3(a, b, c, d, x), Equa_3(a, b, c, d, x3));
												fprintf(output, "|     |                     / ||        ||                  /  \\                                      /     |\n");
												fprintf(output, "|     |                    /  ||        ||                 /    \\                                    /      |\n");
												fprintf(output, "|     |                   /   ||        ||                /      \\                                  /       |\n");
												fprintf(output, "|     |                  /    ||        ||               /        \\                                /        |\n");
												fprintf(output, "|     |                 /     ||        ||              /          \\                              /         |\n");
												fprintf(output, "|     |                /      ||        ||             /            \\                            /          |\n");
												fprintf(output, "|     |               /       ||        ||            /              \\                          /           |\n");
												fprintf(output, "| f(x)|              /        ||        ||           /                \\                        /            |\n");
												fprintf(output, "|     |             /         ||        ||          /                  \\                      /             |\n");
												fprintf(output, "|     |            /          ||        ||         /                    \\                    /              |\n");
												fprintf(output, "|     |           /           ||        ||        /                      \\                  /               |\n");
												fprintf(output, "|     |          /            ||        ||       /                        \\                /                |\n");
												fprintf(output, "|     |         /             ||        ||      /                          \\              /                 |\n");
												fprintf(output, "|     |        /              ||        ||     /                            \\            /                  |\n");
												fprintf(output, "|     |       /               ||        ||    /                              \\          /                   |\n");
												fprintf(output, "|     |      /                ||        ||   /                                \\        /                    |\n");
												fprintf(output, "|     |     /                 ||        ||  /                                  \\      /                     |\n");
												fprintf(output, "|     |    /                  ||        || /                                    \\    /                      |\n");
												fprintf(output, "|     | -oo                   ||        ||0                                       %.2f                      |\n", Equa_3(a, b, c, d, y));
												fprintf(output, "|=====|=====================================================================================================|\n");
											}
											else {
												if (x<x2 && y>x2) {
													fprintf(output, "|=====|======================================================================|\n");
													fprintf(output, "|  x  | -oo                 %.2f                     %.2f                %.2f|\n", x, y, x3);
													fprintf(output, "|-----|----------------------------------------------------------------------|\n");
													fprintf(output, "|f'(x)|            +                      -                      +           |\n");
													fprintf(output, "|-----|----------------------------------------------------------------------|\n");
													fprintf(output, "|     |                      %.2f                                         %.2f|\n", Equa_3(a, b, c, d, x), Equa_3(a, b, c, d, x3));
													fprintf(output, "|     |                     /    \\                                        /  |\n");
													fprintf(output, "|     |                    /      \\                                      /   |\n");
													fprintf(output, "|     |                   /        \\                                    /    |\n");
													fprintf(output, "|     |                  /          \\                                  /     |\n");
													fprintf(output, "|     |                 /            \\                                /      |\n");
													fprintf(output, "|     |                /              \\                              /       |\n");
													fprintf(output, "|     |               /                \\                            /        |\n");
													fprintf(output, "| f(x)|              /                  \\                          /         |\n");
													fprintf(output, "|     |             /                    \\                        /          |\n");
													fprintf(output, "|     |            /                      \\                      /           |\n");
													fprintf(output, "|     |           /                        \\                    /            |\n");
													fprintf(output, "|     |          /                          \\                  /             |\n");
													fprintf(output, "|     |         /                            \\                /              |\n");
													fprintf(output, "|     |        /                              \\              /               |\n");
													fprintf(output, "|     |       /                                \\            /                |\n");
													fprintf(output, "|     |      /                                  \\          /                 |\n");
													fprintf(output, "|     |     /                                    \\        /                  |\n");
													fprintf(output, "|     |    /                                      \\      /                   |\n");
													fprintf(output, "|     | -oo                                        \\ %.2f                    |\n", Equa_3(a, b, c, d, y));
													fprintf(output, "|=====|======================================================================|\n");
												}
												else {
													if (x < x2 && y < x2)
													{
														fprintf(output, "|=====|=========================================================|\n");
														fprintf(output, "|  x  | -oo                  %.2f     %.2f                  %.2f|\n", x1, x2, x3);
														fprintf(output, "|-----|---------------------------------------------------------|\n");
														fprintf(output, "|f'(x)|             +         ||        ||             +        |\n");
														fprintf(output, "|-----|-----------------------||--------||----------------------|\n");
														fprintf(output, "|     |                      0||        ||                 %.2f |\n", Equa_3(a, b, c, d, x3));
														fprintf(output, "|     |                     / ||        ||                  /   |\n");
														fprintf(output, "|     |                    /  ||        ||                 /    |\n");
														fprintf(output, "|     |                   /   ||        ||                /     |\n");
														fprintf(output, "|     |                  /    ||        ||               /      |\n");
														fprintf(output, "|     |                 /     ||        ||              /       |\n");
														fprintf(output, "|     |                /      ||        ||             /        |\n");
														fprintf(output, "|     |               /       ||        ||            /         |\n");
														fprintf(output, "| f(x)|              /        ||        ||           /          |\n");
														fprintf(output, "|     |             /         ||        ||          /           |\n");
														fprintf(output, "|     |            /          ||        ||         /            |\n");
														fprintf(output, "|     |           /           ||        ||        /             |\n");
														fprintf(output, "|     |          /            ||        ||       /              |\n");
														fprintf(output, "|     |         /             ||        ||      /               |\n");
														fprintf(output, "|     |        /              ||        ||     /                |\n");
														fprintf(output, "|     |       /               ||        ||    /                 |\n");
														fprintf(output, "|     |      /                ||        ||   /                  |\n");
														fprintf(output, "|     |     /                 ||        ||  /                   |\n");
														fprintf(output, "|     |    /                  ||        || /                    |\n");
														fprintf(output, "|     | -oo                   ||        ||0                     |\n");
														fprintf(output, "|=====|=========================================================|\n");
													}
													else
													{
														if (x<x1 && y>x1)
														{
															fprintf(output, "|=====|==================================================================================|\n");
															fprintf(output, "|  x  | -oo                  %.2f                    %.2f       %.2f                 %.2f|\n", x, x1, x2, x3);
															fprintf(output, "|-----|----------------------------------------------------------------------------------|\n");
															fprintf(output, "|f'(x)|            +                      -            ||        ||             +        |\n");
															fprintf(output, "|-----|------------------------------------------------||--------||----------------------|\n");
															fprintf(output, "|     |                      %.2f                      ||        ||                   %.2f|\n", Equa_3(a, b, c, d, x), Equa_3(a, b, c, d, x3));
															fprintf(output, "|     |                     /    \\                     ||        ||                  /   |\n");
															fprintf(output, "|     |                    /      \\                    ||        ||                 /    |\n");
															fprintf(output, "|     |                   /        \\                   ||        ||                /     |\n");
															fprintf(output, "|     |                  /          \\                  ||        ||               /      |\n");
															fprintf(output, "|     |                 /            \\                 ||        ||              /       |\n");
															fprintf(output, "|     |                /              \\                ||        ||             /        |\n");
															fprintf(output, "|     |               /                \\               ||        ||            /         |\n");
															fprintf(output, "| f(x)|              /                  \\              ||        ||           /          |\n");
															fprintf(output, "|     |             /                    \\             ||        ||          /           |\n");
															fprintf(output, "|     |            /                      \\            ||        ||         /            |\n");
															fprintf(output, "|     |           /                        \\           ||        ||        /             |\n");
															fprintf(output, "|     |          /                          \\          ||        ||       /              |\n");
															fprintf(output, "|     |         /                            \\         ||        ||      /               |\n");
															fprintf(output, "|     |        /                              \\        ||        ||     /                |\n");
															fprintf(output, "|     |       /                                \\       ||        ||    /                 |\n");
															fprintf(output, "|     |      /                                  \\      ||        ||   /                  |\n");
															fprintf(output, "|     |     /                                    \\     ||        ||  /                   |\n");
															fprintf(output, "|     |    /                                      \\    ||        || /                    |\n");
															fprintf(output, "|     | -oo                                         0  ||        ||0                     |\n");
															fprintf(output, "|=====|==================================================================================|\n");
														}
														else
														{
															fprintf(output, "|=====|=========================================================================================================|\n");
															fprintf(output, "|  x  | -oo                  %.2f                    %.2f                    %.2f     %.2f                  %.2f|\n", x, y, x1, x2, x3);
															fprintf(output, "|-----|---------------------------------------------------------------------------------------------------------|\n");
															fprintf(output, "|f'(x)|            +                      -                      +            ||        ||             +        |\n");
															fprintf(output, "|-----|-----------------------------------------------------------------------||--------||----------------------|\n");
															fprintf(output, "|     |                      %.2f                                           0 ||        ||                  %.2f|\n", Equa_3(a, b, c, d, x), Equa_3(a, b, c, d, x3));
															fprintf(output, "|     |                     /    \\                                        /   ||        ||                  /   |\n");
															fprintf(output, "|     |                    /      \\                                      /    ||        ||                 /    |\n");
															fprintf(output, "|     |                   /        \\                                    /     ||        ||                /     |\n");
															fprintf(output, "|     |                  /          \\                                  /      ||        ||               /      |\n");
															fprintf(output, "|     |                 /            \\                                /       ||        ||              /       |\n");
															fprintf(output, "|     |                /              \\                              /        ||        ||             /        |\n");
															fprintf(output, "|     |               /                \\                            /         ||        ||            /         |\n");
															fprintf(output, "| f(x)|              /                  \\                          /          ||        ||           /          |\n");
															fprintf(output, "|     |             /                    \\                        /           ||        ||          /           |\n");
															fprintf(output, "|     |            /                      \\                      /            ||        ||         /            |\n");
															fprintf(output, "|     |           /                        \\                    /             ||        ||        /             |\n");
															fprintf(output, "|     |          /                          \\                  /              ||        ||       /              |\n");
															fprintf(output, "|     |         /                            \\                /               ||        ||      /               |\n");
															fprintf(output, "|     |        /                              \\              /                ||        ||     /                |\n");
															fprintf(output, "|     |       /                                \\            /                 ||        ||    /                 |\n");
															fprintf(output, "|     |      /                                  \\          /                  ||        ||   /                  |\n");
															fprintf(output, "|     |     /                                    \\        /                   ||        ||  /                   |\n");
															fprintf(output, "|     |    /                                      \\      /                    ||        || /                    |\n");
															fprintf(output, "|     | -oo                                          %.2f                     ||        ||0                     |\n", Equa_3(a, b, c, d, y));
															fprintf(output, "|=====|=========================================================================================================|\n");
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void BBT21(float a, float b, float c)
{
	if (a == 0)
		BBT19(b, 0, c);
	else
	{
		float x1, x2, x3, x4, x5, x6, x7;
		short k, l;
		GiaiPT_Bac4(a, 0, b, 0, c, x1, x2, x3, x4, k);
		GiaiPT_Bac3(4 * a, 0, 2 * b, 0, x5, x6, x7, l);
		switch (k) {
		case 0:
			if (l == 1)//tu co nghiem bang 0
			{
				if (a > 0)
				{
					fprintf(output, "\t|=====|=======================================|\n");
					fprintf(output, "\t|  x  |-oo             %.2f             +oo   |\n", x5);
					fprintf(output, "\t|-----|---------------------------------------|\n");
					fprintf(output, "\t|f'(x)|        -        0         +           |\n");
					fprintf(output, "\t|-----|---------------------------------------|\n");
					fprintf(output, "\t|     | +oo                             +oo   |\n");
					fprintf(output, "\t| f(x)|    \\                         /        |\n");
					fprintf(output, "\t|     |     \\                       /         |\n");
					fprintf(output, "\t|     |      \\                     /          |\n");
					fprintf(output, "\t|     |       \\                   /           |\n");
					fprintf(output, "\t|     |        \\                 /            |\n");
					fprintf(output, "\t|     |         \\               /             |\n");
					fprintf(output, "\t|     |          \\             /              |\n");
					fprintf(output, "\t|     |           \\           /               |\n");
					fprintf(output, "\t|     |            \\         /                |\n");
					fprintf(output, "\t|     |             \\       /                 |\n");
					fprintf(output, "\t|     |              \\     /                  |\n");
					fprintf(output, "\t|     |                %.2f                   |\n", Equa_4(a, b, c, x5));
					fprintf(output, "\t|=====|=======================================|\n");
				}
				else
					fprintf(output, "Ham so khong xac dinh\n");
			}
			if (l == 3)
			{
				if (a > 0)
				{
					if (x5 == x6 && x6 == x7)
					{
						fprintf(output, "\t|=====|=======================================|\n");
						fprintf(output, "\t|  x  |-oo             %.2f             +oo   |\n", x5);
						fprintf(output, "\t|-----|---------------------------------------|\n");
						fprintf(output, "\t|f'(x)|        -        0         +           |\n");
						fprintf(output, "\t|-----|---------------------------------------|\n");
						fprintf(output, "\t|     | +oo                             +oo   |\n");
						fprintf(output, "\t| f(x)|    \\                         /        |\n");
						fprintf(output, "\t|     |     \\                       /         |\n");
						fprintf(output, "\t|     |      \\                     /          |\n");
						fprintf(output, "\t|     |       \\                   /           |\n");
						fprintf(output, "\t|     |        \\                 /            |\n");
						fprintf(output, "\t|     |         \\               /             |\n");
						fprintf(output, "\t|     |          \\             /              |\n");
						fprintf(output, "\t|     |           \\           /               |\n");
						fprintf(output, "\t|     |            \\         /                |\n");
						fprintf(output, "\t|     |             \\       /                 |\n");
						fprintf(output, "\t|     |              \\     /                  |\n");
						fprintf(output, "\t|     |                %.2f                   |\n", Equa_4(a, b, c, x5));
						fprintf(output, "\t|=====|=======================================|\n");
					}
					else
					{
						if (x5 == x6)
						{
							fprintf(output, "\t|=====|===============================================|\n");
							fprintf(output, "\t|  x  |-oo          %.2f         %.2f            +oo  |\n", x5, x7);
							fprintf(output, "\t|-----|-----------------------------------------------|\n");
							fprintf(output, "\t|f'(x)|       -      0     -      0        +          |\n");
							fprintf(output, "\t|-----|---------------------------------------------- |\n");
							fprintf(output, "\t|     | +oo                                      +oo  |\n");
							fprintf(output, "\t| f(x)|    \\                                   /      |\n");
							fprintf(output, "\t|     |      \\                                /       |\n");
							fprintf(output, "\t|     |        \\                             /        |\n");
							fprintf(output, "\t|     |          \\                          /         |\n");
							fprintf(output, "\t|     |            \\                       /          |\n");
							fprintf(output, "\t|     |              \\                    /           |\n");
							fprintf(output, "\t|     |                \\                 /            |\n");
							fprintf(output, "\t|     |                  \\              /             |\n");
							fprintf(output, "\t|     |                    \\           /              |\n");
							fprintf(output, "\t|     |                      \\        /               |\n");
							fprintf(output, "\t|     |                        \\     /                |\n");
							fprintf(output, "\t|     |                          %.2f                 |\n", Equa_4(a, b, c, x7));
							fprintf(output, "\t|=====|===============================================|\n");

						}
						else
						{
							if (x6 == x7)
							{
								fprintf(output, "\t|=====|=======================================|\n");
								fprintf(output, "\t|  x  |-oo             %.2f             +oo   |\n", x5);
								fprintf(output, "\t|-----|---------------------------------------|\n");
								fprintf(output, "\t|f'(x)|        -        0         +           |\n");
								fprintf(output, "\t|-----|---------------------------------------|\n");
								fprintf(output, "\t|     | +oo                             +oo   |\n");
								fprintf(output, "\t| f(x)|    \\                         /        |\n");
								fprintf(output, "\t|     |     \\                       /         |\n");
								fprintf(output, "\t|     |      \\                     /          |\n");
								fprintf(output, "\t|     |       \\                   /           |\n");
								fprintf(output, "\t|     |        \\                 /            |\n");
								fprintf(output, "\t|     |         \\               /             |\n");
								fprintf(output, "\t|     |          \\             /              |\n");
								fprintf(output, "\t|     |           \\           /               |\n");
								fprintf(output, "\t|     |            \\         /                |\n");
								fprintf(output, "\t|     |             \\       /                 |\n");
								fprintf(output, "\t|     |              \\     /                  |\n");
								fprintf(output, "\t|     |                %.2f                   |\n", Equa_4(a, b, c, x5));
								fprintf(output, "\t|     |                %.2f                   |\n", Equa_4(a, b, c, x5));
								fprintf(output, "\t|=====|=======================================|\n");
							}
							else
							{
								fprintf(output, "\t|=====|===================================================================|\n");
								fprintf(output, "\t|  x  |-oo          %.2f             %.2f            %.2f            +oo  |\n", x5, x6, x7);
								fprintf(output, "\t|-----|-------------------------------------------------------------------|\n");
								fprintf(output, "\t|f'(x)|       -      0        +        0        -     0       +           |\n");
								fprintf(output, "\t|-----|-------------------------------------------------------------------|\n");
								fprintf(output, "\t|     | +oo                           %.2f                           +oo  |\n", Equa_4(a, b, c, x6));
								fprintf(output, "\t| f(x)|    \\                        /     \\                        /      |\n");
								fprintf(output, "\t|     |     \\                      /       \\                      /       |\n");
								fprintf(output, "\t|     |      \\                    /         \\                    /        |\n");
								fprintf(output, "\t|     |       \\                  /           \\                  /         |\n");
								fprintf(output, "\t|     |        \\                /             \\                /          |\n");
								fprintf(output, "\t|     |         \\              /               \\              /           |\n");
								fprintf(output, "\t|     |          \\            /                 \\            /            |\n");
								fprintf(output, "\t|     |           \\          /                   \\          /             |\n");
								fprintf(output, "\t|     |            \\        /                     \\        /              |\n");
								fprintf(output, "\t|     |             \\      /                       \\      /               |\n");
								fprintf(output, "\t|     |              \\    /                         \\    /                |\n");
								fprintf(output, "\t|     |               %.2f                           %.2f                 |\n", Equa_4(a, b, c, x5), Equa_4(a, b, c, x7));
								fprintf(output, "\t|=====|===================================================================|\n");
							}
						}
					}
				}
				else
					fprintf(output, "Ham so khong xac dinh\n");
			}
			break;
		case 2:
			if (l == 1 || (l == 3 && x5 == x7))
			{
				if (a > 0)
				{
					if (x1 != x2)
					{
						fprintf(output, "\t|=====|=============================================|\n");
						fprintf(output, "\t|  x  |-oo             %.2f    %.2f         +oo     |\n", x1, x2);
						fprintf(output, "\t|-----|---------------------------------------------|\n");
						fprintf(output, "\t|f'(x)|        -                       +            |\n");
						fprintf(output, "\t|-----|---------------------------------------------|\n");
						fprintf(output, "\t|     | +oo                                   +oo   |\n");
						fprintf(output, "\t| f(x)|    \\                                /       |\n");
						fprintf(output, "\t|     |     \\                              /        |\n");
						fprintf(output, "\t|     |      \\                            /         |\n");
						fprintf(output, "\t|     |       \\                          /          |\n");
						fprintf(output, "\t|     |        \\                        /           |\n");
						fprintf(output, "\t|     |         \\                      /            |\n");
						fprintf(output, "\t|     |          \\                    /             |\n");
						fprintf(output, "\t|     |           \\                  /              |\n");
						fprintf(output, "\t|     |            \\                /               |\n");
						fprintf(output, "\t|     |             \\              /                |\n");
						fprintf(output, "\t|     |              \\            /                 |\n");
						fprintf(output, "\t|     |                 0        0                  |\n");
						fprintf(output, "\t|=====|=============================================|\n");
					}
					if (x1 == x2)
					{
						fprintf(output, "\t|=====|=======================================|\n");
						fprintf(output, "\t|  x  |-oo              0               +oo   |\n");
						fprintf(output, "\t|-----|---------------------------------------|\n");
						fprintf(output, "\t|f'(x)|        -        0         +           |\n");
						fprintf(output, "\t|-----|---------------------------------------|\n");
						fprintf(output, "\t|     | +oo                             +oo   |\n");
						fprintf(output, "\t| f(x)|    \\                         /        |\n");
						fprintf(output, "\t|     |     \\                       /         |\n");
						fprintf(output, "\t|     |      \\                     /          |\n");
						fprintf(output, "\t|     |       \\                   /           |\n");
						fprintf(output, "\t|     |        \\                 /            |\n");
						fprintf(output, "\t|     |         \\               /             |\n");
						fprintf(output, "\t|     |          \\             /              |\n");
						fprintf(output, "\t|     |           \\           /               |\n");
						fprintf(output, "\t|     |            \\         /                |\n");
						fprintf(output, "\t|     |             \\       /                 |\n");
						fprintf(output, "\t|     |              \\     /                  |\n");
						fprintf(output, "\t|     |                  0                    |\n");
						fprintf(output, "\t|=====|=======================================|\n");
					}
				}
				else
				{
					if (x1 != x2)
					{
						fprintf(output, "\t|=====|====================================|\n");
						fprintf(output, "\t|  x  |%.2f             0             %.2f|\n", x1, x2);
						fprintf(output, "\t|-----|-----------------------------------|\n");
						fprintf(output, "\t|f'(x)| 0        +             -          |\n");
						fprintf(output, "\t|-----|-----------------------------------|\n");
						fprintf(output, "\t|     |                 %.2f              |\n");
						fprintf(output, "\t| f(x)|              /      \\             |\n");
						fprintf(output, "\t|     |             /        \\            |\n");
						fprintf(output, "\t|     |            /          \\           |\n");
						fprintf(output, "\t|     |           /            \\          |\n");
						fprintf(output, "\t|     |          /              \\         |\n");
						fprintf(output, "\t|     |         /                \\        |\n");
						fprintf(output, "\t|     |        /                  \\       |\n");
						fprintf(output, "\t|     |       /                    \\      |\n");
						fprintf(output, "\t|     |      /                      \\     |\n");
						fprintf(output, "\t|     |     /                        \\    |\n");
						fprintf(output, "\t|     |    /                          \\   |\n");
						fprintf(output, "\t|     |  0                              0 |\n");
						fprintf(output, "\t|=====|===================================|\n");

					}
					if (x1 == x2)
					{
						fprintf(output, "Ham so bang 0 voi x = 0\n");
					}
				}
			}
			if (l == 3 && x5 != x7)
			{
				if (a > 0)
				{
					if (x1 != x2)
					{
						if (x7 <= x2)
						{
							fprintf(output, "\t|=====|=============================================|\n");
							fprintf(output, "\t|  x  |-oo             %.2f    %.2f         +oo     |\n", x1, x2);
							fprintf(output, "\t|-----|---------------------------------------------|\n");
							fprintf(output, "\t|f'(x)|        -                       +            |\n");
							fprintf(output, "\t|-----|---------------------------------------------|\n");
							fprintf(output, "\t|     | +oo                                   +oo   |\n");
							fprintf(output, "\t| f(x)|    \\                                /       |\n");
							fprintf(output, "\t|     |     \\                              /        |\n");
							fprintf(output, "\t|     |      \\                            /         |\n");
							fprintf(output, "\t|     |       \\                          /          |\n");
							fprintf(output, "\t|     |        \\                        /           |\n");
							fprintf(output, "\t|     |         \\                      /            |\n");
							fprintf(output, "\t|     |          \\                    /             |\n");
							fprintf(output, "\t|     |           \\                  /              |\n");
							fprintf(output, "\t|     |            \\                /               |\n");
							fprintf(output, "\t|     |             \\              /                |\n");
							fprintf(output, "\t|     |              \\            /                 |\n");
							fprintf(output, "\t|     |                 0        0                  |\n");
							fprintf(output, "\t|=====|=============================================|\n");
						}
						if (x7 > x2)
						{
							fprintf(output, "\t|=====|==========================================================================|\n");
							fprintf(output, "\t|  x  |-oo          %.2f             %.2f     %.2f          %.2f            +oo  |\n", x5, x1, x2, x7);
							fprintf(output, "\t|-----|--------------------------------------------------------------------------|\n");
							fprintf(output, "\t|f'(x)|       -      0        +                       -       0       +          |\n");
							fprintf(output, "\t|-----|--------------------------------------------------------------------------|\n");
							fprintf(output, "\t|     | +oo                            0       0                            +oo  |\n");
							fprintf(output, "\t| f(x)|    \\                        /            \\                        /      |\n");
							fprintf(output, "\t|     |     \\                      /              \\                      /       |\n");
							fprintf(output, "\t|     |      \\                    /                \\                    /        |\n");
							fprintf(output, "\t|     |       \\                  /                  \\                  /         |\n");
							fprintf(output, "\t|     |        \\                /                    \\                /          |\n");
							fprintf(output, "\t|     |         \\              /                      \\              /           |\n");
							fprintf(output, "\t|     |          \\            /                        \\            /            |\n");
							fprintf(output, "\t|     |           \\          /                          \\          /             |\n");
							fprintf(output, "\t|     |            \\        /                            \\        /              |\n");
							fprintf(output, "\t|     |             \\      /                              \\      /               |\n");
							fprintf(output, "\t|     |              \\    /                                \\    /                |\n");
							fprintf(output, "\t|     |               %.2f                                  %.2f                 |\n", Equa_4(a, b, c, x5), Equa_4(a, b, c, x7));
							fprintf(output, "\t|=====|==========================================================================|\n");
						}
					}
					if (x1 == x2)
					{
						fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0) v (%.2f,+oo)\n", x5, x7);
						fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (0,%.2f)\n", x5, x7);
						fprintf(output, "Dao ham cua ham so bang 0 voi moi x thuoc {%.2f,%.2f}\n", x5, x7);
					}
				}
				if (a < 0)
				{
					if (x1 != x2)
					{
						if (x7 >= x2)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (0,%.2f)\n", x2);
							fprintf(output, "Dao ham cua ham so luon am voi  moi x thuoc (%.2f,0)\n", x1);
							fprintf(output, "Dao ham cua ham so bang 0 voi x = 0\n");
						}
						if (x7 < x2)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (0,%.2f)\n", x1, x5, x7);
							fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (%.2f,0) v (%.2f,%.2f)\n", x5, x7, x2);
							fprintf(output, "Dao ham cua ham so bang 0 voi x thuoc {%.2f,0,%.2f}\n", x5, x7);
						}
					}
					if (x1 == x2)
					{
						fprintf(output, "Ham so khong co dao ham\n");
					}
				}
			}
			break;
		case 4:
			if (l == 1 || (l == 3 && x5 == x7))
			{
				if (a > 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (0,+oo)\n");
						fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,0)\n");
					}
					else
					{
						if (x2 == x3)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,+oo)\n", x4);
							fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f)\n", x1);
						}
						if (x2 != x3)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (0,%.2f) v (%.2f,+oo)\n", x3, x4);
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (-oo,%.2f) v (%.2f,0)\n", x1, x2);
							fprintf(output, "Dao ham cua ham so bang 0 voi x = 0\n");
						}
					}
				}
				if (a < 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Ham so khong co dao ham\n");
					}
					else
					{
						if (x2 == x3)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0)\n", x1);
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (0,%.2f)\n", x4);
						}
						if (x1 != x3)
						{
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f)\n", x1, x2);
							fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f)\n", x3, x4);
						}
					}
				}
			}
			if (l == 3 && x5 != x7)
			{
				if (a > 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Dao ham cua ham so luon duong voi x thuoc (%.2f,0) v (%.2f,+oo)\n", x5, x7);
						fprintf(output, "Dao ham cua ham so luon am voi x thuoc (-oo,%.2f) v (0,%.2f)\n", x5, x7);
						fprintf(output, "Dao ham cua ham so bang 0 voi x thuoc {%.2f,%.2f}\n", x5, x7);
					}
					else
					{
						if (x2 == x3)
						{
							if (x7 <= x4)
							{
								fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,+oo)\n", x4);
								fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f)\n", x1);
							}
							if (x7 > x4)
							{
								fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (%.2f,+oo)\n", x5, x1, x7);
								fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (%.2f,%.2f)\n", x5, x4, x7);
								fprintf(output, "Dao ham cua ham so bang 0 voi x thuoc {%.2f,%.2f}\n", x5, x7);
							}
						}
						else
						{
							if (x3 != x4)
							{
								if (x7 < x3)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0) v (%.2f,%.2f) v (%.2f,+oo)\n", x5, x7, x3, x4);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (%.2f,%.2f) v (0,%.2f)\n", x1, x2, x5, x7);
									fprintf(output, "Dao ham cua ham so bang 0 khi x thuoc {%.2f,0,%.2f}\n", x5, x7);
								}
								if (x7 >= x3 && x7 <= x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0) v (%.2f,+oo)\n", x2, x4);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (0,%.2f)\n", x1, x3);
									fprintf(output, "Dao ham cua ham so bang 0 voi x = 0\n");
								}
								if (x7 > x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (%.2f,0) v (%.2f,+oo)\n", x5, x1, x2, x7);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (0,%.2f) v (%.2f,%.2f)\n", x5, x3, x4, x7);
									fprintf(output, "Dao ham cua ham so bang 0 voi moi x thuoc {%.2f,0,%.2f}\n", x5, x7);
								}
							}
							if (x3 == x4)
							{
								if (x7 < x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0) v (%.2f,%.2f) v (%.2f,+oo)\n", x5, x7, x4, x4);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (%.2f,%.2f) v (0,%.2f)\n", x1, x1, x5, x7);
									fprintf(output, "Dao ham cua ham so bang 0 voi moi x thuoc {%.2f,0,%.2f}\n", x5, x7);
								}
								if (x7 == x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,0) v (%.2f,+oo)\n", x5, x7);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (0,%.2f)\n", x5, x7);
									fprintf(output, "Dao ham cua ham so bang 0 voi x = 0\n");
								}
								if (x7 > x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (%.2f,0) v (%.2f,+oo)\n", x5, x1, x1, x7);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (-oo,%.2f) v (0,%.2f) v (%.2f,%.2f)\n", x5, x4, x4, x7);
									fprintf(output, "Dao ham cua ham so bang 0 voi moi x thuoc {%.2f,0,%.2f}\n", x5, x7);
								}
							}
						}
					}
				}
				if (a < 0)
				{
					if (x1 == x4)
					{
						fprintf(output, "Ham so khong co dao ham\n");
					}
					else
					{
						if (x2 == x3)
						{
							if (x7 >= x4)
							{
								fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (0,%.2f)\n", x4);
								fprintf(output, "Dao ham cua ham so luon am voi  moi x thuoc (%.2f,0)\n", x1);
							}
							if (x7 < x4)
							{
								fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (0,%.2f)\n", x1, x5, x7);
								fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (%.2f,0) v (%.2f,%.2f)\n", x5, x7, x4);
								fprintf(output, "Dao ham cua ham so bang 0 voi x thuoc {%.2f,%.2f}\n", x5, x7);
							}
						}
						else
						{
							if (x3 != x4)
							{
								fprintf(output, "Tap xac dinh cua Ham so la [%.2f,%.2f]v[%.2f,%.2f]\n", x1, x2, x3, x4);
								if (x7 <= x3)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f)\n", x1, x2);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (%.2f,%.2f)\n", x3, x4);
								}
								if (x7 > x3 && x7 < x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f) v (%.2f,%.2f)\n", x1, x5, x3, x7);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (%.2f,%.2f) v (%.2f,%.2f)\n", x5, x2, x7, x4);
									fprintf(output, "Dao ham cua ham so bang 0 khi x thuoc {%.2f,%.2f}\n", x5, x7);
								}
								if (x7 >= x4)
								{
									fprintf(output, "Dao ham cua ham so luon duong voi moi x thuoc (%.2f,%.2f)\n", x3, x4);
									fprintf(output, "Dao ham cua ham so luon am voi moi x thuoc (%.2f,%.2f)\n", x1, x2);
								}
							}
							if (x3 == x4)
								fprintf(output, "Ham so khong co dao ham\n");
						}
					}
				}
			}
			break;
		default:
			break;
		}
	}
}

void BBT22(float a, float b, float c, float d)
{
	if (a == 0)
	{
		if (b == 0)
			fprintf(output, "Ham so bang 0 voi moi x thuoc TXD\n");
		else
		{
			if (b < 0)
			{
				c = -c;
				d = -d;
			}
			if (c > 0) {
				if (-d - b * c < 0)
				{
					fprintf(output, "\t|=====|=======================|\n");
					fprintf(output, "\t|  x  |%.2f             +oo   |\n", -d / c);
					fprintf(output, "\t|-----|-----------------------|\n");
					fprintf(output, "\t|f'(x)| 0        -            |\n");
					fprintf(output, "\t|-----|-----------------------|\n");
					fprintf(output, "\t|     | +oo                   |\n");
					fprintf(output, "\t| f(x)|     \\                 |\n");
					fprintf(output, "\t|     |      \\                |\n");
					fprintf(output, "\t|     |       \\               |\n");
					fprintf(output, "\t|     |        \\              |\n");
					fprintf(output, "\t|     |         \\             |\n");
					fprintf(output, "\t|     |          \\            |\n");
					fprintf(output, "\t|     |           \\           |\n");
					fprintf(output, "\t|     |            \\          |\n");
					fprintf(output, "\t|     |             \\         |\n");
					fprintf(output, "\t|     |              \\        |\n");
					fprintf(output, "\t|     |               \\       |\n");
					fprintf(output, "\t|     |                 0     |\n");
					fprintf(output, "\t|=====|=======================|\n");
				}
				else
				{

					fprintf(output, "\t|=====|=======================|\n");
					fprintf(output, "\t|  x  |%.2f            +oo    |\n", -d / c);
					fprintf(output, "\t|-----|-----------------------|\n");
					fprintf(output, "\t|f'(x)| 0        +            |\n");
					fprintf(output, "\t|-----|-----------------------|\n");
					fprintf(output, "\t|     |                +oo    |\n");
					fprintf(output, "\t| f(x)|              /        |\n");
					fprintf(output, "\t|     |             /         |\n");
					fprintf(output, "\t|     |            /          |\n");
					fprintf(output, "\t|     |           /           |\n");
					fprintf(output, "\t|     |          /            |\n");
					fprintf(output, "\t|     |         /             |\n");
					fprintf(output, "\t|     |        /              |\n");
					fprintf(output, "\t|     |       /               |\n");
					fprintf(output, "\t|     |      /                |\n");
					fprintf(output, "\t|     |     /                 |\n");
					fprintf(output, "\t|     |    /                  |\n");
					fprintf(output, "\t|     |  0                    |\n");
					fprintf(output, "\t|=====|=======================|\n");
				}
			}
			else
			{
				if (c != 0) {
					if (-d - b * c < 0)
					{
						fprintf(output, "\t|=====|=======================|\n");
						fprintf(output, "\t|  x  |-oo             %.2f   |\n", -d / c);
						fprintf(output, "\t|-----|-----------------------|\n");
						fprintf(output, "\t|f'(x)| 0        -            |\n");
						fprintf(output, "\t|-----|-----------------------|\n");
						fprintf(output, "\t|     | +oo                   |\n");
						fprintf(output, "\t| f(x)|     \\                 |\n");
						fprintf(output, "\t|     |      \\                |\n");
						fprintf(output, "\t|     |       \\               |\n");
						fprintf(output, "\t|     |        \\              |\n");
						fprintf(output, "\t|     |         \\             |\n");
						fprintf(output, "\t|     |          \\            |\n");
						fprintf(output, "\t|     |           \\           |\n");
						fprintf(output, "\t|     |            \\          |\n");
						fprintf(output, "\t|     |             \\         |\n");
						fprintf(output, "\t|     |              \\        |\n");
						fprintf(output, "\t|     |               \\       |\n");
						fprintf(output, "\t|     |                 0     |\n");
						fprintf(output, "\t|=====|=======================|\n");
					}
					else
					{
						fprintf(output, "\t|=====|=======================|\n");
						fprintf(output, "\t|  x  |-oo            %.2f    |\n", -d / c);
						fprintf(output, "\t|-----|-----------------------|\n");
						fprintf(output, "\t|f'(x)| 0        +            |\n");
						fprintf(output, "\t|-----|-----------------------|\n");
						fprintf(output, "\t|     |                +oo    |\n");
						fprintf(output, "\t| f(x)|              /        |\n");
						fprintf(output, "\t|     |             /         |\n");
						fprintf(output, "\t|     |            /          |\n");
						fprintf(output, "\t|     |           /           |\n");
						fprintf(output, "\t|     |          /            |\n");
						fprintf(output, "\t|     |         /             |\n");
						fprintf(output, "\t|     |        /              |\n");
						fprintf(output, "\t|     |       /               |\n");
						fprintf(output, "\t|     |      /                |\n");
						fprintf(output, "\t|     |     /                 |\n");
						fprintf(output, "\t|     |    /                  |\n");
						fprintf(output, "\t|     |  0                    |\n");
						fprintf(output, "\t|=====|=======================|\n");
					}
				}
				else
				{
					if (d >= 0)
						fprintf(output, "Ham so luon bang %.2f voi moi x thuoc R\n", abs(b) / d);
					else
						fprintf(output, "Ham so khong xac dinh\n");
				}
			}
		}
	}
	else
	{
		if (c == 0)
		{
			if (d == 0)
				fprintf(output, "Ham so khong xac dinh\n");
			else
				BBT18(a / d, b / d);
		}
		else
		{
			float x1 = -b / a;
			float x2 = -d / c;
			if (x1 > x2)
				swap(x1, x2);
			a = d * a;
			if (x1 == x2)
			{
				if (a * c > 0)
					fprintf(output, "Ham so luon bang %.2f voi moi x thuoc R\\{%.2f}", a / c, x1);
				if (a * c < 0)
					fprintf(output, "Ham so khong xac dinh\n");
			}
			else
			{
				if (a > 0)
				{
					if (a * d - b * c < 0)
					{
						fprintf(output, "\t|=====|============================================|\n");
						fprintf(output, "\t|  x  |-oo             %.2f      %.2f           +oo|\n", x1, x2);
						fprintf(output, "\t|-----|--------------------------------------------|\n");
						fprintf(output, "\t|f'(x)|          -                        -        |\n");
						fprintf(output, "\t|-----|--------------------------------------------|\n");
						fprintf(output, "\t|     | +oo                      +oo               |\n");
						fprintf(output, "\t| f(x)|     \\                       \\              |\n");
						fprintf(output, "\t|     |      \\                       \\             |\n");
						fprintf(output, "\t|     |       \\                       \\            |\n");
						fprintf(output, "\t|     |        \\                       \\           |\n");
						fprintf(output, "\t|     |         \\                       \\          |\n");
						fprintf(output, "\t|     |          \\                       \\         |\n");
						fprintf(output, "\t|     |           \\                       \\        |\n");
						fprintf(output, "\t|     |            \\                       \\       |\n");
						fprintf(output, "\t|     |             \\                       \\      |\n");
						fprintf(output, "\t|     |              \\                       \\     |\n");
						fprintf(output, "\t|     |               \\                       \\    |\n");
						fprintf(output, "\t|     |                 0                      %.2f|\n", sqrt(a / c));
						fprintf(output, "\t|=====|============================================|\n");
					}
					else
					{
						fprintf(output, "\t|=====|========================================|\n");
						fprintf(output, "\t|  x  |-oo            %.2f    %.2f         +oo |\n", x1, x2);
						fprintf(output, "\t|-----|----------------------------------------|\n");
						fprintf(output, "\t|f'(x)|          +                    +        |\n");
						fprintf(output, "\t|-----|----------------------------------------|\n");
						fprintf(output, "\t|     |                +oo                 +oo |\n");
						fprintf(output, "\t| f(x)|              /                    /    |\n");
						fprintf(output, "\t|     |             /                    /     |\n");
						fprintf(output, "\t|     |            /                    /      |\n");
						fprintf(output, "\t|     |           /                    /       |\n");
						fprintf(output, "\t|     |          /                    /        |\n");
						fprintf(output, "\t|     |         /                    /         |\n");
						fprintf(output, "\t|     |        /                    /          |\n");
						fprintf(output, "\t|     |       /                    /           |\n");
						fprintf(output, "\t|     |      /                    /            |\n");
						fprintf(output, "\t|     |     /                    /             |\n");
						fprintf(output, "\t|     |    /                    /              |\n");
						fprintf(output, "\t|     |%.2f                    0               |\n", sqrt(a / c));
						fprintf(output, "\t|=====|========================================|\n");
					}
				}
				else
				{
					if (a * d - b * c < 0)
					{
						fprintf(output, "\t|=====|=======================|\n");
						fprintf(output, "\t|  x  |%.2f             %.2f  |\n", x1, x2);
						fprintf(output, "\t|-----|-----------------------|\n");
						fprintf(output, "\t|f'(x)|          -            |\n");
						fprintf(output, "\t|-----|-----------------------|\n");
						fprintf(output, "\t|     | +oo                   |\n");
						fprintf(output, "\t| f(x)|     \\                 |\n");
						fprintf(output, "\t|     |      \\                |\n");
						fprintf(output, "\t|     |       \\               |\n");
						fprintf(output, "\t|     |        \\              |\n");
						fprintf(output, "\t|     |         \\             |\n");
						fprintf(output, "\t|     |          \\            |\n");
						fprintf(output, "\t|     |           \\           |\n");
						fprintf(output, "\t|     |            \\          |\n");
						fprintf(output, "\t|     |             \\         |\n");
						fprintf(output, "\t|     |              \\        |\n");
						fprintf(output, "\t|     |               \\       |\n");
						fprintf(output, "\t|     |                 0     |\n");
						fprintf(output, "\t|=====|=======================|\n");
					}
					else
					{
						fprintf(output, "\t|=====|=======================|\n");
						fprintf(output, "\t|  x  |%.2f            %.2f   |\n", x1, x2);
						fprintf(output, "\t|-----|-----------------------|\n");
						fprintf(output, "\t|f'(x)|          +            |\n");
						fprintf(output, "\t|-----|-----------------------|\n");
						fprintf(output, "\t|     |                +oo    |\n");
						fprintf(output, "\t| f(x)|              /        |\n");
						fprintf(output, "\t|     |             /         |\n");
						fprintf(output, "\t|     |            /          |\n");
						fprintf(output, "\t|     |           /           |\n");
						fprintf(output, "\t|     |          /            |\n");
						fprintf(output, "\t|     |         /             |\n");
						fprintf(output, "\t|     |        /              |\n");
						fprintf(output, "\t|     |       /               |\n");
						fprintf(output, "\t|     |      /                |\n");
						fprintf(output, "\t|     |     /                 |\n");
						fprintf(output, "\t|     |    /                  |\n");
						fprintf(output, "\t|     |  0                    |\n");
						fprintf(output, "\t|=====|=======================|\n");
					}
				}
			}
		}
	}
}