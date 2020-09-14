#include "lists.h"
/**
* check_cycle - functoin that checks if a singly linked list has a cycle
* @list: head pointer
* Return: 1 if list has a cycle, 0 otherwise
*/
int check_cycle(listint_t *list)
{
listint_t *i = list;
listint_t *j = list;
if (list)
{
while (i->next)
{
i = i->next;
if (!i->next)
return (0);
i = i->next;
j = j->next;
if (i == j)
return (1);
}
}
return (0);
}
