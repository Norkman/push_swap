/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:57:23 by nle-bret          #+#    #+#             */
/*   Updated: 2021/12/03 13:14:18 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_lennum(long int n)
{	
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		len++;
		n = (n / 10);
	}
	return (len);
}

static void	ft_conststr(char *str, long int n, int len)
{
	int	i;

	i = len;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i - 1] = 48 + n % 10;
		i--;
		n = n / 10;
	}
}

char	*ft_llutoa(unsigned long long num)
{
	char		*str;
	int			len;
	long int	n;

	n = num;
	len = ft_lennum(n);
	if (n >= 0)
	{
		str = malloc(sizeof(*str) * (len + 1));
		if (!str)
			return (NULL);
		ft_conststr(str, n, len);
		str[len] = '\0';
	}
	else
	{
		str = malloc(sizeof(*str) * (len + 2));
		if (!str)
			return (NULL);
		str[0] = '-';
		ft_conststr(str + 1, -n, len);
		str[len + 1] = '\0';
	}
	return (str);
}
