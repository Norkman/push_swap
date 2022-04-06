/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:14:38 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/05 16:52:34 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_printf(t_list **list)
{
	int	nbr;
	t_list *tmp;

	tmp = *list;
	while (tmp->next)
	{
		nbr = tmp->content;
		ft_printf("%d\n",nbr);
		tmp = tmp->next;
	}
}

t_list **ft_make_list(int len_list, char **nbr_char)
{
	t_list	**list;
	t_list	*list_new;
	int	i;

	list = NULL;
	i = 1;
	while (i <= len_list)
	{
		list_new = ft_lstnew(ft_atoi(nbr_char[1]));
		printf("OK");
		//ft_lstadd_back(list, list_new);
		i++;
	}
	free(list_new);
	return (list);
}
