#include <stdio.h>
#include <math.h>

const double ERROR = 10.0e-4;

double equation(double x);
double equivalent(double x);
double range(double a, double b);
int is_negative(double a);

int main(int argc, char *argv[])
{
	double a = 1.5;

	int i = 0;
	double x = a;
	while (range(equation(x), 0.0) >= ERROR)
	{
		x = equivalent(x);
		i++;
	}

	const double MY_ROOT = x;

	printf("MY_ROOT\t\t= %+lf\n", MY_ROOT);
	printf("f(MY_ROOT)\t= %+lf\n", equation(MY_ROOT));
	printf("Difference\t= %+e\n", range(0.0, equation(MY_ROOT)));
	printf("Iterations:\t= %+d\n", i);

	return 0;
}

double equation(double x)
{
	return x-pow(x, 3.0)-4.0*pow(x, 2.0)+10.0;
}

double equivalent(double x)
{
	return sqrt(x-pow(x, 3.0)+10.0)/2;
}
double range(double a, double b)
{
	return fabs(b-a);
}

int is_negative(double a)
{
	return !!signbit(a);
}

