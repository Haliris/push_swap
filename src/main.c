/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:15:19 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/24 13:15:22 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	perform_move(t_lst *stack_a, t_lst *stack_b)
{
	t_stack	*to_move;
	size_t	cost_a;
	size_t	cost_b;

	to_move = find_cheapest_move(stack_a);
	cost_a = to_move->cost[0];
	cost_b = to_move->cost[1];
	if (to_move->synchro == TRUE)
		synchro_rotate(stack_a, stack_b, to_move);
	else
	{
		rotate_b(stack_b, to_move, stack_a, cost_b);
		rotate_a(stack_a, to_move, cost_a);
	}
	pb(stack_a, stack_b);
}

void  sort_3(t_lst *stack)
{
	long  *extremes[2];

	find_extremes(stack, extremes);
	while (*stack->tail->data != *extremes[1])
		ra(stack);
	if (*stack->head->data != *extremes[0])
		sa(stack);
}

int	sort_turk(t_lst *stack_a)
{
	t_lst	*stack_b;

	stack_b = ft_calloc(1, sizeof(t_lst));
	if (!stack_b)
		handle_error(EXIT_FAILURE);
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->size = 0;
	if (stack_a->size > 3)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		find_moves(stack_a, stack_b);
	}
	sort_3(stack_a);
	push_back(stack_a, stack_b);
	free(stack_b);
	return (0);
}

void	final_sort(t_lst *stack, long min)
{
	t_stack *roaming;

	roaming = stack->head;
	while (*roaming->data != min)
		roaming = roaming->next;
	if (is_after_median(stack, roaming) == TRUE)
	{
		while (stack->head != roaming)
		rra(stack);
	}
	else
	{
	while(stack->head != roaming)
		ra(stack);
	}
}

int	main(int ac, char **av)
{
	t_lst	*stack_a;
	long			*args_array;
	int				i;
	long			*extremes[2];

	i = 0;
	if (ac < 2)
		handle_error(EXIT_FAILURE);
	args_array = parse_args(av, ac);
	stack_a = initialize(args_array, ac);
	sort_turk(stack_a);
	find_extremes(stack_a, extremes);
	final_sort(stack_a, *extremes[0]);
	trash_list(&stack_a);
}
