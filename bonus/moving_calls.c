/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:00:08 by ajeanne           #+#    #+#             */
/*   Updated: 2022/11/12 17:00:36 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	mv_swap(t_list_data **lst)
{
	if (*lst && (*lst)->next)
	{
		lst_swap(*lst, (*lst)->next);
		while ((*lst)->prev)
			*lst = (*lst)->prev;
		return (0);
	}
	return (1);
}

int	double_mv_swap(t_list_data **lsta, t_list_data **lstb)
{
	if (!mv_swap(lsta))
		if (!mv_swap(lstb))
			return (0);
	return (1);
}

int	mv_push(t_list_data **lst_src, t_list_data **lst_dest)
{
	if (!(*lst_src))
		return (1);
	lst_push(lst_src, lst_dest);
	return (0);
}

int	mv_rotate(t_list_data **lst)
{
	if (*lst && (*lst)->next)
	{
		lst_rotate(lst);
		while ((*lst)->prev)
			*lst = (*lst)->prev;
		return (0);
	}
	return (1);
}

int	double_mv_rotate(t_list_data **lsta, t_list_data **lstb)
{
	if (!mv_rotate(lsta))
		if (!mv_rotate(lstb))
			return (0);
	return (1);
}
