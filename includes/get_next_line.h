/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:29:00 by dalves-s          #+#    #+#             */
/*   Updated: 2021/09/04 17:10:10 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/resource.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

# define BUFFER_SIZE 1024

size_t	gft_strlen(char *s);
void	*gft_calloc(size_t nmemb, size_t size);
char	*gft_strjoin(char *s1, char *s2);
size_t	gt_strlcpy(char *dst, char *src, size_t size);
char	*gft_substr(char *s, unsigned int start, size_t len);
char	*gft_strdup(char *src);
int		get_next_line(int fd, char **line);

#endif