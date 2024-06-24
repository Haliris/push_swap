/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:22:56 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/24 12:40:38 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

size_t		parse_a_down(t_lst *stack, long *data, int prospect)
{
	t_stack	*roaming;
	size_t	cost;
	size_t	depth;

	cost = 0;
	depth = 0;
	roaming = stack->head;
	while (roaming != stack->tail)
	{
		if (*data < *roaming->data && *roaming->data <= prospect)
		{
			cost = depth;
			prospect = *roaming->data;
		}
		depth++;
		roaming = roaming->next;
	}
	if (*data < *roaming->data && *roaming->data <= prospect)
		cost = depth;
	return (cost);
}

size_t		parse_a_up(t_lst *stack, long *data, int prospect)
{
	t_stack	*roaming;
	size_t	cost;
	size_t	depth;

	cost = 0;
	depth = 1;
	roaming = stack->tail;
	while (roaming != stack->head)
	{
		if (*data < *roaming->data && *roaming->data <= prospect)
		{
			cost = depth;
			prospect = *roaming->data;
		}
		depth++;
		roaming = roaming->prev;
	}
	if (*data < *roaming->data && *roaming->data <= prospect)
		cost = depth;
	return (cost);
}

size_t parse_a_down_extreme(t_lst *stack, long data)
{
	t_stack *roaming;
	size_t depth;

	roaming = stack->head;
	depth = 0;
	while (*roaming->data != data)
  {
	depth++;
    roaming = roaming->next;
  }
  return (depth);
}

size_t parse_a_up_extreme(t_lst *stack, long data)
{
	t_stack *roaming;
	size_t depth;

	roaming = stack->tail;
	depth = 1;
	while (*roaming->data != data)
	{
		depth++;
		roaming = roaming->prev;
	}
	return (depth);
}
