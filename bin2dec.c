#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void to_base_2(double n)
{
	int times = 0;

	do {
		n = 2 * n;

		if (n >= 1.0) {
			printf("1");
			n = n - 1.0;
		} else {
			printf("0");
		}

		times++;
	} while (n != 0.0 && times < 64);
}

double parse(char arr[])
{
	double num = 0.0;

	if (arr[0] == '0' && arr[1] == '.') {
		arr = arr + 2;
		int i = -1;
		while (*arr) {
			num += (*arr - '0') * pow(2, i);
			arr++;
			i--;
		}
	}

	return num;
}
int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage %s <n>\nwith n in [0, 1]\n", argv[0]);
		exit(1);
	}

	double n = parse(argv[1]);
	printf("%lf\n", n);

	return 0;
}
