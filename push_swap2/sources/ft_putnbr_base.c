/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:29:08 by nle-bret          #+#    #+#             */
/*   Updated: 2021/08/12 11:18:40 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(int str)
{
	write(1, &str, 1);
}

int	len_of_base(char *base)
{
	long int	i;

	i = 0;
	while (base[i] != 0)
		i++;
	return (i);
}

int	ft_is_error(char *base)
{
	int	i;
	int	j;
	int	len;

	len = len_of_base(base);
	if (len <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == base [j])
			return (0);
		j++;
		i++;
	}
	return (1);
}

void	ft_putnbr_base(unsigned long long nb, char *base)
{
	int	num_in_base;

	num_in_base = 0;
	if (ft_is_error(base) == 1)
	{
		if (nb < (unsigned long long)len_of_base(base))
		{
			ft_putchar(base[nb]);
		}
		if (nb >= (unsigned long long)len_of_base(base))
		{
			ft_putnbr_base(nb / len_of_base(base), base);
			num_in_base = base[nb % len_of_base(base)];
			ft_putchar(num_in_base);
		}
	}
}
