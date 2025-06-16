/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/16 21:12:07 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>

static inline char	*ft_extract_line(char *buf);
static inline char	*ft_trimbuf(char *buf);

/**
 * Returns a line read from file descriptor `fd`.
 *
 * @param fd File descriptor to read from.
 * @return String from the read line or NULL in case of error or if there
 * is nothing else to read.
 */
char	*get_next_line(int fd)
{
	static char	buf[FD_MAX][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (!ft_strchr(buf[fd], '\n'))
	{
		bytes = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes == -1)
			return (free(line), NULL);
		if (bytes == 0)
			break ;
		buf[fd][bytes] = '\0';
		if (!ft_strchr(buf[fd], '\n'))
			line = ft_strjoin(line, ft_extract_line(buf[fd]));
	}
	line = ft_strjoin(line, ft_extract_line(buf[fd]));
	ft_trimbuf(buf[fd]);
	return (line);
}

static inline char	*ft_extract_line(char *buf)
{
	char	*line;
	size_t	len_nl;

	len_nl = 0;
	while (buf[len_nl] != '\n' && buf[len_nl])
		++len_nl;
	if (buf[len_nl] == '\n')
		++len_nl;
	line = NULL;
	if (len_nl)
		line = ft_substr(buf, 0, len_nl);
	return (line);
}

static inline char	*ft_trimbuf(char *buf)
{
	size_t	len_nl;
	size_t	len_buf;

	len_nl = 0;
	len_buf = 0;
	while (buf[len_nl] != '\n' && buf[len_nl])
		++len_nl;
	if (buf[len_nl] == '\n')
		++len_nl;
	len_buf = ft_strlen(buf);
	buf = ft_memcpy(buf, buf + len_nl, BUFFER_SIZE);
	buf[len_buf - len_nl] = '\0';
	return (buf);
}
