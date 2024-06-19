/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:06:59 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/19 11:45:26 by jteissie         ###   ########.fr       */
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
	return (s_stack);
}

t_stack	*add_node(t_stack *head, t_stack *tail, long *data)
{
	t_stack	*last;

	if (!head)
		return (NULL);
	if (!tail)
	{
		last = create_node(data);
		last->prev = head;
		head->next = last;
	}
	else
	{
		last = create_node(data);
		last->prev = tail;
		tail->next = last;
	}
	return (last);
}

t_stack_list	*initialize(long *args, size_t size)
{
	size_t			i;
	t_stack_list	*s_stack_list;

	i = 0;
	s_stack_list = ft_calloc(1, sizeof(t_stack_list));
	if (!s_stack_list)
	{
		free(args);
		handle_error(EXIT_FAILURE);
	}
	s_stack_list->head = create_node(&args[i++]);
	if (!s_stack_list->head)
	{
		free(args);
		handle_error(EXIT_FAILURE);
	}
	while (i < size - 1)
	{
		s_stack_list->tail = add_node(s_stack_list->head, s_stack_list->tail, &args[i++]);
		if (!s_stack_list->tail)
		{
			free(args);
			trash_list(s_stack_list);
			handle_error(EXIT_FAILURE);
		}
	}
	s_stack_list->tail->next = s_stack_list->head;
	return (s_stack_list);
}

long	*parse_args(char **av, size_t size)
{
	size_t		i;
	long		*args_array;

	i = 1;
	args_array = ft_calloc(size, sizeof(long));
	if (!args_array)
		handle_error(EXIT_FAILURE);
	while (i < size)
	{
		args_array[i - 1] = ft_check_atol(av[i]);
		i++;
	}
	return (args_array);
}
