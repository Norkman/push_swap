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
			return (1);
		while (j < ft_strlen(list[i]))
		{
			if (ft_isdigit(list[i][j]) == 1)
			{
				ft_printf("ERROR\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_list *ft_make_list(int len_list, char **nbr_char)
{
	t_list	*list;
	int	new_content;
	int	i;

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

	while (tl)
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
