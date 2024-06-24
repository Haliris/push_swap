/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_costs_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:45:00 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/24 16:28:01 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

size_t	get_inter(size_t cost_a, size_t cost_b, t_stack *node)
{
	if (node->synchro == FALSE)
		return (cost_b + cost_a);
	if (cost_a >= cost_b)
		return (cost_a);
	else
		return (cost_b);
}

int	is_after_median(t_lst *stack_a, t_stack *node)
{
	int		median;
	int		index;
	t_stack	*roaming;

	index = 1;
	median = MEDIAN(stack_a);
	roaming = stack_a->head;
	while (roaming != node)
	{
		roaming = roaming->next;
		index++;
	}
	if (index > median)
		return (1);
	return (0);
}

void	find_extremes(t_lst *stack, long *extremes[])
{
	t_stack	*roaming;
	size_t	index;

	index = 0;
	roaming = stack->head;
	extremes[0] = roaming->data;
	extremes[1] = roaming->data;
	while (index < stack->size)
	{
		if (*roaming->data > *extremes[1])
			extremes[1] = roaming->data;
		else if (*roaming->data < *extremes[0])
			extremes[0] = roaming->data;
		roaming = roaming->next;
		index ++;
	}
}

void	find_moves(t_lst *stack_a, t_lst *stack_b)
{
	long	*extremes[2];
	int		median;

	median = MEDIAN(stack_a);
	while (stack_a->size > 3)
	{
		find_extremes(stack_b, extremes);
		update_cost(stack_a, stack_b, extremes, median);
		perform_move(stack_a, stack_b);
	}
}
