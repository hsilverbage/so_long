/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsilverb <hsilverb@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:36:12 by hsilverb          #+#    #+#             */
/*   Updated: 2023/05/29 20:29:14 by hsilverb         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_error(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
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
	mlx_hook(game.win_ptr, 17, 1L << 2, ft_close_mlx, &game); //17 = destroy - ft_close ft destroy
	mlx_hook(game.win_ptr, 2, 1L << 0, ft_move_event, &game); // 2 = key pressed, ft_moves event if W or if A ..
	mlx_loop(game.mlx_ptr);

	return (0);
}
