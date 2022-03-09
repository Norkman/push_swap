/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:45:48 by nle-bret          #+#    #+#             */
/*   Updated: 2022/03/09 16:22:46 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(int *list, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", list[i]);
		i++;
	}
	ft_printf("\n");
}

int push_swap(int size, char **nbr_on_char)
{
	int i;
	int	nbr;
	int	*la;
	int	*lb;

	la = malloc(sizeof(*la) * (size));
	lb = malloc(sizeof(*lb) * (size));
	i = 1;
	while (i < size)
	{
		nbr = ft_atoi(nbr_on_char[i]);
		la[i - 1] = nbr;
		i++;
	}

	print_list(la, size - 1);
	fct_sa(la);	
	fct_sb(lb);	
	print_list(la, size - 1);
	free(lb);
	free(la);
	return (0);
}
