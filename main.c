/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:12 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/23 18:49:27 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

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

	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, (game.width * 64), (game.height * 64), "so_long");
	ft_display_map(&game);
	mlx_loop(game.mlx_ptr);

	// ft_free_all(&game);

	return (0);
}
