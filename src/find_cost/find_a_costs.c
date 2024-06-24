/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_a_costs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:28:21 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/24 16:25:23 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	move_back(size_t cost, t_lst *stack_a, t_lst *stack_b, int after_median)
{
	if (after_median)
	{
		while (cost)
		{
			cost--;
			rra(stack_a);
		}
	}
	else
	{
		while (cost)
		{
			ra(stack_a);
			cost--;
		}
	}
	pa(stack_a, stack_b);
}

size_t	find_extreme_pos(t_lst *stack, long data, int *after_median)
{
	size_t	cost_up;
	size_t	cost_down;

	cost_up = parse_a_up_extreme(stack, data);
	cost_down = parse_a_down_extreme(stack, data);
	if (cost_down <= cost_up)
	{
		*after_median = FALSE;
		return (cost_down);
	}
	else
	{
		*after_median = TRUE;
		return (cost_up);
	}
}

size_t	find_position(t_lst *stack_a, long *data, int *after_median)
{
	size_t	cost_up;
	size_t	cost_down;
	int		maximum;
	t_stack	*roaming;

	maximum = INT_MAX;
	cost_up = parse_a_up(stack_a, data, maximum);
	cost_down = parse_a_down(stack_a, data, maximum);
	if (cost_down <= cost_up)
		return (cost_down);
	else
	{
		*after_median = TRUE;
		return (cost_up);
	}
}

void	push_back(t_lst *stack_a, t_lst *stack_b)
{
	t_stack	*roaming;
	long	*extremes[2];
	int		after_median;

	roaming = stack_b->head;
	while (stack_b->size)
	{
		after_median = FALSE;
		find_extremes(stack_a, extremes);
		if (*roaming->data > *extremes[1] || *roaming->data < *extremes[0])
			roaming->cost[0] = find_extreme_pos(stack_a, *extremes[0], &after_median);
		else
			roaming->cost[0] = find_position(stack_a, roaming->data, &after_median);
		move_back(roaming->cost[0], stack_a, stack_b, after_median);
		if (stack_b->size)
			roaming = stack_b->head;
	}
}
