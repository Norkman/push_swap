/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
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

char	*ft_utoa(int n)
{
	char		*str;
	int			len;
	long int	nbr;

	nbr = n;
	if (n >= 0)
	{
		len = ft_lennum(nbr);
		str = malloc(sizeof(*str) * (len + 1));
		if (!str)
			return (NULL);
		ft_conststr(str, n, len);
		str[len] = '\0';
	}
	else
	{
		nbr = nbr + 4294967296;
		len = ft_lennum(nbr);
		str = malloc(sizeof(*str) * (len + 1));
		if (!str)
			return (NULL);
		ft_conststr(str, nbr, len);
		str[len] = '\0';
	}
	return (str);
}
