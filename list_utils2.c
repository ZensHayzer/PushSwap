/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 23:26:11 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/29 06:22:03 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_lstaddback(t_list_data **lst, t_list_data *element)
{
	if (!element)
		return (1);
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = element;
	element->prev = *lst;
	element->next = NULL;
	while ((*lst)->prev)
		*lst = (*lst)->prev;
	return (0);
}

t_list_data	*last_item(t_list_data *lst)
{
	t_list_data	*tmp;

	while (lst->next)
		lst = lst->next;
	tmp = lst;
	while (lst->prev)
		lst = lst->prev;
	return (tmp);
}

int	*pre_sorting(t_list_data *a, int len_list, int *list)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	list = fill_tab(a, list, &tmp);
	while (i < len_list)
	{
		j = i + 1;
		while (j < len_list)
		{
			if (list[j] < list[i])
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (list);
}

void	stack_content_modifier(t_list_data **a, int *sorted_list)
{
	int	pos;

	pos = 0;
	while ((*a)->next)
	{
		while ((*a)->content != sorted_list[pos])
			pos++;
		(*a)->content = pos;
		*a = (*a)->next;
		pos = 0;
	}
	while ((*a)->content != sorted_list[pos])
			pos++;
	(*a)->content = pos;
	while ((*a)->prev)
		*a = (*a)->prev;
	return ;
}
