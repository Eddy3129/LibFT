/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:46:17 by eddlim            #+#    #+#             */
/*   Updated: 2025/05/26 22:09:24 by marvin           ###   ########.fr       */
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
	size_t	len;
	size_t	idx;
	char	*dest;

	idx = 0;
	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && is_trim(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_trim(set, s1[end - 1]))
		end--;
	len = end - start;
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (idx < len)
	{
		dest[idx] = s1[start + idx];
		idx++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = "ahahelloahaha";
	char	*s2 = "ah";
	printf("%s\n", ft_strtrim(s1, s2));
}
*/