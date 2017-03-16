/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:34:56 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 20:35:19 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_d_linklst *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->tail;
		list->tail = list->tail->prev;
		if (list->size > 1)
			list->tail->next = NULL;
		tmp->next = list->head;
		tmp->prev = NULL;
		list->head->prev = tmp;
		list->head = tmp;
	}
}

void	rrb(t_d_linklst *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->tail;
		list->tail = list->tail->prev;
		if (list->size > 1)
			list->tail->next = NULL;
		tmp->next = list->head;
		tmp->prev = NULL;
		list->head->prev = tmp;
		list->head = tmp;
	}
}

void	rrr(t_d_linklst *list_a, t_d_linklst *list_b)
{
	rra(list_a);
	rrb(list_b);
}
