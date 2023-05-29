/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:32:19 by henrik            #+#    #+#             */
/*   Updated: 2023/05/29 17:19:40 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_w_pressed(t_game *game)
{
	


}

int	ft_move_event(int key, t_game *game)
{
	if (key == W)
		env = ft_w_pressed();
	else if (key == S)
		env = ft_s_pressed();
	else if (key == A)
		env = ft_a_pressed();
	else if (key == D)
		env = ft_d_pressed();
	else if (key == ESC)
	{
		//ft_close_mlx(env);
		ft_printf("%s\n", "close window");
	}
	return (key);
}
