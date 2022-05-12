/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:42:09 by nle-bret          #+#    #+#             */
/*   Updated: 2022/05/12 11:15:20 by nle-bret         ###   ########.fr       */
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
t_tablist	*ft_make_list(int len_list, char **nbr_char);
t_list	*add_list(int num, t_list *head);
void	printf_list(t_list *head);
int		count_list(t_tablist *tl, char arg);
t_list	*remove_list(int num, t_list *head);
void	lst_printf(t_list *list);
void	free_list(t_tablist *tl);
int		push_swap(int argc, char **argv);
t_list	*fct_swap(t_list *list);
t_tablist	*fct_swap_arg(t_tablist *tl, char arg);
t_tablist	*fct_push(t_tablist *tl, char c);
t_tablist	*fct_push_arg(t_tablist *tl, char arg);
t_tablist	*fct_rotate_arg(t_tablist *tl, char arg);
t_list	*fct_rotate(t_list *list);
t_tablist	*fct_rotate_reverse_arg(t_tablist *tl, char arg);
t_list	*fct_rotate_reverse(t_list *list);
t_tablist	*ft_sort_three(t_tablist *tl);
int	ft_check_error(int length, char **list);
int	ft_is_sorted(t_tablist *tl, char arg);
t_tablist	*ft_sort_under_five(t_tablist *tl);
int	ft_isbigger(t_list *list);
int	ft_check_double(t_tablist *tl);
int	ft_findpos(t_tablist *list, char arg, int nbr);
t_tablist *ft_higher_up(t_tablist *tl, char arg);
t_tablist *ft_lower_up(t_tablist *tl, char arg);
int ft_findhigher(t_tablist *tl, char arg);
int ft_findlower(t_tablist *tl, char arg);

#endif
