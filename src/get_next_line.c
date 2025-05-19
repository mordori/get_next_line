/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/19 20:59:19 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// REMOVE
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
	static char	buf[BUFFER_SIZE];
	t_vars		vars;
	size_t		len;

	if (fd < 1)
		return (NULL);

	vars.str = malloc(1);

	while (1)
	{
		vars.len = read(fd, buf, BUFFER_SIZE);
		if (vars.len < 1)
			return (NULL);

		vars.str = ft_strjoin(vars.str, buf);
		if (!vars.str)
			return (NULL);

		len = ft_linelen(buf);
		if (buf[len] == '\n')
		{
			return (vars.str);
		}
	}

	return (vars.str);
}

// Malloc leftovers
// Read to buffer
// Append until newline
//

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*file = "file.txt";
	fd = open(file, O_RDONLY);
	char	*str;

	while ((str = get_next_line(fd)))
	{
		write (1, "\n", 2);
		write (1, str, ft_linelen(str));
		write (1, "\n", 2);
		free(str);
	}

	return (0);
}
