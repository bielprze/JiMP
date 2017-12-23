#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void losowanie_tablicy(int tab[10]){
	
	srand(time(NULL));	
	for(int i=0; i<10; i++)
	{
		tab[i]=rand()%100;
	}
}

void wyswietlanie(int tab[10]) {

	for(int i=0; i<10; i++)
	{
		printf("%d ", tab[i]);
	}
	printf("\n");
}

double srednia(int tab[10]) {
	
	int suma=0;
	for(int i=0; i<10; i++)
	{
		suma=suma+tab[i];
	}
	return suma/10;
}	

void bubblesort(int tab[10]){

	int temp;
	for (int c = 0 ; c < ( 10 - 1 ); c++)
 	{
		for (int d = 0 ; d < 10 - c - 1; d++)
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

double mediana(int tab[10]){
	
	bubblesort(tab);
	return (tab[4]+tab[5])/2;
}
void maks_i_min(int tab[10]){
	bubblesort(tab);
	printf("Wartość maks to: %d , wartość min to: %d\n", tab[9], tab[0]);
}

int main(){

	int tab[10];
	
	
	int warunek1=1;
	int warunek2;
	int warunek3=0;

	while(warunek1 == 1)
	{	
		printf("Powiedz, co chcesz zrobić:\n [1] Wypełnij tablicę liczbami losowymi\n [2] Wyświetl tablicę\n [3] Oblicz średnią liczb\n [4] Oblicz medianę liczb\n [5] Maksymalny i minimalny element\n [6] wyjście\n");
		scanf("%d",&warunek2);
	
		switch(warunek2){
		case 1: 
			losowanie_tablicy(tab);
			warunek3=1;
			break;
		case 2:
			if(warunek3==1) wyswietlanie(tab);
			else printf("Nie wypełnino tablicy!\n");
			break;
		case 3: 
			if(warunek3==1) srednia(tab);
			else printf("Nie wypełnino tablicy!\n");
			break;
		case 4:
			if(warunek3==1) mediana(tab);
			else printf("Nie wypełnino tablicy!\n");
			break;
		case 5: 
			if(warunek3==1) maks_i_min(tab);
			else printf("Nie wypełnino tablicy!\n");
			break;
		case 6:
			warunek1=0;
			break;
		}
	}
		
		

	return 0;
}
