#ifndef			SO_LONG_H
# define		SO_LONG_H


# ifdef __APPLE__
#  include "../mlx/mlx.h"
# elif __linux__
#  include "../mlx_linux/mlx.h"
# endif

# include <stdlib.h>
# include "../libft/libft.h"
# include "var.h"
# include "struct.h"

typedef struct s_image
{
	void			*img_ptr;
	char			*img_path;
	int				width;
	int				height;
	struct s_image	*next;
}				t_image;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	*images;
}				t_window;

#endif
