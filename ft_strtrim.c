/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddlim <eddlim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:46:17 by eddlim            #+#    #+#             */
/*   Updated: 2025/05/26 13:49:39 by eddlim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_trim(const char *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	count;
	char	*dest;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && is_trim(s1[i]))
	{	
		i++;
		count++;
	}
	start = i;
	while (s1[i] && !is_trim(set, s1[i]))
		i++;
	end = i - 1;
	dest = ft_calloc((end - start - count), sizeof(char));
	while (s1[start])
	{
				
}


