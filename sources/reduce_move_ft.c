void	ft_w_pressed(t_game *game, int x, int y, int k)
{
	if (game->map[k][x] != '1')
	{
		game->moves += 1;
		if (game->map[k][x] == 'E')
		{
			if (game->nb_c == 0)
			{
				ft_printf("You won with %d moves", game->moves);
				ft_close_mlx(game);
			}
			else
			{
				game->map[y][x] = '0';
				ft_img_to_win(game, game->exit_w_homer, (x * 64), (k * 64));
				ft_img_to_win(game, game->grass, (x * 64), (y * 64));
			}
		}
		else
		{
			if (game->map[k][x] == 'C')
				game->nb_c -= 1;
			if (game->map[y][x] == 'E')
				ft_img_to_win(game, game->exit, (x * 64), (y * 64));
			else
			{
				game->map[y][x] = '0';
				ft_img_to_win(game, game->grass, (x * 64), (y * 64));
			}
			game->map[k][x] = 'P';
			ft_img_to_win(game, game->homer, (x * 64), (k * 64));
		}
		ft_printf("You made %d moves\n", game->moves);
	}
}
