/*
 ============================================================================
 Name        : Zadanie3.c
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


#define PI 3.1415

double pole_kwadrat(double a)
{
	double pole;
	pole=a*a;
	return pole;
}

double pole_prostokat(double a, double b)
{
	double pole;
	pole=a*b;
	return pole;
}

double pole_trojkat(double a, double h)
{
	double pole;
	pole=0.5*a*h;
	return pole;
}

double pole_kolo(double r)
{
	double pole;
	pole=PI*r*r;
	return pole;
}

double CelFah(double TempC, double TempF, int war)
{
	double TempK;
	switch (war) //1 - C->F, 2 - F->C
	{
	case 1:
		TempK=32+1.8*TempC;
		break;
	case 2:
		TempK=0.56*(TempF-32);
		break;
	default:
		printf("Nie ma takiej opcji]n");
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

double obwod_prostokat(double a, double b)
{
	double obwod;
	obwod=2*a+2*b;
	return obwod;
}
double obwod_trojkat(double a, double b, double c)
{
	double obwod;
	obwod=a+b+c;
	return obwod;
}
double obwod_kolo(double promien)
{
	double obwod;
	obwod=2*promien*PI;
	return obwod;
}
int main(void) {

	int war;
	int war2;
	int war3=1;
	int flag=1;
	double a, b, c;



	while(war3)
	{
		printf("Wybierz dzialanie:\n [1] - pole kwadratu\n [2] - pole prostokata\n [3] - pole trojkata\n [4] - pole kola\n [5] - przeliczanie stC/stF\n [6] - przeliczanie Deg/Rad\n [7] - obwod kwadratu\n [8] - obwod prostokata\n[9] - obwod trojkata\n [10] - obwod kola [11] - wyjscie\n");
		scanf("%d", &war);
		switch(war)
		{
			case 1:
				while(flag)
				{
					printf("podaj dlugosc boku\n");
					scanf("%lf", &a);
					if(a>0) 
					{
						printf("pole wynosi: %lf\n", pole_kwadrat(a));
						flag=0;
					}
					else printf("Podaj dodatnią długość boku\n");
				}
				flag=1;
				break;
			case 2:
				while(flag)
				{	
					printf("podaj dlugosc bokow\n");
					scanf("%lf", &a);
					scanf("%lf", &b);
					if(a<0 || b<0) printf("Podaj dodatnią długość boku\n");
					else 
					{
						printf("pole wynosi: %lf\n", pole_prostokat(a,b));
						flag=0;
					}
				}
				flag=1;	
				break;
			case 3:
				while(flag)
				{
					printf("podaj dlugosc podstawy i wysokosc\n");
					scanf("%lf", &a);
					scanf("%lf", &b);
					if(a<0 || b<0) printf("Podaj dodatnią długość boku i wysokości\n");
					else
					{
						printf("pole wynosi: %lf\n", pole_trojkat(a,b));
						flag=0;
					}
				}
				flag=1;
				break;
			case 4:
				while(flag)
				{		
					printf("podaj promien\n");
					scanf("%lf", &a);
					if(a<0 ) printf("Podaj dodatni promien\n");
					else
					{
						printf("pole wynosi: %lf\n", pole_kolo(a));
						flag=0;
					}
				}		
				flag=1;
				break;
			case 5:
				printf("Co przeliczyc?\n [1] - Cel -> Fah\n [2] - Fah -> Cel\n");
				while(flag)
				{
					scanf("%d", &war2);
					if(war2==1 || war2==2)
					{
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
						flag=0;
					}
					else printf("Nie ma takie opcji\n");
				}
				flag=1;
				break;
			case 6:
				printf("Co przeliczyc?\n [1] - Deg -> Rad\n [2] - Rad -> Deg\n");
				while(flag)
				{	
					scanf("%d", &war2);
					if(war2==1 || war2==2)
					{
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
						flag=0;
					}
					else printf("Nie ma takie opcji\n");
				}
				flag=1;
				break;
			case 7:
				while(flag)
				{
					printf("podaj dlugosc boku\n");
					scanf("%lf", &a);
					if(a>0) 
					{
						printf("pole wynosi: %lf\n", obwod_prostokat(a, a));
						flag=0;
					}
					else printf("Podaj dodatnią długość boku\n");
				}
				flag=1;
				break;		
			case 8:
				while(flag)
				{
					printf("podaj dlugosc bokow\n");
					scanf("%lf", &a);
					scanf("%lf", &b);
					if(a>0 && b>0) 
					{
						printf("pole wynosi: %lf\n", obwod_prostokat(a, b));
						flag=0;
					}
					else printf("Podaj dodatnią długość bokow\n");
				}
				flag=1;
				break;	
			case 9:
				while(flag)
				{
					printf("podaj dlugosc bokow\n");
					scanf("%lf", &a);
					scanf("%lf", &b);
					scanf("%lf", &c);
					if(a>0 && b>0 && c>0) 
					{
						printf("pole wynosi: %lf\n", obwod_trojkat(a, b, c));
						flag=0;
					}
					else printf("Podaj dodatnią długość bokow\n");
				}
				flag=1;
				break;
			case 10:
				while(flag)
				{
					printf("podaj dlugosc boku\n");
					scanf("%lf", &a);
					if(a>0) 
					{
						printf("pole wynosi: %lf\n", obwod_kolo(a));
						flag=0;
					}
					else printf("Podaj dodatnią długość boku\n");
				}
				flag=1;
				break;		
			case 11:
				war3=0;
				break;
			default:
				printf("Brak opcji\n");
				break;
		}
	}
	return EXIT_SUCCESS;
}
