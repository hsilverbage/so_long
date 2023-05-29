#include "../includes/so_long.h"

void	ft_img_to_win(t_game *game, t_image *image, int x, int y)
{
	t_image	*tmp;

	tmp = image;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, tmp->img_ptr, x, y);
}

void	ft_add_image(t_game *game, char *img_path, t_image **image)
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

	*image = new;
}

void	ft_add_sprites_to_map(t_game *game)
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
				ft_img_to_win(game, game->wall, (i * 64), (i_tab * 64));
			else if (game->map[i_tab][i] == '0')
				ft_img_to_win(game, game->grass, (i * 64), (i_tab * 64));
			else if (game->map[i_tab][i] == 'C')
				ft_img_to_win(game, game->donuts, (i * 64), (i_tab * 64));
			else if (game->map[i_tab][i] == 'P')
				ft_img_to_win(game, game->homer, (i * 64), (i_tab * 64));
			else if (game->map[i_tab][i] == 'E')
				ft_img_to_win(game, game->exit, (i * 64), (i_tab * 64));
			i++;
		}
		i = 0;
		i_tab++;
	}
}

void	ft_display_map(t_game *game)
{
	ft_add_image(game, "sprites/wall.xpm", &game->wall);
	ft_add_image(game, "sprites/grass.xpm", &game->grass);
	ft_add_image(game, "sprites/donuts.xpm", &game->donuts);
	ft_add_image(game, "sprites/homer.xpm", &game->homer);
	ft_add_image(game, "sprites/exit.xpm", &game->exit);

	ft_add_sprites_to_map(game);
}
