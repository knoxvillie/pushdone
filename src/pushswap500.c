/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:38:31 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/16 16:54:01 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pushswap_500(t_stack *a, t_stack *b, int part)
{
	pushswap_100logic(a, b, part);
	pushswap_500logic(b, a, (5 * part));
	pushswap_100logic(a, b, (25 * part));
	ft_finish(b, a);
}

void	index_in_chunk2(t_stack *s, long val)
{
	int	i;
	int	j;

	i = 0;
	j = (s->size - 1);
	while ((i + 1) < s->size)
	{
		if (s->list[i] >= val)
			break ;
		i++;
	}
	while (j > (i + 1))
	{
		if (s->list[j] >= val)
			break ;
		j--;
	}
	best_rotate(s, i, j);
}

void	pushswap_500logic(t_stack *b, t_stack *a, int part)
{
	t_func_var	var;

	var.ntil = part - 1;
	var.lst.list = ascending_list(b->list, b->size);
	var.lst.size = b->size;
	var.total = b->size;
	var.step = var.total / part;
	var.sent = 0;
	if (is_sorted(b))
		return ;
	while (var.sent < var.total)
	{
		var.val = ft_median(var.lst.list, var.lst.size, var.ntil, part);
		while (var.sent <= (var.total - ((var.total / part) * var.ntil)))
		{
			index_in_chunk2(b, var.val);
			ft_push(b, a);
			var.sent++;
			bettera(a, var.val, var.step);
		}
		var.ntil--;
	}
	free (var.lst.list);
}

/* void	pushswap_500(t_stack *b, t_stack *a, int part)
{
	int	sent;
	int	total;
	int	val;
	int	ntil;
	int	step;
	t_stack lst;

	ntil = part - 1;
	lst.list_num = ascending_list(b->list_num, b->size);
	lst.size = b->size;
	total = b->size;
	step = total / part;

	sent = 0;
	if (is_sorted(b))
		return ;
	while (sent < total)
	{
		val = ft_median(lst.list_num, lst.size, ntil, part);
		//ft_printf("POS: %d, Valor: %d\n", (((lst.size - 1) * ntil) / part), val);
		while (sent <= (total - ((total / part) * ntil)))
		{
			indexinchunk2(b, val);
			ft_push(b, a);
			sent++;
			bettera(a, val, step);
		}
		ntil--;
	}
	free (lst.list_num);
} */
