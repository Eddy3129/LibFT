/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:23:56 by eddlim            #+#    #+#             */
/*   Updated: 2025/05/19 19:41:06 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2, int n)
{
	int	i;

	i = 1;
	while (*s1 && *s2 && *s1 == *s2 && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	return (*s1 - *s2);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*s1 = "abcdef";
	char	*s2 = "abczzz";
	printf("%d", ft_strcmp(s1, s2, 4));
}*/
