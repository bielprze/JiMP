/*
 ============================================================================
 Name        : Zadanie 5.2
 Author      : Przemysław Bielecki
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypelnianie(int tab[3][3])
{
	srand(time(NULL));
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{	
			tab[i][j]=rand()%11;
			printf("%d ", tab[i][j]);
			
		}
	printf("\n");
	}
}

int wyznacznik(int tab[3][3])
{
	int det;	
	
	det=(tab[0][0]*tab[1][1]*tab[2][2])
	   +(tab[1][0]*tab[2][1]*tab[0][2])
           +(tab[2][0]*tab[0][1]*tab[1][2])
	   -(tab[2][0]*tab[1][1]*tab[0][2])
           -(tab[0][0]*tab[2][1]*tab[1][2])
	   -(tab[1][0]*tab[0][1]*tab[2][2]);

	return det;
}
