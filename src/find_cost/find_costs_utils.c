/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_costs_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:45:00 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/21 11:15:10 by jteissie         ###   ########.fr       */
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
	median = (stack_a->size / 2) + (stack_a->size % 2);
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
