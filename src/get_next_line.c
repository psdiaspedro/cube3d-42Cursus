/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:28:13 by dalves-s          #+#    #+#             */
/*   Updated: 2021/09/04 17:11:08 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gline_break(char *line_buf, size_t len)
{
	size_t	i;

	i = 0;
	if (!line_buf)
		return (i);
	while (i < len)
	{
		if (line_buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*gft_calloc(size_t nmemb, size_t size)
{
	void	*point;
	char	*set;
	size_t	i;

	i = 0;
	point = malloc(nmemb * size);
	if (!point)
		return (NULL);
	set = (char *)point;
	while (i < size)
	{
		set[i] = 0;
		i++;
	}
	return (point);
}

char	*gnew_line(char **line, char *line_buf, int bytes)
{
	int		i;
	char	*aux;
	int		len;

	len = 0;
	i = 0;
	aux = NULL;
	while ((line_buf)[i] != '\n' && (line_buf)[i] != '\0')
		i++;
	*line = gft_substr((line_buf), 0, i);
	if (bytes)
	{
		if ((line_buf)[i] == '\n')
			i++;
		len = gft_strlen((char *)((line_buf) + i));
		aux = gft_substr((line_buf), i, len);
		if (!aux)
			return (NULL);
	}
	free((line_buf));
	if (!*line)
		return (NULL);
	return (aux);
}

char	gsplit_line(int fd, char **line_buf, char **buf, int *bytes)
{
	char	*temp;

	while (*bytes && !(gline_break(*line_buf, gft_strlen(*line_buf))))
	{
		*bytes = read(fd, *buf, BUFFER_SIZE);
		(*buf)[*bytes] = 0;
		if (*bytes < 0 || *bytes > BUFFER_SIZE)
		{
			free(*buf);
			return (0);
		}
		temp = *line_buf;
		*line_buf = gft_strjoin(temp, *buf);
		free(temp);
	}
	free(*buf);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*line_buf;
	char		*buf;
	int			bytes;
	int			check;

	bytes = BUFFER_SIZE;
	if ((fd < 0) || !line || (BUFFER_SIZE <= 0) || fd > RLIMIT_NOFILE)
		return (-1);
	if (!line_buf)
		line_buf = gft_strdup("");
	buf = gft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	check = gsplit_line(fd, &line_buf, &buf, &bytes);
	if (!check)
		return (-1);
	line_buf = gnew_line(line, line_buf, bytes);
	if (!bytes)
		return (0);
	return (1);
}
