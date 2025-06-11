/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/11 12:59:22 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_cpybuf(char *buf);
static void	ft_trimbuf(char *buf);

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
		return (ft_trimbuf(buf), line);
	while (1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && !line[0]))
			return (free(line), NULL);
		buf[bytes] = '\0';
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		if (line[ft_linelen(line) - 1] == '\n' || bytes == 0)
			return (ft_trimbuf(buf), line);
	}
}

static inline char	*ft_cpybuf(char *buf)
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

static inline void	ft_trimbuf(char *buf)
{
	size_t	buf_len;
	size_t	line_len;

	buf_len = 0;
	while (buf[buf_len])
		++buf_len;
	line_len = ft_linelen(buf);
	buf = ft_memcpy(buf, buf + line_len, BUFFER_SIZE);
	buf[buf_len - line_len] = '\0';
}
