#include <stdio.h>
#include <math.h>

const double ERROR = 10.0e-4;

double equation1(double x);
double equation2(double x);
double equation3(double x);
double derivative1(double x);
double derivative2(double x);
double derivative3(double x);

double (*const equation[])(double) = { equation1, equation2, equation3 };
double (*const derivative[])(double) = { derivative1, derivative2, derivative3 };

double range(double a, double b);
int is_negative(double a);

int main(int argc, char *argv[])
{
	double a = 1.5;
	double b = 2.5;

	int iterations = 0;
	double x = a;

	for (int i = 0; i < 3; i++) {
		iterations = 0;
		a = 1.5;
		b = 2.5
		    x = b - (equation[i](b) / (equation[i](b) - equation[i](a))) * (b - a);
		while (range(equation[i](x), 0.0) >= ERROR) {
			x = b - (equation[i](b) / (equation[i](b) - equation[i](a))) * (b - a);
			a = b;
			b = x;
			iterations++;
		}

		double MY_ROOT = x;
		printf("\nEquation %d\n", i + 1);
		printf("MY_ROOT\t\t= %+lf\n", MY_ROOT);
		printf("f(MY_ROOT)\t= %+lf\n", equation[i](MY_ROOT));
		printf("Difference\t= %+e\n", range(0.0, equation[i](MY_ROOT)));
		printf("Iterations:\t= %+d\n", iterations);
	}

	/*
	 * const double MY_ROOT = x;
	 *
	 * printf("MY_ROOT\t\t= %+lf\n", MY_ROOT);
	 * printf("f(MY_ROOT)\t= %+lf\n", equation(MY_ROOT));
	 * printf("Difference\t= %+e\n", range(0.0, equation(MY_ROOT)));
	 * printf("Iterations:\t= %+d\n", i);
	 */
	return 0;
}

double equation1(double x)
{
	return x / 2.0 - tan(x);
}

double derivative1(double x)
{
	return 1.0 / 2.0 - pow(1.0 / cos(x), 2.0);
}

double equation2(double x)
{
	return 2 * cos(x) - exp(x) / 2.0;
}

double derivative2(double x)
{
	return -exp(x) / 2.0 - 2.0 * sin(x);
}

double equation3(double x)
{
	return pow(x, 5.0) - 6.0;
}

double derivative3(double x)
{
	return 5.0 * pow(x, 4.0);
}

double range(double a, double b)
{
	return fabs(b - a);
}

int is_negative(double a)
{
	return !!signbit(a);
}
