/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:11:28 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/29 20:13:29 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_all(t_game *game)
{


}

int	ft_close_mlx(t_game *game)
{
	if (game->map.map_char)
		free_map(game->map.map_char);
	ft_free_all(game);
	if (game->mlx.win != NULL)
		mlx_destroy_window(game->mlx.init, game->win_ptr);
	mlx_destroy_display(game->mlx.init);
	free(game->mlx.init);
	exit(0);
	return (0);
}
