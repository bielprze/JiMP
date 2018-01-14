/*
 ============================================================================
 Name        : Zadanie 5.2
 Author      : Przemysław Bielecki
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypelnianie(int tab_size, int tab[tab_size][tab_size])
{
	for(int i=0; i<tab_size; i++)
	{
		for(int j=0; j<tab_size; j++)
		{	
			tab[i][j]=rand()%11;
		}
	}
}

void wyswietlanie(int tab_size, int tab[tab_size][tab_size])
{
	for(int i=0; i<tab_size; i++)
	{
		for(int j=0; j<tab_size; j++)
		{
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}	
}
int wyznacznikMacierzy3Na3(int tab[3][3])
{
	int det;	
	
	det=(tab[0][0]*tab[1][1]*tab[2][2])+(tab[1][0]*tab[2][1]*tab[0][2])+(tab[2][0]*tab[0][1]*tab[1][2])-(tab[2][0]*tab[1][1]*tab[0][2])-(tab[0][0]*tab[2][1]*tab[1][2])-(tab[1][0]*tab[0][1]*tab[2][2]);

	return det;
}
