#include <stdio.h>
#include <math.h>

const double ERROR = 10.0e-4;
const double REAL_ROOT = 1.45002531965993597;

double equation(double x);
double range(double a, double b);
int is_negative(double a);

int main(int argc, char *argv[])
{
	double a = 1.0;
	double b = 7.0;

	int i = 0;

	while (range(equation(a), equation(b)) >= ERROR) {
		if (is_negative(equation(a)) != is_negative(equation(b))) {
			double mid = (a + b) / 2;

			if (is_negative(equation(a)) == is_negative(equation(mid)))
				a = mid;
			else
				b = mid;
		}
		i++;
	}

	const double MY_ROOT = (a + b) / 2;

	printf("REAL_ROOT\t= %+lf\n", REAL_ROOT);
	printf("MY_ROOT\t\t= %+lf\n", MY_ROOT);
	printf("f(ROOT)\t\t= %+lf\n", equation(REAL_ROOT));
	printf("f(MY_ROOT)\t= %+lf\n", equation(MY_ROOT));

	printf("Difference\t= %+e\n", range(equation(REAL_ROOT), equation(MY_ROOT)));
	printf("Iterations:\t= %+d\n", i);
	return 0;
}

double equation(double x)
{
	return pow(x, 5.0) - 4.0 * pow(x, 2.0) + 2.0;
}

double range(double a, double b)
{
	return fabs(b - a);
}

int is_negative(double a)
{
	return !!signbit(a);
}
