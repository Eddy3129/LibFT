#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    char *str = "Hello, World! maka baka da mn you";
    char **words = ft_split(str, ' ');

    if (words == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int i = 0;
    while (words[i] != NULL)
    {
        printf("%s\n", words[i]);
        free(words[i]);
        i++;
    }
}