/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:12:55 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/19 15:59:36 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push(t_stack_list *giver, t_stack_list *receiver)
{
	t_stack	*giver_temp;

	add_node_front(receiver, giver->head->data);
	if (!receiver->head)
	{
		trash_list(giver);
		trash_list(receiver);
		handle_error(EXIT_FAILURE);
	}
	giver_temp = giver->head;
	giver->head = giver->head->next;
	giver_temp->data = NULL;
	free(giver_temp);
}

void	pa(t_stack_list *stack_a, t_stack_list *stack_b)
{
	if (!stack_a)
		return ;
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_stack_list *stack_a, t_stack_list *stack_b)
{
	if (!stack_b)
		return ;
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
