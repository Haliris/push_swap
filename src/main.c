/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:15:19 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/20 16:07:40 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

t_stack	*find_cheapest_move(t_lst *sa, t_lst *sb)
{
	t_stack *roaming;
	t_stack	*prospect;
	size_t	min_cost;
	size_t	current_cost;

	roaming = stack_a->head;
	prospect = stack_a->head;
	min_cost = get_inter(roaming->cost[0], roaming->cost[1], roaming);
	while (roaming != stack_a->tail)
	{
		current_cost = get_inter(roaming->cost[0], roaming->cost[1], roaming);
		if (min_cost > current_cost)
		{
			min_cost = current_cost;
			prospect = roaming;
		}
		roaming = roaming->next;
	}
	return (prospect);
}


void	move(t_stack *node, t_lst *stack_a, t_lst *stack_b)
{

}

void	perform_move(t_lst *stack_a, t_lst *stack_b)
{
	t_stack	*to_move;

	to_move = find_cheapest_move(stack_a, stack_b);
	move(to_move, stack_a, stack_b);
}

void	find_moves(t_lst *stack_a, t_lst *stack_b)
{
	long	extremes[2];
	int		median;
	t_stack	*target;

	operation = 0;
	median = (stack_a->size / 2) + (stack_a->size % 2);
	find_extremes(stack_b, extremes);
	while (stack_a->size > 3);
	{
		update_cost(stack_a, stack_b, extremes, median);
		perform_move(stack_a, stack_b);
	}
}

int	sort_turk(t_lst *stack_a)
{
	t_lst	*stack_b;

	stack_b = ft_calloc(1, sizeof(t_lst));
	if (!stack_b)
		return (-1); //catch error better
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->size = 0;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	find_moves(stack_a, stack_b);
	trash_list(&stack_b);
	return (0);
}

int	main(int ac, char **av)
{
	t_lst	*stack_a;
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
