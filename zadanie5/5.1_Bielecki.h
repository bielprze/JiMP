
/*
 ============================================================================
 Name        : Zadanie 5.1
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include <stdio.h>

int porownanie (int godz1[], int godz2[], int tab_size)
{
	for(int i=0; i<tab_size; i++)
	{
		if(godz1[i]>godz2[i]) 
			return -1;
		else if(godz1[i]<godz2[i]) 
			return 1;		
	}
	return 0;
}

void wypelnianie(int tab[], int tab_size)
{
	for(int i=0; i<tab_size; i++)
	{
		scanf("%d", &tab[i]);
	}
}

int check(int godz1[])
{
	if(godz1[0]<0 || godz1[0]>2) 
	{
		printf("niepoprawna godzina, program zostanie zakonczony\n");
		return -1;
	}
	if(godz1[1]<0 || godz1[1]>3) 
	{
		printf("niepoprawna godzina, program zostanie zakonczony\n");
		return -1;
	}
	if(godz1[2]<0 || godz1[2]>6) 
	{
		printf("niepoprawna godzina, program zostanie zakonczony\n");
		return -1;
	}
	if(godz1[3]<0 || godz1[3]>9) 
	{
		printf("niepoprawna godzina, program zostanie zakonczony\n");
		return -1;
	}
	return 1;
}
