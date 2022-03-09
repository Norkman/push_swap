/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:27:19 by nle-bret          #+#    #+#             */
/*   Updated: 2022/01/07 16:02:11 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fct_x(va_list args)
{
	unsigned int	nbr;
	int				len_nbr;

	nbr = va_arg(args, unsigned int);
	len_nbr = ft_len_nbr(nbr, "0123456789abcdef");
	ft_putnbr_base(nbr, "0123456789abcdef");
	return (len_nbr);
}

int	fct_x_up(va_list args)
{
	long long int	nbr;
	int				len_nbr;

	nbr = va_arg(args, unsigned int);
	len_nbr = ft_len_nbr(nbr, "0123456789ABCDEF");
	ft_putnbr_base(nbr, "0123456789ABCDEF");
	return (len_nbr);
}

int	fct_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	fct_s(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	fct_p(va_list args)
{
	unsigned long long	int_v;
	long				len_nbr;

	int_v = va_arg(args, unsigned long long);
	if (int_v == -1)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd("ffffffffffffffff", 1);
		return (16 + 2);
	}
	if (int_v == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len_nbr = ft_len_nbr(int_v, "0123456789abcdef");
	ft_putstr_fd("0x", 1);
	ft_putnbr_base(int_v, "0123456789abcdef");
	return (len_nbr + 2);
}
