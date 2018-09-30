#include <stdio.h> 
#include <stdlib.h>

const double DIZIMA = 111.0/900.0;

void to_base_2(double n)
{
	int times = 0;

	printf("0.");
	do
	{
		n = 2*n;

		if (n >= 1.0)
		{
			printf("1");
			n = n-1.0;
		}
		else
		{
			printf("0");
		}

		times++;
	} while (times < 7);
}

int main(int argc, char *argv[])
{
	to_base_2(DIZIMA);
	printf("\n");
	return 0;	
}

