/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:11:42 by nle-bret          #+#    #+#             */
/*   Updated: 2022/05/12 10:23:08 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c)
{
	char	c_tmp;

	c_tmp = (char)c;
	if (c_tmp == '\t' || c_tmp == '\n' || c_tmp == '\r'
		|| c_tmp == '\v' || c_tmp == '\f' || c_tmp == ' ')
		return (1);
	return (0);
}

static int	ft_convert(char *str, int i, long int num)
{
	while (i < ft_strlen(str) && ft_isdigit(str[i]))
	{
		num = 10 * num + (str[i] - 48);
		i++;
	}
	return (num);
}

long int	ft_atoli(const char *nptr)
{
	char		*str;
	int			i;
	long int	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	str = (char *)nptr;
	while (ft_isspace(str[i]))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		num = ft_convert(str, i + 1, num);
	}
	num = ft_convert(str, i, num);
	return (sign * num);
}
