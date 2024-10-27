#include "libft.h"
#include <stddef.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return (char *)s;
        s++;
    }
    if (c == '\0')
        return (char *)s;
    return NULL;
}

static char *substr(const char *s, unsigned int start, size_t len)
{
    char *subs = malloc((len + 1) * sizeof(char));
    if (subs == NULL)
    {
        return NULL;
    }

    size_t i = 0;
    while (i < len)
    {
        subs[i] = s[start + i];
        i++;
    }
    subs[i] = '\0';
    return subs;
}

char **ft_split(const char *s, char c)
{
    char **str;
    int count = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == c)
            count++;
        i++;
    }

    str = (char **)malloc((count + 1) * sizeof(char *));
    if (str == NULL)
        return NULL;

    int y = 0;
    i = 0;
    while (s[i] != '\0')
    {
        while (s[i] == c)
            i++;

        if (s[i] != '\0')
        {
            char *word;
            size_t word_len = ft_strchr(&s[i], c) ? ft_strchr(&s[i], c) - &s[i] : ft_strlen((char *)&s[i]);
            word = substr(s, i, word_len);
            str[y++] = word;
            i += word_len;
        }
    }

    str[y] = NULL;
    return str;
}

int main(void)
{
    char string[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
    char **str = ft_split(string, ' ');

    int i = 0;
    while (str[i] != NULL)
    {
        printf("%s$\n", str[i]);
        free(str[i]);
        i++;
    }

    free(str);
    return 0;
}
