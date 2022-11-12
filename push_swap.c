/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:13:39 by ajeanne           #+#    #+#             */
/*   Updated: 2022/11/12 15:43:42 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "push_swap.h"

#include <stdio.h>

void	clear(t_lists *lists)
{
	if (!lists)
		return ;
	ft_lstclear(lists->a);
	ft_lstclear(lists->b);
	ft_lstclear(lists->beg);
	ft_lstclear(lists->end);
	clear_mv(lists->mv);
	free(lists);
	return ;
}

int	error(t_lists *lists)
{
	clear(lists);
	write(1, "Error\n", 6);
	return (1);
}

int	parsing(t_list_data **a, char **number_list, int list_len)
{
	int	i;

	i = 1;
	while (i < list_len)
	{
		if (isok_nb(number_list[i]))
			return (1);
		if (*a && already_exist(a, ft_atoi(number_list[i])))
			return (1);
		if (*a)
		{
			if (ft_lstaddback(a, ft_lstnew(ft_atoi(number_list[i]))))
				return (1);
		}
		else
			*a = ft_lstnew(ft_atoi(number_list[i]));
		if (!(*a))
			return (1);
		i++;
	}
	return (0);
}

int	sorting(t_lists *lists, int *sorted_list, int list_len)
{
	int	med;

	med = list_len / 3;
	stack_content_modifier(&lists->a, sorted_list);
	while (lst_len(lists->a) > 3)
	{
		med_spliting(lists, med);
		med = (med + list_len) / 2;
	}
	while (!is_sorted(lists->a))
		if (sorta(lists))
			return (1);
	while (lists->b && !(lists->error))
		lists->error = choose_push(lists);
	while (is_lowest((lists->a)->content, lists->a) && !(lists->error))
	{
		if (last_sort_r(lists->a) <= last_sort_rr(lists->a))
			lists->error = split_sorting(lists, "ra\n");
		else if (last_sort_r(lists->a) > last_sort_rr(lists->a))
			lists->error = split_sorting(lists, "rra\n");
	}
	if (lists->error)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_lists	*lists;
	int		*list;

	list = malloc(sizeof(int) * argc - 1);
	if (!list)
		return (0);
	lists = ft_lstnew_lists();
	if (!lists)
		return (free(list), 0);
	if (argc < 3)
		return (free(list), error(lists));
	if (parsing(&lists->a, argv, argc))
		return (free(list), error(lists));
	if (lst_len(lists->a) == 2)
		return (only_two(lists->a), 0);
	if (sorting(lists, pre_sorting(lists->a, argc - 1, list), argc - 1))
		return (free(list), clear(lists), 0);
	free(list);
	optimization(lists->mv);
	printing(lists->mv);
	return (clear(lists), 0);
}
