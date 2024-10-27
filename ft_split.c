/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:28 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/11 17:39:46 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


// Parameters
// s: The string to be split.
// c: The delimiter character.
// Return
// value The array of new strings resulting from the split.
// NULL if the allocation fails.
// External
// functs. malloc, free
// Description
// Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must end
// with a NULL pointer.

// we are returning a 2D char **str or str = [x][y].
// An array of strings is like an array of char in 2D., it is like writing a char with different pointers str[x][y].
// x + y.

// Count how many occurences of 'c' in char const *s = int count.
// Create a buffer for an array of strings char **str = (char **)malloc(count * sizeof(char));

// Now we have our buffer, an empty array of strings.
// ft_substr create a substring starting from a pointer of s1 for a certain number of character n.
// *ft_substr(char const *s, unsigned int start, size_t len) wheres is the string, start is the pointer to the start and len how long is the string

#include <stddef.h>
int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

char    *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return ((char *)s);
        s ++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

char    *ft_strdup(const char *s1)
{
    int        ls;
    char    *ptr;
    char    *getlen;
    int        i;


    getlen = (char *) s1;
    ls = ft_strlen (getlen);
    ptr = (char *) malloc ((ls + 1) * sizeof(const char));
    if (ptr == NULL)
    {
        return (NULL);
    }
    i = 0;
    while (i < ls)
    {
        ptr[i] = s1[i];
        i ++;
    }
    ptr[i] = '\0';
    return (ptr);
}

static char    *substr(const char *s, unsigned int start, size_t len)
{
    char    *subs;
    size_t    i;

    if (*s == '\0')
        return (NULL);
    subs = ft_strdup(s);
    i = 0;
    while (s[i] != '\0' && i < len)
    {
        subs[i] = s[start + i];
        i ++;
    }
    subs[i] = '\0';
    return (subs);
}

char **ft_split(const char *s, char c)
{
	char	**str;
	int		count;
	int 	y;
	int		i;
	size_t	word_len;
	char	*first_occurence;

	count = 1;
	if (!(s))
		return (NULL);
	i = 0;
	while (s[i]!= '\0')
	{
		if (s[i] == c)
			count++;
		i ++;
	}
	str = (char **)malloc((count + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (s[i] != '\0' && y <= count)
	{
		if ((i == 0) || (s[i] == c))
		{
			first_occurence = ft_strchr((char *)&s[i], c);
			if (first_occurence != NULL)
				word_len = first_occurence - &s[i];
			else
				word_len = ft_strlen((char *)&s[i]);
			str[y++] = substr(s, i, word_len);
			i += word_len;
	}
		else
			i++;
	}
	str[y] = NULL;
	return(str);
}

// #include <stdio.h>
// int main (void)
// {
//     char string[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
//     char **str;
//     str = ft_split (string, ' ');
//     int i = 0;
//     while (str[i] != NULL) {
//         printf("%s\n", str[i]);
//         i++;
//     }
//     return (0);
// }
