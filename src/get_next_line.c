/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/17 05:12:02 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static inline char	*extract_line(char *buf);
static inline void	trimbuf(char *buf);

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
	int			found_nl;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = extract_line(buf);
	if (buf[0] && !line)
		return (NULL);
	found_nl = ft_strchr(buf, '\n') != NULL;
	while (!found_nl)
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
		found_nl = ft_strchr(buf, '\n') != NULL;
	}
	return (trimbuf(buf), line);
}

/**
 * Extracts a string with a newline from buf, NUL-terminating the result.
 *
 * @param buf Buffer of read characters.
 * @return Extracted string with a newline.
 */
static inline char	*extract_line(char *buf)
{
	char	*line;
	size_t	len_nl;

	if (!buf[0])
		return (NULL);
	len_nl = 0;
	while (buf[len_nl] != '\n' && buf[len_nl])
		++len_nl;
	if (buf[len_nl] == '\n')
		++len_nl;
	line = ft_substr(buf, 0, len_nl);
	return (line);
}

/**
 * Removes a string with a newline from buf, then NUL-terminates the result.
 *
 * @param buf Buffer of read characters.
 */
static inline void	trimbuf(char *buf)
{
	size_t	len_nl;

	len_nl = 0;
	while (buf[len_nl] != '\n' && buf[len_nl])
		++len_nl;
	if (buf[len_nl] == '\n')
		++len_nl;
	ft_memcpy(buf, buf + len_nl, BUFFER_SIZE);
	buf[ft_strlen(buf) - len_nl] = '\0';
}
