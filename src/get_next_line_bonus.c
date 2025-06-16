/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/12 01:12:56 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buf[FD_MAX];
	char		tmp[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1)
		return (NULL);
	while(!ft_strchr(buf[fd], '\n'))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		tmp[bytes] = '\0';
		buf[fd] = ft_strjoin(buf[fd], tmp);
	}
	if (!buf[fd])
		return (NULL);
	line = ft_extract_line(buf[fd]);
	buf[fd] = ft_trimbuf(buf[fd]);
	if (!line && bytes == 0)
	{
		free(buf[fd]);
		buf[fd] = NULL;
	}
	return (line);
}

static inline char	*ft_extract_line(char *buf)
{

}

static inline char	*ft_trimbuf(char *buf)
{

}
