/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:06:59 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/26 14:17:23 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*create_node(long *content)
{
	t_stack	*s_stack;

	s_stack = ft_calloc(1, sizeof(t_stack));
	if (!s_stack)
		return (NULL);
	s_stack->data = content;
	s_stack->next = NULL;
	s_stack->prev = NULL;
	s_stack->cost[0] = 0;
	s_stack->cost[1] = 0;
	s_stack->synchro = FALSE;
	return (s_stack);
}

void	add_node(t_lst *stack, long *data)
{
	t_stack	*new_tail;

	if (!stack->head)
	{
		stack->head = create_node(data);
		if (!stack->head)
		{
			free(stack);
			stack = NULL;
			return ;
		}
		stack->size += 1;
		return ;
	}
	new_tail = create_node(data);
	if (!new_tail)
	{
		trash_list(&stack);
		return ;
	}
	stack->size += 1;
	replace_tail(stack, new_tail);
}

void	add_node_front(t_lst *stack, long *data)
{
	t_stack	*new_head;

	if (!stack->head)
	{
		stack->head = create_node(data);
		stack->size += 1;
		if (!stack->head)
			return (trash_list(&stack));
	}
	else
	{
		new_head = create_node(data);
		stack->size += 1;
		if (!new_head)
			return (trash_list(&stack));
		replace_head(stack, new_head);
	}
}

t_lst	*initialize(long *args, size_t size)
{
	size_t	i;
	t_lst	*stack;

	i = 0;
	stack = ft_calloc(1, sizeof(t_lst));
	if (!stack)
	{
		ft_free(args);
		handle_error(EXIT_FAILURE);
	}
	stack->size = 0;
	while (i < size - 1)
	{
		add_node(stack, &args[i++]);
		if (!stack)
		{
			ft_free(args);
			handle_error(EXIT_FAILURE);
		}
	}
	return (stack);
}

long	*parse_args(char **av, int size)
{
	int		i;
	long	*args_array;

	i = 1;
	args_array = ft_calloc(size, sizeof(long));
	if (!args_array)
		handle_error(EXIT_FAILURE);
	while (i < size)
	{
		args_array[i - 1] = ft_check_atol(av[i], args_array);
		i++;
	}
	if (find_duplicates(args_array, size) == TRUE)
	{
		free(args_array);
		handle_error(EXIT_FAILURE);
	}
	return (args_array);
}
