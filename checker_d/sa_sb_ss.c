/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:35:25 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 20:35:47 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_d_linklst *list_a)
{
	long int tmp;

	if (list_a->size > 1)
	{
		tmp = list_a->head->value;
		list_a->head->value = list_a->head->next->value;
		list_a->head->next->value = tmp;
	}
}

void	sb(t_d_linklst *list_b)
{
	long int tmp;

	if (list_b->size > 1)
	{
		tmp = list_b->head->value;
		list_b->head->value = list_b->head->next->value;
		list_b->head->next->value = tmp;
	}
}

void	ss(t_d_linklst *list_a, t_d_linklst *list_b)
{
	sa(list_a);
	sb(list_b);
}
