/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:54 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/16 00:51:09 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * Allocates memory for `nmemb` elements of `size` bytes, initialized with \0.
 *
 * Guards against overflow, returning NULL.
 *
 * @param nmemb Number of elements.
 * @param size Size of an element in bytes.
 * @return Pointer to the beginning of the allocated memory area, or `NULL`
 * if allocation failed.
 */

 /*
void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	size_t			bytes;
	unsigned char	*str;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	bytes = nmemb * size;
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	str = (unsigned char *)ptr;
	while (bytes--)
		str[bytes] = '\0';
	return (ptr);
}*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if ((!dest || !src) && n)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*strjoin(char *s1, char *s2, int i)
{
	char	*str;

	str = malloc(i * BUFFER_SIZE);
	if (str)
	{
		ft_memcpy(str, s1, (i - 1) * BUFFER_SIZE);
		ft_memcpy(&str[(i - 1) * BUFFER_SIZE], s2, BUFFER_SIZE);
	}
	free(s1);
	return (str);
}


