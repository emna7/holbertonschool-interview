#include "holberton.h"
/**
* _strlen - returns the len of a string
* @s: string
* Return: the length
**/
int _strlen(char *s)
{
char *c = s;
while (*s)
s++;
return (s - c);
}

/**
 * is_digit - checks if the arg is a number
 * @c: argument
 *
 * Return: false or true
 **/
int is_digit(char *c)
{
	while (*c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

/**
 * multiply - multiplies two numbers
 * @a: first "number"
 * @b: second "number"
 **/
void multiply(char *a, char *b)
{
	int i, len_a, len_b, total, a_number, b_number, res = 0, tmp;
	int *ptr;

	len_a = _strlen(a);
	len_b = _strlen(b);
	tmp = len_b;
	total = len_a + len_b;
	ptr = malloc(sizeof(int) * total);
	if (!ptr)
	{
		return;
	}
	for (len_a--; len_a >= 0; len_a--)
	{
		a_number = a[len_a] - '0';
		res = 0;
		len_b = tmp;
		for (len_b--; len_b >= 0; len_b--)
		{
			b_number = b[len_b] - '0';
			res += ptr[len_b + len_a + 1] + (a_number * b_number);
			ptr[len_a + len_b + 1] = res % 10;
			res /= 10;
		}
		if (res)
			ptr[len_a + len_b + 1] = res % 10;
	}
	while (*ptr == 0)
	{
		ptr++;
		total--;
	}
	for (i = 0; i < total; i++)
		printf("%i", ptr[i]);
	printf("\n");
}

/**
 * main - multiplies two numbers
 * @argc: argument count
 * @argv: argument vectors
 *
 * Return: 0
 **/
int main(int argc, char *argv[])
{
	char *a = argv[1];
	char *b = argv[2];

	if (argc != 3 || !is_digit(a) || !is_digit(b))
	{
		printf("Error\n");
		exit(98);
	}
	multiply(a, b);
	return (0);
}
