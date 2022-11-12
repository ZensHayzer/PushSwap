/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:13:31 by ajeanne           #+#    #+#             */
/*   Updated: 2022/11/12 16:22:00 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>

/***************************************/
/*             CHAINED LISTS           */
/***************************************/

typedef struct t_list_data
{
	int					content;
	struct t_list_data	*next;
	struct t_list_data	*prev;
}				t_list_data;

typedef struct t_mv_list
{
	char				*content;
	struct t_mv_list	*next;
	struct t_mv_list	*prev;
}				t_mv_list;

typedef struct t_lists
{
	t_list_data	*a;
	t_list_data	*b;
	t_list_data	*beg;
	t_list_data	*end;
	t_mv_list	*mv;
	int			error;
}				t_lists;

/***************************************/
/*               FUNCTIONS             */
/***************************************/

// list_utils
t_list_data	*ft_lstnew(int content);
void		lst_swap(t_list_data *lst, t_list_data *lst1);
size_t		lst_len(t_list_data *lst);
void		lst_push(t_list_data **lst, t_list_data **lst1);

// list_utils1
int			isok_nb(char *nb);
long		ft_atoi(const char *str);
void		ft_lstclear(t_list_data *lst);
int			already_exist(t_list_data **a, int nb);
void		lst_rotate(t_list_data **lst);

// list_utils2
void		lst_rrotate(t_list_data **lst);
int			ft_lstaddback(t_list_data **lst, t_list_data *element);
t_list_data	*last_item(t_list_data *lst);
int			*pre_sorting(t_list_data *a, int len_list, int *list);
void		stack_content_modifier(t_list_data **a, int *sorted_list);

// list_utils3
int			medspliting_push(t_lists *lists, int *undermed);
void		printing(t_mv_list *mv);
int			split_sorting(t_lists *lists, char *mv);
void		only_two(t_list_data *a);

// list_utils4
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		clear_mv(t_mv_list *lst);

// list_utils5
t_mv_list	*last_item_mv(t_mv_list *lst);
int			last_sort_r(t_list_data *a);
int			last_sort_rr(t_list_data *a);
int			med_r(t_list_data *a, int med);
int			med_rr(t_list_data *a, int med);

// list_utils6
t_mv_list	*ft_lstnew_mv(char *content);
int			ft_lstaddback_mv(t_mv_list **lst, t_mv_list *element);
int			lst_len_mv(t_mv_list *lst);
t_lists		*ft_lstnew_lists(void);
int			*fill_tab(t_list_data *a, int *list, int *tmp);

// moving_func
int			mv_swap(t_list_data **lst);
int			double_mv_swap(t_list_data **lsta, t_list_data **lstb);
int			mv_push(t_list_data **lst_src, t_list_data **lst_dest);
int			mv_rotate(t_list_data **lst);
int			double_mv_rrotate(t_list_data **lsta, t_list_data **lstb);

// moving_func1
int			mv_rrotate(t_list_data **lst);
int			double_mv_rotate(t_list_data **lsta, t_list_data **lstb);

// sorting_func
int			is_sorted(t_list_data *lst);
int			under_med(t_list_data *lst, int med);
int			med_spliting(t_lists *lists, int med);
int			sorta(t_lists *lists);

// push_swap
void		clear(t_lists *lists);
int			error(t_lists *lists);
int			parsing(t_list_data **a, char **number_list, int list_len);
int			sorting(t_lists *lists, int *sorted_list, int list_len);

// sort_neededs
int			is_lowest(int b_content, t_list_data *a);
int			is_r(t_list_data *a, t_list_data *b);
int			is_rr(t_list_data *a, t_list_data *b);

// opti_func
void		is_reducible(t_mv_list *mv);
int			is_rotation(char *content);
void		optimization(t_mv_list *mv);

// push_elements
int			execute_r(t_list_data *a, t_list_data *b, t_mv_list **waiting_list);
int			execute_rr(t_list_data *a, t_list_data *b,
				t_mv_list **waiting_list);
int			place_element(t_lists *lists, t_mv_list **waiting_list,
				t_list_data *b, t_mv_list **tmp);
int			choose_push(t_lists *lists);

// push_elements1
int			execute_begin(t_lists *lists, t_mv_list **tmp, int *i);
int			execute_end(t_lists *lists, t_mv_list **tmp, int *i);
void		execute_list(t_mv_list *tmp, t_lists *lists);
void		tmp_to_mv(t_mv_list **tmp, t_mv_list **mv);

// sorting_case
int			rra_sorta(t_lists *lists);

// sorting_exec
void		med_exec_r(t_lists *lists, int med);
void		med_exec_rr(t_lists *lists, int med);

#endif
