#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sprawdzenie_liczby(int a)
{
	if(a<1 || a>10)
	{
		printf("Podano liczbę z poza przedziału\n");
		return 0;	
	}
	return 1;
}

void wypelnianie_tablicy(int tab[])
{
	for(int i=0; i<10; i=i+1)
	{
		tab[i]=i+1;
	}
}

int szukanie_liczby(int x, int tab[],int begin, int end)
{
	int s;
	s=(begin+end)/2;
	if(tab[s]>x) 
	{
		return szukanie_liczby(x,tab ,begin, s-1);
	}
	if(tab[s]<x)
	{
		return szukanie_liczby(x,tab ,s+1, end);
	}
	return s;
}

int main() {
	int a, warunek, tab[10];
		
	do
	{	
		printf("Podaj liczbę z przedziału [1, 10]\n");
		scanf("%d", &a);
		warunek=sprawdzenie_liczby(a);
	}while(warunek!=1);	
	
	wypelnianie_tablicy(tab);
	

	printf("szukana liczba to %d, a znaleziona to %d\n", a,szukanie_liczby(a, tab, 0, 9)+1); //drugi argument to liczba w połowie przedziału. Ponieważ 5 i 6 są w połowie możemy wybrać jedną z tcyh dwóch.

	return 1;
}
