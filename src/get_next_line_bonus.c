/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/11 18:03:02 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static inline char	*ft_cpybuf(char *buf);
static inline void	ft_trimbuf(char *buf);

/**
 * Returns a line read from file descriptor `fd`.
 *
 * @param fd File descriptor to read from.
 * @return String from the read line or NULL in case of error or if there
 * is nothing else to read.
 */
char	*get_next_line(int fd)
{
	static char	buf[MAX_FD][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_cpybuf(buf[fd]);
	if (!line)
		return (free(line), NULL);
	if (buf[fd][0] && buf[fd][ft_linelen(buf[fd]) - 1] == '\n')
		return (ft_trimbuf(buf[fd]), line);
	while (1)
	{
		bytes = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && !line[0]))
			return (free(line), NULL);
		buf[fd][bytes] = '\0';
		line = ft_strjoin(line, buf[fd]);
		if (!line)
			return (NULL);
		if (line[ft_linelen(line) - 1] == '\n' || bytes == 0)
			return (ft_trimbuf(buf[fd]), line);
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
