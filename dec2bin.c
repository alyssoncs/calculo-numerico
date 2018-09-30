#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage %s <n>\nwith n in [0, 1]\n", argv[0]);
		exit(1);
	}

	double n = strtod(argv[1], NULL);

	if (n == 1.0) {
		printf("1.0\n");
	} else {
		printf("0.");
		to_base_2(n);
		printf("\n");
	}

	return 0;
}
