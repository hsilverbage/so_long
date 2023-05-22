.PHONY: 		clean fclean re norm

NAME = so_long

CC = gcc

ifeq ($(shell uname),Linux)
	MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o
	CFLAGS = -Wall -Wextra -Werror -ggdb
	MAKEFLAGS	+= --no-print-directory -s
	MLX_DIR = mlx_linux/
else
	CFLAGS = -Wall -Wextra -Werror
	MLXFLAGS = -framework OpenGL -framework AppKit -Lmlx -lmlx -lm
	MLX_DIR = mlx/
endif

DISPLAY = @printf

# COLORS
RED=\033[0;31m
BLUE=\033[0;34m
GREEN=\033[0;32m
YELLOW=\033[0;33m
END=\033[0m

SRC_DIR = .
OBJ_DIR = .obj

LIBFT_A		= libft.a
LIBF_DIR 	= libft/
LIBFT		= $(addprefix $(LIBF_DIR), $(LIBFT_A))

MLX_A		= libmlx.a
MLX			= $(addprefix $(MLX_DIR), $(MLX_A))


SRC = $(SRC_DIR)/main.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): libft $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) $(MLX) -o $(NAME)
	@echo "$(GREEN)Compilation succeded ! ✔️$(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/game
	@$(CC) $(CFLAGS) -I mlx -c $< -o $@

libft:
	@make -C ./libft

norm:
	@norminette ./libft | grep "Error" && echo "$(RED)Norminette KO!$(END)" || echo "$(GREEN)Norminette OK!$(END)"

clean:
	@echo "$(YELLOW)All .o files deleted 🗑 $(END)"
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW)The final program is deleted 🗑 $(END)"
	@rm -f $(NAME)

re: fclean norm all
