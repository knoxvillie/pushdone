/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfaustin <kfaustin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:59:54 by kfaustin          #+#    #+#             */
/*   Updated: 2023/02/20 11:34:41 by kfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_number(char xar)
{
	if (xar >= '0' && xar <= '9')
		return (1);
	return (0);
}

int	is_positive_negative(char xar)
{
	if (xar == '-' || xar == '+')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	number;
	int	sign;
	int	i;

	i = 0;
	number = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && is_number(str[i]))
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}

long	ft_atol(char *str)
{
	long	number;
	int		sign;
	int		i;

	i = 0;
	number = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && is_number(str[i]))
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}
