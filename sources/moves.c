/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:32:19 by henrik            #+#    #+#             */
/*   Updated: 2023/05/31 18:29:59 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close_mlx(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit (0);
}

void	ft_w_pressed(t_game *game, int x, int y)
{
	if (game->map[y - 1][x] != '1')
	{
		game->moves += 1;
		if (game->map[y - 1][x] == 'E')
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

void	ft_s_pressed(t_game *game, int x, int y)
{
	if (game->map[y + 1][x] != '1')
	{
		game->moves += 1;
		if (game->map[y + 1][x] == 'E')
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

void	ft_a_pressed(t_game *game, int x, int y)
{
	if (game->map[y][x - 1] != '1')
	{
		game->moves += 1;
		if (game->map[y][x - 1] == 'E')
		{
			if (game->nb_c == 0)
			{
				ft_printf("You won with %d moves", game->moves);
				ft_close_mlx(game);
			}
			else
			{
				game->map[y][x] = '0';
				ft_img_to_win(game, game->exit_w_homer, ((x - 1) * 64), (y * 64));
				ft_img_to_win(game, game->grass, (x * 64), (y * 64));
			}
		}
		else
		{
			if (game->map[y][x - 1] == 'C')
				game->nb_c -= 1;
			if (game->map[y][x] == 'E')
				ft_img_to_win(game, game->exit, (x * 64), (y * 64));
			else
			{
				game->map[y][x] = '0';
				ft_img_to_win(game, game->grass, (x * 64), (y * 64));
			}
			game->map[y][x - 1] = 'P';
			ft_img_to_win(game, game->homer, ((x - 1) * 64), (y * 64));
		}
		ft_printf("You made %d moves\n", game->moves);
	}
}

void	ft_d_pressed(t_game *game, int x, int y)
{
	if (game->map[y][x + 1] != '1')
	{
		game->moves += 1;
		if (game->map[y][x + 1] == 'E')
		{
			if (game->nb_c == 0)
			{
				ft_printf("You won with %d moves", game->moves);
				ft_close_mlx(game);
			}
			else
			{
				game->map[y][x] = '0';
				ft_img_to_win(game, game->exit_w_homer, ((x + 1) * 64), (y * 64));
				ft_img_to_win(game, game->grass, (x * 64), (y * 64));
			}
		}
		else
		{
			if (game->map[y][x + 1] == 'C')
				game->nb_c -= 1;
			if (game->map[y][x] == 'E')
				ft_img_to_win(game, game->exit, (x * 64), (y * 64));
			else
			{
				game->map[y][x] = '0';
				ft_img_to_win(game, game->grass, (x * 64), (y * 64));
			}
			game->map[y][x + 1] = 'P';
			ft_img_to_win(game, game->homer, ((x + 1) * 64), (y * 64));
		}
		ft_printf("You made %d moves\n", game->moves);
	}
}

int	ft_move_event(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (key == W)
		ft_w_pressed(game, x, y);
	else if (key == S)
		ft_s_pressed(game, x, y);
	else if (key == A)
		ft_a_pressed(game, x, y);
	else if (key == D)
		ft_d_pressed(game, x, y);
	else if (key == ESC)
		ft_close_mlx(game);
	// int i = 0;
	// while (game->map[i])
	// {
	// 	ft_printf("%s\n", game->map[i++]);
	// }
	return (key);
}
