/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:11:28 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/01 16:40:25 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close_mlx(t_game *game)
{
	int	i;

	i = game->height - 1;
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	while (i >= 0)
		free(game->map[i--]);
	free(game->map);
	free(game->mlx_ptr);
	free(game->homer->img_ptr);
	free(game->wall->img_ptr);
	free(game->exit->img_ptr);
	free(game->exit_w_homer->img_ptr);
	free(game->donuts->img_ptr);
	free(game->grass->img_ptr);
	free(game->homer);
	free(game->wall);
	free(game->exit);
	free(game->exit_w_homer);
	free(game->donuts);
	free(game->grass);

	exit (0);
}
