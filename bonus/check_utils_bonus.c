/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:23:31 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/26 11:37:01 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

int	is_sorted(t_lst *stack)
{
	t_stack	*roaming;
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

int	find_duplicates(long *args, int size)
{
	int	main_index;
	int	roaming_index;

	main_index = 0;
	roaming_index = 1;
	while (main_index < size)
	{
		while (roaming_index < size - 1)
		{
			if (args[main_index] == args[roaming_index])
				return (TRUE);
			roaming_index++;
		}
		main_index++;
		roaming_index = main_index + 1;
	}
	return (FALSE);
}
