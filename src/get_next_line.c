/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/20 14:18:16 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// REMOVE
#include <stdio.h>


int	ft_cpybuf(char **line, char *buf)
{
	size_t	buf_len;

	buf_len = ft_linelen(buf);
	*line = malloc((buf_len + 1) * sizeof (char));
	if (!*line)
		return (0);
	*line = ft_memcpy(*line, buf, buf_len + 1);
	*line[buf_len] = '\0';
	return (1);
}

void	ft_trimbuf(char *buf)
{
	size_t	buf_len;

	buf_len = ft_linelen(buf);
	if (buf_len)
	{
		ft_memcpy(buf, buf + buf_len, BUFFER_SIZE - buf_len);
		ft_memset(buf + BUFFER_SIZE - buf_len, 0, buf_len);
	}
	else
		ft_memset(buf, 0, BUFFER_SIZE);
}

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
	size_t		line_len;

	if (fd < 1 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (!ft_cpybuf(&line, buf))
		return (NULL);
	line_len = ft_linelen(line);
	if (line[line_len] == '\n')
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
		if (line[ft_linelen(line) - 1] == '\n')
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
		write (1, "\n", 1);
		write (1, str, ft_linelen(str));
		write (1, "\n", 1);
		free(str);
	}

	return (0);
}
