/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/29 16:03:00 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static inline char	*join_lines(char *line, const char *buf);
static inline char	*extract_line(const char *buf);
static inline void	trimbuf(char *buf);
static inline size_t	linelen(const char *buf);

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

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE < 1 || FD_MAX < 3)
		return (NULL);
	line = extract_line(buf[fd]);
	if (buf[fd][0] && !line)
		return (NULL);
	while (!ft_strchr(buf[fd], '\n'))
	{
		bytes = read(fd, buf[fd], BUFFER_SIZE);
		if (bytes == -1)
			return (free(line), NULL);
		if (bytes == 0)
			break ;
		buf[fd][bytes] = '\0';
		line = join_lines(line, buf[fd]);
		if (!line)
			return (NULL);
	}
	trimbuf(buf[fd]);
	return (line);
}

/**
 * Joins an extracted string from the `buf` to the line that has no newline yet.
 *
 * @param buf Buffer of read characters.
 * @return Extracted string with a newline.
 */
static inline char	*join_lines(char *line, const char *buf)
{
	char	*new_line;

	new_line =  extract_line(buf);
	if (!new_line)
		return (NULL);
	return (ft_strjoin(line, new_line));
}

/**
 * Extracts a string from `buf`, NUL-terminating the result.
 *
 * @param buf Buffer of read characters.
 * @return Extracted string.
 */
static inline char	*extract_line(const char *buf)
{
	if (!buf[0])
		return (NULL);
	return (ft_substr(buf, 0, linelen(buf)));
}

/**
 * Removes a string with a newline from `buf`, then NUL-terminates the result.
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
static inline size_t	linelen(const char *buf)
{
	size_t	len_nl;

	len_nl = 0;
	while (buf[len_nl] != '\n' && buf[len_nl])
		++len_nl;
	if (buf[len_nl] == '\n')
		++len_nl;
	return (len_nl);
}
