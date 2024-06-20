/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_costs_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:45:00 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/20 17:23:44 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

size_t	get_inter(size_t cost_a, size_t cost_b, t_stack *node)
{
	if (node->synchro == FALSE)
		return (cost_b + cost_a);
	if (cost_a < cost_b)
		return (cost_b - cost_a);
	else if (cost_b < cost_a)
		return (cost_a - cost_b);
	else
		return (0);
}

int	is_after_median(t_lst *stack_a, t_stack *node)
{
	int		median;
	int		depth;
	t_stack	*roaming;

	median = (stack_a->size / 2) + (stack_a->size % 2);
	roaming = stack_a->head;
	while (roaming != node)
		depth++;
	if (depth > median)
		return (1);
	return (0);
}

void	set_synchro(size_t i, size_t depth, t_lst *lst_a, t_stack *sa)
{
	if (is_after_median(lst_a, sa))
	{
		if (depth > i)
			sa->synchro = TRUE;
	}
	else if (!is_after_median(lst_a, sa))
	{
		if (depth < i)
			sa->synchro = TRUE;
	}
}
