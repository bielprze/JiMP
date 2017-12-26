
/*
 ============================================================================
 Name        : Zadanie 5.2
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include "5.2_Bielecki.h"

int main(){
	int tab[3][3];
	wypelnianie(tab);
	printf("wyznacznik macierzy to %d \n", wyznacznik(tab));

	return 0;
}
