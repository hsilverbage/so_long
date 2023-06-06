/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:10 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/06 16:46:10 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_walls(t_game *game, int lines)
{
	int	i;
	int	i_tab;

	i = (game->width - 1);
	i_tab = 1;
	while (i_tab < lines - 1)
	{
		if (game->map[i_tab][0] != '1' || game->map[i_tab][i] != '1')
			ft_error("Error\nMap is not surrounded by walls", game);
		i_tab++;
	}
	i = 0;
	while (game->map[i_tab][i])
	{
		if (game->map[0][i] != '1' || game->map[i_tab][i] != '1')
			ft_error("Error\nMap is not surrounded by walls", game);
		i++;
	}
}

void	ft_check_c(t_game *game)
{
	int	c;
	int	i;
	int	i_tab;

	c = 0;
	i = 0;
	i_tab = 0;

	while (i_tab < (game->height - 1))
	{
		while (i < (game->width - 1))
		{
			if (game->map[i_tab][i] == 'C')
				c += 1;
			i++;
		}
		i = 0;
		i_tab++;
	}
	if (c < 1)
		ft_error("Error\nInput at least one C", game);
	game->nb_c = c;

}

void	ft_check_e_and_p(t_game *game)
{
	int	e;
	int	p;
	int	i;
	int	i_tab;

	i = 0;
	i_tab = 0;
	e = 0;
	p = 0;
	while (i_tab < (game->height - 1))
	{
		while (i < (game->width - 1))
		{
			if (game->map[i_tab][i] == 'E')
				e += 1;
			if (game->map[i_tab][i] == 'P')
				p += 1;
			i++;
		}
		i = 0;
		i_tab++;
	}
	if (e != 1 || p != 1)
		ft_error("Error\nInput one E and one P", game);
	ft_check_c(game);
}

void	ft_no_other_char(t_game *game)
{
	int	i;
	int	i_tab;

	i = 0;
	i_tab = 0;
	while (i_tab < (game->height - 1))
	{
		while (i < (game->width - 1))
		{
			if (game->map[i_tab][i] != '1' && game->map[i_tab][i] != '0'
					&& game->map[i_tab][i] != 'C' && game->map[i_tab][i] != 'P'
					&& game->map[i_tab][i] != 'E')
				ft_error("Error\nOnly 1 0 C E P are valid inputs in the map", game);
			i++;
		}
		i = 0;
		i_tab++;
	}
	ft_check_e_and_p(game);
}
