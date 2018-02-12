#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_numbers(char* nazwa_pliku, int ilosc_liczb)
{
	FILE* f=fopen(nazwa_pliku, "w");
	if(NULL==f)
	{
		printf("Nie udalo sie otworzyc pliku\n");
		exit(1);
	}
	for(int i=0; i<ilosc_liczb; i++)
	{
		fprintf(f, "%d\n", rand()%1001);
	}
	fclose(f);
}	

void kontrola_argumentow(int argc, char *argv[])
{
	if(argc!=3)
	{
		printf("za malo argumentow\n");
		exit(1);
	}
	if(atoi(argv[1])<=0)
	{
		printf("ilosc liczb mniejsza od 0\n");
		exit(1);
	}
}
int main(int argc, char *argv[])
{
	srand(time(NULL));
	kontrola_argumentow(argc, argv);
	generate_numbers(argv[2], atoi(argv[1]));
	
	return 0;
}
