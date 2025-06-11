/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:29:34 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/11 03:18:43 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

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
	close(fd);
	return (0);
}
