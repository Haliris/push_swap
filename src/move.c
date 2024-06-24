/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:21:56 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/24 16:56:10 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	synchro_rotate(t_lst *stack_a, t_lst *stack_b, t_stack *node)
{
	size_t	cost_a;
	size_t	cost_b;

	cost_a = node->cost[0];
	cost_b = node->cost[1];
	if (is_after_median(stack_a, node) == TRUE)
		synchro_move_down(cost_a, cost_b, stack_a, stack_b);
	else if (is_after_median(stack_a, node) == FALSE)
		synchro_move_up(cost_a, cost_b, stack_a, stack_b);
}

void	synchro_move_down(size_t cost_a, size_t cost_b, t_lst *a, t_lst *b)
{
	while (cost_a && cost_b)
	{
		rrr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a)
	{
		rra(a);
		cost_a--;
	}
	while (cost_b)
	{
		rrb(b);
		cost_b--;
	}
}

void	synchro_move_up(size_t cost_a, size_t cost_b, t_lst *a, t_lst *b)
{
	while (cost_a && cost_b)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a)
	{
		ra(a);
		cost_a--;
	}
	while (cost_b)
	{
		rb(b);
		cost_b--;
	}
}

void	rotate_a(t_lst *stack_a, t_stack *node, size_t cost_a)
{
	if (is_after_median(stack_a, node) == TRUE)
	{
		while (cost_a)
		{
			rra(stack_a);
			cost_a--;
		}
	}
	else
	{
		while (cost_a)
		{
			ra(stack_a);
			cost_a--;
		}
	}
}

void	rotate_b(t_lst *sb, t_stack *node, t_lst *sa, size_t cost)
{
	if (is_after_median(sa, node) == TRUE)
	{
		while (cost)
		{
			rb(sb);
			cost--;
		}
	}
	else
	{
		while (cost)
		{
			rrb(sb);
			cost--;
		}
	}
}
