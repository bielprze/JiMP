/*
 ============================================================================
 Name        : Zadanie 5.3
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include "5.3_Bielecki.h"

int main() {
	int tab[2][2][2];
	const int tab_size=sizeof(tab)/sizeof(tab[0]);
	printf("%d \n", tab_size);

	wypelnianie(tab, tab_size);
	mnozenie_macierzy(tab, tab_size);
	
	return 0;
}
