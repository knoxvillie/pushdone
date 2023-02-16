/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:58:41 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/16 16:58:43 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	minontop(t_stack *s)
{
	int	imin;

	if (s->size < 2)
		return ;
	imin = min_index(s->list, s->size);
	while (imin != 0)
	{
		if (imin <= (s->size / 2))
			ft_shiftup(s);
		else
			ft_shiftdown(s);
		imin = min_index(s->list, s->size);
	}
}

void	maxontop(t_stack *s)
{
	int	imax;

	if (s->size < 2)
		return ;
	imax = max_index(s->list, s->size);
	while (imax != 0)
	{
		if (imax <= (s->size / 2))
			ft_shiftup(s);
		else
			ft_shiftdown(s);
		imax = max_index(s->list, s->size);
	}
}

void	index_in_chunk(t_stack *s, int val)
{
	int	i;
	int	j;

	i = 0;
	j = (s->size - 1);
	while ((i + 1) < s->size)
	{
		if (s->list[i] <= val)
			break ;
		i++;
	}
	while (j > (i + 1))
	{
		if (s->list[j] <= val)
			break ;
		j--;
	}
	best_rotate(s, i, j);
}

void	do_best_rotate(t_stack *s, int posi, int posj, int center)
{
	if (ft_abs(posi, center) >= ft_abs(posj, center))
	{
		while (posi > 0)
		{
			ft_shiftup(s);
			posi--;
		}
	}
	else
	{
		if (posj == (posi + 1))
			ft_shiftdown(s);
		while ((posj + 1) <= s->size)
		{
			ft_shiftdown(s);
			posj++;
		}
	}
}

void	best_rotate(t_stack *s, int i, int j)
{
	int	center;

	if (s->size < 3)
		return ;
	center = (s->size / 2);
	if (i == (s->size - 1))
	{
		ft_shiftdown(s);
		i = 0;
	}
	do_best_rotate (s, i, j, center);
}

/* void	bestrotate(t_stack *s, int i, int j)
{
	int	center;

	if (s->size < 3)
		return ;
	center = s->size / 2;
	if (i == s->size - 1)
	{
		ft_shiftdown(s);
		i = 0;
	}
	if (ft_abs(i, center) >= ft_abs(j, center))
	{
		while (i > 0)
		{
			ft_shiftup(s);
			i--;
		}
	}
	else
	{
		if (j == i + 1)
			ft_shiftdown(s);
		while (j + 1 <= s->size)
		{
			ft_shiftdown(s);
			j++;
		}
	}
} */
