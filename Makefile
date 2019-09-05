SRCS = 

FLAGS = -Wall -Wextra -Werror

NAME = ft_fdf

LIBFT = libft

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@gcc $(FLAGS) $(SRCS) -L $(LIBFT) -lft -o $(NAME)

clean:
	@rm -rf $(NAME)
	@rm -rf ft_ls.dSYM
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)

re: fclean all

debug:
	@gcc $(SRCS) -L $(LIBFT) -lft -o $(NAME) -g -fsanitize=address


