#include "binary_trees.h"
/**
* sorted_array_to_avl - creates an AVL tree from an array
* @array: pointer to the array
* @size: size of the array
* Return: on success pointer the new avl tree, NULL otherwise
*/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
avl_t *head = NULL;
int edge = 0;
if (!array || !size)
return (NULL);
if (size % 2 == 0)
edge = ((int)size / 2) - 1;
else
edge = (int)size / 2;
head = binary_tree_node(array[edge]);
return (head);
}
/**
* binary_tree_node - creates a new node
* @value: value to enter in the node
* Return: new node of NULL if it fails
*/
avl_t *binary_tree_node(int value)
{
avl_t *new = NULL;
new = malloc(sizeof(*new));
if (!new)
return (NULL);
new->n = value;
new->left = NULL;
new->parent = NULL;
new->right = NULL;
return (new);
}
