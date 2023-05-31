/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:32:19 by henrik            #+#    #+#             */
/*   Updated: 2023/05/31 16:29:45 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close_mlx(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit (0);
}

void	ft_w_pressed(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->map[y - 1][x] != '1')
	{
		game->moves += 1;
		game->map[y - 1][x] = 'P';
		game->map[y][x] = '0';
		ft_img_to_win(game, game->homer, (x * 64), ((y - 1) * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
		ft_printf("You made %d moves\n", game->moves);
	}
}

void	ft_s_pressed(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->map[y + 1][x] != '1')
	{
		game->map[y + 1][x] = 'P';
		game->map[y][x] = '0';
		ft_img_to_win(game, game->homer, (x * 64), ((y + 1) * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
		game->moves += 1;
		ft_printf("You made %d moves\n", game->moves);
	}

}

void	ft_a_pressed(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->map[y][x - 1] != '1')
	{
		game->map[y][x - 1] = 'P';
		game->map[y][x] = '0';
		ft_img_to_win(game, game->homer, ((x - 1) * 64), (y * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
		game->moves += 1;
		ft_printf("You made %d moves\n", game->moves);
	}

}

void	ft_d_pressed(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->map[y][x + 1] != '1')
	{
		game->map[y][x + 1] = 'P';
		game->map[y][x] = '0';
		ft_img_to_win(game, game->homer, ((x + 1) * 64), (y * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
		game->moves += 1;
		ft_printf("You made %d moves\n", game->moves);
	}

}

int	ft_move_event(int key, t_game *game)
{
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
	int i = 0;
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i++]);
	}
	return (key);
}
