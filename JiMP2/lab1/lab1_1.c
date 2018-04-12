#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int number = 5;
	int i, j, k;
	for (i = 1; i <= number; i++)
	{
		for (j = 1; j <= number - i; j++)
		{                    
			printf(" ");
		}

		for (k = 1; k <= i; k++)
		{
			printf("*");
        	}

	printf("\n");
	}
	return 0;
}
