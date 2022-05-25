/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:45:12 by mrobaii           #+#    #+#             */
/*   Updated: 2022/05/25 00:34:58 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	sort_two(t_node **stack, int ac)
{
	t_node	*head;
	t_node	*sec;

	if (ac == 2)
		exit(0);
	head = *stack;
	sec = head->next;
	if (head->num > sec->num)
		sa(stack);
	exit(0);
}

void	sort_three(t_node **stack_a, int ac)
{
	t_node	*head;
	t_node	*sec;

	head = *stack_a;
	sec = head->next;
	if (ac == 3 || ac == 2)
		sort_two(stack_a, ac);
	if (head->num > sec->num && head->num < sec->next->num)
		sa(stack_a);
	else if (head->num > sec->num && sec->num > sec->next->num)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->num > sec->next->num && sec->next->num > sec->num)
		ra(stack_a);
	else if (head->num < sec->next->num && sec->next->num < sec->num)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (sec->next->num < head->num && head->num < sec->num)
		rra(stack_a);
}

void	approximity(t_node **stack_a, int num)
{
	int	index;
	int	app;

	index = get_index(*stack_a, num);
	app = ft_lstsize(*stack_a) / 2;
	while ((*stack_a)->num != num)
	{
		if ((*stack_a)->next->num == num)
			sa(stack_a);
		else
			if (app >= index)
				ra(stack_a);
		else
			rra(stack_a);
	}
}

void	chunks_approximity(t_node **stack_a, int start, int end)
{
	int	index;
	int	app;

	index = chunks_index(*stack_a, start, end);
	app = ft_lstsize(*stack_a) / 2;
	while (*stack_a && ((*stack_a)->num > end || (*stack_a)->num < start))
	{
		if (app >= index)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_ten(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	min;
	int	count;

	count = 0;
	size = ft_lstsize(*stack_a);
	while (size != 3)
	{
		min = get_min(*stack_a);
		approximity(stack_a, min);
		pb(stack_a, stack_b);
		size = ft_lstsize(*stack_a);
		count++;
	}
	sort_three(stack_a, min);
	while (count - 1)
	{
		pa(stack_a, stack_b);
		count--;
	}
	if (ft_lstsize(*stack_b) == 1)
		pa(stack_a, stack_b);
}
