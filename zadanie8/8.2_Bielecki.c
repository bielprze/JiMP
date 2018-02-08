#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

enum ArgumentType {CHAR, CHARP, INT, DOUBLE};

void wyswietl_char(const void* argument, const unsigned width)
{
	char arg = *(char*)argument;
	if (!(isprint(arg)))
        	printf("\n");
    
	else
	{
        	if(width % 2 == 1)
           		printf("%*c%c\n", (width-1) / 2, ' ', arg);
        
        	else
        		printf("%*c%c\n", (width/2-1), ' ', arg);
    	}
}

void wyswietl_charp(const void* argument, const unsigned width)
{
	char *arg = *(char**)argument;
	unsigned length = strlen(arg);
	if (arg==NULL)
        	printf("\n");
        else if(length>=width)
		printf("%s\n", arg);
	else
	{
        	if((width-strlen(arg))% 2 == 1)
            		printf("%*c%s\n",(width-length-1)/2,' ', arg);
        
        	else
        		printf("%*c%s\n",((width-length)/2),' ', arg);
    	}
}

void wyswietl_int(const void* argument, const unsigned width)
{
	char tab[100];
	unsigned length = strlen(tab);
	snprintf(tab, 100, "%d", *(int*)argument);
	if(length >= width)
        	printf("%s\n", tab);
	else if((width-length) % 2 == 1)
      		printf("%*c%s\n", (width-length-1)/2, ' ', tab);
	else
        	printf("%*c%s\n", ((width-length) / 2), ' ', tab);
    
}

void wyswietl_double(const void* argument, const unsigned width)
{
	char tab[100];
	snprintf(tab,100,"%f", *(double*)argument);
	unsigned length = strlen(tab);
	unsigned po_przecinku = 2;
	for(unsigned i = 1; i <=length; i++)
	{
        	if(tab[i]=='.')
		{
        		length=i+3;
        		if(tab[i+1]=='0')
			{
        	        	if(tab[i+2]=='0')
				{
        	        		po_przecinku = 0;
        	        		length=i+1;
        	        	}
	
        	    	}
        		else if(tab[i+2]=='0')
			{
        	            po_przecinku = 1;
        	            length=i+2;
        	        }
        		break;
         	}
	}
        
 	if(po_przecinku>=width)
 	{
        	printf("%.*f\n",po_przecinku ,*(double*)argument);
	}
	else if((width-length)%2 == 1){
        	printf("%*c%.*f\n",(width-length-1)/2,' ',po_przecinku,*(double*)argument);
	}
	else
	{
	        printf("%*c%.*f\n",((width-length)/2),' ',po_przecinku,*(double*)argument);
	}
}

void printArgumentInTheMiddle(enum ArgumentType typ, void *argument, unsigned width)
{
	if(!argument)
		printf("\n");

	if(typ == CHAR)
        	wyswietl_char(argument, width);
    
	else if(typ == CHARP)
        	wyswietl_charp(argument, width);
    
	else if(typ == INT)
        	wyswietl_int(argument, width);
    
	else if(typ == DOUBLE)
       		wyswietl_double(argument, width);
}

char *inputString(FILE* fp, size_t size)
{
	char *napis;
	int ch;
	size_t dlugosc = 0;

	napis = realloc(NULL, sizeof(char)*size);
	if(!napis)
		return napis;
	while(EOF!=(ch=fgetc(fp)) && ch != '\n')
	{
        	napis[dlugosc++]=ch;
        	if(dlugosc==size)
		{
			napis = realloc(napis, sizeof(char)*(size+=16));
			if(!napis)
				return napis;
        	}
	}
	napis[dlugosc++]='\0';

	return realloc(napis, sizeof(char)*dlugosc);
}

int main()
{
	unsigned width = 20;
	char* napis;
	printf("Podaj swoja zmienna *char\n"); 
	napis=inputString(stdin, 10); 

	printf("Podaj swoja zmienna char\n");
	char zmienna_char;
	scanf("%c", &zmienna_char);

	printf("Podaj swoja zmienna int\n");
	int zmienna_int;
	scanf("%d", &zmienna_int);

	printf("Podaj swoja zmienna double\n");
	double zmienna_double;
	scanf("%lf", &zmienna_double);

	void *argument=&napis;
	printArgumentInTheMiddle(CHARP,argument,width);

	argument = &zmienna_int;
	printArgumentInTheMiddle(INT,argument,width);

	argument = &zmienna_char;
	printArgumentInTheMiddle(CHAR,argument,width);

	argument = &zmienna_double;
	printArgumentInTheMiddle(DOUBLE,argument,width);
	return 0;
}
