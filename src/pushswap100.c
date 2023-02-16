/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:33:12 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/16 16:54:01 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pushswap_100(t_stack *a, t_stack *b, int part)
{
	pushswap_100logic(a, b, part);
	ft_finish(b, a);
}

void	pushswap_100logic(t_stack *a, t_stack *b, int part)
{
	t_func_var	var;

	var.ntil = 1;
	var.lst.list = ascending_list(a->list, a->size);
	var.lst.size = a->size;
	var.total = a->size;
	var.step = var.total / part;
	var.sent = 0;
	if (is_sorted(a))
		return ;
	while (var.sent < var.total)
	{
		var.val = ft_median(var.lst.list, var.lst.size, var.ntil, part);
		while (var.sent < ((var.total / part) * var.ntil))
		{
			index_in_chunk(a, var.val);
			ft_push(a, b);
			var.sent++;
			betterb(b, var.val, var.step);
		}
		var.ntil++;
	}
	free (var.lst.list);
}

/* void	pushswap_100(t_stack *a, t_stack *b, int part)
{
	int	sent;
	int	total;
	int	val;
	int	ntil;
	int	step;
	t_stack lst;

	ntil = 1;
	lst.list_num = ascending_list(a->list_num, a->size);
	lst.size = a->size;
	total = a->size;
	step = total / part;
	sent = 0;
	if (is_sorted(a))
		return ;
	while (sent < total)
	{
		val = ft_median(lst.list_num, lst.size, ntil, part);
		//ft_printf("POS: %d, Valor: %d\n", (((lst.size - 1) * ntil) / part), val);
		while (sent < ((total / part) * ntil))
		{
			indexinchunk(a, val);
			ft_push(a, b);
			sent++;
			betterb(b, val, step);
		}
		ntil++;
	}
	free (lst.list_num);
} */
