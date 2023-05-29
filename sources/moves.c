/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:32:19 by henrik            #+#    #+#             */
/*   Updated: 2023/05/29 19:53:42 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_close_mlx(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}

// void	ft_w_pressed(t_game *game)
// {



// }

int	ft_move_event(int key, t_game *game)
{
	// if (key == W)
	// 	game = ft_w_pressed();
	// else if (key == S)
	// 	game = ft_s_pressed();
	// else if (key == A)
	// 	game = ft_a_pressed();
	// else if (key == D)
	// 	game = ft_d_pressed();
	// else
	if (key == ESC)
	{
		ft_printf("you suck");
		ft_close_mlx(game);
		ft_printf("%s\n", "close window");
	}
	return (key);
}
