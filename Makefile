SRCS = ./SRCS/ft_fdf.c ./SRCS/init_structs.c ./SRCS/checks.c

NAME = ft_fdf

FLAGS = -Wall -Werror -Wextra

LIBFT = libft

MINLIB = minilibx_macos

MINILIBX = -I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

GCC = gcc

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@make -C $(MINLIB)
	$(GCC) $(FLAGS) $(MINILIBX) $(SRCS) -L $(LIBFT) -lft -o $(NAME)

clean:
	@rm -rf $(NAME)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)

re: fclean all

debug:
	@gcc $(SRCS) -L $(LIBFT) -lft -o $(NAME) -g -fsanitize=address