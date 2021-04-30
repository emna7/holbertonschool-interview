#include "substring.h"

/**
 * find_substring - finds all possible substrings containing a list of words
 * within a given string
 * @s: the string to scan
 * @words: array of words all substrings must be a concatenation arrangement of
 * @nb_words: number of elements in array @words
 * @n: address where to store number of elements in returned array
 * Return: allocated array, NULL if no solution is found
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	char *tmp = NULL, *p = NULL;
	int leng = strlen(s);
	int *marker;
	int diclen = 0, count = 0;
	int len = strlen(words[0]);
	int i, j, k;

	diclen = len * nb_words;
	tmp = calloc((diclen + 1), sizeof(char));
	marker = calloc((leng + 1), sizeof(int));
	for (i = 0; i <= leng - diclen;)
	{
		strncpy(tmp, &s[i], diclen);
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < diclen;)
			{
				p = strstr(tmp + k, words[j]);
				if (p != NULL && ((p - tmp) % len) == 0)
					break;
				else if (p != NULL)
				{
					k = p - tmp + 1;
					p = NULL;
				}
				else if (p == NULL)
					goto nextseg;
			}
			if (p != NULL)
				memset(p, '.', len);
			else
				goto nextseg;
		}
		if (leng != 0 && diclen != 0)
			marker[count++] = i;
nextseg:
	i++;
	}
	*n = count;
	return (marker);
}
