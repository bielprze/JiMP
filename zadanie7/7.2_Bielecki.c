/*
============================================================================
Name        : Zadanie 7.2
Author      : Przemysław Bielecki
============================================================================
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *inputString(FILE* fp, size_t size){
	char *napis;
	int ch;
	size_t dlugosc = 0;

	napis = realloc(NULL, sizeof(char)*size);
	if(!napis)
		return napis;
	while(EOF!=(ch=fgetc(fp)) && ch != '\n')
	{
        	napis[dlugosc++]=ch;
        	if(dlugosc==size)
		{
			napis = realloc(napis, sizeof(char)*(size+=16));
			if(!napis)
				return napis;
        	}
	}
	napis[dlugosc++]='\0';

	return realloc(napis, sizeof(char)*dlugosc);
}



void print_and_scan(char* napis, int tab[])
{
	int dlugosc = strlen(napis);
	int j=0;
	for(int i = 0; i<dlugosc; i++)
	{
		if(napis[i]=='%' && napis[i+1]=='d')
		{
			i++;
			scanf("%d",&tab[j]);
			j++;
       		}
		else
			printf("%c",napis[i]);
	}
	printf("\n");
}

int sprawdz_ilosc_argumentow(char* napis)
{
	int suma=0;
	int dlugosc = strlen(napis);
	for(int i=0; i<dlugosc; i++)
	{
		if(napis[i]=='%' && napis[i+1]=='d')
		{
			suma=suma+1;
		}
	}
	return suma;
}

int main(void)
{

	int suma;
	char* napis;
	printf("Podaj swoj napis, %%d gdzie ma być zmienna\n"); 

	napis=inputString(stdin, 10);	
	suma=sprawdz_ilosc_argumentow(napis);
	
	int *tablica_zmiennych;
	tablica_zmiennych=(int*)malloc(suma*sizeof(*tablica_zmiennych));

	print_and_scan(napis, tablica_zmiennych);
	
	free(napis);
	free(tablica_zmiennych);
	return 0;
}


