/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:40:29 by ajeanne           #+#    #+#             */
/*   Updated: 2022/11/12 16:43:25 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "limits.h"

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
