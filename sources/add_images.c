/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:48:25 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/26 16:55:58 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_add_image_wall(t_game *game, char *img_path)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	if (!new)
		return ;
	new->height = 64;
	new->width = 64;
	new->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, img_path, &(new->width), &(new->height));
	new->img_path = img_path;
	new->next = NULL;

	game->wall = new;
}

void	ft_add_image_grass(t_game *game, char *img_path)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	if (!new)
		return ;
	new->height = 64;
	new->width = 64;
	new->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, img_path, &(new->width), &(new->height));
	new->img_path = img_path;
	new->next = NULL;

	game->grass = new;
}

void	ft_add_image_donuts(t_game *game, char *img_path)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	if (!new)
		return ;
	new->height = 64;
	new->width = 64;
	new->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, img_path, &(new->width), &(new->height));
	new->img_path = img_path;
	new->next = NULL;

	game->donuts = new;
}

void	ft_add_image_homer(t_game *game, char *img_path)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	if (!new)
		return ;
	new->height = 64;
	new->width = 64;
	new->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, img_path, &(new->width), &(new->height));
	new->img_path = img_path;
	new->next = NULL;

	game->homer = new;
}
void	ft_add_image_exit(t_game *game, char *img_path)
{
	t_image	*new;

	new = malloc(sizeof(t_image));
	if (!new)
		return ;
	new->height = 64;
	new->width = 64;
	new->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, img_path, &(new->width), &(new->height));
	new->img_path = img_path;
	new->next = NULL;

	game->exit = new;
}
