/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:29:32 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 20:31:15 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_sort(t_d_linklst *list)
{
	t_node	*tmp;
	size_t	i;

	i = 0;
	tmp = list->head;
	while (tmp->next != NULL)
	{
		if (tmp->value < tmp->next->value)
			i++;
		tmp = tmp->next;
	}
	if (i == list->size - 1)
		return (1);
	return (0);
}

int		correct(char *op)
{
	if (ft_strcmp(op, "sa") != 0 && ft_strcmp(op, "sb") != 0 &&
			ft_strcmp(op, "ss") != 0 && ft_strcmp(op, "pa") != 0
			&& ft_strcmp(op, "pb") != 0 && ft_strcmp(op, "ra") != 0
			&& ft_strcmp(op, "rb") != 0 && ft_strcmp(op, "rr") != 0
			&& ft_strcmp(op, "rra") != 0 && ft_strcmp(op, "rrb") != 0
			&& ft_strcmp(op, "rrr") != 0)
		return (0);
	return (1);
}

void	do_op(t_d_linklst *list_a, t_d_linklst *list_b, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		sa(list_a);
	else if (ft_strcmp(op, "sb") == 0)
		sb(list_b);
	else if (ft_strcmp(op, "ss") == 0)
		ss(list_a, list_b);
	else if (ft_strcmp(op, "pa") == 0)
		pa(list_a, list_b);
	else if (ft_strcmp(op, "pb") == 0)
		pb(list_a, list_b);
	else if (ft_strcmp(op, "ra") == 0)
		ra(list_a);
	else if (ft_strcmp(op, "rb") == 0)
		rb(list_b);
	else if (ft_strcmp(op, "rr") == 0)
		rr(list_a, list_b);
	else if (ft_strcmp(op, "rra") == 0)
		rra(list_a);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(list_b);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(list_a, list_b);
	if (list_a->flag_v == 1)
		flag_v(list_a, list_b);
	list_a->count++;
}

void	show_res(t_d_linklst *list_a, t_d_linklst *list_b)
{
	if (is_sort(list_a) && list_b->size == 0)
	{
		ft_putstr(GREEN"OK"RESET);
		write(1, "\n", 1);
		if (list_a->flag_z == 1)
		{
			ft_putstr(BLUE);
			ft_putnbr(list_a->count);
			ft_putstr(RESET);
			write(1, "\n", 1);
		}
		if (list_a->flag_s == 1)
		{
			printlist(list_a);
			write(1, "\n", 1);
		}
	}
	else
	{
		ft_putstr(RED"KO"RESET);
		write(1, "\n", 1);
	}
}

void	read_op(t_d_linklst *list_a, t_d_linklst *list_b)
{
	char	*op;

	op = ft_strnew(BUFF_S);
	while (get_next_line(0, &op))
	{
		if (correct(op))
			do_op(list_a, list_b, op);
		else
		{
			ft_putstr(RED"Error"RESET);
			exit(WRONG_ARG);
		}
	}
	show_res(list_a, list_b);
}
