#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>


void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void split_sort(int *array, int *inner, int start, int end);
void merge(int *array, int *inner, int start, int mid, int end);

#endif
