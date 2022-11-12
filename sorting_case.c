/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:13:17 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/31 17:44:10 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra_sorta(t_lists *lists)
{
	mv_rrotate(&lists->a);
	if (ft_lstaddback_mv(&lists->mv, ft_lstnew_mv("rra\n")))
		return (1);
	return (0);
}
