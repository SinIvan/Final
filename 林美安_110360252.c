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
