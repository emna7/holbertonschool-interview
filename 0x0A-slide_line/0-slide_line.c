#include <stdio.h>
#include "slide_line.h"

/**
* slide_line - function that slides and merges an array of integers
* @line: array of integers
* @size: size of integers
* @direction: direction to merge
* Return: 1 on success, 0 on failure
*/
int slide_line(int *line, size_t size, int direction)
{
size_t start = 1, pause = size, find = 0, rep = 0;
int flag = -1;
if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
{
return (0);
}
if (direction == SLIDE_RIGHT)
{
find = size - 1;
rep = size - 1;
start = -1;
pause = -1;
}
while (find != pause)
{
if (*(line + find) != 0)
{
if (flag == *(line + find))
{
*(line + find) += flag;
flag = -1;
}
else
{
flag = *(line + find);
if ((direction == SLIDE_LEFT && find != 0)
||
((direction == SLIDE_RIGHT && find != (size - 1))))
if (*(line + rep) != 0)
rep += start;
}
*(line + rep) = *(line + find);
if (rep != find)
*(line + find) = 0;
} find += start;
}
return (1);
}
