/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:29:34 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/29 09:24:45 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "src/get_next_line_bonus.h"

int	main(void)
{
	int		fd_1;
	int		fd_2;
	char	*str_1;
	char	*str_2;
	char	*file_A = "file_a.txt";
	char	*file_B = "file_b.txt";

	fd_1 = open(file_A, O_RDONLY);
	fd_2 = open(file_B, O_RDONLY);
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	printf("FD_MAX = %d\n", FD_MAX);
	while (1)
	{
		str_1 = get_next_line(fd_1);
		if (str_1)
			printf("File A, %s", str_1);
		free(str_1);
		str_2 = get_next_line(fd_2);
		if (str_2)
			printf("File B, %s", str_2);
		free(str_2);
		if (!str_1 && !str_2)
			break ;
		printf("--------------------\n");
	}
	close(fd_1);
	close(fd_2);
	return (0);
}
