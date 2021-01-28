#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
/**
 *create_tree - Function that creates an avl tree
 *@array: array
 *@parent: parent
 *@start: start
 *@end: end
 *Return: avl tree
 */
avl_t *create_tree(int *array, avl_t *parent, int start, int end)
{
int middle;
avl_t *tree;
if (start > end)
return (NULL);
middle = (start + end) / 2;
tree = malloc(sizeof(avl_t));
if (tree == NULL)
return (NULL);
tree->parent = parent;
tree->n = array[middle];
tree->left = create_tree(array, tree, start, middle - 1);
tree->right = create_tree(array, tree, middle + 1, end);
return (tree);
}
/**
 *sorted_array_to_avl - Function that builds an AVL tree from an array
 *@array: array
 *@size: size
 *Return: avt tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
int siz = size - 1;
if (size <= 0 || !array)
return (NULL);
return (create_tree(array, NULL, 0, siz));
}
