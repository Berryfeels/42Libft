/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:55:48 by stdi-pum          #+#    #+#             */
/*   Updated: 2023/12/03 21:09:23 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
// Parameters
// s1: The string to be trimmed.
// set: The reference set of characters to trim.
// Return value
// The trimmed string.
// NULL if the allocation fails.
// External functs. malloc
// Description
// The ft_strtrim() function takes a string and trims it.
// Trimming means removing the characters specified in the set string
// from the start AND from the end of the string s1, without removing what's
//in the middle of s1.
// From s1 "ababaaaMy name is Simonbbaaabbad" we want to remove every a and
// b from the start and the end of s1, keeping the stuff in the middle of s1.
// the result is "My name is Simone"

//get length s1;# include "libft.h"ugh s1 from Start (s1[0])
	//while (s1[i] == (set[y++]) && set[y] == '\0'))
	//int start = 0; start ++;
	//loop while iterate through s1 from End (s1[len--])
	//if (s1[len] == (set[y++] until set[y] == '\0'))
	//malloc buffer will be = len - n.
	//malloc create a buffer for new string resulting from ft_strtrim.
	//copy s1[n++]  in buffer till n < len

char	*ft_strtrim(char const *s1, char const *set)
{
	int		y;
	int		i;
	char	*strim;
	char	*src;

	if (s1 == NULL)
		return (NULL);
	src = (char *) s1;
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i ++;
	}
	y = ft_strlen (src);
	while (y > 0)
	{
		if (ft_strchr(set, s1[y]) == NULL)
			break ;
		y --;
	}
	y += 1;
	strim = (char *) malloc ((y - i + 1) * sizeof(char const));
	if (strim == NULL)
		return (NULL);
	ft_strlcpy (strim, s1 + i, (y - i + 1));
	return (strim);
}
// #include <stdio.h>

// int main(void)
// {
// 	const char *s1 = "abababbabbTrim this string!aabbaabbabab";
// 	const char *set = "ab";
// 	char *trimmed = ft_strtrim(s1, set);

// 	if (trimmed != NULL)
// 	{
// 		printf("Original: '%s'\n", s1);
// 		printf("Trimmed : '%s'\n", trimmed);

// 		free(trimmed); // Don't forget to free the allocated memory
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed.\n");
// 	}

// 	return 0;
// }
