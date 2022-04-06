/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <nle-bret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:42:09 by nle-bret          #+#    #+#             */
/*   Updated: 2022/04/05 16:38:34 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "sources/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

t_list	**ft_make_list(int len_list, char **nbr_char);
void	lst_printf(t_list **list);
//int		ft_printf(const char *format, ...);
int		push_swap(int argc, char **argv);
int		ft_atoi(const char *nptr);
void	fct_sa(int *la);
void	fct_sb(int *lb);
void	fct_ss(int *la, int *lb);
void	fct_pa(int *la, int *lb);
void	fct_pb(int *la, int *lb);

#endif
