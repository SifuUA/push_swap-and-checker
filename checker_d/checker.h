/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 20:28:43 by okres             #+#    #+#             */
/*   Updated: 2017/03/15 20:29:29 by okres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define OUT_OF_MEM 1
# define WRONG_ARG 2
# define BUFF_S 10

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef struct		s_node
{
	long int		value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_d_linklst
{
	struct s_node	*head;
	struct s_node	*tail;
	size_t			size;
	int				count;
	size_t			elem_pos;
	int				flag_v;
	int				flag_s;
	int				flag_z;
	int				flag_t;
	int				prec_t;
}					t_d_linklst;

void				sa(t_d_linklst *list_a);
void				sb(t_d_linklst *list_a);
void				ss(t_d_linklst *list_a, t_d_linklst *list_b);
void				pa(t_d_linklst *list_a, t_d_linklst *list_b);
void				pb(t_d_linklst *list_a, t_d_linklst *list_b);
void				ra(t_d_linklst *list);
void				rb(t_d_linklst *list);
void				rr(t_d_linklst *list_a, t_d_linklst *list_b);
void				rra(t_d_linklst *list);
void				rrb(t_d_linklst *list);
void				rrr(t_d_linklst *list_a, t_d_linklst *list_b);
t_d_linklst			*creat(void);
void				printlist(t_d_linklst *list);
void				push_front(t_d_linklst *list, long int value);
void				push_head(t_d_linklst *list, t_d_linklst *list2);
void				del_list(t_d_linklst *list);
void				read_op(t_d_linklst *list_a, t_d_linklst *list_b);
void				flag_v(t_d_linklst *a, t_d_linklst *b);
#endif
