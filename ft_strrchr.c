/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:41:48 by eddlim            #+#    #+#             */
/*   Updated: 2025/05/19 20:15:00 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *s, int c)
{
	while (*s)
		s++;
	s--;
	while (*s)
	{
		if (*s == c)
			return (s);
		s--;
	}
	return (0);
}
/*
#include <stdio.h>
int     main(void)
{
	char c[6] = "hello";
	printf("%s",ft_strrchr(c,'x'));
}*/
