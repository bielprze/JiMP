#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main() {
	
	time_t mytime;
	mytime = time(NULL);
	char tab[25];
	strcpy(tab,  ctime(&mytime));
	//int rozmiar = sizeof(tab)/sizeof(char);
	printf("%s\n", ctime(&mytime));

	//printf("%c%c%c\n", tab[4],  tab[5], tab[6]);

	char month[3], day[3], day_number1[1], day_number2[1];

	day[0]=tab[0];
	day[1]=tab[1];
	day[2]=tab[2];

	
	month[0]=tab[4];
	month[1]=tab[5];
	month[2]=tab[6];

	day_number1[0]=tab[8];
	day_number2[0]=tab[9];

	
	printf("miesiąc: %c%c%c\n", month[0], month[1], month[2]);
	
	int ilosc_dni, numer_dnia1;

	numer_dnia1=atoi(day_number1);
	
	
	

	printf("numer dnia:%d\n",numer_dnia1);
	int dzien;

       	if(0==strcmp(month, "Mar") || 
	   0==strcmp(month, "May") ||
	   0==strcmp(month, "Jul") || 
           0==strcmp(month, "Aug") ||
           0==strcmp(month, "Oct") ||
           0==strcmp(month, "Dec") || 
           0==strcmp(month, "Jan")) ilosc_dni=31;
	else ilosc_dni=30;

	if(0==strcmp(day, "Mon")) dzien=1; 
	if(0==strcmp(day, "Tue")) dzien=2;
	if(0==strcmp(day, "Wed")) dzien=3; 
        if(0==strcmp(day, "Thu")) dzien=4;
        if(0==strcmp(day, "Fri")) dzien=5;
        if(0==strcmp(day, "Sat")) dzien=6;  
	else dzien=7;

	printf("dzien: %d\n", dzien);
	printf("ilosc dni miesiaca: %d\n", ilosc_dni);
	
	printf("MON TUE WED THU FRI SAT SUN\n");
	//
	int flag=1, dday=numer_dnia1;
	int calendar[42];

	
	/*
	            1  2  3
	4  5  6  7  8  9  10
	11 12 13 14 15 16 17
	18 19 20 21 22 23 24
	25 26 27 28 29 30 31
	*/
	while(flag)
	{
		if(dday>7) dday=dday-7;
		else flag=0;
	}
	printf("dday %d\n", dday);

	int daycheck=dzien;
	int countcheck=dday;
	
	flag=1;
	while(flag)
	{
		countcheck=countcheck-1;
		daycheck=daycheck-1;
		if(countcheck==1) flag=0;
	}
	printf("dzien %d\n", daycheck);

/*
	   
		switch(dday){
		case 1: 
		case 2:
		case 3: 
		case 4:
		case 5: 
		case 6:
		case 7:


	for(int i=0; i<ilosc_dni; i++)
	{
		calendar[
	}	
	*/
	return 0;
}
