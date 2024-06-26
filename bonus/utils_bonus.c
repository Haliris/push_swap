/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:32:25 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/26 11:15:02 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "libft.h"

void	handle_error(int code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(code);
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
