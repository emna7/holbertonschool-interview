#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* is_palindrome - checks if a singly list is palindrome
* @head: double pointer to the head
* Return: 1 if palindrome, 0 otherwise
*/
int is_palindrome(listint_t **head)
{
int j = 0, i = 0, s;
listint_t *beg, *end;
if (!head)
return (0);
if (!(*head))
return (1);
end = *head;
beg = *head;
j += 1;
while (end->next)
{
end = end->next;
j++;
}
s = j / 2;
while (i <= s)
{
if (beg->n != end->n)
return (0);
beg += 2;
end -= 2;
i++;
}
return (1);
}
