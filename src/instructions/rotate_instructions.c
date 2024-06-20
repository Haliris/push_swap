/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:53:56 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/19 14:28:42 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rotate(t_lst *stack)
{
	stack->tail = stack->head;
	stack->head = stack->head->next;
}

void	ra(t_lst *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_lst *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_lst *a, t_lst *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
