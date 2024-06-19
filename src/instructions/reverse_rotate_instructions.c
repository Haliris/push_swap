/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:09:24 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/19 14:13:32 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	reverse_rotate(t_stack_list stack)
{
	stack->head = stack->tail;
	stack->tail = stack->tail->prev;
}

void	rra(t_stack_list a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_stack_list b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_stack_list a, t_stack_list b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
