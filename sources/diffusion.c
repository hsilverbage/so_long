/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffusion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:30:05 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/06 16:20:05 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_find_x(t_game *game)
{
	int 	i;
	int 	i_tab;
	char	**tab;

	i = 0;
	i_tab = 0;
	tab = game->map;
	while (tab[i_tab])
	{
		while (tab[i_tab][i])
		{
			if (tab[i_tab][i] == 'P')
				return (i);
			i++;
		}
		i = 0;
		i_tab++;
	}
	return (-1);
}

int ft_find_y(t_game *game)
{
	int 	i;
	int 	i_tab;
	char	**tab;

	i = 0;
	i_tab = 0;
	tab = game->map;
	while (tab[i_tab])
	{
		while (tab[i_tab][i])
		{
			if (tab[i_tab][i] == 'P')
				return (i_tab);
			i++;
		}
		i = 0;
		i_tab++;
	}
	return (-1);
}

int	ft_flood_fill(char **map, int x, int y, int to_find, t_game *game)
{
	if (y < 0 || y >= game->height || x < 0 || x >= game->width || to_find == 0)
		return (to_find);
	if (map[y][x] == 'C' || map[y][x] == 'E')
		to_find -= 1;
	if (map[y][x] == '1' || map[y][x] == 'K')
		return (to_find);
	map[y][x] = 'K';
	to_find = ft_flood_fill(map, x - 1, y, to_find, game);
	to_find = ft_flood_fill(map, x + 1, y, to_find, game);
	to_find = ft_flood_fill(map, x , y - 1, to_find, game);
	to_find = ft_flood_fill(map, x , y + 1, to_find, game);
	return (to_find);
}

void	ft_diffusion(t_game *game)
{
	int		x;
	int		y;
	int		check;
	int		to_find;
	char	**map;

	map = game->map;
	to_find = game->nb_c + 1;
	x = ft_find_x(game);
	y = ft_find_y(game);
	check = ft_flood_fill(map, x ,y, to_find, game);
	ft_free_map(game->map);
	if (check != 0)
		ft_error("Error\nExit or item are not reachable");
}
