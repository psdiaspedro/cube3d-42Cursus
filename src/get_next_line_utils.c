/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:28:13 by dalves-s          #+#    #+#             */
/*   Updated: 2021/09/15 11:44:46 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	joined = (char *)gft_calloc(gft_strlen(s1)
			+ gft_strlen(s2) + 1, sizeof(char));
	if (joined == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		joined[i] = s2[j];
		j++;
		i++;
	}
	joined[i] = '\0';
	return (joined);
}

size_t	gft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if ((src == 0) || (dst == 0))
		return (0);
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (gft_strlen(src));
}

char	*gft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size_s;
	size_t	max_len;

	size_s = gft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (size_s < start)
	{
		sub = (char *)gft_calloc(sizeof(char), 1);
		if (!sub)
			return (NULL);
		return (sub);
	}
	max_len = size_s - start;
	if (len > max_len)
		len = max_len;
	sub = (char *)gft_calloc(sizeof(char), len + 1);
	if (!sub)
		return (NULL);
	gft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}

char	*gft_strdup(char *src)
{
	char	*dst;
	size_t	len;
	size_t	i;

	i = 0;
	len = gft_strlen(src);
	dst = (char *)gft_calloc(sizeof(char), len + 1);
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
