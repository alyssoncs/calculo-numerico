#include <stdio.h>

double estimate_precision(void)
{
	double epsilon = 1;
	double s = 2;

	while (s > 1.0)
	{
		epsilon /= 2;
		s = 1.0+epsilon;
	}

	return 2*epsilon;
}

int main(void)
{
	printf("Precision: %.18lf\n", estimate_precision());
}
