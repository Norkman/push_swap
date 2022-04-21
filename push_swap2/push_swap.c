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

	tl = malloc(sizeof(*tl));
	tl->lb = NULL;

	tl->la = ft_make_list(argc, argv);

	ft_printf("list a : ");
	printf_list(tl->la);
	ft_printf("\n");
	ft_printf("list b : ");
	printf_list(tl->lb);
	ft_printf("\n");

	tl = fct_push_arg(tl, 'b');

	ft_printf("list a : ");
	printf_list(tl->la);
	ft_printf("\n");
	ft_printf("list b : ");
	printf_list(tl->lb);
	ft_printf("\n");

	free_list(tl);
	return (0);
}
