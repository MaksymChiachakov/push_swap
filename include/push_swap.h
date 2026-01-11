/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:33:15 by mchiacha          #+#    #+#             */
/*   Updated: 2026/01/07 15:33:31 by mchiacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	cap;
}	t_stack;

/* parse.c */
char	**split_args(int argc, char **argv);
char	**split_str(const char *s);
void	free_tokens(char **tokens);
char	**split_str_supp(int i, char **res);
void	split_str_supp_len(int *i, int *j, char **res, const char *p);
int		split_args_fill(char **all, char **argv, int argc);

/* validate.c */
int		parse_integers(char **tokens, int **out_arr, int *out_n);
int		check_duplicates(int *arr, int n);

/* indexify.c */
int		*indexify(int *arr, int n);

/* hybrid.c */
void	push_back_to_a(t_stack *s);

/* ops.c */
t_stack	*stack_init(int n);
void	stack_free(t_stack *s);
void	rotate_left(int *arr, int len);
void	rotate_right(int *arr, int len);
void	pa(t_stack *s);
void	pb(t_stack *s);
void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);

/* mini_sort.c */
void	mini_sort(t_stack *s);
void	sort_2(t_stack *s);
void	sort_3(t_stack *s);
void	sort_4(t_stack *s);
void	sort_5(t_stack *s);

/* mini_sort_utils.c */
int		find_min_pos(t_stack *s);
void	push_min_to_b(t_stack *s);
void	push_back_to_a(t_stack *s);
void	push_chunks_to_b(t_stack *s, float n_chunks);
void	radix_with_ops(t_stack *s);

/* utils.c */
long	ft_atol(const char *s);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

#endif
