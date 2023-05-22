#include "so_long.h"

char	**ft_create_map(char **argv, char **map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = line;
	return (map);
}

int	ft_parsing(char **argv)
{
	char	**map;

	map = ft_create_map(argv, map);
	return (0);
}
