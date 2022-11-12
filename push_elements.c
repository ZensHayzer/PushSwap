/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:11:31 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/30 17:05:40 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	execute_r(t_list_data *a, t_list_data *b, t_mv_list **waiting_list)
{
	while (a)
	{
		if (!is_lowest(b->content, a) && !is_lowest(a->content, a))
			break ;
		else if (is_lowest(b->content, a) && b->content < a->content
			&& b->content > last_item(a)->content)
			break ;
		else if (a->prev && is_lowest(b->content, a)
			&& b->content < a->content && b->content > a->prev->content)
			break ;
		a = a->next;
		if (ft_lstaddback_mv(waiting_list, ft_lstnew_mv("ra\n")))
			return (1);
	}
	return (0);
}

int	execute_rr(t_list_data *a, t_list_data *b, t_mv_list **waiting_list)
{
	if (a)
	{
		a = last_item(a);
		if (ft_lstaddback_mv(waiting_list, ft_lstnew_mv("rra\n")))
			return (1);
	}
	while (a)
	{
		if (!is_lowest(b->content, a) && !is_lowest(a->content, a))
			break ;
		else if (a->prev && is_lowest(b->content, a)
			&& b->content < a->content && b->content > a->prev->content)
			break ;
		a = a->prev;
		if (ft_lstaddback_mv(waiting_list, ft_lstnew_mv("rra\n")))
			return (1);
	}
	return (0);
}

int	place_element(t_lists *lists, t_mv_list **waiting_list,
			t_list_data *b, t_mv_list **tmp)
{
	if (is_r(lists->a, b) <= is_rr(lists->a, b))
		lists->error = execute_r(lists->a, b, waiting_list);
	else if (is_r(lists->a, b) > is_rr(lists->a, b))
		lists->error = execute_rr(lists->a, b, waiting_list);
	if (lists->error)
		return (1);
	if (ft_lstaddback_mv(waiting_list, ft_lstnew_mv("pa\n")))
		return (1);
	if (!(*tmp))
	{
		*tmp = *waiting_list;
		return (0);
	}
	if (lst_len_mv(*waiting_list) >= lst_len_mv(*tmp))
		return (clear_mv(*waiting_list), 0);
	clear_mv(*tmp);
	*tmp = *waiting_list;
	return (0);
}

void	initialize_vars(t_lists *lists, t_mv_list **tmp, int *i)
{
	lists->beg = lists->b;
	lists->end = last_item(lists->b);
	*tmp = NULL;
	*i = 0;
}

int	choose_push(t_lists *lists)
{
	t_mv_list	*tmp;
	int			i;

	initialize_vars(lists, &tmp, &i);
	lists->error = execute_begin(lists, &tmp, &i);
	lists->beg = lists->beg->next;
	while (lists->beg != lists->end && i / 2 < lst_len_mv(tmp) && !lists->error)
	{
		if (!(i % 2))
		{
			lists->error = execute_begin(lists, &tmp, &i);
			lists->beg = (lists->beg)->next;
		}
		else if (i % 2)
		{
			lists->error = execute_end(lists, &tmp, &i);
			lists->end = (lists->end)->prev;
		}
	}
	if (lists->error)
		return (clear_mv(tmp), 1);
	execute_list(tmp, lists);
	tmp_to_mv(&tmp, &lists->mv);
	return (0);
}
