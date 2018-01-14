/*
 ============================================================================
 Name        : Zadanie 6.3
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanie_tablicy(int tab[], int tab_size)
{
	srand(time(NULL));	
	for(int i=0; i<tab_size; i++)
	{
		tab[i]=rand()%100;
	}
}

void wyswietlanie(int tab[], int tab_size) 
{
	for(int i=0; i<tab_size; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}

double srednia(int tab[], int tab_size) 
{
	int suma=0;
	for(int i=0; i<tab_size; i++)
	{
		suma=suma+tab[i];
	}
	return suma/tab_size;
}	

void bubblesort(int tab[], int tab_size)
{
	int temp;
	for (int c=0; c<(tab_size-1); c++)
 	{
		for (int d=0 ; d<tab_size-c-1; d++)
		{
			if (tab[d] > tab[d+1]) 
			{
				temp=tab[d];
        			tab[d]=tab[d+1];
       				tab[d+1]=temp;
			}
		}
	}

}

double mediana(int tab[], int tab_size)
{
	
	bubblesort(tab, tab_size);
	return (tab[4]+tab[5])/2;
}

void maks_i_min(int tab[], int tab_size)
{
	bubblesort(tab, tab_size);
	printf("Wartość maks to: %d , wartość min to: %d\n", tab[9], tab[0]);
}

int main(){

	int tab[10];	
	int warunek1=1;
	int warunek2;
	int warunek3=0;
	const int tab_size=sizeof(tab)/sizeof(tab[0]);

	while(warunek1 == 1)
	{	
		printf("Powiedz, co chcesz zrobić:\n [1] Wypełnij tablicę liczbami losowymi\n [2] Wyświetl tablicę\n [3] Oblicz średnią liczb\n [4] Oblicz medianę liczb\n [5] Maksymalny i minimalny element\n [6] wyjście\n");
		scanf("%d",&warunek2);
	
		switch(warunek2){
		case 1: 
			losowanie_tablicy(tab, tab_size);
			warunek3=1;
			break;
		case 2:
			if(warunek3==1) wyswietlanie(tab, tab_size);
			else printf("Nie wypełnino tablicy!\n");
			break;
		case 3: 
			if(warunek3==1) srednia(tab, tab_size);
			else printf("Nie wypełnino tablicy!\n");
			break;
		case 4:
			if(warunek3==1) mediana(tab, tab_size);
			else printf("Nie wypełnino tablicy!\n");
			break;
		case 5: 
			if(warunek3==1) maks_i_min(tab, tab_size);
			else printf("Nie wypełnino tablicy!\n");
			break;
		case 6:
			warunek1=0;
			break;
		}
	}

	return 0;
}
