/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:50:51 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/31 17:07:01 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

int	medspliting_push(t_lists *lists, int *undermed)
{
	mv_push(&lists->a, &lists->b);
	if (ft_lstaddback_mv(&lists->mv, ft_lstnew_mv("pb\n")))
		return (1);
	*undermed = *undermed - 1;
	return (0);
}

void	printing(t_mv_list *mv)
{
	int		i;

	i = 1;
	if (mv)
	{
		while (mv->next)
		{
			write(1, (mv)->content, ft_strlen((mv)->content));
			mv = mv->next;
			i++;
		}
		write(1, (mv)->content, ft_strlen((mv)->content));
	}
	return ;
}

int	split_sorting(t_lists *lists, char *mv)
{
	while (is_lowest((lists->a)->content, lists->a))
	{
		if (!ft_strncmp(mv, "rra\n", 5))
			mv_rrotate(&lists->a);
		else if (!ft_strncmp(mv, "ra\n", 5))
			mv_rotate(&lists->a);
		if (ft_lstaddback_mv(&lists->mv, ft_lstnew_mv(mv)))
			return (1);
	}
	return (0);
}

void	only_two(t_list_data *a)
{
	if (a->content > a->next->content)
		write(1, "sa\n", 4);
	return ;
}
