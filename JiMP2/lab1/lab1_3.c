#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
    float _a = *(float*)a;
    float _b = *(float*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}

void wypelnij(float tab[], int tab_size)
{
	float temp;
	for(int i=0; i<tab_size; i++)
	{
		printf("podaj liczbe:\n");
		scanf("%f", &temp);
		tab[i]=temp;
	}
}



int main(void)
{
	float tab[8];
	int tab_size=sizeof(tab)/sizeof(tab[0]);

	wypelnij(tab, tab_size);
	qsort(tab, tab_size, sizeof(float), compare);

	printf("Najwieksza z podanych liczb to: %f\n", tab[7]);
	
	return 0;
}
