/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:58:29 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/16 14:42:12 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_int_limits(stack *a)
{
	int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->list[i] < INT_MIN || a->list[i] > INT_MAX)
		{
			write (2, "Error\n", 6);
			free (a->list);
			exit (0);
		}
		i++;
	}
}

void	check_reps(stack *a)
{
	long	*list;
	int		i;

	i = 0;
	list = ascending_list(a->list, a->size);
	while (i < (a->size - 1))
	{
		if (list[i] == list[i + 1])
		{
			write (2, "Error\n", 6);
			free (a->list);
			free (list);
			exit (0);
		}
		i++;
	}
	free (list);
}

void	check_invalid_single_argv(char *str)
{
	char	**check;
	int		s;
	int		i;

	s = 0;
	check = ft_split(str);
	while (check[s])
	{
		i = 0;
		if (is_positive_negative(check[s][i]))
			i++;
		while (check[s][i])
		{
			if (!is_number(check[s][i]))
			{
				write (2, "Error\n", 6);
				free_split(check);
				exit (0);
			}
			i++;
		}
		s++;
	}
	free_split(check);
}

void	check_invalid_mult_argv(int argc, char **argv)
{
	int	s;
	int	i;

	s = 1;
	while (s < argc)
	{
		i = 0;
		if (is_positive_negative(argv[s][i]))
			i++;
		while (argv[s][i])
		{
			if (!is_number(argv[s][i]))
			{
				write (2, "Error\n", 6);
				exit (0);
			}
			i++;
		}
		s++;
	}
}

void	checkarguments(stack *a, stack *b, char **argv, int argc)
{
	if (argc == 2)
	{
		check_invalid_single_argv(argv[1]);
		single_argv(a, b, argv[1]);
	}
	else
	{
		check_invalid_mult_argv(argc, argv);
		multiples_argv(a, b, argc, argv);
	}
	check_int_limits(a);
	check_reps(a);
}
