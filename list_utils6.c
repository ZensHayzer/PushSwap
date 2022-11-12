/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:51:13 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/29 20:26:55 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_mv_list	*ft_lstnew_mv(char *content)
{
	t_mv_list	*new_element;

	new_element = malloc(sizeof(t_mv_list));
	if (!new_element)
		return (NULL);
	new_element->content = content;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

int	ft_lstaddback_mv(t_mv_list **lst, t_mv_list *element)
{
	if (!element)
		return (1);
	if (*lst)
	{
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = element;
	}
	element->prev = *lst;
	element->next = NULL;
	if (!(*lst))
		*lst = element;
	while ((*lst)->prev)
		*lst = (*lst)->prev;
	return (0);
}

int	lst_len_mv(t_mv_list *lst)
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

t_lists	*ft_lstnew_lists(void)
{
	t_lists	*new_element;

	new_element = malloc(sizeof(t_lists));
	if (!new_element)
		return (NULL);
	new_element->a = NULL;
	new_element->b = NULL;
	new_element->beg = NULL;
	new_element->end = NULL;
	new_element->mv = NULL;
	new_element->error = 0;
	return (new_element);
}

int	*fill_tab(t_list_data *a, int *list, int *tmp)
{
	while (a->next)
	{
		list[*tmp] = a->content;
		a = a->next;
		*tmp = *tmp + 1;
	}
	list[*tmp] = a->content;
	return (list);
}
