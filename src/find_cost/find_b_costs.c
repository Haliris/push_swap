/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_b_costs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:27:32 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/25 11:52:39 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*find_cheapest_move(t_lst *sa)
{
	t_stack	*roaming;
	t_stack	*prospect;
	size_t	min_cost;
	size_t	index;
	size_t	current_cost;

	roaming = sa->head;
	prospect = sa->head;
	index = 0;
	min_cost = get_inter(roaming->cost[0], roaming->cost[1], roaming);
	while (index < sa->size)
	{
		current_cost = get_inter(roaming->cost[0], roaming->cost[1], roaming);
		if (min_cost > current_cost)
		{
			min_cost = current_cost;
			prospect = roaming;
		}
		roaming = roaming->next;
		index++;
	}
	return (prospect);
}

size_t	find_b_extreme(t_lst *lst_a, t_stack *sa, t_lst *sb, long *extreme)
{
	size_t	cost_up;
	size_t	cost_down;

	cost_down = parse_b_down_extreme(sb, extreme);
	cost_up = parse_b_up_extreme(sb, extreme);
	if (cost_down <= cost_up)
	{
		if (is_after_median(lst_a, sa) == FALSE)
			sa->synchro = TRUE;
		return (cost_down);
	}
	else
	{
		if (is_after_median(lst_a, sa) == TRUE)
			sa->synchro = TRUE;
		return (cost_up);
	}
}

size_t	find_b_cost(t_lst *lst_a, t_stack *sa, t_lst *sb, long *extreme[])
{
	size_t	cost;

	cost = 0;
	sa->synchro = FALSE;
	if (*sa->data < *extreme[0] || *sa->data > *extreme[1])
		cost = find_b_extreme(lst_a, sa, sb, extreme[1]);
	else
		cost = find_b_inter(lst_a, sa, sb, sa->data);
	return (cost);
}

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

void	update_cost(t_lst *sa, t_lst *sb, long *extreme[])
{
	t_stack	*roaming;
	size_t	index;
	int		after_median;

	index = 0;
	roaming = sa->head;
	after_median = FALSE;
	while (index < sa->size)
	{
		roaming->cost[0] = find_extreme_pos(sa, *roaming->data, &after_median);
		roaming->cost[1] = find_b_cost(sa, roaming, sb, extreme);
		roaming = roaming->next;
		index++;
		after_median = FALSE;
	}
}
