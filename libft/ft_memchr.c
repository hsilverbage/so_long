/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:48:45 by hsilverb          #+#    #+#             */
/*   Updated: 2022/11/29 16:29:18 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

 /*
void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*char_str;

	char_str = (unsigned char *) str;
	i = 0;
	while (i < n && n != 0)
	{
		if (char_str[i] == (unsigned char) c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *str;

	str = (unsigned char*)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}
