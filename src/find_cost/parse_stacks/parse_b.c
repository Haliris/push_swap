/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:20:42 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/24 18:05:57 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

size_t	parse_b_down(t_lst *sb, long *data)
{
	t_stack	*roaming;
	long	biggest_min;
	size_t	depth;
	size_t	cost;

	biggest_min = INT_MIN;
	roaming = sb->head;
	cost = 0;
	depth = 0;
	while (depth < sb->size)
	{
		if (*data > *roaming->data && *roaming->data >= biggest_min)
		{
			biggest_min = *roaming->data;
			cost = depth;
		}
		roaming = roaming->next;
		depth++;
	}
	return (cost);
}

size_t	parse_b_up(t_lst *sb, long *data)
{
	t_stack	*roaming;
	long	biggest_min;
	size_t	depth;
	size_t	cost;

	biggest_min = INT_MIN;
	roaming = sb->tail;
	cost = 0;
	depth = 1;
	while (depth <= sb->size)
	{
		if (*data > *roaming->data && *roaming->data >= biggest_min)
		{
			biggest_min = *roaming->data;
			cost = depth;
		}
		roaming = roaming->prev;
		depth++;
	}
	return (cost);
}

size_t	find_b_inter(t_lst *la, t_stack *sa, t_lst *lb, long *data)
{
	size_t	cost_up;
	size_t	cost_down;

	cost_down = parse_b_down(lb, data);
	cost_up = parse_b_up(lb, data);
	if (0 <= cost_up)
	{
		if (is_after_median(la, sa) == FALSE)
			sa->synchro = TRUE;
		return (cost_down);
	}
	else
	{
		if (is_after_median(la, sa) == TRUE)
			sa->synchro = TRUE;
		return (cost_up);
	}
}

size_t	parse_b_down_extreme(t_lst *sb, long *extreme)
{
	t_stack	*roaming;
	size_t	depth;

	roaming = sb->head;
	depth = 0;
	while (*roaming->data != *extreme)
	{
		roaming = roaming->next;
		depth++;
	}
	return (depth);
}

size_t	parse_b_up_extreme(t_lst *sb, long *extreme)
{
	t_stack	*roaming;
	size_t	depth;

	roaming = sb->tail;
	depth = 1;
	while (*roaming->data != *extreme)
	{
		roaming = roaming->prev;
		depth++;
	}
	return (depth);
}
