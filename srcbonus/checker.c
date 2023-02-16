/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:48:26 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/16 16:53:13 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_sort_t_stacks(t_stack *a, t_stack *b)
{
	if (b->size)
	{
		ft_printf("KO\n");
		return ;
	}
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	invalid_output(t_stack *a, t_stack *b, char *str)
{
	free (a->list);
	free (b->list);
	free (str);
	write (2, "Error\n", 6);
	exit (0);
}

void	contruct_t_stack(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		ft_sx(a);
	else if (!ft_strcmp(str, "sb\n"))
		ft_sx(b);
	else if (!ft_strcmp(str, "ra\n"))
		ft_rx(a);
	else if (!ft_strcmp(str, "rb\n"))
		ft_rx(b);
	else if (!ft_strcmp(str, "rra\n"))
		ft_rrx(a);
	else if (!ft_strcmp(str, "rrb\n"))
		ft_rrx(b);
	else if (!ft_strcmp(str, "pa\n"))
		ft_px(b, a);
	else if (!ft_strcmp(str, "pb\n"))
		ft_px(a, b);
	else
		invalid_output(a, b, str);
}

void	get_output(t_stack *a, t_stack *b, int fd)
{
	char	*output;

	while (1)
	{
		output = get_next_line(fd);
		if (!output)
			break ;
		contruct_t_stack (a, b, output);
		free (output);
	}
	free (output);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc >= 2)
	{
		if (argc == 2)
		{
			str_null(argv[1]);
			check_invalid_single_argv(argv[1]);
			single_argv(&a, &b, argv[1]);
		}
		else
		{
			check_invalid_mult_argv(argc, argv);
			multiples_argv(&a, &b, argc, argv);
		}
		check_int_limits(&a);
		check_reps(&a);
		get_output(&a, &b, STDIN_FILENO);
		check_sort_t_stacks(&a, &b);
		free (a.list);
		free (b.list);
	}
	return (0);
}
