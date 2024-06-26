/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteissie <jteissie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:17:19 by jteissie          #+#    #+#             */
/*   Updated: 2024/06/26 11:20:34 by jteissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line_bonus.h"
#include "push_swap_bonus.h"

void	a_instruction(t_lst *sa, t_lst *sb, char *line)
{
	if (ft_strncmp(line, "ra\n", 3) == 0)
		rotate(sa);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		reverse_rotate(sa);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		push(sb, sa);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		swap(sa);
}

void	b_instruction(t_lst *sa, t_lst *sb, char *line)
{
	if (ft_strncmp(line, "rb\n", 3) == 0)
		rotate(sb);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		reverse_rotate(sb);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		push(sa, sb);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		swap(sb);
}

void	synchro_instruction(t_lst *sa, t_lst *sb, char *line, int *error)
{
	if (ft_strncmp(line, "rr\n", 3) == 0)
	{
		rotate(sa);
		rotate(sb);
	}
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
	{
		reverse_rotate(sa);
		reverse_rotate(sb);
	}
	else
		*error = TRUE;
}

int	execute_instructions(t_lst *sa, t_lst *sb)
{
	char	*line;
	int		error;

	error = FALSE;
	line = get_next_line(STDIN_FILENO);
	if (!line)
		return (-1);
	while (line)
	{
		if (ft_strchr(line, 'a'))
			a_instruction(sa, sb, line);
		else if (ft_strchr(line, 'b'))
			b_instruction(sa, sb, line);
		else
			synchro_instruction(sa, sb, line, &error);
		free(line);
		if (error == TRUE)
			return (-1);
		line = get_next_line(STDIN_FILENO);
	}
	return (0);
}
