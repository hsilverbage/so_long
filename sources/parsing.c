/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:06 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/06 17:30:56 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_if_ber(char *str, t_game *game)
{
	int	i;

	i = ft_strlen(str);
	if (!(str[i - 1] == 'r' && str[i - 2] == 'e'
			&& str[i - 3] == 'b' && str[i - 4] == '.'))
	{
		ft_error("Error\nInvalid map extension !", game);
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
	game->map = ft_calloc(nb_lines + 1, sizeof(char *));
	if (!game->map)
		ft_error("Error\nYour map file is empty", game);
	while (line[0] != '\0')
	{
		game->map[i++] = line;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	game->map[i] = NULL;
	close(fd);
}

int	ft_count_lines(char *str, t_game *game)
{
	int	nb;
	int	fd;
	char	*s;

	fd = open(str, O_RDONLY);
	nb = 0;
	s = get_next_line(fd);
	if (!s)
		ft_error("Error\nYour map file is empty", game);
	while (s[0] != '\0')
	{
		nb++;
		free(s);
		s = get_next_line(fd);
	}
	if (s)
		free(s);
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
			ft_error("Error\nMap is not a rectangle", game);
		i++;
	}
	game->width = len;
}

int	ft_parsing(char **argv, t_game *game)
{
	int	nb_lines;

	ft_check_if_ber(argv[1], game);
	nb_lines = ft_count_lines(argv[1], game);
	if (nb_lines < 3)
		ft_error("Error\nThe map can't be smaller than 3 lines", game);
	ft_create_map(argv, nb_lines, game);
	if (!game->map)
		ft_error("Error\nYour map file is empty", game);
	ft_check_rectangle(game);
	game->height = nb_lines;
	ft_check_walls(game, nb_lines);
	ft_no_other_char(game);
	ft_diffusion(game);
	ft_create_map(argv, nb_lines, game);
	return (0);
}
