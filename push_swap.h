/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:42:09 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/05 15:07:17 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "sources/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_tablist
{
	t_list	*la;
	t_list	*lb;
}t_tablist;
typedef struct s_data
{
	int	pos;
	int	up_o;
	int	len_la;
	int	len_lb;
}t_data;
typedef struct s_cost
{
	int	up;
	int	down;
	int	updown;
	int	downup;
}t_cost;
t_tablist	*ft_make_list(int len_list, char **nbr_char);
t_list		*add_list(int num, t_list *head);
void		printf_list(t_list *head);
int			count_list(t_tablist *tl, char arg);
t_list		*remove_list(int num, t_list *head);
void		lst_printf(t_list *list);
void		free_list(t_tablist *tl);
int			push_swap(int argc, char **argv);
t_list		*fct_swap(t_list *list);
t_tablist	*fct_swap_arg(t_tablist *tl, char arg);
t_tablist	*fct_push(t_tablist *tl, char c);
t_tablist	*fct_push_arg(t_tablist *tl, char arg);
t_tablist	*fct_rotate_arg(t_tablist *tl, char arg);
t_list		*fct_rotate(t_list *list);
t_tablist	*fct_rotate_reverse_arg(t_tablist *tl, char arg);
t_list		*fct_rotate_reverse(t_list *list);
t_tablist	*ft_sort_three(t_tablist *tl);
int			ft_check_error(int length, char **list);
int			ft_is_sorted(t_tablist *tl, char arg);
int			ft_is_reversesorted(t_tablist *tl, char arg);
t_tablist	*ft_sort_under_five(t_tablist *tl);
int			ft_isbigger(t_list *list);
int			ft_check_double(t_tablist *tl);
int			ft_findpos(t_tablist *list, char arg, int nbr);
t_tablist	*ft_higher_up(t_tablist *tl, char arg);
t_tablist	*ft_lower_up(t_tablist *tl, char arg);
int			ft_findhigher(t_tablist *tl, char arg);
int			ft_findlower(t_tablist *tl, char arg);
t_tablist	*ft_sort_under_seventy(t_tablist *tl);
t_tablist	*ft_putinlb(t_tablist *tl);
t_tablist	*ft_choicerotate(t_tablist *tl, int costh, int costl);
int			ft_med_list(t_tablist *tl);
t_tablist	*ft_sort_under_fivehundred(t_tablist *tl);
int			ft_howmanyunder(t_list *list, int nbr);
t_tablist	*ft_putbox(t_tablist *tl, int box);
t_tablist	*ft_putnbrofbox(t_tablist *tl, int box);
int			ft_findcostdown(t_tablist *tl, int rest_nbr_box);
int			ft_findcostup(t_tablist	*tl, int rest_nbr_box);
t_tablist	*ft_rotateup(t_tablist *tl, int costup);
t_tablist	*ft_rotatedown(t_tablist *tl, int costdown);
int			ft_findinferior(t_list *list, int nbr);
int			ft_findsuperior(t_list *list, int nbr);
int			ft_findnbr(t_tablist *tl, char arg, int pos);
t_data		ft_m_d_la(t_tablist *tl, int nbr);
void		disp(t_list *head_a, t_list *head_b);
t_tablist	*ft_rotatelesscost(t_tablist *tl, t_cost cost, int len);
t_tablist	*ft_sortinla(t_tablist *tl, int len);
t_tablist	*ft_rotatedownalt(t_tablist *tl, int cost, int len);
t_tablist	*ft_rotatecostdown(t_tablist *tl, t_data d);
t_tablist	*ft_rotatecostdownex(t_tablist *tl, t_data d);
t_tablist	*ft_rotateupalt(t_tablist *tl, int cost, int len);
t_tablist	*ft_rotatecostup(t_tablist *tl, t_data d);
t_tablist	*ft_rotatedownup(t_tablist *tl, int cost, int len);
t_tablist	*ft_rotateupdown(t_tablist *tl, int cost, int len);
t_tablist	*ft_rotatecostdownup(t_tablist *tl, t_data d);
t_tablist	*ft_rotatecostupdown(t_tablist *tl, t_data d);
int			ft_howcostdown(t_tablist *tl, int len);
int			ft_howcostup(t_tablist *tl, int len);
int			ft_howcostupdown(t_tablist *tl, int len);
int			ft_howcostdownup(t_tablist *tl, int len);
t_tablist	*ft_putinlbalt(t_tablist *tl);
#endif
