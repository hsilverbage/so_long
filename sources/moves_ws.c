/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:23:38 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/01 14:25:25 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_if_exit_w(t_game *game, int x, int y)
{
	if (game->nb_c == 0)
	{
		ft_printf("You won with %d moves", game->moves);
		ft_close_mlx(game);
	}
	else
	{
		game->map[y][x] = '0';
		ft_img_to_win(game, game->exit_w_homer, (x * 64), ((y - 1) * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
	}
}
void	ft_w_pressed(t_game *game, int x, int y)
{
	if (game->map[y - 1][x] != '1')
	{
		game->moves += 1;
		if (game->map[y - 1][x] == 'E')
		{
			ft_if_exit_w(game, x, y);
		}
		else
		{
			if (game->map[y - 1][x] == 'C')
				game->nb_c -= 1;
			if (game->map[y][x] == 'E')
				ft_img_to_win(game, game->exit, (x * 64), (y * 64));
			else
			{
				game->map[y][x] = '0';
				ft_img_to_win(game, game->grass, (x * 64), (y * 64));
			}
			game->map[y - 1][x] = 'P';
			ft_img_to_win(game, game->homer, (x * 64), ((y - 1) * 64));
		}
		ft_printf("You made %d moves\n", game->moves);
	}
}
void	ft_if_exit_s(t_game *game, int x, int y)
{
	if (game->nb_c == 0)
	{
		ft_printf("You won with %d moves", game->moves);
		ft_close_mlx(game);
	}
	else
	{
		game->map[y][x] = '0';
		ft_img_to_win(game, game->exit_w_homer, (x * 64), ((y + 1) * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
	}
}
void	ft_s_pressed(t_game *game, int x, int y)
{
	if (game->map[y + 1][x] != '1')
	{
		game->moves += 1;
		if (game->map[y + 1][x] == 'E')
		{
			ft_if_exit_s(game, x, y);
		}
		else
		{
			if (game->map[y + 1][x] == 'C')
				game->nb_c -= 1;
			if (game->map[y][x] == 'E')
				ft_img_to_win(game, game->exit, (x * 64), (y * 64));
			else
			{
				game->map[y][x] = '0';
				ft_img_to_win(game, game->grass, (x * 64), (y * 64));
			}
			game->map[y + 1][x] = 'P';
			ft_img_to_win(game, game->homer, (x * 64), ((y + 1) * 64));
		}
		ft_printf("You made %d moves\n", game->moves);
	}
}
