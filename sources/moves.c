/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrik <henrik@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:32:19 by henrik            #+#    #+#             */
/*   Updated: 2023/05/29 17:09:41 by henrik           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_move_event(int key, t_game *game)
{
	if (key == W)
		env = w_pressed(env, 1);
	else if (key == S)
		env = s_pressed(env, 2);
	else if (key == A)
		env = a_pressed(env, 3);
	else if (key == D)
		env = d_pressed(env, 4);
	else if (key == ESC)
	{
		close_mlx(env);
		ft_printf("%s\n", "close window");
	}
	else
		ft_printf("%s\n", "invalid key");
	return (key);
}
