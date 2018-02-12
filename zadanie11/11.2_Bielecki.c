#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int compare(const void * a, const void * b)
{
    if ( *(int*)a <  *(int*)b )
	return -1;
    else if ( *(int*)a == *(int*)b )
	return 0;
    else 
	return 1;
}

void kontrola_pliku(FILE* f)
{
    if(NULL==f)
	{
		printf("Nie udalo sie otworzyc pliku\n");
		exit(1);
	}
}

int ilosc_linii(FILE* myfile)
{
	int ch, number_of_lines=0;

	do
	{
		ch = fgetc(myfile);
		if(ch == '\n')
	        number_of_lines++;
	} while (ch != EOF);

	return number_of_lines;
}

void read_ints (const char* file_name, int data[]) 
{
	FILE* file = fopen (file_name, "r");
	kontrola_pliku(file);

	int i = 0;

	fscanf (file, "%d", &data[i]);
	while (!feof (file))
	{	
		i++;
    		fscanf (file, "%d", &data[i]);
	}

	fclose (file);
}
void wyswietlanie(int tab[], int number_of_lines)
{
	for(int i=0; i<number_of_lines; i++)
	{
		printf("%d\n", tab[i]);
	}
}

void array_to_file(int tab[], char* name, int number_of_lines)
{
	FILE* file=fopen(name, "w");
	kontrola_pliku(file);
	for(int i=0; i<number_of_lines; i++)
	{
		fprintf(file, "%d\n", tab[i]);
	}
	fclose(file);
}

int main(int argc, char *argv[])
{
	if(argc<2 || argc>3)
	{
		printf("zla liczba argumentow\n");
		exit(1);
	}
	
	FILE* f = fopen(argv[1], "r");
	kontrola_pliku(f);
	int number_of_lines=ilosc_linii(f);

	int *tab;
	tab=(int*)malloc(number_of_lines* sizeof(*tab)+1); 

	read_ints(argv[1], tab);	
	qsort(tab, number_of_lines, sizeof(int), compare);	

	if(argc==2)
	{
		wyswietlanie(tab, number_of_lines);
	}
	else
	{
		array_to_file(tab, argv[2], number_of_lines);
	}

	return 0;
}
