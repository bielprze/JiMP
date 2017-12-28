#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(char)*len);
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
		{
			printf("%c",napis[i]);
		}
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

int main(void){

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


