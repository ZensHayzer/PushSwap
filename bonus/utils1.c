/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:10:04 by ajeanne           #+#    #+#             */
/*   Updated: 2022/11/12 17:55:50 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	is_sorted(t_list_data *lst)
{
	while (lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	while (lst->prev)
		lst = lst->prev;
	return (1);
}
