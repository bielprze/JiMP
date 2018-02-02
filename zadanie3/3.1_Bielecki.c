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
	double pole=a*a;
	return pole;
}

double pole_prostokat(double a, double b)
{
	double pole=a*b;
	return pole;
}

double pole_trojkat(double a, double h)
{
	double pole=0.5*a*h;;
	return pole;
}

double pole_kolo(double r)
{
	double pole=PI*r*r;
	return pole;
}

double celcius_to_fahrenheit(double tempC)
{
	double tempK=32+1.8*tempC;
	return tempK;
}

double fahrenheit_to_celcius(double tempF)
{
	double tempK=0.56*(tempF-32);
	return tempK;
}

double degrees_to_radians(double deg)
{
	double ang=deg*(PI/180);
	return ang;
}

double radians_to_degrees(double rad)
{
	double ang=rad*(180/PI);
	return ang;
}

double obwod_prostokat(double a, double b)
{
	double obwod=2*a+2*b;
	return obwod;
}

double obwod_trojkat(double a, double b, double c)
{
	double obwod=a+b+c;
	return obwod;
}

double obwod_kolo(double promien)
{
	double obwod=2*promien*PI;
	return obwod;
}

void wybor(int warunek)
{	
	int war2;
	int war;
	double a, b, c;

	while(warunek)
	{
		printf("Wybierz dzialanie:\n [1] - pole kwadratu\n [2] - pole prostokata\n [3] - pole trojkata\n [4] - pole kola\n [5] - przeliczanie stC/stF\n [6] - przeliczanie Deg/Rad\n [7] - obwod kwadratu\n [8] - obwod prostokata\n [9] - obwod trojkata\n [10] - obwod kola\n [11] - wyjscie\n");
		scanf("%d", &war);
		switch(war)
		{
			case 1:
				while(1)
				{
					printf("podaj dlugosc boku\n");
					scanf("%lf", &a);
					if(a>0) 
					{
						printf("pole wynosi: %lf\n", pole_kwadrat(a));
						break;
					}
					else printf("Podaj dodatnią długość boku\n");
				}
				break;
			case 2:
				while(1)
				{	
					printf("podaj dlugosc bokow\n");
					scanf("%lf", &a);
					scanf("%lf", &b);
					if(a<0 || b<0)
						printf("Podaj dodatnią długość boku\n");
					else 
					{
						printf("pole wynosi: %lf\n", pole_prostokat(a,b));
						break;
					}
				}
				break;
			case 3:
				while(1)
				{
					printf("podaj dlugosc podstawy i wysokosc\n");
					scanf("%lf", &a);
					scanf("%lf", &b);
					if(a<0 || b<0) 
						printf("Podaj dodatnią długość boku i wysokości\n");
					else
					{
						printf("pole wynosi: %lf\n", pole_trojkat(a,b));
						break;
					}
				}
				break;
			case 4:
				while(1)
				{		
					printf("podaj promien\n");
					scanf("%lf", &a);
					if(a<0 ) 
						printf("Podaj dodatni promien\n");
					else
					{
						printf("pole wynosi: %lf\n", pole_kolo(a));
						break;
					}
				}		
				break;
			case 5:
				printf("Co przeliczyc?\n [1] - Celcius -> Fahrenheit\n [2] - Fahrenheit -> Celcius\n");
				scanf("%d", &war2);

				if(war2==1 || war2==2)
				{
					printf("podaj temperature\n");
					scanf("%lf", &a);
					if(war2==1)
						printf("Temperatura w stopniach Fahrenheita wynosi: %lf\n", celcius_to_fahrenheit(a));
					if(war2==2)
						printf("Temperatura w stopniach Celcjusza wynosi: %lf\n", fahrenheit_to_celcius(a));			
				}
				else 
				{
					printf("Nie ma takie opcji, program zostanie zakonczony\n");
					exit(1);
				}
				break;
			case 6:
				printf("Co przeliczyc?\n [1] - Deg -> Rad\n [2] - Rad -> Deg\n");
				scanf("%d", &war2);

				if(war2==1 || war2==2)
				{
					printf("podaj miare kata\n");
					scanf("%lf", &a);
					switch(war2)
					{
						case 1:
							printf("Kat w radianach wynosi: %lf\n",degrees_to_radians(a));
						break;
						case 2:
							printf("Kat w stopniach wynosi: %lf\n",radians_to_degrees(a));
						break;
					}
				}
				else 
				{
					printf("Nie ma takie opcji, program zostanie zakonczony\n");
					exit(1);
				}
				break;
			case 7:
				while(1)
				{
					printf("podaj dlugosc boku\n");
					scanf("%lf", &a);
					if(a>0) 
					{
						printf("pole wynosi: %lf\n", obwod_prostokat(a, a));
						break;
					}
					else 
						printf("Podaj dodatnią długość boku\n");
				}
				break;		
			case 8:
				while(1)
				{
					printf("podaj dlugosc bokow\n");
					scanf("%lf", &a);
					scanf("%lf", &b);
					if(a>0 && b>0) 
					{
						printf("pole wynosi: %lf\n", obwod_prostokat(a, b));
						break;
					}
					else
						printf("Podaj dodatnią długość bokow\n");
				}
				break;	
			case 9:
				while(1)
				{
					printf("podaj dlugosc bokow\n");
					scanf("%lf", &a);
					scanf("%lf", &b);
					scanf("%lf", &c);
					if(a>0 && b>0 && c>0) 
					{
						printf("pole wynosi: %lf\n", obwod_trojkat(a, b, c));
						break;
					}
					else printf("Podaj dodatnią długość bokow\n");
				}
				break;
			case 10:
				while(1)
				{
					printf("podaj dlugosc boku\n");
					scanf("%lf", &a);
					if(a>0) 
					{
						printf("pole wynosi: %lf\n", obwod_kolo(a));
						break;
					}
					else printf("Podaj dodatnią długość boku\n");
				}
				break;		
			case 11:
				warunek=0;
				break;
			default:
				printf("Brak opcji\n");
				break;
		}
	}
}

int main(void) {
	wybor(1);
	return EXIT_SUCCESS;
}
