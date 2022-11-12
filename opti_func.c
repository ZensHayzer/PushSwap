/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:42:50 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/31 16:25:22 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	reducer(t_mv_list *mv, t_mv_list *to_del, char *modification)
{
	mv->content = modification;
	if (to_del->next)
		to_del->next->prev = to_del->prev;
	to_del->prev->next = to_del->next;
	free(to_del);
	return ;
}

void	is_reducible(t_mv_list *mv)
{
	t_mv_list	*tmp;

	tmp = mv;
	while (tmp && tmp->content == mv->content)
		tmp = tmp->next;
	if (tmp && !ft_strncmp(mv->content, "ra\n", 4)
		&& !ft_strncmp(tmp->content, "rb\n", 4))
		return (reducer(mv, tmp, "rr\n"));
	if (tmp && !ft_strncmp(mv->content, "rb\n", 4)
		&& !ft_strncmp(tmp->content, "ra\n", 4))
		return (reducer(mv, tmp, "rr\n"));
	if (tmp && !ft_strncmp(mv->content, "rra\n", 5)
		&& !ft_strncmp(tmp->content, "rrb\n", 5))
		return (reducer(mv, tmp, "rrr\n"));
	if (tmp && !ft_strncmp(mv->content, "rrb\n", 5)
		&& !ft_strncmp(tmp->content, "rra\n", 5))
		return (reducer(mv, tmp, "rrr\n"));
	return ;
}

int	is_rotation(char *content)
{
	if (!ft_strncmp(content, "ra\n", ft_strlen("ra\n")))
		return (1);
	if (!ft_strncmp(content, "rb\n", ft_strlen("rb\n")))
		return (1);
	if (!ft_strncmp(content, "rra\n", ft_strlen("rra\n")))
		return (1);
	if (!ft_strncmp(content, "rrb\n", ft_strlen("rrb\n")))
		return (1);
	return (0);
}

void	optimization(t_mv_list *mv)
{
	while (mv)
	{
		if (is_rotation(mv->content))
		{
			is_reducible(mv);
		}
		mv = mv->next;
	}
	return ;
}
