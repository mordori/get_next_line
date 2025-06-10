/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/10 20:00:06 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// REMOVE
#include <stdio.h>

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
	size_t		buf_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_cpybuf(buf);
	if (!line)
		return (NULL);
	if (ft_strchr(line, '\n'))
	{
		ft_trimbuf(buf);
		return (line);
	}
	while (1)
	{
		buf_len = read(fd, buf, BUFFER_SIZE);
		if (buf_len < 1)
		{
			free(line);
			return (NULL);
		}
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		if (ft_strchr(line, '\n'))
		{
			ft_trimbuf(buf);
			return (line);
		}
	}
	return (NULL);
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*file = "file.txt";
	fd = open(file, O_RDONLY);
	char	*str;

	while ((str = get_next_line(fd)))
	{
		write (1, str, ft_linelen(str));
		free(str);
	}
	return (0);
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

static void	ft_trimbuf(char *buf)
{
	size_t	line_len;

	line_len = ft_linelen(buf);
	printf("LINELEN :%zu\n", line_len);
	buf = ft_memcpy(buf, buf + line_len, BUFFER_SIZE - line_len);
	buf[BUFFER_SIZE - line_len] = '\0';
}
