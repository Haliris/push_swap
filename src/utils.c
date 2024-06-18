/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:32:25 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/18 14:52:28 by jteissie         ###   ########.fr       */
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

	while(str[i])
	{
		if(!ft_isdigit(str[i]))
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

void  trash_list(t_stack_list **lst)
{
  t_stack_list  *roaming;
  t_stack_list  *current;

  if (!lst)
    return ;
  roaming = lst->head;
  while (roaming)
  {
    current = roaming;
    roaming = roaming->next;
    free(current->data);
    free(current);
  }
  lst->head = NULL;
  lst->tail = NULL;
}
