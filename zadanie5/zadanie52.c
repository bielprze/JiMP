
/*
 ============================================================================
 Name        : Zadanie52.c
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include "zadanie52.h"

int main(){
	int tab[3][3];
	wypelnianie(tab);
	printf("wyznacznik macierzy to %d \n", wyznacznik(tab));

	return 0;
}
