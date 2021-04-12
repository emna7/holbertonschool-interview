#include "regex.h"
#include <stdio.h>
#include <stdlib.h>
/**
* regex_match - function that checks wether a given
* pattern matches a given string
* @str: given string
* @pattern: given pattern
* Return: 1 if they match, 0 otherwise
*/

int regex_match(char const *str, char const *pattern)
{
	if (!*pattern)
	{
		return (!*pattern);
	}
	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);
		while (*str && (*pattern == *(str++) || *pattern == '.'))
		{
			if (regex_match(str, pattern + 2))
				return (1);
		}
	}
	else if (*pattern == *str || (*pattern == '.' && *str))
		return (regex_match(++str, ++pattern));
	return (0);
}
