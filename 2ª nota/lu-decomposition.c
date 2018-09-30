#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void decompose(double **a, double *b, int n);
void forward_substitution(double **a, double b[], int n);
void back_substitution(double **a, double b[], double x[], int n);
void solve(double **a, double b[], double x[], int n);
void read_equations(double **a, double *b, int n);

int main(void)
{
	double **a, *b, *x;
	int n;

	printf("Insert the size of the square matrix\n");
	scanf("%d", &n);

	//n = 4;
	a = malloc(sizeof(double *)*n);
	if (a)
	{
		for (int i = 0; i < n; i++)
			a[i] = malloc(sizeof(double)*n);
	}
	b = malloc(sizeof(double)*n);
	x = malloc(sizeof(double)*n);

	if (a && b && x)
	{
		read_equations(a, b, n);


		decompose(a, b, n);
		printf("L = \t");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == j)
					printf("%.4lf\t\t", 1.0);
				else if (j > i)
					printf("%.4lf\t\t", 0.0);
				else
					printf("%.4lf\t\t", a[i][j]);
			}
			printf("\n\n\t");
		}
		printf("\n\n");

		printf("U = \t");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j >= i)
					printf("%.4lf\t\t", a[i][j]);
				else
					printf("%.4lf\t\t", 0.0);
			}
			printf("\n\n\t");
		}
		printf("\n");

		solve(a, b, x, n);
		printf("x = {");
		for (int i = 0; i < n; i++)
		{
			printf("%lf, ", x[i]);
		}
		printf("}\n");
	}
	else exit (1); 
	
	for (int i = 0; i < n; i++)
		free(a[i]);
	free(a);
	free(b);
	free(x);

	return 0;
}

void decompose(double **a, double *b, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int p = i;
		for (int ii = i+1; ii < n; ii++)
			if (fabs(a[ii][i]) > fabs(a[p][i]))
				p = ii;
		if (p != i)
		{
			double *dummy_ptr = a[p];
			a[p] = a[i];
			a[i] = dummy_ptr;

			double dummy_dbl = b[p];
			b[p] = b[i];
			b[i] = dummy_dbl;
		}
		
		for (int j = i+1; j < n; j++)
		{
			double factor = a[j][i]/a[i][i];
			a[j][i] = factor;

			for (int k = i+1; k < n; k++)
				a[j][k] -= a[i][j]*factor;
		}
	}

}

void forward_substitution(double **a, double b[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int sum = b[i];
		for (int j = 0; j < i; j++)
			sum -= a[i][j]*b[j];
		b[i] = sum;
	}
}

void back_substitution(double **a, double b[], double x[], int n)
{
	x[n-1] = b[n-1]/a[n-1][n-1];
	for (int i = n-2; i >= 0; i--)
	{
		int sum = b[i];
		for (int j = i+1; j < n; j++)
			sum -= a[i][j]*x[j];
		x[i] = sum/a[i][i];
	}

}

void solve(double **a, double b[], double x[], int n)
{
	forward_substitution(a, b, n);
	back_substitution(a, b, x, n);
}

void read_equations(double **a, double *b, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%lf", &a[i][j]);
		scanf("%lf", &b[i]);
	}
}




