/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:32:19 by henrik            #+#    #+#             */
/*   Updated: 2023/05/30 17:59:38 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close_mlx(t_game *game)
{
	ft_printf("you tryed to closed the window\n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	return (0);
}

void	ft_w_pressed(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->map[x][y - 1] != '1')
	{
		game->map[x][y - 1] = 'P';
		game->map[x][y] = '0';
		ft_img_to_win(game, game->homer, (x * 64), ((y - 1) * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
	}
	else
		ft_printf("home is at pos ; %d : %d / x : y", game->pos_x, game->pos_y);
}

void	ft_s_pressed(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->map[x][y + 1] != '1')
	{
		game->map[x][y + 1] = 'P';
		game->map[x][y] = '0';
		ft_img_to_win(game, game->homer, (x * 64), ((y + 1) * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
	}
	else
		ft_printf("home is at pos ; %d : %d / x : y", game->pos_x, game->pos_y);
}

void	ft_a_pressed(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->map[x - 1][y] != '1')
	{
		game->map[x - 1][y] = 'P';
		game->map[x][y] = '0';
		ft_img_to_win(game, game->homer, ((x - 1) * 64), (y * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
	}
	else
		ft_printf("home is at pos ; %d : %d / x : y", game->pos_x, game->pos_y);
}
void	ft_d_pressed(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->map[x + 1][y] != '1')
	{
		game->map[x + 1][y] = 'P';
		game->map[x][y] = '0';
		ft_img_to_win(game, game->homer, ((x + 1) * 64), (y * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
	}
	else
		ft_printf("home is at pos ; %d : %d / x : y", game->pos_x, game->pos_y);
}

int	ft_move_event(int key, t_game *game)
{
	int i = 0;
	while (game->map[i + 1])
	{
		ft_printf("%s\n", game->map[i++]);
	}
	if (key == W)
		ft_w_pressed(game);
	else if (key == S)
		ft_s_pressed(game);
	else if (key == A)
		ft_a_pressed(game);
	else if (key == D)
		ft_d_pressed(game);
	else if (key == ESC)
	{
		ft_close_mlx(game);
	}
	return (key);
}
