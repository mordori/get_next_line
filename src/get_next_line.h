/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:49 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/15 17:00:20 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>	// malloc, free
#include <unistd.h>	// read
#include <stdint.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 14
#endif

typedef struct	s_vars
{
	char	buffer[BUFFER_SIZE];
	char	*str;
	size_t	bytes;
	size_t	len;
	size_t	index;
}				t_vars;

char	*get_next_line(int fd);
//void	*ft_calloc(size_t nmemb, size_t size);

#endif
