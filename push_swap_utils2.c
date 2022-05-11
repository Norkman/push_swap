/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:11:52 by nle-bret          #+#    #+#             */
/*   Updated: 2022/05/11 18:06:50 by nle-bret         ###   ########.fr       */
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
			if (ft_isdigit(list[i][j]) == 0 && list[i][j] != '-'
				|| list[i][j] == '-' && ft_isdigit(list[i][j + 1]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_double(t_list *list)
{
	t_list	*tmpi;
	t_list	*tmpj;

	tmpi = list;
	while (tmpi->next)
	{
		tmpj = tmpi->next;
		while (tmpj)
		{
			if (tmpi->content == tmpj->content)
				return (1);
			tmpj = tmpj->next;
		}
		tmpi = tmpi->next;
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

