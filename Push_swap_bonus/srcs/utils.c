/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucifer <lucifer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:25:30 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/25 17:20:12 by lucifer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_Swap.h"

int	get_index(t_node *stack, int number)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (stack->num == number)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	get_min(t_node *stack_a)
{
	int	*tab;
	int	min;

	tab = sort_stack(stack_a);
	min = tab[0];
	free(tab);
	return (min);
}

int	get_max(t_node *stack_a)
{
	int	*tab;
	int	size;
	int	max;

	tab = sort_stack(stack_a);
	size = ft_lstsize(stack_a);
	max = tab[size - 1];
	free(tab);
	return (max);
}

int	ft_atoi(char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	check_degit(str + i);
	res = res * sign;
	if (res > INT_MAX || res < INT_MIN)
	{
		write (1, "ERROR int\n", 10);
		exit(0);
	}
	return (res);
}

int	chunks_index(t_node *stack, int start, int end)
{
	int	i;

	i = 1;
	while (stack)
	{
		if (stack->num >= start && stack->num <= end)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}
