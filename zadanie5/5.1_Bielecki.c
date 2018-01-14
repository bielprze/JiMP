
/*
 ============================================================================
 Name        : Zadanie 5.1
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include "5.1_Bielecki.h"


int main() {
	
	int godz1[4], godz2[4], warunek1, wynik;
	const int tab_size=sizeof(godz1)/sizeof(godz1[0]);	

	printf("Podaj pierwsza godzine (kazda cyfre zatwierdzajac enterem):\n");
	wypelnianie(godz1, tab_size);
	warunek1=check(godz1);
	
	if(warunek1==-1)
		return 1;

	printf("Podaj druga godzine (kazda cyfre zatwierdzajac enterem):\n");
	wypelnianie(godz2, tab_size);	
	warunek1=check(godz2);

	if(warunek1==-1)
		return 1;
		

	wynik=porownanie(godz1, godz2, tab_size);

	if(wynik==-1) 
	{	
		printf("Godzina %d%d:%d%d jest większa od %d%d:%d%d\n", godz1[0],  godz1[1],  godz1[2],  godz1[3], godz2[0],  godz2[1],  godz2[2],  godz2[3]);
	}
	if(wynik==1) 
	{	
		printf("Godzina %d%d:%d%d jest mniejsza od %d%d:%d%d\n", godz1[0],  godz1[1],  godz1[2],  godz1[3], godz2[0],  godz2[1],  godz2[2],  godz2[3]);
	}
	if(wynik==0) 
		printf("Godziny sa takie same\n");
	return 0;
}

