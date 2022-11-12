/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:12:56 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/31 15:23:31 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	med_exec_r(t_lists *lists, int med)
{
	while ((lists->a)->content > med && !(lists->error))
	{
		mv_rotate(&lists->a);
		lists->error = ft_lstaddback_mv(&lists->mv, ft_lstnew_mv("ra\n"));
	}
}

void	med_exec_rr(t_lists *lists, int med)
{
	while ((lists->a)->content > med && !(lists->error))
	{
		mv_rrotate(&lists->a);
		lists->error = ft_lstaddback_mv(&lists->mv, ft_lstnew_mv("rra\n"));
	}
}
