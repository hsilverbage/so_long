/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:32:19 by henrik            #+#    #+#             */
/*   Updated: 2023/05/30 11:57:26 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close_mlx(t_game *game)
{
	ft_printf("you tryed to closed the window\n");
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	return (0);
}

// void	ft_w_pressed(t_game *game)
// {

// 	ft_printf("W has been pressed\n");
// }

// void	ft_s_pressed(t_game *game)
// {



// }

// void	ft_a_pressed(t_game *game)
// {



// }
// void	ft_d_pressed(t_game *game)
// {



// }

int	ft_move_event(int key, t_game *game)
{
	if (key == W)
		ft_printf("W has been pressed\n");//ft_w_pressed(game);
	else if (key == S)
		ft_printf("S has been pressed\n"); //game = ft_s_pressed();
	else if (key == A)
		ft_printf("A has been pressed\n"); //game = ft_a_pressed();
	else if (key == D)
		ft_printf("D has been pressed\n"); //game = ft_d_pressed();
	else if (key == ESC)
	{
		ft_close_mlx(game);
	}
	return (key);
}
