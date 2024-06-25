/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:22:18 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/25 16:34:22 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	check_digit(char *str)
{
	int	i;

	i = 0;
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

	if (number*sign < INT_MIN || number*sign > INT_MAX)
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
