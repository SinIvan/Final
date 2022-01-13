#include <stdio.h>
#include <stdlib.h>

char op[5] = { '#', '+', '-', '*', '/', };
float cal(float x, float y, int op)
{
	switch (op)
	{
	case 1: return x + y;
	case 2: return x - y;
	case 3: return x * y;
	case 4: return x / y;
	default: return 0.0;
	}
}

float calculate_mode11(float a, float b, float c, float d, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(a, b, op1);
	r2 = cal(r1, c, op2);
	r3 = cal(r2, d, op3);
	return r3;
}

float calculate_mode12(float a, float b, float c, float d, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(b, c, op2);
	r2 = cal(a, r1, op1);
	r3 = cal(r2, d, op3);
	return r3;
}

float calculate_mode13(float a, float b, float c, float d, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(c, d, op3);
	r2 = cal(b, r1, op2);
	r3 = cal(a, r2, op1);
	return r3;
}

float calculate_mode14(float a, float b, float c, float d, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(b, c, op2);
	r2 = cal(r1, d, op3);
	r3 = cal(a, r2, op1);
	return r3;
}

float calculate_mode15(float a, float b, float c, float d, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(a, b, op1);
	r2 = cal(c, d, op3);
	r3 = cal(r1, r2, op2);
	return r3;
}

int get24(int a, int b, int c, int d)
{
	int op1, op2, op3;
	int flag = 0;
	for (op1 = 1; op1 <= 4; op1++)
		for (op2 = 1; op2 <= 4; op2++)
			for (op3 = 1; op3 <= 4; op3++)
			{
				if (calculate_mode11(a, b, c, d, op1, op2, op3) == 24)
				{
					printf("((%d%c%d)%c%d)%c%d=24\n", a, op[op1], b, op[op2], c, op[op3], d);
					flag = 1;
				}
				if (calculate_mode12(a, b, c, d, op1, op2, op3) == 24)
				{
					printf("%d%c(%d%c%d)%c%d=24\n", a, op[op1], b, op[op2], c, op[op3], d);
					flag = 1;
				}
				if (calculate_mode13(a, b, c, d, op1, op2, op3) == 24)
				{
					printf("%d%c(%d%c(%d%c%d))=24\n", a, op[op1], b, op[op2], c, op[op3], d);
					flag = 1;
				}
				if (calculate_mode14(a, b, c, d, op1, op2, op3) == 24)
				{
					printf("%d%c((%d%c%d)%c%d)=24\n", a, op[op1], b, op[op2], c, op[op3], d);
					flag = 1;
				}
				if (calculate_mode15(a, b, c, d, op1, op2, op3) == 24)
				{
					printf("(%d%c%d)%c(%d%c%d)=24\n", a, op[op1], b, op[op2], c, op[op3], d);
					flag = 1;
				}
			}
	return flag;
}

int User_definded_print()
{
	int a, b, c, d;
	int replay;

	do
	{
		printf("Please input four integer (1 - 13)\n");
	loop: scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a < 1 || a > 13 || b < 1 || b > 13 || c < 1 || c > 13 || d < 1 || d > 13)
		{
			printf("Input illege, Please input again\n");
			goto loop;
		}

		if (get24(a, b, c, d));
		else
			printf("Sorry, the four integer cannot be calculated to get 24\n");
		getchar();

		printf("Y to replay & 0 to end");
		scanf("%d", &replay);
		getchar();
	} while (replay);

	return 0;
}