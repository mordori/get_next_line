/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:49 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/19 20:48:48 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>	// malloc, free
#include <unistd.h>	// read
#include <stdint.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

typedef struct	s_vars
{
	char	*str;
	size_t	bytes;
	size_t	len;
	size_t	index;
}				t_vars;

char	*get_next_line(int fd);
char	*ft_strjoin(char*s1, char const *s2);
size_t	ft_linelen(const char *s);

#endif
