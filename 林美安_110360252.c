int main()
{
	int a, b, c, d;
	int replay;

	do
	{
		printf("Please input four integer (1 - 13)\n");
	loop: scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a < 1 || a > 13 || b < 1 || b > 13 || c < 1 || c > 13 || d < 1 || d > 13)
		{
			printf("Input illege, PLease input again\n");
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
