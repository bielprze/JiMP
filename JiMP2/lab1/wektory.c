#include <stdio.h>
#include <math.h>

typedef struct Wektor {
	float x;
	float y;
	float z;
}Wektor;

Wektor dodawanie(Wektor A, Wektor B)
{
	Wektor suma;
	suma.x=A.x+B.x;
	suma.y=A.y+B.y;
	suma.z=A.z+B.z;
	return suma;
}

Wektor mnozenie_skalar(Wektor A, float skalar)
{
	Wektor iloczyn_sk;
	iloczyn_sk.x=A.x*skalar;
	iloczyn_sk.y=A.y*skalar;
	iloczyn_sk.z=A.z*skalar;

	return iloczyn_sk;
}

Wektor iloczyn_wektorowy(Wektor A, Wektor B)
{
	Wektor iloczyn_w;

	iloczyn_w.x=(A.y*B.z)-(B.y*A.z);
	iloczyn_w.y=(A.z*B.x)-(A.x*B.z);
	iloczyn_w.z=(A.x*B.y)-(B.x*A.y);

	return iloczyn_w;
}

Wektor normalizacja(Wektor A)
{
	Wektor znormalizowany;

	znormalizowany.x=A.x/(sqrt(A.x*A.x+A.y*A.y+A.z*A.z));
	znormalizowany.y=A.y/(sqrt(A.x*A.x+A.y*A.y+A.z*A.z));
	znormalizowany.z=A.z/(sqrt(A.x*A.x+A.y*A.y+A.z*A.z));

	return znormalizowany;
}

float iloczyn_skalarny(Wektor A, Wektor B)
{
	float iloczyn_skalarny=A.x*B.x+A.y*B.y+A.z*B.z;
	return iloczyn_skalarny;
}

void porownanie(Wektor A, Wektor B)
{
	if(A.x==B.x && A.y==B.y && A.z==B.z)
		printf("Wektory A i B sa rowne\n");
	else
		printf("Wektory A i B nie sa rowne\n");
}

int main(void)
{
	Wektor A, B, wektor_testowy;

	printf("Podaj wspolrzedne wektora A\n");
	scanf("%f", &A.x);
	scanf("%f", &A.y);
	scanf("%f", &A.z);

	printf("Podaj wspolrzedne wektora B\n");
	scanf("%f", &B.x);
	scanf("%f", &B.y);
	scanf("%f", &B.z);

	wektor_testowy = dodawanie(A, B);
	printf("Suma wektorow A i B wynosi [%f, %f, %f]\n", wektor_testowy.x, wektor_testowy.y, wektor_testowy.z);

	float skalar = 3.5;

	wektor_testowy = mnozenie_skalar(A, skalar);
	printf("Wektor A pomnozony przez skalar %f wynosi [%f, %f, %f]\n",skalar, wektor_testowy.x, wektor_testowy.y, wektor_testowy.z);

	wektor_testowy = iloczyn_wektorowy(A, B);
	printf("Iloczyn wektorowy wektorow A i B to [%f, %f, %f]\n", wektor_testowy.x, wektor_testowy.y, wektor_testowy.z);

	float suma_sk = iloczyn_skalarny(A, B);
	printf("iloczyn skalarny wektorow A i B to %f\n", suma_sk);

	wektor_testowy = normalizacja(A);
	printf("Znormalizowany wektor A to [%f, %f, %f]\n", wektor_testowy.x, wektor_testowy.y, wektor_testowy.z);

	porownanie(A, B);
	return 0;
}
