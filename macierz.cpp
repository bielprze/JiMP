#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>

using namespace std;

class Macierz {

  public:

	int n;
	int m;
	float *matrix;

	Macierz();
	Macierz(int N, int M);
	void wypelnij();
	void display();
	~Macierz()
	{
		cout<<"Adres: "<<(void*)matrix<<endl;
		delete []matrix;
	}



	Macierz& operator=(const Macierz& C)
	{
		n=C.n;
		m=C.m;
		delete[] matrix;		
		matrix = new float [n*m];
		memcpy(matrix, C.matrix, n*m*sizeof(float));
		return *this;
	}


	Macierz (const Macierz& C): n(C.n), m(C.m)
	{
		matrix=new float[n*m];
		memcpy(matrix, C.matrix, n*m*sizeof(float));
	}


	Macierz operator+(Macierz B)
	{
		Macierz suma(n, m);
	
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				suma.matrix[i*m+j] = matrix[i*m+j] + B.matrix[i*m+j];
		return suma;
	}

	Macierz operator-(Macierz B)
	{
		Macierz roznica(n, m);
	
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				roznica.matrix[i*m+j] = matrix[i*m+j] - B.matrix[i*m+j];
		return roznica;
	}
	
	Macierz operator*(float liczba)
	{
		Macierz iloczyn(n, m);
	
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				iloczyn.matrix[i*m+j] = matrix[i*m+j] * liczba;
		return iloczyn;
	}

	Macierz operator/(float liczba)
	{
		Macierz iloraz(n, m);
	
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				iloraz.matrix[i*m+j] = matrix[i*m+j] / liczba;
		return iloraz;
	}
/*
	int operator==(Macierz B)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(matrix[i*m+j] != B.matrix[i*m+j])
					return -1;
		return 1;
		
	}*/
};

Macierz::Macierz(int N, int M)
{
	matrix = new float[N*M];
	n=N;
	m=M;
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			matrix[i*m+j] = 1;
}

void Macierz::wypelnij()
{
	float a;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%f", &a);
			matrix[i*m+j] = a;
		}
	}
}

void Macierz::display()
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			printf("%f ", matrix[i*m+j]);
		printf("\n");	
	}
}

int main()
{
	{
		Macierz m1(3,3), m2(3,3), m3(3,3);
		Macierz mw(3,3);
		m1.wypelnij();
		m2.wypelnij();
		mw=m1+m2;
	}
	
	int n, m;
	float c;
	printf("podaj wymiary nxm\n");
	scanf("%d", &n);
	scanf("%d", &m);
	Macierz A(n,m);
	Macierz B(n,m);
	Macierz M_test(n,m);
	
	printf("wypelnij macierz A\n");
	A.wypelnij();
	printf("wypelnij macierz B\n");
	B.wypelnij();
	M_test=A+B;

	printf("suma:\n");
	M_test.display();

	M_test = A-B;
	printf("roznica:\n");
	M_test.display();

	printf("podaj liczbe\n");
	scanf("%f", &c);

	printf("dzielenie przez podana liczbe:\n");
	M_test = A/c;
	M_test.display();

	printf("mnozenie przez podana liczbe:\n");
	M_test = A*c;
	M_test.display();

	//if(A==B)
	//	printf("macierze A i B sa rowne\n");
	//else
	//	printf("macierze A i B sa rozne\n");



	return 0;
}
