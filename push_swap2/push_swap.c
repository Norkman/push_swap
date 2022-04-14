/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:55:50 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/08 13:17:17 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_tablist	*tl;

	tl->lb = NULL;
	tl->la = ft_make_list(argc, argv);
	printf_list(tl->la);
	tl->la = fct_sa(tl->la);
	printf_list(tl->la);
	free_list(tl->la);
	return (0);
}
