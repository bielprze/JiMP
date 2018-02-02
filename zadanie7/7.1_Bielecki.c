/*
 ============================================================================
 Name        : Zadanie 7.1
 Author      : Przemysław Bielecki
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanie_tablicy(int tab_size, double tab[tab_size])
{	
	srand(time(NULL));	
	for(int i=0; i<tab_size; i++)
	{
		tab[i]=rand()%100;
	}
	tab[0]=1;
	tab[9]=1;
}

void wyswietlanie(int tab_size, double tab[tab_size])
{
	for(int i=0; i<tab_size; i++)
	{
		printf("%f ", tab[i]);
	}
	printf("\n");
}

double srednia(double* wsk1, double* wsk2) 
{	
	int flag=1;
	double suma=0;
	double waga=0;
	int i=0;

	while(flag) 
	{
		suma=suma+(*(wsk1+i)*i);
		waga=waga+i;
		if(&*(wsk1+i)==&*wsk2) 
			flag=0;	
		i++;
	}

	return suma/waga;
}


double* ostatni_element(const double* tab, int size)
{
	return (double*)(tab+(size-1));
}

int main() 
{
	double tab[10];
	double *wsk_a, *wsk_b;
	int tab_size=sizeof(tab)/sizeof(tab[0]);
	
	losowanie_tablicy(tab, tab_size);

	wsk_a=tab;
	wsk_b=ostatni_element(tab, tab_size);

	printf("srednia wazona: %f\n", srednia(wsk_a, wsk_b));

	return 0;
}
