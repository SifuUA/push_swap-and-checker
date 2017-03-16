/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:31:45 by okres             #+#    #+#             */
/*   Updated: 2017/03/16 14:50:53 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	find_same(long int num, t_d_linklst *list)
{
	t_node	*tmp;

	tmp = list->head;
	while (tmp)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	write_in_list(t_d_linklst *list, char **s, int i)
{
	long int	tmp;

	while (s[i])
	{
		tmp = ft_atoi(s[i]);
		if (ft_strcmp(ft_itoa((int)tmp), s[i]) == 0 &&
				find_same(tmp, list) == 0)
			push_front(list, tmp);
		else
		{
			ft_putstr(RED"Error"RESET);
			exit(WRONG_ARG);
		}
		i++;
	}
}

int			find_flags(char **s, t_d_linklst *a)
{
	int		i;

	i = 1;
	while (s[i])
	{
		if (s[i][0] == '-' && s[i][1] == 'v')
			a->flag_v = 1;
		else if (s[i][0] == '-' && s[i][1] == 'z')
			a->flag_z = 1;
		else if (s[i][0] == '-' && s[i][1] == 's')
			a->flag_s = 1;
		else if (s[i][0] == '-' && s[i][1] == 't')
		{
			a->flag_t = 1;
			s[i][0] = ' ';
			s[i][1] = ' ';
			a->prec_t = ft_atoi(s[i]);
		}
		else
			break ;
		i++;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	int				i;
	t_d_linklst		*list_a;
	t_d_linklst		*list_b;

	list_a = creat();
	list_b = creat();
	if (argc > 1)
	{
		i = find_flags(argv, list_a);
		write_in_list(list_a, argv, i);
		read_op(list_a, list_b);
	}
	del_list(list_a);
	return (0);
}
