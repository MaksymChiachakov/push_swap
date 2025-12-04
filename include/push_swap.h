#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int *a;
	int *b;
	int size_a;
	int size_b;
	int cap;
}	t_stack;

/* parse.c */
char **split_args(int argc, char **argv);
char **split_str(const char *s);
void	free_tokens(char **tokens);

/* validate.c */
int	parse_integers(char **tokens, int **out_arr, int *out_n);
int	check_duplicates(int *arr, int n);

/* indexify.c */
int *indexify(int *arr, int n);

/* radix.c */
void	radix_with_ops(t_stack *s);

/* ops.c */
t_stack *stack_init(int n);
void mini_sort(t_stack *s);
void sort_2(t_stack *s);
void sort_3(t_stack *s);
void sort_4(t_stack *s);
void sort_5(t_stack *s);
void    push_min_to_b(t_stack *s);
int find_min_pos(t_stack *s);


void push_chunks_to_b(t_stack *s, int n_chunks);
void push_back_to_a(t_stack *s);

void stack_free(t_stack *s);
void	pa(t_stack *s);
void	pb(t_stack *s);
void	ss(t_stack *s);
void	sa(t_stack *s);
void	sb(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);
void	rrr(t_stack *s);

void	rra(t_stack *s);
void	rrb(t_stack *s);

/* utils.c */
long	ft_atol(const char *s);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);

#endif
