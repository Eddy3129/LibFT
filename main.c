#include "libft.h"
#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_itoa(123456789));
    printf("%s\n", ft_itoa(-2147483648));
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(100000000));
    printf("%s\n", ft_itoa(101030010));
}