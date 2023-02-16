/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:39:37 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/16 16:40:48 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

// Stack structure
typedef struct pushswap
{
	long		*list;
	int			size;
	char		c;
}	stack;

//
typedef struct pushplus
{
	long	val;
	int		sent;
	int		total;
	int		ntil;
	int		step;
	stack 	lst;
}	func_var;

// check_args.c
void	checkarguments(stack *a, stack *b, char **argv, int argc);
void	check_int_limits(stack *a);
void	check_reps(stack *a);
void	check_invalid_single_argv(char *str);
void	check_invalid_mult_argv(int argc, char **argv);
// ft_split.c
char	**ft_split(char *str);
int		word_counter(char *str);
void	free_split(char **str);
// list_utils.c
int		min_index(long *list, int size);
int		max_index(long *list, int size);
long	ft_median(long *list, int size, int ntil, int part);
long	*ascending_list(long *lst, int size);
// moves.c
void	ft_remove_first_elem(stack *s);
void	ft_swap(stack *s);
void	ft_shiftup(stack *s);
void	ft_shiftdown(stack *s);
void	ft_push(stack *from, stack *to);
// multiples_args.c
void	init_b(stack *b);
void	multiples_argv(stack *a, stack *b, int argc, char **argv);
// pushswap3.c
void	pushswap_3(stack *s);
// pushswap5.c
void	pushswap_5(stack *a, stack *b);
void	push5_utils(stack *a, stack *b);
// pushswap100.c
void	pushswap_100(stack *a, stack *b, int part);
void	pushswap_100logic(stack *a, stack *b, int part);
// pushswap500.c
void	pushswap_500(stack *a, stack *b, int part);
void	index_in_chunk2(stack *s, long val);
void	pushswap_500logic(stack *b, stack *a, int part);
// single_argv.c
void	single_argv(stack *a, stack *b, char *str);
void	init_a_sigle_argv(stack *a, char *str);
void	str_null(char *str);
// sort_stack.c
void	minontop(stack *s);
void	maxontop(stack *s);
void	index_in_chunk(stack *s, int val);
void	do_best_rotate(stack *s, int posi, int posj, int center);
void	best_rotate(stack *s, int i, int j);
// sort_stack2.c
void	betterb(stack *s, long val, int step);
void	bettera(stack *s, long val, int step);
void	ft_finish(stack *from, stack *to);
int		is_sorted(stack *s);
// str_to_number.c
int		is_number(char xar);
int		is_positive_negative(char xar);
int		ft_atoi(char *str);
long	ft_atol(char *str);
// utils.c
int		ft_abs(int x, int y);
int		ft_avarege(int *list, int size);
void	print_stacks(stack a, stack b);
int		ft_strcmp(char *s1, char *s2);

#endif
