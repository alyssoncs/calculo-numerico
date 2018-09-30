#include <stdio.h>

char n_bit(char c, int n)
{
	return (c >> (7 - n)) & 1;
	int val = c;

	for (int i = 7; i >= 0; i--)
		printf("%d", (val >> i) & 1);
}
int main(int argc, char *argv[])
{
	double val = 111.0 / 900.0;

	char arr[sizeof(double)];
	char *p = (char *)&val;

	for (int i = 0; i < sizeof(double); i++) {
		arr[sizeof(double) - (i + 1)] = *p;
		p++;
	}


	printf("Decimal:\t%lf\n", val);
	printf("Binario:\t");
	for (int i = 0; i < sizeof(double); i++) {
		for (int j = 0; j < sizeof(char) * 8; j++)
			printf("%d", n_bit(arr[i], j));
			//printf("foi (%d, %d)\n", i, j);
		printf(" ");
	}
	printf("\n");

	return 0;
}
