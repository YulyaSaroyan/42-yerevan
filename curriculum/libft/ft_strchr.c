#include <stddef.h>

char *ft_strchr(char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return (s);
        s++;
    }

    if (c == '\0')
        return (s);

    return (NULL); 
}

