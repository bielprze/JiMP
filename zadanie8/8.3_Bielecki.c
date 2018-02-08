#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long copy_to_char_and_do_the_rest(void* data, size_t size)
{
	long long suma = 0;
	char *tab;

	tab=(char*)malloc(size);

	memcpy(tab,data,size);

	int tab_size = size/sizeof(tab[0]);

	for(int i = 0; i < tab_size; i++)
	{
        	printf("%x ",tab[i]);
        	suma = suma + tab[i];
	}
	printf("\n");

	printf("suma: %lld", suma);
	printf("\n");
	return suma;
}

int main()
{
	char tab[8] = "abcdefgh";
	void *arg = &tab;
	copy_to_char_and_do_the_rest(arg,sizeof(tab));


	char zmienna_char = 'a';
	void *arg_ch = &zmienna_char;
	copy_to_char_and_do_the_rest(arg_ch, sizeof(zmienna_char));


    	int zmienna_int = 23;
	void *arg_i = &zmienna_int;
	copy_to_char_and_do_the_rest(arg_i,sizeof(zmienna_int));

    	float zmienna_float = 23.44;
	void *arg_f = &zmienna_float;
   	copy_to_char_and_do_the_rest(arg_f,sizeof(zmienna_float));
	
	return 0;
}
