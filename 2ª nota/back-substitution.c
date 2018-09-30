#include <stdio.h>
#include <stdlib.h>

void solve(double **a, double *b, double *x, int n);
void read_equations(double **a, double *b, int n);

int main(void)
{
	double **a, *b, *x;
	int n_equations;

	printf("Insert the numbers of equations\n");
	scanf("%d", &n_equations);

	a = malloc(sizeof(double *)*n_equations);
	if (a)
	{
		for (int i = 0; i < n_equations; i++)
			a[i] = malloc(sizeof(double)*n_equations);
	}
	b = malloc(sizeof(double)*n_equations);
	x = malloc(sizeof(double)*n_equations);

	if (a && b && x)
	{
		read_equations(a, b, n_equations);
		solve(a, b, x, n_equations);

		printf("X = ");
		for (int i = 0; i < n_equations; i++)
			printf("%lf, ", x[i]);
		printf("\n");
	}
	else exit (1); 
	
	for (int i = 0; i < n_equations; i++)
		free(a[i]);
	free(a);
	free(b);
	free(x);

	return 0;
}


void read_equations(double **a, double *b, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			scanf("%lf", &a[i][j]);
		scanf("%lf", &b[i]);
	}
}

void solve(double **a, double *b, double *x, int n)
{
	x[n-1] = b[n-1]/a[n-1][n-1];
	int sum;
	for (int i = n-2; i >= 0; i--)
	{
		sum = b[i];
		for (int j = i+1; j < n; j++)
			sum -= a[i][j]*x[j];
		x[i] = sum/a[i][i];
	}
}



