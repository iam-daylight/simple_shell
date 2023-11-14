#include <stdio.h>

/*
 * factorial - calculate the factorial of a non-negative integer.
 * @n: number to print
 * Return: store
 */
int factorial(int n)
{
	int store = 1;
	int v = 1;

	while (v <= n)
	{
		store = store * v;
		v++;
	}
		return (store);
}

/*
 * main - main function of the program
 * @a: argument to take
 */
int main(void)
{
	int a;

	a = factorial(5);
	printf("The factorial of 5 is %d\n", a);

}
