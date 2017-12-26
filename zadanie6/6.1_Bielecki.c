/*
 ============================================================================
 Name        : Zadanie 6.1
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include <stdio.h>


int main() {

	printf("Podaj znak którego numer chcesz zobaczyć\n");
	char a;
	scanf("%c", &a);
	
	int b=a;
	printf("Twój znak to %c, a jego numer to %d\n", a, b);	
	
	return 0;
}
