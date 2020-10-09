#include <stdio.h>
#include <stdlib.h>
#include "menger.h"
/**
* menger - function that draws a 2D menger sponge
* @level: level of menger sponge
* Return: nothing
*/
void menger (int level)
{
int size = 0;
int i = 0;
int j = 0;
int x = 0;
int y = 0;
char c;
size = pow(3, level);
while (i < size)
{
for (j = 0 ; j < size;)
{
c = '#';
x = i;
y = j++;
while (y > 0 || x > 0)
{
if (y % 3 == 1 && x % 3 == 1)
{
c = ' ';
}
x = x / 3;
y = y / 3;
}
printf("%c", c);
}
printf("\n");
i++;
}
}
