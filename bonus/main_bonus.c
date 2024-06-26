/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:41:51 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/26 14:33:07 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line_bonus.h"
#include "push_swap_bonus.h"

void	check(t_lst	*sa)
{
	t_lst	*sb;

	sb = ft_calloc(1, sizeof(t_lst));
	if (!sb)
	{
		ft_putstr_fd("Malloc error for stack_b\n", STDERR_FILENO);
		return ;
	}
	if (execute_instructions(sa, sb) == -1)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	else if (is_sorted(sa) == TRUE)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	trash_list(&sb);
}

int	main(int ac, char **av)
{
	long	*args_array;
	t_lst	*stack;

	if (ac < 2)
		handle_error(EXIT_FAILURE);
	args_array = parse_args(av, ac);
	stack = initialize(args_array, ac);
	check(stack);
	trash_list(&stack);
	free(args_array);
	exit(EXIT_SUCCESS);
}
