/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:54:09 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/18 16:09:20 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

long	ft_check_atol(char *str);
void	handle_error(int code);
t_stack	*create_node(long *content);
t_stack	*add_node(t_stack *head, t_stack *tail, long *data);
t_stack_list	*initialize(long *args, size_t size);
long	*parse_args(char **av, size_t size);
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
