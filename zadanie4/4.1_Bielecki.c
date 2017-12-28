/*
 ============================================================================
 Name        : Zadani 4.1
 Author      : Przemysław Bielecki
 ============================================================================
 */
//Aby skompilować proszę użyć następującej komendy: gcc 4.1_Bielecki.c  -Wall -pedantic -Wextra -Werror -lm

#include <stdio.h>
#include <math.h>

struct pierwiastki
{
	double pierwiastek1;
	double pierwiastek2;
};

double delta(double a, double b, double c)
{
	double delta;
	delta = b*b-4*a*c;
	return delta;
}

struct pierwiastki licz_pierwiastki(double delta,double a, double b)
{	
	struct pierwiastki x;
	x.pierwiastek1=(-1*b-sqrt(delta))/2*a;
	x.pierwiastek2=(-1*b+sqrt(delta))/2*a;

	return x;
}

int main()
{	
	int flag=1;
	double a, b, c, delta2;
	while(flag)
	{
		printf("Podaj wspolczynniki rownania\n");
		scanf("%lf", &a);
		scanf("%lf", &b);
		scanf("%lf", &c);	
		if(a==0) printf("Rownanie nie jest kwadratowe\n");
		else flag=0;		
	}
	delta2=delta(a, b, c);
	if(delta<0) printf("Brak pierwiastkow rzeczywistych\n");
	else
	{	
		struct pierwiastki x;
		x=licz_pierwiastki(delta2, a, b);
		printf("pierwiastki to: %lf, %lf\n", x.pierwiastek1, x.pierwiastek2);
	}	
	return 0;
}
