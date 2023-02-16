/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:58:19 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/16 16:58:22 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	betterb(t_stack *s, long val, int step)
{
	int	i;

	i = 0;
	if (s->size < 2)
		return ;
	if (s->list[i] < ((val + (val - step)) / 2))
		ft_shiftup(s);
}

void	bettera(t_stack *s, long val, int step)
{
	int	i;

	i = 0;
	if (s->size < 2)
		return ;
	if (s->list[i] < (val + (step / 2)))
		ft_shiftup(s);
}

void	ft_finish(t_stack *from, t_stack *to)
{
	while (from->size > 0)
	{
		maxontop(from);
		ft_push(from, to);
	}
}

int	is_sorted(t_stack *s)
{
	int	i;
	int	num;

	if (!s->size)
		return (1);
	i = 0;
	num = s->list[i];
	while (i < (s->size - 1))
	{
		if (num > s->list[i + 1])
			return (0);
		num = s->list[i + 1];
		i++;
	}
	return (1);
}
