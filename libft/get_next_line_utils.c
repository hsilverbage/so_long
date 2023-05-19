/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:18:52 by hsilverb          #+#    #+#             */
/*   Updated: 2023/01/13 15:07:43 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_end_of_line(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_if_read_doesnt_work(char *line, char *buf)
{
	ft_bzero(buf, BUFFER_SIZE + 1);
	if (line)
		free(line);
	return (NULL);
}

/*
void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = malloc(count * size);
	if (s1 == NULL)
		return (NULL);
	ft_bzero(s1, size * count);
	return (s1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
*/
