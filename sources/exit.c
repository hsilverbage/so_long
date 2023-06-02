/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:11:28 by hsilverb          #+#    #+#             */
/*   Updated: 2023/06/02 17:57:33 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int	ft_close_mlx(t_game *game)
// {
// 	int	i;

// 	i = game->height - 1;
// 	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
// 	mlx_destroy_display(game->mlx_ptr);
// 	while (i >= 0)
// 	{
// 		free(game->map[i]);
// 		ft_printf("map line %d is freed\n", i);
// 		i--;
// 	}
// 	free(game->map);
// 	free(game->mlx_ptr);
// 	// free(game->homer->img_ptr);
// 	// free(game->wall->img_ptr);
// 	// free(game->exit->img_ptr);
// 	// free(game->exit_w_homer->img_ptr);
// 	// free(game->donuts->img_ptr);
// 	// free(game->grass->img_ptr);
// 	// free(game->homer);
// 	// free(game->wall);
// 	// free(game->exit);
// 	// free(game->exit_w_homer);
// 	// free(game->donuts);
// 	// free(game->grass);

// 	exit (0);
// }
//Free so_long

void	ft_free_map(char **str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	// free(str);
}
void	ft_destory_image(t_game *game)
{
	if (game) //&& CREATE AN INT THAT CHANGES ONCE I VE CREATED THE SPRITES
	{
		if (game->homer->img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->homer->img_ptr);
		if (game->exit->img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->exit->img_ptr);
		if (game->donuts->img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->donuts->img_ptr);
		if (game->grass->img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->grass->img_ptr);
		if (game->wall->img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->wall->img_ptr);
		if (game->exit_w_homer->img_ptr)
			mlx_destroy_image(game->mlx_ptr, game->exit_w_homer->img_ptr);
	}
}

static void	ft_free_all(t_game *game)
{
	ft_destory_image(game);
	if (game->homer)
		free(game->homer);
	if (game->grass)
		free(game->grass);
	if (game->wall)
		free(game->wall);
	if (game->donuts)
		free(game->donuts);
	if (game->exit)
		free(game->exit);
	if (game->exit_w_homer)
		free(game->exit_w_homer);
		// free(game->homer);
	// free(game->wall);
	// free(game->exit);
	// free(game->homer);
	// free(game->exit_w_homer);
	// free(game->donuts);
	// free(game->grass);
}

int	ft_close_mlx(t_game *game)
{
	if (game->map)
		ft_free_map(game->map);
	ft_free_all(game);
	if (game->mlx_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	//free(game->win_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

