/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:32:25 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/21 11:29:22 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	handle_error(int code)
{
	ft_putstr_fd("Error.\n", STDERR_FILENO);
	exit(code);
}

void	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			handle_error(EXIT_FAILURE);
		i++;
	}
}

long	ft_check_atol(char *str)
{
	long	result;
	int		negative;
	int		i;

	i = 0;
	result = 0;
	negative = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	check_digit(&str[i]);
	while (str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (negative)
		result *= -1;
	return (result);
}

#include <stdio.h>

void	trash_list(t_lst **lst)
{
	t_stack	*trash;
	t_stack	*roaming;
	size_t	i;

	if (!lst || !*lst)
		return ;
	if ((*lst)->size == 0)
	{
		free(*lst);
		return ;
	}
	i = 0;
	roaming = (*lst)->head;
	while (i < (*lst)->size)
	{
		if (roaming->next && roaming->prev)
			roaming->prev->next = NULL;
		if (roaming->prev && roaming->next)
			roaming->next->prev = NULL;
		trash = roaming;
		roaming = roaming->next;
		trash->next = NULL;
		trash->prev = NULL;
		free(trash);
		if (!roaming)
			break;
		i++;
		trash = NULL;
	}
	free(roaming);
	free(*lst);
	*lst = NULL;
}


void	ft_free(void *ptr)
{
	if (!ptr)
		return ;
	else
		free(ptr);
}
