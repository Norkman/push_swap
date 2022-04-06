/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:50:38 by nle-bret          #+#    #+#             */
/*   Updated: 2022/01/07 15:53:07 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkbase(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base [j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_in_base(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	compt;
	int	signe;
	int	i;

	signe = 1;
	i = 0;
	compt = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while (is_in_base(str[i], base) != -1)
	{
		compt = compt * ft_strlen(base) + is_in_base(str[i], base);
		i++;
	}
	return (compt * signe);
}
