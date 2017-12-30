
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
	int tab_size=sizeof(tab)/sizeof(tab[0]);
	wypelnianie(tab_size, tab);
	wyswietlanie(tab_size, tab);
	printf("wyznacznik macierzy to %d \n", wyznacznik(tab));

	return 0;
}
