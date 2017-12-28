/*
 ============================================================================
 Name        : Zadanie 6.1
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include <stdio.h>


int main() {
	unsigned char a;
	for(int i=32; i<127; i++)
	{
		a=i;
		printf("Liczba to: %d, a znak do niej przyporządkowany to: %c\n", i, a);
	}
	
	return 0;
}
