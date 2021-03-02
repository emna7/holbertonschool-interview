#include "list.h"
/**
* add_node_end - function that adds a node at the end
*of a list
* @list: pointer to a pointer of the start of the list
* @str: the string to copy in the new node
* Return: adress of the new node
*/
List *add_node_end(List **list, char *str)
{
List *tmp, *newNode;
newNode = malloc(sizeof(List));
if (!newNode)
return (NULL);
newNode->str = str;
if (!(*list))
{
*list = newNode;
newNode->next = newNode;
newNode->prev = newNode;
}
else
{
tmp = *list;
newNode->next = tmp;
newNode->prev = tmp->prev;
tmp->prev->next = newNode;
tmp->prev = newNode;
}
return (newNode);
}
/**
* add_node_begin - function that adds new node at the
*beginning of a double circular list
* @list: pointer to a pointer of the start of the list
* @str: the string to copy in the new node
* Return: adress of the new node
*/
List *add_node_begin(List **list, char *str)
{
List *tmp, *newNode;
newNode = malloc(sizeof(List));
if (!newNode)
return (NULL);
newNode->str = str;
if (!*list)
{
*list = newNode;
newNode->next = newNode;
newNode->prev = newNode;
}
else
{
tmp = *list;
newNode->next = tmp;
newNode->prev = tmp->prev;
tmp->prev->next = newNode;
tmp->prev = newNode;
*list = newNode;
}
return (newNode);
}
