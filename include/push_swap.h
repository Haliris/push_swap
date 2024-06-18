/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:54:09 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/18 14:47:44 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

long	ft_check_atol(char *str);
void	handle_error(int code);
typedef struct s_stack 
{
	struct s_stack	*next;
	struct s_stack	*prev;
	long			*data;
} t_stack;
typedef struct s_stack_list
{
	t_stack *head;
	t_stack *tail;
} t_stack_list;

#endif
