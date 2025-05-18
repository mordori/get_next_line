/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:52 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/16 01:04:37 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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
	static t_vars	vars;
	size_t			i;
	char			c;

	if (!vars.bytes)
		vars.bytes = read(fd, vars.buffer, BUFFER_SIZE);

	if (!vars.bytes)
		return (NULL);

	printf("index %ld\n", vars.index);
	fflush(stdout);

	printf("bytes %ld\n", vars.bytes);
	fflush(stdout);

	vars.len = 0;
	i = 0;
	c = vars.buffer[vars.index];
	while (c != '\n')
	{
		++vars.len;
		c = vars.buffer[vars.index + vars.len - i * BUFFER_SIZE];

		if (vars.index + vars.len - i * BUFFER_SIZE == BUFFER_SIZE)
		{
			vars.index = 0;
			++i;
		}
	}
	++vars.len;

	printf("len %ld\n", vars.len);
	fflush(stdout);



	vars.str = malloc(vars.len * sizeof (char));
	if (!vars.str)
		return (NULL);

	vars.index = vars.len - i * BUFFER_SIZE;
	i = vars.len;
	vars.str[i--] = '\n';
	while (i--)
	{
		vars.str[i] = 'T';
	}

	return (vars.str);
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*file = "file.txt";
	fd = open(file, O_RDONLY);
	char	*str;
	int		i;

	while ((str = get_next_line(fd)))
	{
		i = 0;
		while (str[i] != '\n')
			++i;
		write (1, "\n\n", 2);
		write (1, str, i + 1);
		write (1, "\n\n", 2);
		free(str);
	}

	return (0);
}
