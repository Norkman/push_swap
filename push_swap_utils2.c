/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:11:52 by nle-bret          #+#    #+#             */
/*   Updated: 2022/05/12 11:27:12 by nle-bret         ###   ########.fr       */
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

int	ft_check_double(t_tablist *tl)
{
	t_list	*tmpi;
	t_list	*tmpj;

	tmpi = tl->la;
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

int	ft_is_sorted(t_tablist *tl, char arg)
{
	int		i;
	t_list	*tmp;

	if (arg == 'a')
		tmp = tl->la;
	else if (arg == 'b')
		tmp = tl->lb;
	if (count_list(tl, arg) < 2)
		return (0);
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_tablist	*ft_make_list(int len_list, char **nbr_char)
{
	t_tablist	*tl;
	long int	long_new_content;
	int			new_content;
	int			i;

	tl = malloc(sizeof(*tl));
	tl->la = NULL;
	tl->lb = NULL;
	if (ft_check_error(len_list, nbr_char) == 1)
		return (NULL);
	i = len_list - 1;
	while (i >= 1)
	{
		long_new_content = ft_atoli(nbr_char[i]);
		//printf("---- %ld\n", long_new_content);
		if (long_new_content > 2147483647 || long_new_content < -2147483648)
		{
			free_list(tl);
			return (NULL);
		}
		new_content = (int)long_new_content;
		tl->la = add_list(new_content, tl->la);
		i--;
	}
	return (tl);
}

