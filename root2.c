#include <stdio.h>
#include <math.h>

const double ERROR = 10.0e-4;
const double REAL_ROOT = 1.45002531965993597;

struct cmd_args
{
	double a, b;
	double precision;
	int iterations;
} ARGS;


int handle_args(int argc, char *argv[]);
double equation(double x);
double range(double a, double b);
int is_negative(double a);

int main(int argc, char *argv[])
{
	if (!handle_args(argc, argv))
	{
		return 1;
	}

	int i, iterations;
	double a = ARGS.a;
	double b = ARGS.b;
	double precision = ARGS.precision;
	i = iterations = ARGS.iterations;

	while (range(equation(a), equation(b)) >= precision && i)
	{
		if (is_negative(equation(a)) != is_negative(equation(b)))
		{
			double mid = (a+b)/2;

			if (is_negative(equation(a)) == is_negative(equation(mid)))
				a = mid;
			else
				b = mid;
		}

		i--;
	}

	if (range(equation(a), equation(b)) >= precision)
	{
		printf("O metodo falhou: precisao acima do especificado\n");
		return 1;
	}

	const double MY_ROOT = (a+b)/2;
	printf("MY_ROOT\t\t= %+lf\n", MY_ROOT);
	printf("f(MY_ROOT)\t= %+lf\n", equation(MY_ROOT));
	printf("Iterations\t= %d\n", iterations-i);
	
	return 0;
}

int handle_args(int argc, char *argv[])
{
	if (argc == 5)
	{
		sscanf(argv[1], "%lf", &ARGS.a);
		sscanf(argv[2], "%lf", &ARGS.b);
		sscanf(argv[3], "%lf", &ARGS.precision);
		sscanf(argv[4], "%d", &ARGS.iterations);

		return 1;
	}
	else
	{
		fprintf(stderr, "usage: %s <a> <b> <precision> <iteration>\n", argv[0]);
		return 0;
	}

}

double equation(double x)
{
	return pow(x, 5.0)-4.0*pow(x, 2.0)+2.0;
}

double range(double a, double b)
{
	return fabs(b-a);
}

int is_negative(double a)
{
	return !!signbit(a);
}

