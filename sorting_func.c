/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:30:30 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/31 18:50:29 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	is_sorted(t_list_data *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	while (lst->prev)
		lst = lst->prev;
	return (1);
}

int	under_med(t_list_data *lst, int med)
{
	int	count;

	count = 0;
	while (lst)
	{
		if (lst->content < med)
			count++;
		lst = lst->next;
	}
	return (count);
}

int	med_spliting(t_lists *lists, int med)
{
	int	undermed;

	undermed = under_med(lists->a, med);
	while (undermed && !(lists->error))
	{
		if ((lists->a)->content <= med)
			lists->error = medspliting_push(lists, &undermed);
		else if (med_r(lists->a, med) <= med_rr(lists->a, med)
			&& !(lists->error))
			med_exec_r(lists, med);
		else if (med_r(lists->a, med) > med_rr(lists->a, med)
			&& !(lists->error))
			med_exec_rr(lists, med);
	}
	if ((lists->error))
		return (1);
	return (0);
}

int	sorta(t_lists *lists)
{
	if (lists->a && lists->a->next && lists->a->next->next
		&& lists->a->content > lists->a->next->content
		&& lists->a->content > lists->a->next->next->content)
	{
		mv_rotate(&lists->a);
		if (ft_lstaddback_mv(&lists->mv, ft_lstnew_mv("ra\n")))
			return (1);
	}
	if (lists->a->next && lists->a->next->next
		&& lists->a->next->content > lists->a->next->next->content)
		if (rra_sorta(lists))
			return (1);
	if (lists->a && lists->a->next
		&& lists->a->content > lists->a->next->content)
	{
		mv_swap(&lists->a);
		if (ft_lstaddback_mv(&lists->mv, ft_lstnew_mv("sa\n")))
			return (1);
	}
	if (lists->a && lists->a->next->next
		&& lists->a->content > lists->a->next->next->content)
		if (rra_sorta(lists))
			return (1);
	return (0);
}
