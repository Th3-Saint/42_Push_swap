/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 21:45:12 by mrobaii           #+#    #+#             */
/*   Updated: 2022/05/28 22:06:07 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	sort_two(t_node **stack, int ac, int n)
{
	t_node	*head;
	t_node	*sec;

	if (ac == 2)
		exit(0);
	head = *stack;
	sec = head->next;
	if (head->num > sec->num)
		sa(stack, n);
	exit(0);
}

void	sort_three(t_node **stack_a, int ac, int n)
{
	t_node	*head;
	t_node	*sec;

	head = *stack_a;
	sec = head->next;
	if (ac == 3 || ac == 2)
		sort_two(stack_a, ac, n);
	if (head->num > sec->num && head->num < sec->next->num)
		sa(stack_a, n);
	else if (head->num > sec->num && sec->num > sec->next->num)
	{
		sa(stack_a, n);
		rra(stack_a, n);
	}
	else if (head->num > sec->next->num && sec->next->num > sec->num)
		ra(stack_a, n);
	else if (head->num < sec->next->num && sec->next->num < sec->num)
	{
		sa(stack_a, n);
		ra(stack_a, n);
	}
	else if (sec->next->num < head->num && head->num < sec->num)
		rra(stack_a, n);
}

void	approximity(t_node **stack_a, int num, int n)
{
	int	index;
	int	app;

	index = get_index(*stack_a, num);
	app = ft_lstsize(*stack_a) / 2;
	while ((*stack_a)->num != num)
	{
		if ((*stack_a)->next->num == num)
			sa(stack_a, n);
		else
			if (app >= index)
				ra(stack_a, n);
		else
			rra(stack_a, n);
	}
}

void	chunks_approximity(t_node **stack_a, int start, int end, int n)
{
	int	index;
	int	app;

	index = chunks_index(*stack_a, start, end);
	app = ft_lstsize(*stack_a) / 2;
	while (*stack_a && ((*stack_a)->num > end || (*stack_a)->num < start))
	{
		if (app >= index)
			ra(stack_a, n);
		else
			rra(stack_a, n);
	}
}

void	sort_ten(t_node **stack_a, t_node **stack_b, int n)
{
	int	size;
	int	min;
	int	count;

	count = 0;
	size = ft_lstsize(*stack_a);
	while (size != 3)
	{
		min = get_min(*stack_a);
		approximity(stack_a, min, n);
		pb(stack_a, stack_b, n);
		size = ft_lstsize(*stack_a);
		count++;
	}
	sort_three(stack_a, min, n);
	while (count - 1)
	{
		pa(stack_a, stack_b, n);
		count--;
	}
	if (ft_lstsize(*stack_b) == 1)
		pa(stack_a, stack_b, n);
}
