#include "../includes/so_long.h"

void	ft_show_img_in_window(t_game *game, t_image *image, int x, int y)
{
	t_image	*current;

	current = image;
	// ft_printf("%p \n", image);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, current->img_ptr, x, y);
}
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
				ft_show_img_in_window(game, game->wall, (i * 64), (i_tab * 64));
			else if (game->map[i_tab][i] == '0')
				ft_show_img_in_window(game, game->grass, (i * 64), (i_tab * 64));
			if (game->map[i_tab][i] == 'C')
				ft_show_img_in_window(game, game->donuts, (i * 64), (i_tab * 64));
			if (game->map[i_tab][i] == 'P')
				ft_show_img_in_window(game, game->homer, (i * 64), (i_tab * 64));
			// if (game->map[i_tab][i] == 'E')
			// 	ft_show_img_in_window(game, game->exit, (i * 64), (i_tab * 64));
			i++;
		}
		i = 0;
		i_tab++;
	}
}
void	ft_display_map(t_game *game)
{
	ft_add_image_wall(game, "sprites/wall.xpm");
	ft_add_image_grass(game, "sprites/grass.xpm");
	ft_add_image_donuts(game, "sprites/donuts.xpm");
	ft_add_image_homer(game, "sprites/homer.xpm");
	//ft_add_image_homer(game, "sprites/exit.xpm");

	// ft_show_img_in_window(game, game->wall, 0, 0);
	// ft_show_img_in_window(game, game->grass, 64, 64);
	// ft_show_img_in_window(game, game->donuts, 0, 64);
	// ft_show_img_in_window(game, game->homer, 64, 0);
	ft_add_walls_to_map(game);

}
