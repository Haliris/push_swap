/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:22:18 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/26 11:59:50 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (-1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

void	check_overflow(long number, int sign, long *args)
{
	if (number * sign < INT_MIN || number * sign > INT_MAX)
	{
		free(args);
		handle_error(EXIT_FAILURE);
	}
}

void	skip_whitespaces(char *str, int *index)
{
	while (str[*index])
	{
		if (str[*index] == ' ')
			*index = *index + 1;
		else if (str[*index] >= '\t' && str[*index] <= '\r')
			*index = *index + 1;
		else
			break ;
	}
}

int	check_sign(char c, int *index)
{
	if (c == '-' || c == '+')
	{
		*index = *index + 1;
		if (c == '-')
			return (-1);
	}
	return (1);
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
