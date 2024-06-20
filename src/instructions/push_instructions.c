/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:12:55 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/20 16:31:21 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	remove_node_front(t_lst	*stack)
{
	t_stack	*temp;

	temp = stack->head;
	if (stack->size > 1)
	{
		stack->head = stack->head->next;
		stack->head->prev = temp->prev;
	}
	else
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	ft_free(temp);
	stack->size -= 1;
}

void	push(t_lst *giver, t_lst *receiver)
{
	t_stack	*giver_temp;

	if (giver->size == 0)
		return ;
	add_node_front(receiver, giver->head->data);
	if (receiver->size == 0)
	{
		trash_list(&giver);
		trash_list(&receiver);
		handle_error(EXIT_FAILURE);
	}
	remove_node_front(giver);
}

void	pa(t_lst *stack_a, t_lst *stack_b)
{
	if (!stack_a)
		return ;
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_lst *stack_a, t_lst *stack_b)
{
	if (!stack_b)
		return ;
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
