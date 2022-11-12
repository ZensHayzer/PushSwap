/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:56:53 by ajeanne           #+#    #+#             */
/*   Updated: 2022/11/12 16:58:54 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	lst_swap(t_list_data *lst, t_list_data *lst1)
{
	t_list_data	*tmp;

	tmp = lst->prev;
	if (lst1->next)
		lst1->next->prev = lst;
	lst->prev = lst1;
	lst->next = lst1->next;
	lst1->next = lst;
	lst1->prev = tmp;
	return ;
}

void	lst_push(t_list_data **lst, t_list_data **lst1)
{
	t_list_data	*tmp;

	tmp = (*lst)->next;
	(*lst)->next = *lst1;
	(*lst)->prev = NULL;
	if (*lst1)
		(*lst1)->prev = *lst;
	*lst1 = *lst;
	*lst = tmp;
	if (*lst)
		(*lst)->prev = NULL;
	return ;
}

void	lst_rotate(t_list_data **lst)
{
	t_list_data	*tmp;

	tmp = *lst;
	(*lst)->next->prev = NULL;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = tmp;
	(*lst)->next->prev = *lst;
	(*lst)->next->next = NULL;
	return ;
}

void	lst_rrotate(t_list_data **lst)
{
	t_list_data	*tmp;
	t_list_data	*start;

	start = *lst;
	while ((*lst)->next)
		*lst = (*lst)->next;
	tmp = *lst;
	*lst = start;
	(*lst)->prev = tmp;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *lst;
}
