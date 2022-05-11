/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:50:38 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/21 17:49:15 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fct_swap(t_list *list)
{
	int	tmp;

	tmp = list->content;
	list->content = list->next->content;
	list->next->content = tmp;
	return (list);
}

t_tablist	*fct_swap_arg(t_tablist *tl, char arg)
{
	if (arg == 'a' && count_list(tl->la) > 1)
		tl->la = fct_swap(tl->la);
	if (arg == 'b' && count_list(tl->lb) > 1)
		tl->lb = fct_swap(tl->lb);
	if (arg == 's' && count_list(tl->la) > 1 && count_list(tl->lb) > 1)
	{
		tl->la = fct_swap(tl->la);
		tl->lb = fct_swap(tl->lb);
	}
	ft_printf("s%c\n", arg);
	return (tl);
}

t_tablist	*fct_push(t_tablist *tl, char c)
{
	t_list	*tmp;

	if (c == 'a')
	{
		tl->la = add_list(tl->lb->content, tl->la);
		tmp = tl->lb;
		tl->lb = tl->lb->next;
		free(tmp);
	}
	if (c == 'b')
	{
		tl->lb = add_list(tl->la->content, tl->lb);
		tmp = tl->la;
		tl->la = tl->la->next;
		free(tmp);
	}
	return (tl);
}

t_tablist	*fct_push_arg(t_tablist *tl, char arg)
{
	if (arg == 'a' && count_list(tl->lb) > 0)
		tl = fct_push(tl, 'a');
	if (arg == 'b' && count_list(tl->la) > 0)
		tl = fct_push(tl, 'b');
	ft_printf("p%c\n", arg);
	return (tl);
}
