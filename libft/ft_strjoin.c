/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:37:06 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/12 10:50:52 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	joined = (char *) malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
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
	free(s1);
	return (joined);
}
