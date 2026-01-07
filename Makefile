# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 15:40:45 by mchiacha          #+#    #+#              #
#    Updated: 2026/01/07 15:40:46 by mchiacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
INCLUDE_DIR = ./include
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

norm:
	norminette $(LIBFT_DIR) $(SRCS) $(INCLUDE_DIR)

re: fclean all

.PHONY: all clean fclean re norm
