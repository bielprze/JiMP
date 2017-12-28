/*
 ============================================================================
 Name        : Zadanie 4.3
 Author      : Przemysław Bielecki
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypelnianie_tablicy(int tab[], int waga, int tab_size)
{
	for(int i=0; i<tab_size; i=i+1)
	{
		tab[i]=waga;
	}
}

void podzial_tablicy(int tab[], int counter, int tab_podzielona[], int tab_size)
{
	switch (counter)
	{
	case 1:
	for(int i=0; i<tab_size; i=i+1)
	{
		tab_podzielona[i]=tab[i];
	}
	break;
	case 2:
	for(int i=0; i<tab_size; i=i+1)
	{
		tab_podzielona[i]=tab[i+tab_size];
	}
	break;
	case 3:
	for(int i=0; i<tab_size; i=i+1)
	{
		tab_podzielona[i]=tab[i+tab_size+tab_size];
	}
	break;
	}
	
}

int wazenie_grup(int tab1[], int tab2[], int tab_size)
{
	int suma1=0;
	int suma2=0;
	int porownanie;	
	for(int i=0; i<tab_size; i=i+1)
	{
		suma1=suma1+tab1[i];
		suma2=suma2+tab2[i];
	}
	if(suma1==suma2)
	{
		porownanie=1;	
		return porownanie;
	}	
	else if(suma1<suma2)
	{
		porownanie=2;	
		return porownanie;
	}
	else if(suma2>suma1)
	{	
		porownanie=3;		
		return porownanie;
	}	
	return -1;
}

int wazenie_kulek(int waga1, int waga2, int counter)
{
	if(waga1==waga2)
	{	
		switch(counter)
		{
		case 1: printf("najciezsza kulka to kulka nr: %d\n", 3);
		 break;
		case 2: printf("najciezsza kulka to kulka nr: %d\n", 6);
		 break;
		case 3: printf("najciezsza kulka to kulka nr: %d\n", 9); 
		 break;
		}
	return 1;
	}
	else if(waga1<waga2)
	{
		switch(counter)
		{
		case 1: printf("najciezsza kulka to kulka nr: %d\n", 2);
		 break;
		case 2: printf("najciezsza kulka to kulka nr: %d\n", 5);	
		 break;
		case 3: printf("najciezsza kulka to kulka nr: %d\n", 8);
		 break;
		}
	return 1;
	}
	else if(waga1>waga2)
	{
		switch(counter)
		{
		case 1: printf("najciezsza kulka to kulka nr: %d\n", 1);
		 break;
		case 2: printf("najciezsza kulka to kulka nr: %d\n", 4);
		 break;
		case 3: printf("najciezsza kulka to kulka nr: %d\n", 7);
		 break;
		}
	return 1;
	}
	return 0;

}

void sprawdzenie(int tab[], int tab_size)
{
	printf("\n");
	printf("Poniżej (w celu sprawdzenia poprawności działania programu) znajduje się lista wag kolejnych kulek: \n");

	for(int i=0; i<tab_size; i=i+1)
	{
		printf("kulka o numerze: %d waży %d \n", i+1, tab[i]);
	}	
}

int main()
{
	int random;
	int tab[9];
	int tab1[3], tab2[3], tab3[3];
	int porownanie;

	srand(time(NULL));
	random=(rand()%9);
	
	wypelnianie_tablicy(tab, 1, 9);
	tab[random]=2;
	
	podzial_tablicy(tab, 1, tab1, 3);
	podzial_tablicy(tab, 2, tab2, 3);	
	podzial_tablicy(tab, 3, tab3, 3);

	porownanie=wazenie_grup(tab1, tab2, 3);
	if(porownanie==1)
	{
		wazenie_kulek(tab3[0], tab3[1], 3);
	}
	else if(porownanie==2)
	{
		wazenie_kulek(tab2[0], tab2[1], 2);
	}
	else
	{
		wazenie_kulek(tab1[0], tab1[1], 1);
	}
	sprawdzenie(tab, 9);
	
	return 0;
}
