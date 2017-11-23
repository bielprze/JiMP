#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypelnianie(int tab[2][2][2])
{
	srand(time(NULL));
	for(int i=0; i<2; i++)
	for(int j=0; j<2; j++)
	for(int k=0; k<2; k++)
	{
		tab[i][j][k]=rand()%201;
		if(tab[i][j][k]>100) tab[i][j][k]=tab[i][j][k]-201;
	}
}


void podzial(int tab[2][2][2], int tab1[2][2], int tab2[2][2])
{
	
	for(int i=0; i<2; i++)
	for(int j=0; j<2; j++)
	{
		tab1[i][j]=tab[0][i][j];
		tab2[i][j]=tab[1][i][j];
	}
	
	for(int i=0; i<2; i++)
	{
	for(int j=0; j<2; j++)
	{
	printf("%d, ", tab1[i][j]);
	}
	printf("\n");
	}

	for(int i=0; i<2; i++)
	{
	for(int j=0; j<2; j++)
	{
	printf("%d, ", tab2[i][j]);
	}
	printf("\n");
	}
	

}

void scalanie(int tab[2][2][2], int tab1[2][2], int tab2[2][2])
{
	for(int i=0; i<2; i++)
	for(int j=0; j<2; j++)
	{
		tab[0][i][j]=tab1[i][j];
		tab[1][i][j]=tab2[i][j];
	}

}

void mnozenie_macierzy(int tab[2][2][2])
{	
	int tab1[2][2];
	int tab2[2][2];
	int wynik[2][2];
	
	for(int i=0; i<2; i++)
	for(int j=0; j<2; j++)
	wynik[i][j]=0;
	

	podzial(tab, tab1, tab2);
	for(int i=0; i<2; i++)
	for(int j=0; j<2; j++)
	for(int k=0; k<2; k++)
	wynik[i][j]+=tab1[i][k]*tab2[k][j];



	for(int i=0; i<2; i++) 
	{
	for(int j=0; j<2; j++)
	{	
		printf("%d ", wynik[i][j]);
	}
	printf("\n");
	}
	
}

