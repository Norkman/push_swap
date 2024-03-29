/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:55:50 by nle-bret          #+#    #+#             */
/*   Updated: 2022/08/02 17:56:12 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tablist	*ft_begin(t_tablist *tl)
{
	if (count_list(tl, 'a') == 2 && ft_is_sorted(tl, 'a') == 1)
		tl = fct_swap_arg(tl, 'a');
	else if (count_list(tl, 'a') == 3)
		tl = ft_sort_three(tl);
	else if (count_list(tl, 'a') <= 5)
		tl = ft_sort_under_five(tl);
	else if (count_list(tl, 'a') <= 500)
		tl = ft_sort_under_fivehundred(tl);
	return (tl);
}

int	push_swap(int argc, char **argv)
{
	t_tablist	*tl;
	char		**list_fct;

	if (ft_check_error(argc, argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (argc < 3)
		return (0);
	tl = ft_make_list(argc, argv);
	if (ft_check_double(tl) || argc - 1 != count_list(tl, 'a'))
	{
		ft_putstr_fd("Error\n", 2);
		free_list(tl);
		return (0);
	}
	tl = ft_begin(tl);
	free_list(tl);
	return (0);
}
