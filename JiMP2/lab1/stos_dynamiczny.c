#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 2147483647;

void push(int stack[], int *top, int el)
{
	stack[(*top)++] = el;
}

int pop(int stack[], int *top)
{
	return stack[--(*top)];
}

int czy_pelny(int *top, int size)
{
	return *top == size ? 1 : 0;
}

int czy_pusty(int *top)
{
	return *top == 0 ? 1 : 0;
}

void init(int *top)
{
	*top=0;
}

void wyswietl(int stack[], int *top)
{
	printf("Zawartosc stosu:\n");
	for(int i=0; i<*top; i++)
	{
		printf("%d\n", stack[i]);
	}
}

int main(void)
{
	int top, el;
	int *stack, *tmp;
	int temp_top=10;
	int counter=0;

	char war;

	stack = malloc(temp_top*sizeof(*stack));

	init(&top);
	printf("Dodawanie do stosu...\n");
	while(!czy_pelny(&top, MAX_SIZE))	
	{
		printf("Podaj liczbe na stos\n");
		scanf("%d", &el);
		
		push(stack, &top, el);
		counter++;
		printf("Na stosie: ");
		wyswietl(stack, &top);

		if(counter==temp_top)
		{
			temp_top=temp_top+10;
			tmp = realloc (stack, temp_top * sizeof(*stack));
			if(NULL!=tmp)
				stack=tmp;
			else
				return -1; 
		}

		if(temp_top==MAX_SIZE)
		{
			printf("stos jest pelen\n");
			break;
		}
		printf("Czy chcesz podac kolejna wartosc? [T/N]");
		scanf(" %c", &war);
		if(war=='N' || war=='n')
			break;
	}
	
	printf("Zdejmowanie ze stosu...\n");
	while(!czy_pusty(&top))	
	{
		el=pop(stack, &top);
		printf("Na stosie: ");
		wyswietl(stack, &top);
	}


	return 0;
}
