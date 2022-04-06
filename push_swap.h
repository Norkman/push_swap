/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:42:09 by nle-bret          #+#    #+#             */
/*   Updated: 2022/03/11 12:07:35 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "sources/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
int		ft_printf(const char *format, ...);
int		push_swap(int size, char **nbr_on_char);
int		ft_atoi(const char *nptr);
void	fct_sa(int *la);
void	fct_sb(int *lb);
void	fct_ss(int *la, int *lb);
void	fct_pa(int *la, int *lb);
void	fct_pb(int *la, int *lb);

#endif
