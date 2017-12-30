/*
 ============================================================================
 Name        : Zadanie 5.3
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wyswietlanie(int tab[2][2], int tab_size)
{
	for(int i=0; i<tab_size; i++)
	{
		for(int j=0; j<tab_size; j++)
		{
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void wypelnianie(int tab[2][2][2], int tab_size)
{
	srand(time(NULL));
	for(int i=0; i<tab_size; i++)
		for(int j=0; j<tab_size; j++)
			for(int k=0; k<tab_size; k++)
			{
				tab[i][j][k]=rand()%201;
				if(tab[i][j][k]>100) tab[i][j][k]=tab[i][j][k]-201;
			}
}


void podzial(int tab[2][2][2], int tab1[2][2], int tab2[2][2], int tab_size)
{
	
	for(int i=0; i<tab_size; i++)
		for(int j=0; j<tab_size; j++)
		{
			tab1[i][j]=tab[0][i][j];
			tab2[i][j]=tab[1][i][j];
		}

	wyswietlanie(tab1, tab_size);
	wyswietlanie(tab2, tab_size);
}


void scalanie(int tab[2][2][2], int tab1[2][2], int tab2[2][2], int tab_size)
{
	for(int i=0; i<tab_size; i++)
		for(int j=0; j<tab_size; j++)
		{
			tab[0][i][j]=tab1[i][j];
			tab[1][i][j]=tab2[i][j];
		}

}

void mnozenie_macierzy(int tab[2][2][2], int tab_size)
{	
	int tab1[2][2];
	int tab2[2][2];
	int wynik[2][2];
	
	for(int i=0; i<tab_size; i++)
		for(int j=0; j<tab_size; j++)
	wynik[i][j]=0;
	

	podzial(tab, tab1, tab2, tab_size);
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<2; k++)
				wynik[i][j]+=tab1[i][k]*tab2[k][j];

	wyswietlanie(wynik, tab_size);	
}

