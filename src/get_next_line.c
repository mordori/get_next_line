/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/11 03:31:10 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_cpybuf(char *buf);
static void	ft_trimbuf(char *buf, ssize_t bytes);

#include <stdio.h>

/**
 * Returns a line read from file descriptor `fd`.
 *
 * @param fd File descriptor to read from.
 * @return String from the read line or NULL in case of error or if nothing
 * was read.
 */
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	line = ft_cpybuf(buf);
	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (free(line), NULL);
	if (buf[0] && buf[ft_linelen(buf) - 1] == '\n')
		return (ft_trimbuf(buf, BUFFER_SIZE), line);
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0 && line[0])
			return (ft_trimbuf(buf, bytes), line);
		if (bytes <= 0)
			return (free(line), NULL);
		buf[bytes] = '\0';
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		if (line[0] && line[ft_linelen(line) - 1] == '\n')
			return (ft_trimbuf(buf, bytes), line);
	}
}

static char	*ft_cpybuf(char *buf)
{
	size_t	line_len;
	char	*line;

	line_len = ft_linelen(buf);
	line = malloc((line_len + 1) * sizeof (char));
	if (!line)
		return (NULL);
	ft_memcpy(line, buf, line_len);
	line[line_len] = '\0';
	return (line);
}

static void	ft_trimbuf(char *buf, ssize_t bytes)
{
	size_t	line_len;
	(void)bytes;

	line_len = ft_linelen(buf);
	buf = ft_memcpy(buf, buf + line_len, BUFFER_SIZE - line_len);
	buf[BUFFER_SIZE - line_len] = '\0';
}
