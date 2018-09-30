#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **gauss_jordan_inverse(double **a, int n);
void forward_substitution(double **a, double b[], int n);
void back_substitution(double **a, double b[], double x[], int n);
void solve(double **a, double b[], double x[], int n);
void read_equations(double **a, int n);

void print_mat(const char *name, double **a, int n)
{
	printf("%s = \t", name);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%.4lf\t\t", a[i][j]);
		printf("\n\n\t");
	}
	printf("\n");

}

int main(void)
{
	double **a, *b, *x;
	double **inverse;
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
		read_equations(a, n);


		inverse = gauss_jordan_inverse(a, n);
		print_mat("A^-1", inverse, n);
	}
	else exit (1); 
	
	for (int i = 0; i < n; i++)
	{
		free(a[i]);
		free(inverse[i]);
	}
	free(a);
	free(b);
	free(x);
	free(inverse);

	return 0;
}

double **gauss_jordan_inverse(double **a, int n)
{
	double **identity = malloc(sizeof(double *)*n);
	if (identity)
	{
		for (int i = 0; i < n; i++)
		{
			identity[i] = malloc(sizeof(double)*n);
			for (int j = 0; j < n; j++)
				identity[i][j] = 0;
			identity[i][i] = 1;
		}

	}
	
	for (int i = 0; i < n; i++)
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

			dummy_ptr = identity[p];
			identity[p] = identity[i];
			identity[i] = dummy_ptr;
		}
		
		double val = a[i][i];
		for (int j = 0; j < n; j++)
		{
			a[i][j] 	/= val;
			identity[i][j] 	/= val;
		}
		
		/* testar por linha zerada */
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				double val = a[j][i];
				for (int k = 0; k < n; k++)
				{

					a[j][k] 	-= val*a[i][k];
					identity[j][k] 	-= val*identity[i][k];
				}
			}
		}

	}

	return identity;

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

void read_equations(double **a, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lf", &a[i][j]);
}




