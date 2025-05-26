/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:16:14 by eddlim            #+#    #+#             */
/*   Updated: 2025/05/19 20:32:25 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, int n)
{
	unsigned char	*temp;

	temp = (unsigned char *) s;
	while (n > 0)
	{
		*temp++ = 0;
		n--;
	}
}
/*
#include <stdio.h>
#include <unistd.h>
int	main(void)
{
	char	s[6] = "XXXXX";
	ft_bzero(s, 3);
	printf("%s", s);
   	int	i = 0;
	while (i < 10)
	{
		write(1, &s[i], 1);
		 i++;
	}     	
}*/
