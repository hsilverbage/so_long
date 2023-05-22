#include "./includes/so_long.h"

void	ft_add_image(t_window *window, char *img_path)
{
	//new = new

	t_image	*new;
	t_image *current;

	current = window->images;
	new = (t_image *)malloc(sizeof(t_image));
	if (!new)
		return ;
	new->height = 64;
	new->width = 64;
	new->img_ptr = mlx_xpm_file_to_image(window->mlx_ptr, img_path, &(new->width), &(new->height));
	new->img_path = img_path;
	new->next = NULL;

	if (window->images == NULL)
		window->images = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

void	ft_display_images(t_window *window)
{
	t_image	*current;
	int x = 0;
	int y = 0;

	current = window->images;
	while (current != NULL)
	{
		mlx_put_image_to_window(window->mlx_ptr, window->win_ptr, current->img_ptr, x, y);
		//x += current->width;
		current = current->next;
	}
}

void	ft_free_all(t_window *window)
{
	t_image *current;
	t_image *next;

	current = window->images;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		mlx_destroy_image(window->mlx_ptr, current->img_ptr);
		free(current);
		current = next;
	}
}

int	ft_parsing(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (!(str[i - 1] == 'r' && str[i - 2] == 'e'
			&& str[i - 3] == 'b' && str[i - 4] == '.'))
	{
		write(1, "Invalid extension !", 20);
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || ft_parsing(argv[1]) == - 1)
		return (0);
	t_window	window;

	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, 1000, 700, "so_long");
	window.images = NULL;

	ft_add_image(&window, "sprites/wall.xpm");
	ft_add_image(&window, "sprites/grass.xpm");
	ft_add_image(&window, "sprites/homer.xpm");
	ft_add_image(&window, "sprites/donut.xpm");

	ft_display_images(&window);
	mlx_loop(window.mlx_ptr);

	ft_free_all(&window);

	return (0);
}
