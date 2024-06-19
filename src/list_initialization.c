/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:06:59 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/19 16:24:58 by jteissie         ###   ########.fr       */
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

void	replace_head(t_stack_list *stack, t_stack *new_head)
{
	if (!stack->tail)
	{
		stack->head->prev = new_head;
		stack->head->next = new_head;
		stack->tail = stack->head;
	}
	else
	{
		new_head->prev = stack->tail;
		stack->tail->next = new_head;
	}
	new_head->next = stack->head;
	stack->head = new_head;
}

void	replace_tail(t_stack_list *stack, t_stack *new_tail)
{
	if (!stack->tail)
	{
		new_tail->prev = stack->head;
		stack->head->next = new_tail;
	}
	else
	{
		new_tail->prev = stack->tail;
		stack->tail->next = new_tail;
	}
	stack->head->prev = new_tail;
	new_tail->next = stack->head;
	stack->tail = new_tail;
}

void	add_node(t_stack_list *stack, long *data)
{
	t_stack	*new_tail;

	if (!stack->head)
	{
		stack->head = create_node(data);
		if (!stack->head)
		{	
			trash_list(stack);
			return ;
		}
		return ;
	}
	new_tail = create_node(data);
	if (!new_tail)
	{	
		trash_list(stack);
		return ;
	}
	replace_tail(stack, new_tail);
}

void	add_node_front(t_stack_list *stack, long *data)
{
	t_stack	*new_head;

	if (!stack->head)
	{
		stack->head = create_node(data);
		if (!stack->head)
			return (trash_list(stack));
	}
	else 
	{
		new_head = create_node(data);
		if (!new_head)
			return (trash_list(stack));
		replace_head(stack, new_head);
	}
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
	while (i < size - 1)
	{
		add_node(s_stack_list, &args[i++]);
		if (!s_stack_list)
		{
			free(args);
			handle_error(EXIT_FAILURE);
		}
	}
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
