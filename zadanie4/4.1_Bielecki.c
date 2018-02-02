/*
 ============================================================================
 Name        : Zadani 4.1
 Author      : Przemysław Bielecki
 ============================================================================
 */
//Aby skompilować proszę użyć następującej komendy: gcc 4.1_Bielecki.c  -Wall -pedantic -Wextra -Werror -lm

#include <stdio.h>
#include <math.h>

struct Pierwiastek
{
	double pierwiastek1;
	double pierwiastek2;
};

double licz_delta(double a, double b, double c)
{
	double delta = b*b-4*a*c;
	return delta;
}

struct Pierwiastek licz_pierwiastki(double a, double b, double delta)
{	
	struct Pierwiastek x;
	x.pierwiastek1=(-1*b-sqrt(delta))/2*a;
	x.pierwiastek2=(-1*b+sqrt(delta))/2*a;

	return x;
}

int main()
{	
	double a, b, c, wartosc_delta;
	while(1)
	{
		printf("Podaj wspolczynniki rownania\n");
		scanf("%lf", &a);
		scanf("%lf", &b);
		scanf("%lf", &c);	
		if(a==0) 
			printf("Rownanie nie jest kwadratowe\n");
		else break;		
	}

	wartosc_delta=licz_delta(a, b, c);

	if(wartosc_delta<0)
		printf("Brak pierwiastkow rzeczywistych\n");
	else
	{	
		struct Pierwiastek x;
		x=licz_pierwiastki(wartosc_delta, a, b);
		if(x.pierwiastek1==x.pierwiastek2)
			printf("delta 0, jest jeden podwójny pierwiastek: %lf\n", x.pierwiastek1);
		else
			printf("pierwiastki to: %lf, %lf\n", x.pierwiastek1, x.pierwiastek2);
	}	
	return 0;
}
