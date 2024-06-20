/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:47:47 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/19 17:48:01 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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