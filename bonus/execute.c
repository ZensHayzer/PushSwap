/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:51:16 by ajeanne           #+#    #+#             */
/*   Updated: 2022/11/12 17:31:59 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	swaps(t_list_data **a, t_list_data **b, char *call)
{
	if (!ft_strncmp(call, "sa\n", ft_strlen("sa\n")))
		return (mv_swap(a), 1);
	else if (!ft_strncmp(call, "sb\n", ft_strlen("sb\n")))
		return (mv_swap(b), 1);
	else if (!ft_strncmp(call, "ss\n", ft_strlen("ss\n")))
		return (double_mv_swap(a, b), 1);
	return (0);
}

int	rotates(t_list_data **a, t_list_data **b, char *call)
{
	if (!ft_strncmp(call, "ra\n", ft_strlen("ra\n")))
		return (mv_rotate(a), 1);
	else if (!ft_strncmp(call, "rb\n", ft_strlen("rb\n")))
		return (mv_rotate(b), 1);
	else if (!ft_strncmp(call, "rr\n", ft_strlen("rr\n")))
		return (double_mv_rotate(a, b), 1);
	return (0);
}

int	reverse_rotates(t_list_data**a, t_list_data **b, char *call)
{
	if (!ft_strncmp(call, "rra\n", ft_strlen("rra\n")))
		return (mv_rrotate(a), 1);
	else if (!ft_strncmp(call, "rrb\n", ft_strlen("rrb\n")))
		return (mv_rrotate(b), 1);
	else if (!ft_strncmp(call, "rrr\n", ft_strlen("rrr\n")))
		return (double_mv_rrotate(a, b), 1);
	return (0);
}

int	pushs(t_list_data **a, t_list_data **b, char *call)
{
	if (!ft_strncmp(call, "pa\n", ft_strlen("pa\n")))
		return (mv_push(b, a), 1);
	if (!ft_strncmp(call, "pb\n", ft_strlen("pb\n")))
		return (mv_push(a, b), 1);
	return (0);
}

int	execute_calls(t_list_data **a, t_list_data **b, char *call)
{
	if (swaps(a, b, call))
		return (1);
	else if (rotates(a, b, call))
		return (1);
	else if (reverse_rotates(a, b, call))
		return (1);
	else if (pushs(a, b, call))
		return (1);
	return (0);
}
