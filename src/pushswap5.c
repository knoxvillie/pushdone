/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:03:44 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/20 15:01:52 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push5_utils(t_stack *a, t_stack *b)
{
	pushswap_3(a);
	if (is_sorted(b))
	{
		ft_shiftup(b);
		ft_push(b, a);
		ft_shiftup(a);
		ft_push(b, a);
	}
	else
	{
		ft_push(b, a);
		ft_shiftup(a);
		ft_push(b, a);
	}
}

void	pushswap_5(t_stack *a, t_stack *b)
{
	long	vmin;
	long	vmax;
	long	*l;

	if (is_sorted(a))
		return ;
	l = a->list;
	vmin = l[min_index(a->list, a->size)];
	vmax = l[max_index(a->list, a->size)];
	while (a->size > 3)
	{
		if (l[0] == vmin || l[0] == vmax)
			ft_push(a, b);
		else
		{
			if ((l[1] == vmin || l[1] == vmax)
				|| (l[2] == vmin || l[2] == vmax))
				ft_shiftup(a);
			else
				ft_shiftdown(a);
			l = a->list;
		}
	}
	push5_utils (a, b);
}

void	pushswap_4(t_stack *a, t_stack *b)
{
	long	vmin;
	long	*l;

	if (is_sorted(a))
		return ;
	l = a->list;
	vmin = l[min_index(a->list, a->size)];
	while (a->size > 3)
	{
		l = a->list;
		if (l[0] == vmin)
			ft_push(a, b);
		else
		{
			if (l[1] == vmin)
				ft_shiftup(a);
			else
				ft_shiftdown(a);
		}
	}
	pushswap_3(a);
	ft_push(b, a);
}
