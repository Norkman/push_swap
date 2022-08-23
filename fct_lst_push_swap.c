/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_lst_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:02:25 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/01 17:38:40 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_list(int num, t_list *head)
{
	t_list	*tmp;

	tmp = (t_list *) malloc(sizeof(t_list));
	tmp->content = num;
	tmp->next = head;
	head = tmp;
	return (head);
}

void	printf_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int	count_list(t_tablist *tl, char arg)
{
	int		cnt;
	t_list	*tmp;

	cnt = 0;
	if (arg == 'a')
		tmp = tl->la;
	else if (arg == 'b')
		tmp = tl->lb;
	while (tmp != NULL)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

void	free_list(t_tablist *tl)
{
	t_list	*tmp;

	while (tl->la != NULL)
	{
		tmp = tl->la;
		tl->la = tl->la->next;
		free(tmp);
	}
	while (tl->lb != NULL)
	{
		tmp = tl->lb;
		tl->lb = tl->lb->next;
		free(tmp);
	}
	free(tl);
}
