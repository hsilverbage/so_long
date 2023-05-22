#include "./includes/so_long.h"

void	ft_add_image(t_game *game, char *img_path)
{
	//new = new

	t_image	*new;
	t_image *current;

	current = game->images;
	new = (t_image *)malloc(sizeof(t_image));
	if (!new)
		return ;
	new->height = 64;
	new->width = 64;
	new->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, img_path, &(new->width), &(new->height));
	new->img_path = img_path;
	new->next = NULL;

	if (game->images == NULL)
		game->images = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

void	ft_display_images(t_game *game)
{
	t_image	*current;
	int x = 0;
	int y = 0;

	current = game->images;
	while (current != NULL)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, current->img_ptr, x, y);
		//x += current->width;
		current = current->next;
	}
}

void	ft_free_all(t_game *game)
{
	t_image *current;
	t_image *next;

	current = game->images;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		mlx_destroy_image(game->mlx_ptr, current->img_ptr);
		free(current);
		current = next;
	}
}


void	ft_error(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));

	if (argc != 2)
		ft_error("Wrong number of arguments");
	ft_parsing(argv, &game);

	// int i = 0;
	// while (game.map)
	// 	ft_printf(game.map[i++]);

	// game.mlx_ptr = mlx_init();
	// game.win_ptr = mlx_new_window(game.mlx_ptr, 1000, 700, "so_long");

	// ft_add_image(&game, "sprites/wall.xpm");
	// ft_add_image(&game, "sprites/grass.xpm");
	// ft_add_image(&game, "sprites/homer.xpm");
	// ft_add_image(&game, "sprites/donut.xpm");

	// ft_display_images(&game);
	// mlx_loop(game.mlx_ptr);

	// ft_free_all(&game);

	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (argc != 2 || ft_parsing(argv[1]) == - 1)
// 		return (0);
// 	t_window	window;

// 	window.mlx_ptr = mlx_init();
// 	window.win_ptr = mlx_new_window(window.mlx_ptr, 1000, 700, "so_long");
// 	window.images = NULL;

// 	ft_add_image(&window, "sprites/wall.xpm");
// 	ft_add_image(&window, "sprites/grass.xpm");
// 	ft_add_image(&window, "sprites/homer.xpm");
// 	ft_add_image(&window, "sprites/donut.xpm");

// 	ft_display_images(&window);
// 	mlx_loop(window.mlx_ptr);

// 	ft_free_all(&window);

// 	return (0);
// }