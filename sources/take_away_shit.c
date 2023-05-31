

/*

EVENT FT



FT_PRESSED_KEY


void	ft_s_pressed(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->map[x][y + 1] != '1')
	{
		game->map[x][y + 1] = 'P';
		game->map[x][y] = '0';
		ft_img_to_win(game, game->homer, (x * 64), ((y + 1) * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
	}
	else
		ft_printf("home is at pos ; %d : %d / x : y", game->pos_x, game->pos_y);
}

void	ft_a_pressed(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->map[x - 1][y] != '1')
	{
		game->map[x - 1][y] = 'P';
		game->map[x][y] = '0';
		ft_img_to_win(game, game->homer, ((x - 1) * 64), (y * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
	}
	else
		ft_printf("home is at pos ; %d : %d / x : y", game->pos_x, game->pos_y);
}
void	ft_d_pressed(t_game *game)
{
	int	x;
	int	y;

	x = game->pos_x;
	y = game->pos_y;
	if (game->map[x + 1][y] != '1')
	{
		game->map[x + 1][y] = 'P';
		game->map[x][y] = '0';
		ft_img_to_win(game, game->homer, ((x + 1) * 64), (y * 64));
		ft_img_to_win(game, game->grass, (x * 64), (y * 64));
	}
	else
		ft_printf("home is at pos ; %d : %d / x : y", game->pos_x, game->pos_y);
}

*/

