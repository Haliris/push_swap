/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:15:19 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/18 16:07:57 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack_list	*s_stack_list_a;
	long			*args_array;
	int				i;

	i = 0;
	args_array = parse_args(av, ac);
	s_stack_list_a = initialize(args_array, ac);
	t_stack *current;
	current = s_stack_list_a->head;
	while (i < 50)
	{
		printf("%ld\n",*(current->data));
		current = current->next;
		i++;
	}
	free(args_array);
	cleanup_list(s_stack_list_a);
}
