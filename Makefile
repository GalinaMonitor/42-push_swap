NAME = push_swap
CC = gcc

# FLAGS = -Wall -Werror -Wextra

DIR_LIBFT = libft/
LIBFT = libft/libft.a

HEADER = push_swap.h

PUSH_SWAP_SRC = push_swap.c

SOURCES_LIBFT = $(addprefix $(DIR_LIBFT), $(LIBFT))

all: $(NAME)

$(NAME): $(LIBFT) $(PUSH_SWAP_SRC)
	@$(CC) $(FLAGS) $(PUSH_SWAP_SRC) $(LIBFT) -o $(NAME)
	@echo "prog is ready to use"

$(LIBFT) :
	$(MAKE) -C $(DIR_LIBFT)

bonus: all
	@echo "minitalk with bonuses is ready to use"

clean:
	$(MAKE) clean -C $(DIR_LIBFT)

fclean:
	$(MAKE) fclean -C $(DIR_LIBFT)
	@rm -f $(NAME)

re: fclean all

.PHONY : all re fclean bonus clean
