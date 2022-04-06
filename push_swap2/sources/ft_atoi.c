/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:24:12 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/01 07:52:58 by nle-bret         ###   ########.fr       */
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

static int	ft_convert(char *str, int i, int num)
{
	while (i < ft_strlen(str) && ft_isdigit(str[i]))
	{
		num = 10 * num + (str[i] - 48);
		i++;
	}
	return (num);
}

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		i;
	int		num;
	int		sign;

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
