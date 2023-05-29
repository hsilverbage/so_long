

// void	ft_display_images(t_game *game, int x, int y)
// {
// 	t_image	*current;

// 	current = game->images;

// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, current->img_ptr, x, y);
// }


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

	game->wall = new;
}

void	ft_add_image_wall(t_game *game, char *img_path)
{
	t_image	*new_image;

	new_image = (t_image *)malloc(sizeof(t_image));
	if (!new_image)
		return ;
	new_image->height = 64;
	new_image->width = 64;
	new_image->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, img_path, &(new_image->width), &(new_image->height));
	new_image->img_path = img_path;
	new_image->next = NULL;

	game->wall = new_image;
}


/*
ALL FT FOR ADDING IMAGES


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

*/
