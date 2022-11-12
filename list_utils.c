/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:34:47 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/31 17:48:42 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

t_list_data	*ft_lstnew(int content)
{
	t_list_data	*new_element;

	new_element = malloc(sizeof(t_list_data));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

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

size_t	lst_len(t_list_data *lst)
{
	size_t	len;

	len = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		len++;
		lst = lst->next;
	}
	return (len);
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
