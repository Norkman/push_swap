/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:42:09 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/21 14:48:51 by nle-bret         ###   ########.fr       */
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
t_list	*ft_make_list(int len_list, char **nbr_char);
t_list	*add_list(int num, t_list *head);
void	printf_list(t_list *head);
int		count_list(t_list *head);
t_list	*remove_list(int num, t_list *head);
void	lst_printf(t_list *list);
void	free_list(t_tablist *tl);
int		push_swap(int argc, char **argv);
t_list	*fct_swap(t_list *list);
t_tablist	*fct_swap_arg(t_tablist *tl, char arg);
t_tablist	*fct_push(t_tablist *tl, t_list *l1, t_list *l2);
t_tablist	*fct_push_arg(t_tablist *tl, char arg);

#endif
