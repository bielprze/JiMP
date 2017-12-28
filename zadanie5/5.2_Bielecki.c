
/*
 ============================================================================
 Name        : Zadanie 5.2
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include "5.2_Bielecki.h"

int main(){
	srand(time(NULL));
	int tab[3][3];
	wypelnianie(tab, 3);
	wyswietlanie(tab, 3);
	printf("wyznacznik macierzy to %d \n", wyznacznik(tab));

	return 0;
}
