/*
 ============================================================================
 Name        : Zadanie3_C.c
 Author      : Przemys³aw Bielecki
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

double kwadrat(double a)
{
	double pole;
	pole=a*a;
	return pole;
}

double prostokat(double a, double b)
{
	double pole;
	pole=a*b;
	return pole;
}

double trojkat(double a, double h)
{
	double pole;
	pole=0.5*a*h;
	return pole;
}

double kolo(double r)
{
	double pole;
	pole=3.1415*r*r;
	return pole;
}

double CelFah(double TempC, double TempF, int war)
{
	double TempK;
	switch (war) //1 - C->F, 2 - F->C
	{
	case 1:
		TempK=32+(9/5)*TempC;
		break;
	case 2:
		TempK=(5/9)*(TempF-32);
		break;
	default:
		break;
	}
	return TempK;
}

double DegRad(double Deg, double Rad, int war)
{
	double ang;
	switch (war) //1 - deg->rad, 2 - rad->deg
	{
	case 1:
		ang=Deg*(3.1415/180);
		break;
	case 2:
		ang=Rad*(180/3.1415);
		break;
	default:
		break;
	}
	return ang;
}


int main(void) {

	int war;
	int war2;
	int war3=1;

	double a, b;



	while(war3)
	{
	printf("Wybierz dzialanie:\n [1] - pole kwadratu\n [2] - pole prostokata\n [3] - pole trojkata\n [4] - pole kola\n [5] - przeliczanie stC/stF\n [6] - przeliczanie Deg/Rad\n [7] - wyjscie\n");
	scanf("%d", &war);
	switch(war)
	{
	case 1:
		printf("podaj dlugosc boku\n");
		scanf("%lf", &a);
		printf("pole wynosi: %lf\n", kwadrat(a));
		break;
	case 2:
		printf("podaj dlugosc bokow\n");
		scanf("%lf", &a);
		scanf("%lf", &b);
		printf("pole wynosi: %lf\n", prostokat(a,b));
		break;
	case 3:
		printf("podaj dlugosc podstawy i wysokosc\n");
		scanf("%lf", &a);
		scanf("%lf", &b);
		printf("pole wynosi: %lf\n", trojkat(a,b));
		break;
	case 4:
		printf("podaj promien\n");
		scanf("%lf", &a);
		printf("pole wynosi: %lf\n", kolo(a));
		break;
	case 5:
		
		printf("Co przeliczyc?\n [1] - Cel -> Fah\n [2] - Fah -> Cel\n");
		scanf("%d", &war2);
		printf("podaj temperature\n");
		scanf("%lf", &a);
		if(war2==1)
		{
			printf("Temperatura w stopniach Fahrenheita wynosi: %lf\n",CelFah(a, 0, 1));
		}
		if(war2==2)
		{
			printf("Temperatura w stopniach Celcjusza wynosi: %lf\n",CelFah(0, a, 2));
		}

		break;
	case 6:
		printf("Co przeliczyc?\n [1] - Deg -> Rad\n [2] - Rad -> Deg\n");
		scanf("%d", &war2);
		printf("podaj miare kata\n");
		scanf("%lf", &a);

		switch(war2)
		{
		case 1:
		printf("Kat w radianach wynosi: %lf\n",DegRad(a, 0, 1));
		break;
		case 2:
		printf("Kat w stopniach wynosi: %lf\n",DegRad(0, a, 2));
		break;
		}
		break;
	case 7:
		war3=0;
		break;
	default:
		break;
	}
	}

	return EXIT_SUCCESS;
}
