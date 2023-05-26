#include "../includes/so_long.h"

// void	ft_add_walls_to_map(t_game *game)
// {
// 	int	i;
// 	int	i_tab;

// 	i = 0;
// 	i_tab = 0;
// 	while (i_tab < game->height)
// 	{
// 		while (i < game->width)
// 		{
// 			if (game->map[i_tab][i] == '1')
// 				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->wall->img_ptr, i, i_tab);
// 			//	ft_display_images(game, '1', (i * 64), (i_tab * 64));
// 			// else if (game->map[i_tab][i] == '0')
// 			// 	ft_display_images(game, '0', (i * 64), (i_tab * 64));
// 			// if (game->map[i_tab][i] == 'C')
// 			// 	ft_display_images(game, 'c', (i * 64), (i_tab * 64));
// 			// if (game->map[i_tab][i] == 'P')
// 			// 	ft_display_images(game, 'p', (i * 64), (i_tab * 64));
// 			i++;
// 		}
// 		i = 0;
// 		i_tab++;
// 	}
// }

void	ft_show_img_in_window(t_game *game, t_image *image, int x, int y)
{
	t_image	*current;

	current = image;
	// ft_printf("%p \n", image);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, current->img_ptr, x, y);
}

void	ft_display_map(t_game *game)
{
	// ft_add_image_wall(game, "sprites/wall.xpm");
	//ft_add_image_grass(game, "sprites/grass.xpm");
	// ft_add_image_homer(game, "sprites/homer.xpm");
	ft_add_image_donuts(game, "sprites/donuts.xmp");

	// ft_printf("wall : %p \n", game->wall);
	// ft_printf("grass : %p \n", game->grass);

	// ft_show_img_in_window(game, game->wall, 0, 0);
	ft_printf("%p\n", game->donuts->img_ptr);
	if (game->donuts->img_ptr)
		ft_show_img_in_window(game, game->donuts, 64, 64);
	//ft_add_walls_to_map(game->wall);


}
