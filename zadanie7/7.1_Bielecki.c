#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void losowanie_tablicy(double tab[10]){
	
	srand(time(NULL));	
	for(int i=0; i<10; i++)
	{
		tab[i]=rand()%100;
	}
	tab[0]=1;
	tab[9]=1;
}

void wyswietlanie(double tab[10]) {

	for(int i=0; i<10; i++)
	{
		printf("%f ", tab[i]);
	}
	printf("\n");
}

double srednia(double* wsk1, double* wsk2) {
	
	double mean;
	int flag=1;

	double suma=0;
	double waga=0;
	int i=0;
	while(flag) {

	suma=suma+(*(wsk1+i)*i);
	waga=waga+i;
	if(&*(wsk1+i)==&*wsk2) flag=0;	
	i++;
	}

	mean=suma/waga;	
	
	return mean;
}


double* ost_el(const double* tab, int size){
	return (double*)(tab+(size-1));
}

int main() {

	double tab[10];
	double *wsk_a, *wsk_b;
	
	losowanie_tablicy(tab);

	//wyswietlanie(tab);

	wsk_a=tab;
	wsk_b=ost_el(tab, 10);

	printf("srednia wazona: %f\n", srednia(wsk_a, wsk_b));

	return 0;
}
