/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:14:54 by myli-pen          #+#    #+#             */
/*   Updated: 2025/05/22 15:20:21 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

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

size_t	ft_strlinelen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*s)
	{
		++len;
		if (*s == '\n')
			break;
		s++;
	}
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
	while (n--)
		*d++ = *s++;
	return (dest);
}

/**
 * Fills `n` bytes of the memory area `s` with byte `c`.
 *
 * @param s Source memory area.
 * @param c Byte to be written with.
 * @param n Number of bytes to be written.
 * @return Pointer to modified `s`.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;

	if (!s && n)
		return (NULL);
	d = (unsigned char *)s;
	while (n--)
		*d++ = (unsigned char)c;
	return (s);
}

/**
 * Allocates memory and copies characters from strings `s1` and `s2`.
 *
 * @param s1 Source string 1.
 * @param s2 Source string 2.
 * @return New string, which is the result of concatenating `s1` and `s2`.
 */
char	*ft_strjoin(char*s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlinelen(s1);
	len2 = ft_strlinelen(s2);
	if (!len2)
		len2 = BUFFER_SIZE;
	str = malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len1);
	ft_memcpy(&str[len1], s2, len2);
	free(s1);
	return (str);
}

/**
 * Allocates memory and returns a substring from the string `s`.
 *
 * @param s Source string.
 * @param start Starting index for the substring in `s`.
 * @param len Maximum length of the substring.
 * @return New substring from `s`.
 */
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (ft_strlen(s) > start)
		while (s[start + i] && i < len)
			++i;
	sub = ft_calloc(i + 1, sizeof (char));
	if (sub && i)
		ft_memcpy(sub, &s[start], i);
	return (sub);
}
	*/
