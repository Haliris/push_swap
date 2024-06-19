/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:15:19 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/19 16:19:50 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

void	sort_turk(t_stack_list *stack_a)
{
	long			maximum;
	long			minimum;
	t_stack_list	*stack_b;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack_list	*stack_a;
	long			*args_array;
	int				i;

	i = 0;
	args_array = parse_args(av, ac);
	stack_a = initialize(args_array, ac);
	//sort_turk(stack_a);
	
	t_stack *current;
	current = stack_a->head;
	while (i < 50)
	{
		printf("%ld\n",*(current->data));
		current = current->prev;
		i++;
	}
/*	trash_list(stack_a);
	free(args_array); */
}
