/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:27:32 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/21 12:26:41 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

void	find_extremes(t_lst *stack, long *extremes[])
{
	t_stack	*roaming;
	size_t 	index;
	
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
	t_stack	*roaming;
	size_t	cost_up;
	size_t	cost_down;

	cost_down = parse_b_down(lb, data);
	cost_up = parse_b_up(lb, data);
	if (cost_down <= cost_up)
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

void	update_cost(t_lst *sa, t_lst *sb, long *extreme[], int med)
{
	t_stack	*roaming;
	size_t	index;
	int		after_median;

	index = 0;
	roaming = sa->head;
	after_median = FALSE;
  if (sb->size >= 22)
  {

  }

	while (index < sa->size)
	{
    // if (*roaming->data == 82 && sb->size >= 96)
	// { 
	// 	printf("82 being evaluated\n");
	// 	printf("stack_a:\n");
   	// 	printf("------\n");
	// 	print_list(sa);
	// 	printf("stack_b:\n");
	// 	print_list(sb);
	// }
		roaming->cost[0] = find_extreme_pos(sa, *roaming->data, &after_median);
		roaming->cost[1] = find_b_cost(sa, roaming, sb, extreme);
		roaming = roaming->next;
		index++;
		after_median = FALSE;
	}
}
