/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fct_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:18:27 by nle-bret          #+#    #+#             */
/*   Updated: 2022/03/09 16:21:58 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fct_sa(int *la)
{
	int	tmp;
	
	if (la[0])
	{
		tmp = la[0];
		la[0] = la[1];
		la[1] = tmp;
		ft_printf("sa\n");
	}

	else
		return ;
}

void	fct_sb(int *lb)
{
	int	tmp;

	if (lb[0])
	{
		tmp = lb[0];
		lb[0] = lb[1];
		lb[1] = tmp;
		ft_printf("sb\n");
	}
	else
		return ;

}

void	fct_ss(int *la, int *lb)
{
	fct_sb(lb);
	fct_sa(la);
}
