/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:54 by myli-pen          #+#    #+#             */
/*   Updated: 2025/06/12 00:42:30 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * Attempts to find the first occurrance of character `c` in `s`.
 *
 * @param s Source string.
 * @param c Character to be searched for.
 * @return Pointer to the first occurrence of `c` in `s`,
 * or `NULL` if not found.
 */
char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	c = (unsigned char)c;
	while (*s && (const unsigned char)*s != c)
		++s;
	if ((const unsigned char)*s == c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_linelen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		if (s[len++] == '\n')
			break ;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if ((!dest || !src) && n)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n-- && *s)
		*d++ = *s++;
	return (dest);
}

/**
 * Allocates memory and copies characters from strings `s1` and `s2`.
 *
 * @param s1 Source string 1.
 * @param s2 Source string 2.
 * @return New string, which is the result of concatenating `s1` and `s2`.
 */
char	*ft_strjoin(char *s1, const char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_linelen(s1);
	len2 = ft_linelen(s2);
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (free(s1), NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(&str[len1], s2, len2);
	str[len1 + len2] = '\0';
	return (free(s1), str);
}
