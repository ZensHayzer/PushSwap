/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:00:58 by ajeanne           #+#    #+#             */
/*   Updated: 2022/11/12 18:07:22 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "unistd.h"

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

void	error(t_list_data *lsta, t_list_data *lstb, char *line)
{
	ft_lstclear(lsta);
	ft_lstclear(lstb);
	if (line)
		free(line);
	write(1, "KO\n", 3);
	return ;
}

void	clean(t_list_data *lsta, t_list_data *lstb, char *line)
{
	ft_lstclear(lsta);
	ft_lstclear(lstb);
	if (line)
		free(line);
	write(1, "OK\n", 3);
	return ;
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

int	main(int argc, char **argv)
{
	char		*line;
	t_list_data	*a;
	t_list_data	*b;

	a = NULL;
	b = NULL;
	line = NULL;
	if (argc < 3)
		return (error(a, b, line), 0);
	if (parsing(&a, argv, argc))
		return (error(a, b, line), 0);
	line = get_next_line(0);
	while (line)
	{
		if (!execute_calls(&a, &b, line))
			return (error(a, b, line), 0);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(a) && !b)
		return (clean(a, b, line), 0);
	return (error(a, b, line), 0);
}
