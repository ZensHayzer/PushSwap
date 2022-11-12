/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elements1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:14:53 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/30 02:14:44 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	execute_begin(t_lists *lists, t_mv_list **tmp, int *i)
{
	t_mv_list	*waiting_list;
	t_list_data	*b_tmp;

	waiting_list = NULL;
	b_tmp = lists->b;
	while (b_tmp->content != (lists->beg)->content && !(lists->error))
	{
		b_tmp = b_tmp->next;
		lists->error = ft_lstaddback_mv(&waiting_list, ft_lstnew_mv("rb\n"));
	}
	if (lists->error)
		return (clear_mv(waiting_list), 1);
	lists->error = place_element(lists, &waiting_list, lists->beg, tmp);
	if (lists->error)
		return (clear_mv(waiting_list), 1);
	*i = *i + 1;
	return (0);
}

int	execute_end(t_lists *lists, t_mv_list **tmp, int *i)
{
	t_mv_list	*waiting_list;
	t_list_data	*b_tmp;

	waiting_list = NULL;
	b_tmp = last_item(lists->b);
	lists->error = ft_lstaddback_mv(&waiting_list, ft_lstnew_mv("rrb\n"));
	while (b_tmp->content != (lists->end)->content)
	{
		b_tmp = b_tmp->prev;
		lists->error = ft_lstaddback_mv(&waiting_list, ft_lstnew_mv("rrb\n"));
	}
	if (lists->error)
		return (clear_mv(waiting_list), 1);
	lists->error = place_element(lists, &waiting_list, lists->end, tmp);
	if (lists->error)
		return (clear_mv(waiting_list), 1);
	*i = *i + 1;
	return (0);
}

void	execute_list(t_mv_list *tmp, t_lists *lists)
{
	while (tmp)
	{
		if (!ft_strncmp(tmp->content, "ra\n", ft_strlen("ra\n")))
			mv_rotate(&lists->a);
		else if (!ft_strncmp(tmp->content, "rb\n", ft_strlen("rb\n")))
			mv_rotate(&lists->b);
		else if (!ft_strncmp(tmp->content, "rra\n", ft_strlen("rra\n")))
			mv_rrotate(&lists->a);
		else if (!ft_strncmp(tmp->content, "rrb\n", ft_strlen("rrb\n")))
			mv_rrotate(&lists->b);
		else if (!ft_strncmp(tmp->content, "pa\n", ft_strlen("pa\n")))
			mv_push(&lists->b, &lists->a);
		else if (!ft_strncmp(tmp->content, "pb\n", ft_strlen("pb\n")))
			mv_push(&lists->a, &lists->b);
		else if (!ft_strncmp(tmp->content, "sa\n", ft_strlen("sa\n")))
			mv_swap(&lists->a);
		else if (!ft_strncmp(tmp->content, "sb\n", ft_strlen("sb\n")))
			mv_swap(&lists->b);
		tmp = tmp->next;
	}
	return ;
}

void	tmp_to_mv(t_mv_list **tmp, t_mv_list **mv)
{
	if (*tmp && *mv)
	{
		(*tmp)->prev = last_item_mv(*mv);
		last_item_mv(*mv)->next = *tmp;
	}
	return ;
}
