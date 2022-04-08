/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:50:13 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/08 11:18:18 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *alst, t_list *new)
{
	t_list	*tmp;

	tmp = alst;
	if (!alst)
	{
		if (alst == NULL)
			alst = new;
	}
	else
	{
		tmp = ft_lstlast(alst);
		tmp->next = new;
	}
}
