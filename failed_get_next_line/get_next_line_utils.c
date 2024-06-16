/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:36:06 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/06/01 15:17:25 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (s == 0)
		return (0);
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	while (src[j] != '\0')
	{
		j++;
	}
	return (j);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;
	int		i;

	len = ft_strlen(s1);
	dest = (char *)malloc(len * sizeof(char) + 1);
	if (dest == 0)
	{
		return (0);
	}
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*dest;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *)malloc(s1_len + s2_len + 1);
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, s1, s1_len + 1);
	ft_strlcpy(&dest[s1_len], s2, s1_len + s2_len + 1);
	return (dest);
}
// if (s1 == 0 || s2 == 0)
// 	return (0);