/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:47:47 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/26 12:25:17 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

void	replace_head(t_lst *stack, t_stack *new_head)
{
	if (!stack || !new_head)
		return ;
	if (!stack->tail)
	{
		stack->head->prev = new_head;
		stack->head->next = new_head;
		stack->tail = stack->head;
	}
	else
	{
		stack->head->prev = new_head;
		stack->tail->next = new_head;
	}
	new_head->prev = stack->tail;
	new_head->next = stack->head;
	stack->head = new_head;
}

void	replace_tail(t_lst *stack, t_stack *new_tail)
{
	if (!stack || !new_tail)
		return ;
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
