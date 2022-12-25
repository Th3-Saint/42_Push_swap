/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucifer <lucifer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 20:36:05 by mrobaii           #+#    #+#             */
/*   Updated: 2022/12/25 17:21:15 by lucifer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Push_Swap.h"
#include "../includes/get_next_line.h"

void	use_actions(char *str, t_node **stack_a, t_node **stack_b)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(stack_a, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		sa(stack_b, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(stack_a, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		ra(stack_b, 0);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(stack_a, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else
	{
		write(1, "ERROR\n", 6);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	char	*str;
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	stack_b = NULL;
	if (ac < 2)
		exit(0);
	stack_a = ft_lstadd(ft_atoi(av[1]));
	ft_put_stack(av, stack_a, ac);
	check_double(stack_a);
	str = get_next_line(0);
	while (str)
	{
		use_actions(str, &stack_a, &stack_b);
		str = get_next_line(0);
	}
	if (check_sorted(stack_a) && !ft_lstsize(stack_b))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}
