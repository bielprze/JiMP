#include <stdio.h>
#include <stdlib.h>

int fibb(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else
		return fibb(n-1)+fibb(n-2);

}


int main(void) 
{
	int n;
	printf("podaj numer wyrazu ciagu\n");
	scanf("%d", &n);

	printf("fibb(%d) = %d\n",n,fibb(n));

	return 0;
}

