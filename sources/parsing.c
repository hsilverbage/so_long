/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:06 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/23 17:36:07 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_if_ber(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!(str[i - 1] == 'r' && str[i - 2] == 'e'
			&& str[i - 3] == 'b' && str[i - 4] == '.'))
	{
		ft_error("Invalid map extension !");
		exit(0);
	}
}

void	ft_create_map(char **argv, int nb_lines, t_game *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	game->map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!game->map)
		exit (0);
	while (line)
	{
		game->map[i++] = line;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
}

int	ft_count_lines(char *str)
{
	int	nb;
	int	fd;

	fd = open(str, O_RDONLY);
	nb = 0;
	while (get_next_line(fd))
		nb++;
	close(fd);
	return (nb);
}

void	ft_check_rectangle(t_game *game)
{
	size_t	len;
	int		i;

	i = 1;
	len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != len)
		{
			free(game->map);
			ft_error("Map is not a rectangle");
		}
		i++;
	}
	game->width = len;
}

int	ft_parsing(char **argv, t_game *game)
{
	int	nb_lines;

	ft_check_if_ber(argv[1]);
	nb_lines = ft_count_lines(argv[1]);
	ft_create_map(argv, nb_lines, game);
	ft_check_rectangle(game);
	game->height = nb_lines;
	ft_check_walls(game, nb_lines);
	ft_no_other_char(game);
	return (0);
}
