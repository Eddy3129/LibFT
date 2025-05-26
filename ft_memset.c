/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:06:37 by eddlim            #+#    #+#             */
/*   Updated: 2025/05/19 20:15:52 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*s;

	s = (unsigned char *) b;
	while (len > 0)
	{
		*s++ = c;
		len--;
	}
	return (b);
}
/*#include <unistd.h>
int	main(void)
{
	char	s[10];
	int	i = 0;
	while (i < 10)
	{
		s[i] = 'X';
		i++;
	}
	ft_memset(s, 'A', 5);
	i = 0;
	while (i < 10)
	{
		write(1, &s[i], 1);
		i++;
	}		
}*/
