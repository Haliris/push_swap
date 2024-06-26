/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:54:09 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/25 16:29:40 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>
# define TRUE 1
# define FALSE 0
# define MEDIAN(stack) ((stack_a->size / 2) + (stack_a->size % 2));

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	long			*data;
	size_t			cost[2];
	int				synchro;
}	t_stack;

typedef struct s_stack_list
{
	t_stack	*head;
	t_stack	*tail;
	size_t	size;
}	t_lst;

int				is_sorted(t_lst *stack);
int				find_duplicates(long *args, int size);

long			ft_check_atol(char *str, long *args);
void			handle_error(int code);
long			*parse_args(char **av, int size);
void			add_node(t_lst *stack, long *data);
void			add_node_front(t_lst *stack, long *data);
void			replace_head(t_lst *stack, t_stack *new_head);
void			replace_tail(t_lst *stack, t_stack *new_tail);
t_lst			*initialize(long *args, size_t size);
void			trash_list(t_lst **lst);
void			ft_free(void *ptr);

void			swap(t_lst *stack);
void			sa(t_lst *stack_a);
void			sb(t_lst *stack_b);
void			ss(t_lst *stack_a, t_lst *stack_b);
void			push(t_lst *giver, t_lst *receiver);
void			pa(t_lst *stack_a, t_lst *stack_b);
void			pb(t_lst *stack_a, t_lst *stack_b);
void			rotate(t_lst *stack);
void			ra(t_lst *a);
void			rb(t_lst *b);
void			rr(t_lst *a, t_lst *b);
void			reverse_rotate(t_lst *stack);
void			rra(t_lst *a);
void			rrb(t_lst *b);
void			rrr(t_lst *a, t_lst *b);

void			find_extremes(t_lst *stack, long *extremes[]);
size_t			find_b_inter(t_lst *la, t_stack *sa, t_lst *lb, long *data);
void			update_cost(t_lst *sa, t_lst *sb, long *extreme[]);
size_t			get_inter(size_t cost_a, size_t cost_b, t_stack *node);
int				is_after_median(t_lst *stack_a, t_stack *node);
size_t			parse_b_down_extreme(t_lst *sb, long *extreme);
size_t			parse_b_up_extreme(t_lst *sb, long *extreme);
void			find_moves(t_lst *stack_a, t_lst *stack_b);

void			synchro_rotate(t_lst *stack_a, t_lst *stack_b, t_stack *node);
void			move(t_stack *node, t_lst *stack_a, t_lst *stack_b);
void			perform_move(t_lst *stack_a, t_lst *stack_b);
void			find_moves(t_lst *stack_a, t_lst *stack_b);
size_t			get_median(t_lst *stack);

void			rotate_a(t_lst *stack_a, t_stack *node, size_t cost_a);
void			rotate_b(t_lst *sb, t_stack *node, t_lst *sa, size_t cost);

void			push_back(t_lst *sa, t_lst *stack_b);
size_t			parse_a_down(t_lst *stack, long *data, int prospect);
size_t			parse_a_up(t_lst *stack, long *data, int prospect);
size_t			parse_a_down_extreme(t_lst *stack, long data);
size_t			parse_a_up_extreme(t_lst *stack, long data);
size_t			find_extreme_pos(t_lst *stack, long data, int *after_median);

#endif
