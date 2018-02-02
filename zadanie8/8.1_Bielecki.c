#include <stdio.h>
#include <stdlib.h>

void kontrola(int *tab, int ilosc_liczb)
{
    if(NULL==tab)
    {
	printf("bledna liczba liczb\n");
	exit(1);
    }
    if(ilosc_liczb<1)
    {
	printf("bledna liczba liczb\n");
	exit(1);
    }
}	

int wpisywanie_liczb(int *tab, int ilosc_liczb)
{
    for(int i = 0; i < ilosc_liczb; i++)
    {
        if(scanf("%d", &tab[i]) == EOF)
        {
            if(i == 0)
                exit(0);
           
            ilosc_liczb = i;
            break;
        }
    }
    return ilosc_liczb;
}

int compare(const void * a, const void * b)
{
    if ( *(int*)a <  *(int*)b )
	return -1;
    else if ( *(int*)a == *(int*)b )
	return 0;
    else 
	return 1;
}

int suma_liczb(int *tab, int ilosc_liczb)
{
    int suma=0;
    for(int i=0; i<ilosc_liczb; i++)
    {
        suma = suma+tab[i];
    }
    return suma;
}

double mediana_liczb(int *tab, int ilosc_liczb)
{
    if(ilosc_liczb % 2 == 0){
        return ((double)tab[ilosc_liczb / 2] + (double)tab[(ilosc_liczb/2)+1]) / 2;
    }
    else
    {
        return (double)tab[(ilosc_liczb+1)/2];
    }
}

int dominanta_liczb(int *tab, int ilosc_liczb)
{
    int dominanta, temp;
    int counter=0;
    int max_counter=0;

    for(int i=0; i<ilosc_liczb; i++)
    {
	if(temp!=tab[i])
	{
    	    temp=tab[i];
	    counter=1;
	}
	else
	{
	    counter++;
	}
	if (counter > max_counter)
	{
	    max_counter = counter;
	    dominanta = tab[i];
	}
    }

    return dominanta;
}

int main(void)
{

    printf("Podaj ile liczb chcesz wpisac: ");
    int ilosc_liczb;
    scanf("%d", &ilosc_liczb);

    int *tab;
    tab = (int*)malloc(ilosc_liczb*sizeof(int));

    kontrola(tab, ilosc_liczb);

    printf("Podaj elementy tablicy: ");
    wpisywanie_liczb(tab, ilosc_liczb);
    //obliczenia(tab, ilosc_liczb);
    qsort(tab, ilosc_liczb, sizeof(int), compare);
    int suma = suma_liczb(tab, ilosc_liczb);
    double mean=(double)suma/(double)ilosc_liczb;
    double mediana = mediana_liczb(tab, ilosc_liczb);
    int dominanta = dominanta_liczb(tab, ilosc_liczb);    

    printf("Suma %d %o %X\n", suma, suma, suma);
    printf("Srednia %0.2f %A\n", mean, mean);
    printf("Mediana %0.2f %A\n", mediana, mediana);
    printf("Dominanta %d %o %X\n", dominanta, dominanta, dominanta);
   
    return 0;
}



