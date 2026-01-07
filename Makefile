NAME = push_swap
SRCS = srcs/main.c srcs/parse.c srcs/validate.c srcs/indexify.c srcs/radix.c \
		srcs/ops.c srcs/utils.c srcs/mini_sort_utils.c srcs/mini_sort.c \
		srcs/push.c srcs/swap.c srcs/rotate.c srcs/rotate_suite.c \
		srcs/parse_supp.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) fclean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
