#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newton_cotes(double (*f)(double), double a, double b, int n);

int main(int argc, char **argv)
{
	int n;

	if (argc != 2)
		n = 20;
	else
		n = atoi(argv[1]);

	printf("Integral of e^x, from 1 to 2\t\t= %lf\n", newton_cotes(exp, 1, 2, n));
	printf("Integral of sqrt(x), from 1 to 4\t= %lf\n", newton_cotes(sqrt, 1, 4, n));

	return 0;
}


double newton_cotes(double (*f)(double), double a, double b, int n)
{
	double h = (b - a) / n;

	double sum = f(a);

	for (int i = 1; i < n; i++)
		sum += 2 * f(a + h * i);
	sum += f(b);

	return h / 2 * sum;
}
