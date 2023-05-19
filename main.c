#include "so_long.h"

void	ft_add_image(t_window *window, char *img_path)
{
	t_image	*new_image;
	t_image *current = window->images;

	new_image = (t_image *)malloc(sizeof(t_image));
	if (!new_image)
		return ;
	new_image->height = 64;
	new_image->width = 64;
	new_image->img_ptr = mlx_xpm_file_to_image(window->mlx_ptr, img_path, &(new_image->width), &(new_image->height));
	new_image->img_path = img_path;
	new_image->next = NULL;

	if (window->images == NULL)
		window->images = new_image;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_image;
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
int	main(int argc, char **argv)
{
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
