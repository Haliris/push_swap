/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:12:55 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/19 14:27:47 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push(t_stack_list *giver, t_stack_list *receiver)
{
	t_stack	*receiver_temp;
	t_stack	*giver_temp;

	if (!giver)
		return ;
	receiver_temp = receiver->head;
	receiver->head = giver->head;
	receiver->head->next = receiver_temp;
	giver_temp = giver->head;
	giver->head = giver->head->next;
	giver_temp->data = NULL;
	free(giver_temp);
}

void	pa(t_stack_list *stack_a, t_stack_list *stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_stack_list *stack_a, t_stack_list *stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
