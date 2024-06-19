/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 11:54:09 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/19 11:56:58 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

long			ft_check_atol(char *str);
void			handle_error(int code);
long			*parse_args(char **av, size_t size);
typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	long			*data;
}	t_stack;
typedef struct s_stack_list
{
	t_stack	*head;
	t_stack	*tail;
}	t_stack_list;
t_stack			*create_node(long *content);
t_stack			*add_node(t_stack *head, t_stack *tail, long *data);
t_stack_list	*initialize(long *args, size_t size);
void			trash_list(t_stack_list *lst);
#endif
