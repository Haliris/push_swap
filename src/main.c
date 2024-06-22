/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:15:19 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/22 20:02:33 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

#include <stdio.h>

size_t	get_median(t_lst *stack)
{
	size_t	median;

	if (stack->size > 3)
		median = 2;
	else
		median = MEDIAN(stack);
	return (median);

}
t_stack	*find_cheapest_move(t_lst *sa)
{
	t_stack *roaming;
	t_stack	*prospect;
	size_t	min_cost;
	size_t	current_cost;

	roaming = sa->head;
	prospect = sa->head;
	min_cost = get_inter(roaming->cost[0], roaming->cost[1], roaming);
	while (roaming != sa->tail)
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
	size_t	cost_a;
	size_t	cost_b;

	cost_a = node->cost[0];
	cost_b = node->cost[1];
	// printf("cost_a = %ld\n", cost_a);
	// printf("cost_b = %ld\n", cost_b);
	if (node->synchro == TRUE)
		synchro_rotate(stack_a, stack_b, node);
	else
	{
		rotate_a(stack_a, node, cost_a);
		rotate_b(stack_b, node, stack_a, cost_b);
	}
	//printf("pushing to b:%ld\n", *node->data);
	pb(stack_a, stack_b);
}

void	perform_move(t_lst *stack_a, t_lst *stack_b)
{
	t_stack	*to_move;

	to_move = find_cheapest_move(stack_a);
	move(to_move, stack_a, stack_b);
}

// void  print_costs(t_lst *sa)
// {
//   t_stack *roaming;
//   size_t  i;

//   i = 0;
//   roaming = sa->head;
//   while (i < sa->size)
//   {
//     printf("Cost0:%ld\n", roaming->cost[0]);
//     printf("Cost1:%ld\n", roaming->cost[1]);
//     roaming = roaming->next;
//     i++;
//   }
// }

void  print_list(t_lst *stack)
{
  int i = 0;
  t_stack *roaming = stack->head;
  printf("stack->size:%ld\n", stack->size);
  while(roaming != stack->tail)
  {
	if (roaming == stack->head)
		printf("head ");
    printf("%ld\n", *roaming->data);
    roaming = roaming->next;
    i++;
  }
  printf("tail:%ld\n", *roaming->data);
  roaming = NULL;
}

void	find_moves(t_lst *stack_a, t_lst *stack_b)
{
	long	*extremes[2];
	int		median;

	median = (stack_a->size / 2) + (stack_a->size % 2);
	while (stack_a->size > 3)
	{
		find_extremes(stack_b, extremes);
		update_cost(stack_a, stack_b, extremes, median);
//	    print_costs(stack_a);
		perform_move(stack_a, stack_b);
	}
}

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

size_t		find_position(t_lst *stack_a, long *data, int *after_median)
{
	size_t	cost_up;
	size_t	cost_down;
	int		maximum;
	t_stack	*roaming;

	maximum = INT_MAX;
	cost_up = parse_a_up(stack_a, data, maximum);
	cost_down = parse_a_down(stack_a, data, maximum);
	if (cost_down <= cost_up)
		return (cost_down);
	else
	{
		*after_median = TRUE;
		return (cost_up);
	}
}

void	move_back(size_t cost, t_lst *stack_a, t_lst *stack_b, int after_median)
{

	if (after_median)
	{
		while (cost)
		{
			cost--;
			rra(stack_a);
		}
	}
	else
	{
		while (cost)
		{
			ra(stack_a);
			cost--;
		}
	}
	pa(stack_a, stack_b);
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

size_t  find_extreme_pos(t_lst *stack, long data, int *after_median)
{
  size_t	cost_up;
  size_t	cost_down;

  cost_up = parse_a_up_extreme(stack, data);
  cost_down = parse_a_down_extreme(stack, data);
  if (cost_down <= cost_up)
  {
	*after_median = FALSE;
	return(cost_down);
  }
  else
{
	*after_median = TRUE;
	return (cost_up);
}
}

void	push_back(t_lst *stack_a, t_lst *stack_b)
{
	t_stack	*roaming;
  long    *extremes[2];
	roaming = stack_b->head;
	int		after_median;
	while (stack_b->size)
	{
//		printf("size of stack_a: %ld\n", stack_a->size);
//		printf("size of stack_b: %ld\n", stack_b->size);
		// printf("------\n");
		// printf("stack_a\n:");
		// print_list(stack_a);
		after_median = FALSE;
		find_extremes(stack_a, extremes);
		if (*roaming->data > *extremes[1] || *roaming->data < *extremes[0])
			roaming->cost[0] = find_extreme_pos(stack_a, *extremes[0], &after_median);
		else
	  		roaming->cost[0] = find_position(stack_a, roaming->data, &after_median);
		// printf("------\n");
		// printf("Pushing to a: %ld\n", *roaming->data);
		move_back(roaming->cost[0], stack_a, stack_b, after_median);
		if (stack_b->size)
			roaming = stack_b->head;
	}
//   printf("------\n");
//   printf("a before final sort\n");
//   print_list(stack_a);
}

void  sort_3(t_lst *stack)
{
  long  *extremes[2];

  find_extremes(stack, extremes);
  while (*stack->tail->data != *extremes[1])
    ra(stack);
  if (*stack->head->data != *extremes[0])
    sa(stack);
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
	// printf("stack a after find moves:\n");
	//print_list(stack_a);
	printf("-----\n");
	printf("stack_b\n");
	print_list(stack_b);
	sort_3(stack_a);
	push_back(stack_a, stack_b);
	ft_free(stack_b);
	return (0);
}


void	final_sort(t_lst *stack, long min)
{
	while (*stack->head->data != min)
	{
		ra(stack);
	}
}

int	main(int ac, char **av)
{
	t_lst	*stack_a;
	long			*args_array;
	int				i;
	long			*extremes[2];

	i = 0;
	args_array = parse_args(av, ac);
	stack_a = initialize(args_array, ac);
	sort_turk(stack_a);
	find_extremes(stack_a, extremes);
	final_sort(stack_a, *extremes[0]); //to opimize
	trash_list(&stack_a);
 	ft_free(args_array);
/*
	t_stack *current;
	current = stack_a->head;
	while (i < stack_a->size)
	{
		printf("%ld\n",*(current->data));
		current = current->prev;
		i++;
	}
	trash_list(&stack_a);
*/
}
