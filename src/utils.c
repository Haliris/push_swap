/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:32:25 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/20 11:30:36 by jteissie         ###   ########.fr       */
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
	check_digit(str);
	while (str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (negative)
		result *= -1;
	return (result);
}

void	trash_list(t_lst **lst)
{
	t_stack	*roaming;
	t_stack	*trash;
	size_t	i;

	if (!lst)
		return ;
	if ((*lst)->size == 0)
	{
		free(*lst);
		return ;
	}
	roaming = (*lst)->head;
	i = 0;
	while (i < (*lst)->size - 1)
	{
		trash = roaming;
		roaming = roaming->next;
		free(trash);
		i++;
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
