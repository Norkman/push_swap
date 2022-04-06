/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:45:48 by nle-bret          #+#    #+#             */
/*   Updated: 2022/03/11 12:22:56 by nle-bret         ###   ########.fr       */
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
	int j;
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

	////////////test////////////////
	j = i;
	i = 1;
	while (i < size)
	{
		nbr = ft_atoi(nbr_on_char[j - 1]);
		printf("%d\n", lb[i - 1]);
		lb[i - 1] = nbr;
		i++;
		j--;
	}
	
	print_list(la, size - 1);
	print_list(lb, size - 1);
	fct_ss(la,lb);
	print_list(la, size - 1);
	print_list(lb, size - 1);
	/////////////test/////////////////
	
	free(lb);
	free(la);
	return (0);
}
