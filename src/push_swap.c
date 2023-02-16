/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:03:04 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/16 11:20:34 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* void	coisas(stack *a, stack *b, int argc, char **argv)
{
	char **s;

	if (argc == 2)
	{
		s = ft_split(argv[1]);
		while ()
	}
} */

int	main(int argc, char **argv)
{
	stack	a;
	stack	b;

	if (argc < 2)
	{
		return (0);
	}
	checkarguments(&a, &b, argv, argc);
	if (a.size <= 3)
		pushswap_3(&a);
	else if (a.size <= 5)
		pushswap_5(&a, &b);
	else if (a.size <= 100)
		pushswap_100(&a, &b, 5);
	else if (a.size >= 500)
		pushswap_500(&a, &b, 2);
	free (a.list);
	free (b.list);
	return (0);
}
