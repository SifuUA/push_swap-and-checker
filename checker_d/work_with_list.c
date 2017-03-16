/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:35:52 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 20:40:15 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_d_linklst		*creat(void)
{
	t_d_linklst *tmp;

	tmp = (t_d_linklst *)malloc(sizeof(t_d_linklst));
	tmp->size = 0;
	tmp->head = NULL;
	tmp->tail = NULL;
	tmp->count = 0;
	tmp->prec_t = 0;
	tmp->flag_z = 0;
	tmp->flag_s = 0;
	tmp->flag_v = 0;
	return (tmp);
}

void			push_front(t_d_linklst *list, long int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		exit(OUT_OF_MEM);
	node->value = value;
	node->next = NULL;
	node->prev = list->tail;
	if (list->tail)
		list->tail->next = node;
	list->tail = node;
	if (list->head == NULL)
		list->head = node;
	list->size++;
}

void			p_h(t_d_linklst *list1, t_d_linklst *list2, t_node *tmp)
{
	if (list1->tail == NULL)
		list1->tail = tmp;
	list2->size--;
	list1->size++;
	if (list2->size == 0)
	{
		list2->head = NULL;
		list2->tail = NULL;
	}
}

void			push_head(t_d_linklst *list1, t_d_linklst *list2)
{
	t_node	*tmp;

	tmp = list2->head;
	if (list2->size > 1)
	{
		list2->head->next->prev = NULL;
		list2->head = list2->head->next;
	}
	tmp->prev = NULL;
	tmp->next = NULL;
	if (list1->head == NULL)
		list1->head = tmp;
	else
	{
		list1->head->prev = tmp;
		tmp->next = list1->head;
		tmp->prev = NULL;
		list1->head = tmp;
	}
	p_h(list1, list2, tmp);
}

void			del_list(t_d_linklst *list)
{
	t_node	*tmp;

	while (list->head)
	{
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
}
