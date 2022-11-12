/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 03:05:36 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/30 03:40:33 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mv_list	*last_item_mv(t_mv_list *lst)
{
	t_mv_list	*tmp;

	while (lst->next)
		lst = lst->next;
	tmp = lst;
	while (lst->prev)
		lst = lst->prev;
	return (tmp);
}

int	last_sort_r(t_list_data *a)
{
	int	cpt;

	cpt = 0;
	while (is_lowest(a->content, a))
	{
		a = a->next;
		cpt++;
	}
	return (cpt);
}

int	last_sort_rr(t_list_data *a)
{
	int	cpt;

	cpt = 0;
	if (a)
	{
		a = last_item(a);
		cpt++;
	}
	while (a && is_lowest(a->content, a))
	{
		a = a->prev;
		cpt++;
	}
	return (cpt);
}

int	med_r(t_list_data *a, int med)
{
	int	cpt;

	cpt = 0;
	while (a && a->content > med)
	{
		a = a->next;
		cpt++;
	}
	return (cpt);
}

int	med_rr(t_list_data *a, int med)
{
	int	cpt;

	cpt = 0;
	a = last_item(a);
	cpt++;
	while (a && a->content > med)
	{
		a = a->prev;
		cpt++;
	}
	return (cpt);
}
