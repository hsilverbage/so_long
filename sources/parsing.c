#include "../includes/so_long.h"

int	ft_check_if_ber(char *str)
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

char	**ft_create_map(char **argv, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		game->map[i++] = line;
		line = get_next_line(fd);
	}
	game->map[i] = line;
	return (game->map);
}

int	ft_parsing(char **argv, t_game *game)
{
	if (ft_check_if_ber(argv[1]) == -1)
		exit (0);
	game->map = ft_create_map(argv, game);
	return (0);
}
