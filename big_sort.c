/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 00:34:14 by mrobaii           #+#    #+#             */
/*   Updated: 2022/05/25 00:35:47 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	find_max(t_node **stack_a, t_node **stack_b)
{
	int	max;
	int	index;
	int	app;
	int	size;

	size = ft_lstsize(*stack_b);
	while (size)
	{
		max = get_max(*stack_b);
		app = ft_lstsize(*stack_b) / 2;
		index = get_index(*stack_b, max);
		while ((*stack_b)->num != max)
		{
			if (app >= index)
				rb(stack_b);
			else
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		size = ft_lstsize(*stack_b);
	}
}

void	ft_sort_big(t_node **stack_a, t_node **stack_b)
{
	int	key_nbr;
	int	start;
	int	end;
	int	i;

	start = ft_lstsize(*stack_a) / 2 - 18;
	end = ft_lstsize(*stack_a) / 2 + 18;
	while (ft_lstsize(*stack_a))
	{
		i = 36;
		while (i--)
		{
			chunks_approximity(stack_a, start, end);
			pb(stack_a, stack_b);
			if (*stack_b && (*stack_b)->num < ft_lstsize(*stack_b) / 2)
				rb(stack_b);
		}
		start -= 18;
		end += 18;
	}
	find_max(stack_a, stack_b);
}
