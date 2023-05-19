/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:22:35 by hsilverb          #+#    #+#             */
/*   Updated: 2023/01/13 19:45:41 by hsilverb         ###   ########lyon.fr   */
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

char	*ft_if_read_doesnt_work_bonus(char *line)
{
	if (line)
		free(line);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*s1;

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
