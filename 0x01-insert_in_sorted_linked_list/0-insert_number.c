#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
*
*
*
*/
listint_t *insert_node(listint_t **head, int number)
{
listint_t *new;
listint_t *current;
current = *head;
new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);
new->n = number;
new->next = NULL;
if (*head == NULL)
{
*head = new;
return (*head);
}
else
{
if (current->n > new->n)
{
new->next = current;
*head = new;
return (*head);
}
else
{
while (current->next != NULL && current->next->n < new->n)
{
current = current->next;
}
new->next = current->next;
current->next = new;
return (new);
}
}
}
