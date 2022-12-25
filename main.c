/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobaii <mrobaii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:37:38 by mrobaii           #+#    #+#             */
/*   Updated: 2022/05/30 01:18:21 by mrobaii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*head;
	int		i;

	i = 2;
	stack_b = NULL;
	if (ac < 2)
		exit(0);
	head = ft_lstadd(ft_atoi(av[1]));
	stack_a = head;
	ft_put_stack(av, head, ac);
	if (check_sorted(stack_a))
		exit(0);
	check_double(stack_a);
	indexing(stack_a);
	if (ac <= 4)
		sort_three(&stack_a, ac, 1);
	else if (ac <= 11)
		sort_ten(&stack_a, &stack_b, 1);
	else
		ft_sort_big(&stack_a, &stack_b, 1);
}
