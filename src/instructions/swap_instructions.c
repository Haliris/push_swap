/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:02:53 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/19 14:27:15 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	swap(t_lst *stack)
{
	t_stack	*new_head;
  t_stack *old_head;

	if (!stack || stack->size < 2)
		return ;
	new_head = stack->head->next;
  	old_head = stack->head;
	new_head->next->prev = old_head;

    old_head->next = new_head->next;
	old_head->prev = new_head;
    

    new_head->prev = stack->tail;
	new_head->next = old_head;
	
    stack->tail->next = new_head;
  	stack->head = new_head;
}

void	sa(t_lst *stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_lst *stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_lst *stack_a, t_lst *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
