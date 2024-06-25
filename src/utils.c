/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:32:25 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/25 16:29:14 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	handle_error(int code)
{
	ft_putstr_fd("Error.\n", STDERR_FILENO);
	exit(code);
}

long	ft_check_atol(char *str, long *args)
{
	long long	result;
	int			sign;
	int			i;

	i = 0;
	result = 0;
	skip_whitespaces(str, &i);
	sign = check_sign(str[i], &i);
	if (check_digit(&str[i]) == -1)
	{
		free(args);
		handle_error(EXIT_FAILURE);
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	check_overflow(result, sign, args);
	result *= sign;
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
	while (i < (*lst)->size)
	{
		trash = roaming;
		roaming = roaming->next;
		if (trash)
			free(trash);
		i++;
	}
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
