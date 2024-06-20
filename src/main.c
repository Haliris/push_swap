/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:15:19 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/20 11:23:24 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

int	sort_turk(t_stack_list *stack_a)
{
	long			maximum;
	long			minimum;
	t_stack_list	*stack_b;

	stack_b = ft_calloc(1, sizeof(t_stack_list));
	if (!stack_b)
		return (-1);
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->size = 0;
	minimum = 0;
	maximum = 0;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	trash_list(&stack_b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack_list	*stack_a;
	long			*args_array;
	int				i;

	i = 0;
	args_array = parse_args(av, ac);
	stack_a = initialize(args_array, ac);
	sort_turk(stack_a);
	
	t_stack *current;
	current = stack_a->head;
	while (i < stack_a->size)
	{
		printf("%ld\n",*(current->data));
		current = current->prev;
		i++;
	}
	trash_list(&stack_a);
 	ft_free(args_array);
}
