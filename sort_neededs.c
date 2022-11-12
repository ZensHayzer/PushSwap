/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_neededs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:39:07 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/25 14:41:46 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_lowest(int b_content, t_list_data *a)
{
	while (a->prev)
		a = a->prev;
	while (a)
	{
		if (b_content > a->content)
			return (1);
		a = a->next;
	}
	return (0);
}

int	is_r(t_list_data *a, t_list_data *b)
{
	int	cpt;

	cpt = 0;
	while (a)
	{
		if (!is_lowest(b->content, a) && !is_lowest(a->content, a))
			break ;
		else if (is_lowest(b->content, a) && b->content < a->content
			&& b->content > last_item(a)->content)
			break ;
		else if (a->prev && is_lowest(b->content, a)
			&& b->content < a->content && b->content > a->prev->content)
		{
			break ;
		}
		a = a->next;
		cpt++;
	}
	return (cpt);
}

int	is_rr(t_list_data *a, t_list_data *b)
{
	int	cpt;

	cpt = 1;
	if (a)
		a = last_item(a);
	while (a)
	{
		if (!is_lowest(b->content, a) && !is_lowest(a->content, a))
			break ;
		else if (a->prev && is_lowest(b->content, a) && b->content < a->content
			&& b->content > a->prev->content)
		{
			break ;
		}
		a = a->prev;
		cpt++;
	}
	return (cpt);
}
