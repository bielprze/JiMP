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

int mod(int a, int b)
{
    int r = a % b;
    return r < 0 ? r + b : r;
}

int main() {
	
	time_t mytime;
	mytime = time(NULL);
	char tab[25];
	strcpy(tab,  ctime(&mytime));
	printf("%s\n", ctime(&mytime));

	char month[3], day[3], day_number1[1], day_number2[1];
	int ilosc_dni;
	int numer_dnia1;
	int dzien;
	int flag=1;
	int dday;

	day[0]=tab[0];
	day[1]=tab[1];
	day[2]=tab[2];

	
	month[0]=tab[4];
	month[1]=tab[5];
	month[2]=tab[6];

	day_number1[0]=tab[8];
	day_number2[0]=tab[9];
	day_number2[0]=day_number2[0];

	numer_dnia1=atoi(day_number1);

	


	if(month[0]=='M' && month[1]=='a' && month[2]=='r') ilosc_dni=31;
	else	if(month[0]=='M' && month[1]=='a' && month[2]=='y') ilosc_dni=31;
		else	if(month[0]=='J' && month[1]=='u') ilosc_dni=31;
			else	if(month[0]=='A') ilosc_dni=31;
				else	if(month[0]=='O') ilosc_dni=31;
					else	if(month[0]=='D') ilosc_dni=31;
						else	if(month[0]=='J' && month[1]=='a') ilosc_dni=31;
							else ilosc_dni=30;

	if(day[0]=='M') dzien=1; 
	if(day[0]=='T' && day[1]=='u') dzien=2;
	if(day[0]=='W') dzien=3;
	if(day[0]=='T' && day[1]=='h') dzien=4;
	if(day[0]=='F') dzien=5;
	if(day[0]=='S' && day[1]=='a') dzien=6;
	if(day[0]=='S' && day[1]=='u') dzien=0;

	
	
	dday=numer_dnia1;


	while(flag)
	{
		if(dday>7) dday=dday-7;
		else flag=0;
	}


	int daycheck=dzien;
	int countcheck=dday;
	
	flag=1;
	while(flag)
	{
		countcheck=countcheck-1;
		daycheck=daycheck-1;
		if(countcheck==1) flag=0;
	}
	
	daycheck=mod(daycheck, 7);

	  
		switch(daycheck){
		case 1: 
		printf("MON TUE WED THU FRI SAT SUN\n");
		for(int i=0; i<ilosc_dni; i++)
		{	
			if(i<9) printf(" %d  ", i+1);
			else printf(" %d ", i+1);
			if((i%7)==6) printf("\n");
		}
		break;

		case 2:

		printf("TUE WED THU FRI SAT SUN MON\n");
		for(int i=0; i<ilosc_dni; i++)
		{
			if(i<9) printf(" %d  ", i+1);
			else printf(" %d ", i+1);
			if((i%7)==6) printf("\n");
		}
		break;

		case 3: 
		printf("WED THU FRI SAT SUN MON TUE\n");
		for(int i=0; i<ilosc_dni; i++)
		{
			if(i<9) printf(" %d  ", i+1);
			else printf(" %d ", i+1);
			if((i%7)==6) printf("\n");
		}
		break;

		case 4:
		printf("THU FRI SAT SUN MON TUE WED\n");
		for(int i=0; i<ilosc_dni; i++)
		{
			if(i<9) printf(" %d  ", i+1);
			else printf(" %d ", i+1);
			if((i%7)==6) printf("\n");
		}
		break;

		case 5: 
		printf("FRI SAT SUN MON TUE WED THU\n");
		for(int i=0; i<ilosc_dni; i++)
		{
			if(i<9) printf(" %d  ", i+1);
			else printf(" %d ", i+1);
			if((i%7)==6) printf("\n");
		}
		break;

		case 6:
		printf("SAT SUN MON TUE WED THU FRI\n");
		for(int i=0; i<ilosc_dni; i++)
		{
			if(i<9) printf(" %d  ", i+1);
			else printf(" %d ", i+1);
			if((i%7)==6) printf("\n");
		}
		break;


		case 0:
		printf("SUN MON TUE WED THU FRI SAT\n");
		for(int i=0; i<ilosc_dni; i++)
		{
			if(i<9) printf(" %d  ", i+1);
			else printf(" %d ", i+1);
			if((i%7)==6) printf("\n");
		}
		break;
		}
		printf("\n");

	return 0;
}
