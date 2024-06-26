/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:09:24 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/26 11:15:02 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

void	reverse_rotate(t_lst *stack)
{
	if (!stack->head || !stack->tail)
		return ;
	stack->head = stack->tail;
	stack->tail = stack->tail->prev;
}

void	rra(t_lst *a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_lst *b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_lst *a, t_lst *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
