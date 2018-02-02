/*
============================================================================
Name        : Zadanie 7.3
Author      : Przemysław Bielecki
============================================================================
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void wypelnianie(int *tab_num, int tab_size)
{
	for(int i = 0; i < tab_size; ++i)	
	{
		*(tab_num+i) = rand()%50;
	}
	
}
void sortowanie_wskaznikow(int* tab_wsk[], int tab_size){
	for(int i = 0; i < tab_size; ++i)
	{
		int flag = 0;
		for(int j =0; j < tab_size-i-1;++j)
		{
			if(*tab_wsk[j]>*tab_wsk[j+1])
			{
				int* temp = tab_wsk[j+1];
				tab_wsk[j+1]=tab_wsk[j];
                		tab_wsk[j]=temp;
                		flag = 1;
                        }
        	}
        	if (flag == 0)
           		 break;
       	}
	
	for(int i = 0; i < tab_size; ++i)
   	     printf("%d ", *tab_wsk[i]);
    
	printf("\n");
}

void wsk_do_num(int tab_num[], int *tab_wsk[], int tab_size)
{
	for(int i = 0; i <tab_size; ++i)
	{
	        tab_wsk[i]=&tab_num[i];
	}
}

void wyswietlanie(int tab_num[], int tab_size)
{
	for(int i = 0; i < tab_size; ++i)	
	{
		printf("%d ", *(tab_num+i));
	}
	printf("\n");
}


int main(void)
{
	srand(time(NULL));

	int tab_num[10];
	int *tab_wsk[10];
	const int tab_size=sizeof(tab_num)/sizeof(tab_num[0]);	
	
	wypelnianie(tab_num, tab_size);	
	wsk_do_num(tab_num, tab_wsk, tab_size);
	sortowanie_wskaznikow(tab_wsk, tab_size);
	wyswietlanie(tab_num, tab_size);

	return 0;
}



