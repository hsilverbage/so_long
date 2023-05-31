#ifndef SO_LONG_H
# define SO_LONG_H


# ifdef __APPLE__
#  include "../mlx/mlx.h"
# elif __linux__
#  include "../mlx_linux/mlx.h"
# endif

# include <stdlib.h>
# include "../libft/libft.h"
# include "var.h"

typedef struct s_image
{
	void			*img_ptr;
	char			*img_path;
}				t_image;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		height;
	int		width;
	int		nb_c;
	int		pos_x; // horizontal
	int		pos_y; //veticale
	int		moves;
	t_image	*wall;
	t_image	*grass;
	t_image	*homer;
	t_image	*donuts;
	t_image	*exit;
}				t_game;

void	ft_error(char *s);
void	ft_check_walls(t_game *game, int lines);
void	ft_no_other_char(t_game *game);
void	ft_display_map(t_game *game);
void	ft_add_image(t_game *game, char *img_path, t_image **image);
void	ft_img_to_win(t_game *game, t_image *image, int x, int y);
void	ft_add_sprites_to_map(t_game *game);

int		ft_parsing(char **argv, t_game *game);
int		ft_close_mlx(t_game *game);
int		ft_move_event(int key, t_game *game);

#endif
