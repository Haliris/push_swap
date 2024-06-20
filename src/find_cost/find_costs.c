/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:27:32 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/20 18:18:47 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	find_extremes(t_lst *stack, long *extremes[])
{
	t_stack	*roaming;
	roaming = stack->head;
	extremes[0] = roaming->data;
	extremes[1] = roaming->data;
	while (roaming != stack->tail)
	{
		if (*roaming->data > *extremes[1])
			extremes[1] = roaming->data;
		else if (*roaming->data < *extremes[0])
			extremes[0] = roaming->data;
		roaming = roaming->next;
	}
	if (*roaming->data > *extremes[1])
		extremes[1] = roaming->data;
	else if (*roaming->data < *extremes[0])
		extremes[0] = roaming->data;
}

size_t	find_b_inter(t_lst *la, t_stack *sa, t_lst *lb, long *data)
{
	t_stack	*roaming;
	long	*benchmark;
	size_t	depth;
	size_t	depth_result;
	size_t	median;
	size_t	index;

	depth = 0;
	depth_result = 0;
	median = (lb->size / 2) + (lb->size % 2);
	roaming = lb->head;
	benchmark = roaming->data;
	while (roaming != lb->tail)
	{
		if (*data > *roaming->data && *roaming->data >= *benchmark)
		{
			benchmark = roaming->data;
			depth_result = depth;
		}
		roaming = roaming->next;
		index++;
		if (index < median)
			depth++;
		else if (index > median)
			depth--;
	}
	if (*data > *roaming->data && *roaming->data >= *benchmark)
		depth_result = depth;
	set_synchro(index, median, la, sa);
	return (depth_result);
}

size_t	find_b_extreme(t_lst *lst_a, t_stack *sa, t_lst *sb, long *extreme)
{
	t_stack	*roaming;
	size_t	b_median;
	size_t	depth;
	size_t	index;

	roaming = sb->head;
	b_median = (sb->size / 2) + (sb->size % 2);
	depth = 0;
	index = 0;
	while (*roaming->data != *extreme)
	{
		roaming = roaming->next;
		index++;
		if (index < b_median)
			depth++;
		else if (index > b_median)
			depth--;
	}
	set_synchro(index, b_median, lst_a, sa);
	extreme = roaming->data;
	return (depth);
}

size_t	find_b_cost(t_lst *lst_a, t_stack *sa, t_lst *sb, long *extreme[])
{
	size_t	cost;

	cost = 0;
	if (*sa->data < *extreme[0])
		cost = find_b_extreme(lst_a, sa, sb, extreme[0]);
	else if (*sa->data > *extreme[1])
		cost = find_b_extreme(lst_a, sa, sb, extreme[1]);
	else
		cost = find_b_inter(lst_a, sa, sb, sa->data);
	return (cost);
}

void	update_cost(t_lst *sa, t_lst *sb, long *extreme[], int med)
{
	t_stack	*roaming;
	size_t	depth;
	size_t	median;
	size_t	index;

	depth = 0;
	index = 0;
	roaming = sa->head;
	median = (sa->size / 2) + (sa->size % 2);
	while (roaming != sa->tail)
	{
		roaming->cost[0] = depth;
		roaming->cost[1] = find_b_cost(sa, roaming, sb, extreme);
		roaming = roaming->next;
		index++;
		if (index < median)
			depth++;
		else if (index > median)
			depth--;
	}
	roaming->cost[0] = depth;
	roaming->cost[1] = find_b_cost(sa, roaming, sb, extreme);
}
