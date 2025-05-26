/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:31:46 by eddlim            #+#    #+#             */
/*   Updated: 2025/05/19 17:40:05 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char c[6] = "hello";
	printf("%s", ft_strchr(c,'x'));
}*/
