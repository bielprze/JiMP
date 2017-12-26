
/*
 ============================================================================
 Name        : Zadanie 5.1
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include <stdio.h>

int porownanie (int godz1[], int godz2[])
{
	for(int i=0; i<4; i++)
	{
		if(godz1[i]>godz2[i]) return -1;
		else if(godz1[i]<godz2[i]) return 1;		
	}
	return 0;
}

void wypelnianie(int tab[])
{
	for(int i=0; i<4; i++)
	{
		scanf("%d", &tab[i]);
	}
}

int check(int godz1[])
{
	if(godz1[0]<0 || godz1[0]>2) 
	{
		printf("niepoprawna godzina\n");
		return -1;
	}
	if(godz1[1]<0 || godz1[1]>6) 
	{
		printf("niepoprawna godzina\n");
		return -1;
	}
	if(godz1[2]<0 || godz1[2]>6) 
	{
		printf("niepoprawna godzina\n");
		return -1;
	}
	if(godz1[3]<0 || godz1[3]>6) 
	{
		printf("niepoprawna godzina\n");
		return -1;
	}
	return 1;
}
