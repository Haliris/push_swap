/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:54:09 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/22 20:41:55 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <limits.h>
# define TRUE 1
# define FALSE 0
# define MEDIAN(stack) (((stack->size) + (stack->size % 2)) / 2);

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

long			ft_check_atol(char *str);
void			handle_error(int code);
long			*parse_args(char **av, size_t size);
t_stack			*create_node(long *content);
void			add_node(t_lst *stack, long *data);
void			add_node_front(t_lst *stack, t_stack *giver_node);
void			remove_node_front(t_lst	*stack);
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
size_t			find_b_extreme(t_lst *lst_a, t_stack *sa, t_lst *sb, long *extreme);
size_t			find_b_cost(t_lst *la, t_stack *sa, t_lst *sb, long *extreme[]);
void			update_cost(t_lst *sa, t_lst *sb, long *extreme[], int med);
size_t			get_inter(size_t cost_a, size_t cost_b, t_stack *node);
int				is_after_median(t_lst *stack_a, t_stack *node);
void			set_synchro(size_t median, size_t index, t_lst *lst_a, t_stack *sa);

t_stack			*find_cheapest_move(t_lst *sa);
void			synchro_move_down(size_t cost_a, size_t cost_b, t_lst *a, t_lst *b);
void			synchro_move_up(size_t cost_a, size_t cost_b, t_lst *a, t_lst *b);
void			synchro_rotate(t_lst *stack_a, t_lst *stack_b, t_stack *node);
void			move(t_stack *node, t_lst *stack_a, t_lst *stack_b);
void			perform_move(t_lst *stack_a, t_lst *stack_b);
void			find_moves(t_lst *stack_a, t_lst *stack_b);
size_t			get_median(t_lst *stack);

void		synchro_move_down(size_t cost_a, size_t cost_b, t_lst *a, t_lst *b);
void		synchro_move_up(size_t cost_a, size_t cost_b, t_lst *a, t_lst *b);
void		synchro_rotate(t_lst *stack_a, t_lst *stack_b, t_stack *node);
void		rotate_a(t_lst *stack_a, t_stack *node, size_t cost_a);
void		rotate_b(t_lst *stack_b, t_stack *node, t_lst *stack_a, size_t cost_b);


size_t  find_extreme_pos(t_lst *stack, long data, int *after_median);
#endif
