/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomvan- <thomvan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:30:58 by marvin            #+#    #+#             */
/*   Updated: 2024/07/01 17:28:58 by thomvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_S_H
# define PUSH_S_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"

typedef struct s_stack
{
	int		top;
	int		bot;
	int		*stack;
	int		size;
	int		count;
	char	name;
	int		max;
	int		min;
	int		max_add;
	int		min_add;
}	t_stack;

typedef struct s_moves
{
	int		aadd;
	int		badd;
}	t_moves;

int			is_repeating(char **argm, int count);
int			is_num(char **argm);
t_stack		*stack_init(int count, char nam);
void		astack_filler(t_stack *A, char **argm, int cntr);
int			is_empty(t_stack *st);
int			swap(t_stack *stk);
int			push(t_stack *src, t_stack *dst);
void		rotate(t_stack *st, int print);
void		r_rotate(t_stack *st, int print);
void		easy_sort(t_stack *s);
int			d_rotate(t_stack *st1, t_stack *st2);
int			d_r_rotate(t_stack *st1, t_stack *st2);
void		min_max(t_stack *st);
int			absolute(int num);
void		push_swap(t_stack *a, t_stack *b);
int			next_up(t_stack *s, int add);
int			n_d(t_stack *s, int add);
void		ranker(int *list, t_stack *a, int size);
int			rtt(int addrs, t_stack *stak);
void		rotator(t_stack *stc, int amount);
void		stack_display(t_stack *s);
int			m_plus(int min_m, int b_adrs, t_stack *b);
int			clo_val_down(t_stack *a, t_stack *b, int a_add);
int			clo_val_up(t_stack *a, t_stack *b, int a_add);
t_moves		f_find_cheap(t_stack *a, t_stack *b);
t_moves		b_find_cheap(t_stack *a, t_stack *b);
void		true_display(t_stack *s);
void		doubler(t_stack *a, t_stack *b, int am1, int am2);
void		pusher(t_stack *a, t_stack *b);
void		b_pusher(t_stack *a, t_stack *b);
long int	big_atoi(const char *str);
int			is_too_much(char **arv);
int			calc(int am1, int am2);
int			is_in_order(t_stack *s);
int			dtab_len(char **set);

#endif