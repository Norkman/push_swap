/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:55:50 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/21 17:38:07 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_tablist	*tl;
	char **list_fct;

	tl = malloc(sizeof(*tl));
	tl->lb = NULL;
	tl->la = ft_make_list(argc, argv);
	if (tl->la == NULL)
	{
		free(tl);
		return (0);
	}
	ft_printf("\n%d\n", ft_is_sorted(tl->la));
	printf_list(tl->la);
	if (count_list(tl->la) == 3)
		tl = ft_sort_three(tl);
	else if (count_list(tl->la) <= 5)
		tl = ft_sort_under_five(tl);
	ft_printf("\n%d\n", ft_is_sorted(tl->la));
	printf_list(tl->la);
	free_list(tl);
	return (0);
}
