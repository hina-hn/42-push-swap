/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:50:02 by YourName          #+#    #+#             */
/*   Updated: 2025/02/05 20:27:05 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*parse_arguments(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]) || !is_valid_int(argv[i]))
		{
			wirte(2, "Error\n", 6);
			exit(1);
		}
		add_to_stack(&stack_a, ft_atoi(argv[i]));
		i++;
	}
	check_duplicate(stack_a);
	return (stack_a);
}

void	sort_stack(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = list_size(*stack_a);
	if (size = 2)
	{
		sa(stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_node *stack_a;
	t_node *stack_b;
	stack_a = NULL;
	stack_b = NULL;

	if (argc < 2)
		return (0);
	stack_a = parse_argument(argc, argv);
	if (!is_sorted(stack_a))
		sort_atack(&stack_a);
	free_stack(&stack_a);
	free_stack(&stack_b);

	return (0);
}