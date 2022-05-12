/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fct2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:40:42 by nle-bret          #+#    #+#             */
/*   Updated: 2022/05/12 08:45:44 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fct_rotate(t_list *list)
{
	t_list	*list_end;
	t_list	*list_head;

	list_head = list->next;
	list_end = ft_lstlast(list);
	list_end->next = list;
	list->next = NULL;

	return (list_head);
}

t_tablist	*fct_rotate_arg(t_tablist *tl, char arg)
{
	if (arg == 'a' && count_list(tl, 'a') > 1)
		tl->la = fct_rotate(tl->la);
	if (arg == 'b' && count_list(tl, 'b') > 1)
		tl->lb = fct_rotate(tl->lb);
	if (arg == 'r' && count_list(tl, 'b') > 1 && count_list(tl, 'b'))
	{
		tl->la = fct_rotate(tl->la);
		tl->lb = fct_rotate(tl->lb);
	}
	ft_printf("r%c\n", arg);
	return (tl);
}

t_list	*fct_rotate_reverse(t_list *list)
{
	t_list	*list_head;
	t_list	*list_end;

	list_head = ft_lstlast(list);
	list_end = list;
	while (list_end->next->next)
		list_end = list_end->next;
	list_end->next = NULL;
	list_head->next = list;
	return (list_head);
}

t_tablist	*fct_rotate_reverse_arg(t_tablist *tl, char arg)
{
	if (arg == 'a' && count_list(tl, 'a') > 1)
		tl->la = fct_rotate_reverse(tl->la);
	if (arg == 'b' && count_list(tl, 'b') > 1)
		tl->lb = fct_rotate_reverse(tl->lb);
	if (arg == 'r' && count_list(tl, 'b') > 1 && count_list(tl, 'a'))
	{
		tl->la = fct_rotate_reverse(tl->la);
		tl->lb = fct_rotate_reverse(tl->lb);
	}
	ft_printf("rr%c\n", arg);
	return (tl);
}
