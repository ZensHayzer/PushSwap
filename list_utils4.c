/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:31:12 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/30 16:55:07 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	char	*tmp;

	tmp = (char *)s;
	while (*tmp)
		tmp++;
	return (tmp - s);
}

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

void	clear_mv(t_mv_list *lst)
{
	t_mv_list	*tmp;
	t_mv_list	*next;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
