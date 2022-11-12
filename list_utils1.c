/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:49:21 by ajeanne           #+#    #+#             */
/*   Updated: 2022/10/25 14:50:27 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int	isok_nb(char *nb)
{
	int	i;

	i = 0;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == 32)
		i++;
	if (nb[i] == '+' || nb[i] == '-')
		i++;
	if (nb[i] < '0' || nb[i] > '9')
		return (1);
	while (nb[i] >= '0' && nb[i] <= '9')
		i++;
	if (nb[i])
		return (1);
	if (ft_atoi(nb) > INT_MAX || ft_atoi(nb) < INT_MIN)
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

void	ft_lstclear(t_list_data *lst)
{
	void	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

int	already_exist(t_list_data **a, int nb)
{
	t_list_data	*tmp;

	tmp = *a;
	while (*a)
	{
		if (nb != (*a)->content)
			*a = (*a)->next;
		else
			return (1);
	}
	*a = tmp;
	return (0);
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
