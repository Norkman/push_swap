/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:14:38 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/21 13:00:10 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error(int length, char **list)
{
	int	i;
	int	j;

	i = 1;
	while (i < length)
	{
		j = 0;
		while (j < ft_strlen(list[i]))
		{
			if (ft_isdigit(list[i][j]) == 0)
			{
				ft_printf("%c\n", list[i][j]);
				ft_printf("ERROR\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_sorted(t_list *list)
{
	int		i;
	t_list	*tmp;

	tmp = list;
	if (count_list(tmp) < 2)
		return (0);
	while (list->next)
	{
		if (list->content > list->next->content)
			return (1);
		list = list->next;
	}
	return (0);
}

t_list *ft_make_list(int len_list, char **nbr_char)
{
	t_list	*list;
	int		new_content;
	int		i;

	list = NULL;
	if (ft_check_error(len_list, nbr_char) == 1)
		return (NULL);
	i = len_list - 1;
	while (i >= 1)
	{
		new_content = ft_atoi(nbr_char[i]);
		list = add_list(new_content, list);
		i--;
	}
	return (list);
}

t_tablist	*ft_sort_three(t_tablist *tl)
{
	char	*list_fct;
	
	while (tl && count_list(tl->la) == 3)
	{
		if (tl->la->content < tl->la->next->content 
				&& tl->la->next->content < tl->la->next->next->content)
			return (tl);
		if (tl->la->content > tl->la->next->content 
				&& tl->la->next->content < tl->la->next->next->content
				&& tl->la->content > tl->la->next->next->content)
			tl = fct_rotate_arg(tl, 'a');
		if (tl->la->content > tl->la->next->content 
				&& tl->la->next->content < tl->la->next->next->content)
			tl = fct_swap_arg(tl, 'a');
		if (tl->la->content > tl->la->next->content 
				&& tl->la->next->content > tl->la->next->next->content)
			tl = fct_rotate_arg(tl, 'a');
		if (tl->la->content < tl->la->next->content 
				&& tl->la->next->content > tl->la->next->next->content)
			tl = fct_rotate_reverse_arg(tl, 'a');
	}
	return (tl);
}

t_tablist	*ft_sort_under_five(t_tablist *tl)
{
	int len_la;

	len_la = count_list(tl->la);
	if (len_la == 5)
		tl == fct_push_arg(tl, 'b');
	tl = fct_push_arg(tl, 'b');
	while (ft_is_sorted(tl->la) == 1 || count_list(tl->la) != len_la)
	{
		tl = ft_sort_three(tl);
		tl = fct_push_arg(tl, 'a');
		if (ft_is_sorted(tl->lb) == 0)
			tl = fct_swap_arg(tl, 'b');
		if (tl->la->content > tl->la->next->content)
		{
			if (count_list(tl->la) == 5)
			{
				fct_rotate_arg(tl, 'a');
				tl = fct_push_arg(tl, 'b');
				tl = fct_push_arg(tl, 'b');
			}
			else 
			{
				tl = fct_swap_arg(tl, 'a');
				tl = fct_push_arg(tl, 'b');
			}
		}
	//tl = fct_push_arg(tl, 'a');
	//if (tl->la->content > tl->la->next->content)
	//	tl = fct_rotate_arg(tl, 'a');
	}
	return (tl);
}
