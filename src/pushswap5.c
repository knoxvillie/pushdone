/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:03:44 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/16 17:02:42 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push5_utils(t_stack *a, t_stack *b)
{
	pushswap_3(a);
	ft_push(b, a);
	if (is_sorted(a))
	{
		ft_push(b, a);
		if (a->size > 4)
			ft_shiftup(a);
	}
	else
	{
		ft_shiftup(a);
		ft_push(b, a);
	}
}

void	pushswap_5(t_stack *a, t_stack *b)
{
	long	imin;
	long	imax;

	imin = min_index(a->list, a->size);
	imax = max_index(a->list, a->size);
	if (is_sorted(a))
		return ;
	while (a->size > 3)
	{
		if (imin == 0 || imax == 0)
			ft_push(a, b);
		else
			ft_shiftup(a);
		imin = min_index(a->list, a->size);
		imax = max_index(a->list, a->size);
	}
	push5_utils (a, b);
}

/* void	pushswap_5(t_stack *a, t_stack *b)
{
	int	imin;
	int	imax;

	imin = min_index(a->list_num, a->size);
	imax = max_index(a->list_num, a->size);
	while (a->size > 3)
	{
		if (imin == 0 || imax == 0)
			ft_push(a, b);
		else
			ft_shiftup(a);
		imin = min_index(a->list_num, a->size);
		imax = max_index(a->list_num, a->size);
	}
	pushswap_3(a);
	ft_push(b, a);
	if (is_sorted(a))
	{
		ft_push(b, a);
		if (a->size > 4)
			ft_shiftup(a);
	}
	else
	{
		ft_shiftup(a);
		ft_push(b, a);
	}
}
 */
