/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:29:34 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/28 23:38:56 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "src/get_next_line_bonus.h"

int	main(void)
{
	int		fd_bonus_1;
	int		fd_bonus_2;
	char	*str_bonus_1;
	char	*str_bonus_2;
	char	*file_bonus_1 = "file_bonus_1.txt";
	char	*file_bonus_2 = "file_bonus_2.txt";

	fd_bonus_1 = open(file_bonus_1, O_RDONLY);
	fd_bonus_2 = open(file_bonus_2, O_RDONLY);
	while (1)
	{
		str_bonus_1 = get_next_line(fd_bonus_1);
		if (str_bonus_1)
			printf("%s", str_bonus_1);
		free(str_bonus_1);
		str_bonus_2 = get_next_line(fd_bonus_2);
		if (str_bonus_2)
			printf("%s", str_bonus_2);
		free(str_bonus_2);
		if (!str_bonus_1 && !str_bonus_2)
			break ;
	}
	close(fd_bonus_1);
	close(fd_bonus_2);
	return (0);
}
