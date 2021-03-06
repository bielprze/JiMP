/*
 ============================================================================
 Name        : Zadanie 6.2
 Author      : Przemysław Bielecki
 ============================================================================
 */

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int czyPrzestepny(int rok)
{
    if ( (((rok%4) == 0) && rok % 100 != 0) || rok % 400 == 0)
        return 1;
    else
        return 0;
}


void wyswietlanie(int daycheck, int ilosc_dni)
{
	switch(daycheck)
	{
		case 1: 
		printf("MON TUE WED THU FRI SAT SUN\n");
		for(int i=0; i<ilosc_dni; i++)
		{	

			printf("%3d ", i+1);
			if((i%7)==6) 
				printf("\n");
		}
		break;

		case 2:

		printf("TUE WED THU FRI SAT SUN MON\n");
		for(int i=0; i<ilosc_dni; i++)
		{

			printf("%3d ", i+1);
			if((i%7)==6) 
				printf("\n");
		}
		break;

		case 3: 
		printf("WED THU FRI SAT SUN MON TUE\n");
		for(int i=0; i<ilosc_dni; i++)
		{
			printf("%3d ", i+1);
			if((i%7)==6)
				printf("\n");
		}
		break;

		case 4:
		printf("THU FRI SAT SUN MON TUE WED\n");
		for(int i=0; i<ilosc_dni; i++)
		{
			printf("%3d ", i+1);
			if((i%7)==6)
				printf("\n");
		}
		break;

		case 5: 
		printf("FRI SAT SUN MON TUE WED THU\n");
		for(int i=0; i<ilosc_dni; i++)
		{
			printf("%3d ", i+1);
			if((i%7)==6) 
				printf("\n");
		}
		break;

		case 6:
		printf("SAT SUN MON TUE WED THU FRI\n");
		for(int i=0; i<ilosc_dni; i++)
		{
			printf("%3d ", i+1);
			if((i%7)==6) 
				printf("\n");
		}
		break;


		case 0:
		printf("SUN MON TUE WED THU FRI SAT\n");
		for(int i=0; i<ilosc_dni; i++)
		{
			printf(" %d ", i+1);
			if((i%7)==6) 
				printf("\n");
		}
		break;
	}
	printf("\n");
}

int sprawdz_ilosc_dni(char month[], int rok)
{
	int ilosc_dni;
	
	switch(month[0])
	{
		case 'M':
			ilosc_dni=31;
		break;
		case 'J':
			if(month[30=='n'])
				ilosc_dni=30;
			else
				ilosc_dni=31;
		break;
		case 'A':
			if(month[1]=='u')
				ilosc_dni=31;
			else
				ilosc_dni=30;
		break;
		case 'O':
			ilosc_dni=31;
		break;
		case 'D':
			ilosc_dni=31;
		break;
		case 'F':
			if(czyPrzestepny(rok))
				ilosc_dni=29;
			else
				ilosc_dni=28;
		break;
		default:
			ilosc_dni=30;
			break;
	}

	return ilosc_dni;
}

int sprawdz_dzien(char day[])
{
	int dzien;

	if(day[0]=='M') 
		dzien=1; 
	if(day[0]=='T' && day[1]=='u') 
		dzien=2;
	if(day[0]=='W') 	
		dzien=3;
	if(day[0]=='T' && day[1]=='h')
		 dzien=4;
	if(day[0]=='F') 
		dzien=5;
	if(day[0]=='S' && day[1]=='a')
		dzien=6;
	if(day[0]=='S' && day[1]=='u') 
		dzien=0;

	return dzien;
}

int przesun_na_pierwszy_tydzien(int dday)
{
	while(1)
	{
		if(dday>7) 
			dday=dday-7;
		else 
			break;
	}
	return dday;
}
int sprawdz_dzien_tygodnia(int daycheck, int countcheck)
{
	while(1)
	{
		countcheck=countcheck-1;
		daycheck=daycheck-1;
		if(countcheck==1) 
			break;
	}
	return daycheck;
}

int operacja_wyznaczania_reszty_z_dzielenia(int a, int b)
{
    int r=a%b;
    return r<0?r+b:r;
}

void day_month_year(char tab[], char day[], char month[], char year[])
{
	time_t mytime;
	mytime = time(NULL);

	strcpy(tab,  ctime(&mytime));
	printf("%s\n", ctime(&mytime));
	strncpy(year, tab+20, 4);
	strncpy(day, tab, 3);
	strncpy(month, tab+4, 3);
}

int main() 
{
	char tab[25];	
	char year[4];
	char day[3];
	char month[3];
	
	day_month_year(tab, day, month, year);

	const int year_int=atoi(year);
	
	char day_number1[1], day_number2[1];
	day_number1[0]=tab[8];
	day_number2[0]=tab[9];
	day_number2[0]=day_number2[0];

	const int numer_dnia1=atoi(day_number1);
	
	const int dzien=sprawdz_dzien(day);
	const int ilosc_dni=sprawdz_ilosc_dni(month, year_int);
	
	int dday=numer_dnia1;
	dday=przesun_na_pierwszy_tydzien(dday);

	
	int daycheck=dzien;
	int countcheck=dday;
	
	daycheck=sprawdz_dzien_tygodnia(daycheck, countcheck);
	daycheck=operacja_wyznaczania_reszty_z_dzielenia(daycheck, 7);
	wyswietlanie(daycheck, ilosc_dni);

	return 0;
}
