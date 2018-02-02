/*
 ============================================================================
 Name        : Zadanie 4.2
 Author      : Przemysław Bielecki
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ZAKRES_OD=1;
const int ZAKRES_DO=10;

int sprawdzenie_liczby(int a)
{
	if(a<ZAKRES_OD || a>ZAKRES_DO)
	{
		printf("Podano liczbę z poza przedziału\n");
		return 1;	
	}
	return 0;
}

void wypelnianie_tablicy(int tab[], int tab_size)
{
	for(int i=0; i<tab_size; i=i+1)
		tab[i]=i+1;
}

int szukanie_liczby(int x, int tab[], int begin, int end)
{
	int polowa_zakresu=(begin+end)/2;
	if(tab[polowa_zakresu]>x) 
		return szukanie_liczby(x, tab, begin, polowa_zakresu-1);
	
	if(tab[polowa_zakresu]<x)
		return szukanie_liczby(x, tab, polowa_zakresu+1, end);
	
	return polowa_zakresu;
}

int main() {
	int a, tab[10];
	const int tab_size=sizeof(tab)/sizeof(tab[0]);
	
	do
	{	
		printf("Podaj liczbę z przedziału [1, 10]\n");
		scanf("%d", &a);
	}while(sprawdzenie_liczby(a));	
	
	wypelnianie_tablicy(tab, tab_size);
	

	printf("szukana liczba to %d, a znaleziona to %d\n", a, szukanie_liczby(a, tab, ZAKRES_OD-1, ZAKRES_DO-1)+1); //drugi argument to liczba w połowie przedziału. Ponieważ 5 i 6 są w połowie możemy wybrać jedną z tych dwóch.

	return 1;
}
