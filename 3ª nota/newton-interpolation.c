#include <stdio.h>
#include <stdlib.h>

void newton_interpolation(double *x, double *y, int n, double **fdd)
{
	for (int i = 0; i < n; i++)
		fdd[i][0] = y[i];

	for (int i = 1; i < n; i++)
		for (int j = 0; j < n-i; j++)
			fdd[j][i] = (fdd[j+1][i-1]-fdd[j][i-1])/(x[i+j]-x[j]);
}

double Pn(double x, double *x_int, double **fdd, int order)
{
	if (order == 0)
		return fdd[0][order];

	double factor = 1;
	for (int i = 0; i < order; i++)
		factor *= (x-x_int[i]);

	return fdd[0][order]*factor+Pn(x, x_int, fdd, order-1);
}

void print_Pn(double *x_int, double **fdd, int order)
{
	if (order == 0)
	{
		printf("%.4lf", fdd[0][order]);
		return;
	}

	print_Pn(x_int, fdd, order-1);
	printf("%+.4lf", fdd[0][order]);
	for (int i = 0; i < order; i++)
		printf("(x%+.4lf)", -x_int[i]);

	return;
}


int main(void)
{
	double **fdd = malloc(sizeof(double *)*6);
	if (fdd)
	{
		for (int i = 0; i < 6; i++)
		{
			fdd[i] = malloc(sizeof(double)*6);
			if (!fdd[i])
				return 1;
		}
	}
	double x[6] = {0.0, 0.5, 1.0, 1.5, 2.0, 2.5};
	double y[6] = {-2.78, -2.41, -1.65, -0.594, 1.34, 4.564};

	newton_interpolation(x, y, 6, fdd);

	printf("P5(x) = ");
	print_Pn(x, fdd, 5);
	printf("\n\n");
	printf("P5(1.23) = %lf\n", Pn(1.23, x, fdd, 5));

	return 0;

}

