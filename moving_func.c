/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 02:07:07 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/25 14:48:39 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>
#include <unistd.h>

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
