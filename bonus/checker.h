/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:20:35 by ajeanne           #+#    #+#             */
/*   Updated: 2022/11/15 12:55:52 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "gnl/get_next_line.h"

/***************************************/
/*             CHAINED LISTS           */
/***************************************/

typedef struct t_list_data
{
	int					content;
	struct t_list_data	*next;
	struct t_list_data	*prev;
}				t_list_data;

/***************************************/
/*               FUNCTIONS             */
/***************************************/

// execute
int			swaps(t_list_data **a, t_list_data **b, char *call);
int			rotates(t_list_data **a, t_list_data **b, char *call);
int			reverse_rotates(t_list_data**a, t_list_data **b, char *call);
int			pushs(t_list_data **a, t_list_data **b, char *call);
int			execute_calls(t_list_data **a, t_list_data **b, char *call);

// utils
t_list_data	*ft_lstnew(int content);
int			ft_lstaddback(t_list_data **lst, t_list_data *element);
int			already_exist(t_list_data **a, int nb);
long		ft_atoi(const char *str);
int			isok_nb(char *nb);

// utils1
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			is_sorted(t_list_data *lst);
void		ft_lstclear(t_list_data *lst);

// moving
void		lst_swap(t_list_data *lst, t_list_data *lst1);
void		lst_push(t_list_data **lst, t_list_data **lst1);
void		lst_rotate(t_list_data **lst);
void		lst_rrotate(t_list_data **lst);

// moving_calls
int			mv_swap(t_list_data **lst);
int			double_mv_swap(t_list_data **lsta, t_list_data **lstb);
int			mv_push(t_list_data **lst_src, t_list_data **lst_dest);
int			mv_rotate(t_list_data **lst);
int			double_mv_rotate(t_list_data **lsta, t_list_data **lstb);

// moving_calls1
int			mv_rrotate(t_list_data **lst);
int			double_mv_rrotate(t_list_data **lsta, t_list_data **lstb);

// checker

#endif
