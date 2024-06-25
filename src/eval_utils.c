/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:23:31 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/25 16:37:00 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	is_sorted(t_lst *stack)
{
	t_stack *roaming;
	size_t	index;

	roaming = stack->head;
	index = 1;
	while (index < stack->size)
	{
		roaming = roaming->next;
		if (*roaming->prev->data > *roaming->data)
			return (FALSE);
		index++;
	}
	return (TRUE);
}
