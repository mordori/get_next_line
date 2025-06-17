/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/17 15:03:21 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static inline char	*extract_line(char *buf);
static inline void	trimbuf(char *buf);
static inline size_t	linelen(char *buf);

/**
 * Returns a line read from file descriptor `fd`.
 *
 * @param fd File descriptor to read from.
 * @return String from the read line or NULL in case of error or if there
 * is nothing else to read.
 */
char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = extract_line(buf);
	if (buf[0] && !line)
		return (NULL);
	while (!ft_strchr(buf, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (free(line), NULL);
		if (bytes == 0)
			break ;
		buf[bytes] = '\0';
		line = ft_strjoin(line, extract_line(buf));
		if (!line)
			return (NULL);
	}
	trimbuf(buf);
	return (line);
}

/**
 * Extracts a string with a newline from buf, NUL-terminating the result.
 *
 * @param buf Buffer of read characters.
 * @return Extracted string with a newline.
 */
static inline char	*extract_line(char *buf)
{
	if (!buf[0])
		return (NULL);
	return (ft_substr(buf, 0, linelen(buf)));
}

/**
 * Removes a string with a newline from buf, then NUL-terminates the result.
 *
 * @param buf Buffer of read characters.
 */
static inline void	trimbuf(char *buf)
{
	size_t	len_nl;

	len_nl = linelen(buf);
	ft_memcpy(buf, buf + len_nl, BUFFER_SIZE);
	buf[ft_strlen(buf) - len_nl] = '\0';
}

/**
 * Counts the number of characters in a `buf` to an included newline,
 * or to NUL if not found.
 *
 * @param buf Buffer of read characters.
 * @return Number of characters in a buffer to an included newline,
 * or to NUL if not found.
 */
static inline size_t	linelen(char *buf)
{
	size_t	len_nl;

	len_nl = 0;
	while (buf[len_nl] != '\n' && buf[len_nl])
		++len_nl;
	if (buf[len_nl] == '\n')
		++len_nl;
	return (len_nl);
}
