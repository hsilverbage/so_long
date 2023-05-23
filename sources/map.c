#include "../includes/so_long.h"

void	ft_add_image(t_game *game, char *img_path)
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

// void	ft_display_images(t_game *game, int x, int y)
// {
// 	t_image	*current;

// 	current = game->images;

// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, current->img_ptr, x, y);
// }

void	ft_add_walls_to_map(t_game *game)
{
	int	i;
	int	i_tab;

	i = 0;
	i_tab = 0;
	while (i_tab < game->height)
	{
		while (i < game->width)
		{
			if (game->map[i_tab][i] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->homer->img_ptr, i, i_tab);
			//	ft_display_images(game, '1', (i * 64), (i_tab * 64));
			// else if (game->map[i_tab][i] == '0')
			// 	ft_display_images(game, '0', (i * 64), (i_tab * 64));
			// if (game->map[i_tab][i] == 'C')
			// 	ft_display_images(game, 'c', (i * 64), (i_tab * 64));
			// if (game->map[i_tab][i] == 'P')
			// 	ft_display_images(game, 'p', (i * 64), (i_tab * 64));
			i++;
		}
		i = 0;
		i_tab++;
	}
}

void	ft_display_map(t_game *game)
{
	ft_add_image(game, "sprites/wall.xpm");
	// ft_add_image(game, "sprites/grass.xpm", game->grass);
	// ft_add_image(game, "sprites/homer.xpm", game->homer);
	// ft_add_image(game, "sprites/donut.xpm", game->donuts);

	ft_add_walls_to_map(game);


}