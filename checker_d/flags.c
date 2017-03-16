/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:31:22 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 20:52:43 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	flag_v(t_d_linklst *a, t_d_linklst *b)
{
	ft_putstr(YELLOW"STACK A: ");
	printlist(a);
	ft_putstr(RESET);
	ft_putstr(BLUE"STACK B: "BLUE);
	printlist(b);
	ft_putstr(RESET);
	if (a->prec_t > 0 && a->flag_t == 1)
		sleep(a->prec_t);
}

void	printlist(t_d_linklst *list)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		ft_putnbr(tmp->value);
		write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
