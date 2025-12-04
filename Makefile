NAME = push_swap
SRCS = srcs/main.c srcs/parse.c srcs/validate.c srcs/indexify.c srcs/radix.c \
		srcs/ops.c srcs/utils.c srcs/mini_sort_utils.c srcs/mini_sort.c \
		srcs/hybrid.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
