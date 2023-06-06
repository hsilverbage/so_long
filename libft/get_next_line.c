/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:28:48 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/06 13:28:49 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(int fd, char *line, char *buffer, int i)
{
	int	j;

	j = -1;
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	while (read(fd, buffer + i, 1) > 0 && buffer[i] != '\n')
		i++;
	if (buffer[i] != '\n' && i > 0)
		buffer[i++] = '\n';
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	if (line != NULL)
	{
		while (++j < i)
		{
			if (buffer[j] != '\n')
				line[j] = buffer[j];
		}
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;

	line = NULL;
	line = get_line(fd, line, buffer, 0);
	return (line);
}
