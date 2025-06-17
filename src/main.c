/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:29:34 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/17 04:41:29 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

// MANDATORY
#include "get_next_line.h"
int	main(void)
{
	int		fd;
	char	*str;
	char	*file = "file.txt";

	printf("\033[33mMANDATORY\033[0m\n");
	fd = open(file, O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}


// BONUS
// #include "get_next_line_bonus.h"
// int	main(void)
// {
// 	int		fd_bonus_1;
// 	int		fd_bonus_2;
// 	char	*str_bonus_1;
// 	char	*str_bonus_2;
// 	char	*file_bonus_1 = "file_bonus_1.txt";
// 	char	*file_bonus_2 = "file_bonus_2.txt";

// 	printf("\033[33mBONUS\033[0m\n");
// 	fd_bonus_1 = open(file_bonus_1, O_RDONLY);
// 	fd_bonus_2 = open(file_bonus_2, O_RDONLY);
// 	while (1)
// 	{
// 		str_bonus_1 = get_next_line(fd_bonus_1);
// 		if (str_bonus_1)
// 			printf("%s", str_bonus_1);
// 		free(str_bonus_1);
// 		str_bonus_2 = get_next_line(fd_bonus_2);
// 		if (str_bonus_2)
// 			printf("%s", str_bonus_2);
// 		free(str_bonus_2);
// 		if (!str_bonus_1 && !str_bonus_2)
// 			break ;
// 	}
// 	close(fd_bonus_1);
// 	close(fd_bonus_2);
// 	return (0);
// }
