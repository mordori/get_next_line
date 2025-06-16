/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/16 18:54:49 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static inline char	*ft_extract_line(char *buf, ssize_t bytes);
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
	static char	*buf[FD_MAX];
	char		tmp[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	bytes = -2;
	while (!ft_strchr(buf[fd], '\n'))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		tmp[bytes] = '\0';
		buf[fd] = ft_strjoin(buf[fd], tmp);
	}
	if (!buf[fd])
		return (NULL);
	line = ft_extract_line(buf[fd], bytes);
	buf[fd] = ft_trimbuf(buf[fd]);
	if (!line && (bytes == 0 || bytes == -1))
	{
		free(buf[fd]);
		buf[fd] = NULL;
	}
	return (line);
}

static inline char	*ft_extract_line(char *buf, ssize_t bytes)
{
	char	*line;
	size_t	len_nl;

	len_nl = 0;
	while (buf[len_nl] != '\n' && buf[len_nl])
		++len_nl;
	if (buf[len_nl] == '\n')
		++len_nl;
	line = NULL;
	if (len_nl && bytes != -1)
		line = ft_substr(buf, 0, len_nl);
	return (line);
}

static inline char	*ft_trimbuf(char *buf)
{
	char	*new_buf;
	size_t	len_nl;
	size_t	len_buf;

	len_nl = 0;
	len_buf = 0;
	while (buf[len_nl] != '\n' && buf[len_nl])
		++len_nl;
	if (buf[len_nl] == '\n')
		++len_nl;
	len_buf = ft_strlen(buf);
	new_buf = ft_substr(buf, len_nl, len_buf - len_nl);
	free(buf);
	return (new_buf);
}
