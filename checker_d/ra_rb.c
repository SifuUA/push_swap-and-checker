/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:34:21 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 20:34:50 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_d_linklst *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->head;
		list->head = tmp->next;
		tmp->prev = list->tail;
		tmp->next = NULL;
		list->tail->next = tmp;
		list->tail = tmp;
	}
}

void	rb(t_d_linklst *list)
{
	t_node	*tmp;

	if (list->size > 1)
	{
		tmp = list->head;
		list->head = tmp->next;
		tmp->prev = list->tail;
		tmp->next = NULL;
		list->tail->next = tmp;
		list->tail = tmp;
	}
}

void	rr(t_d_linklst *list_a, t_d_linklst *list_b)
{
	ra(list_a);
	rb(list_b);
}
