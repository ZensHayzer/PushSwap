/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_calls1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:02:13 by ajeanne           #+#    #+#             */
/*   Updated: 2022/11/12 17:05:34 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	mv_rrotate(t_list_data **lst)
{
	if (*lst && (*lst)->next)
	{
		lst_rrotate(lst);
		while ((*lst)->prev)
			*lst = (*lst)->prev;
		return (0);
	}
	return (1);
}

int	double_mv_rrotate(t_list_data **lsta, t_list_data **lstb)
{
	if (!mv_rrotate(lsta))
		if (!mv_rrotate(lstb))
			return (0);
	return (1);
}
