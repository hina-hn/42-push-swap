/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:50:02 by YourName          #+#    #+#             */
/*   Updated: 2025/02/09 15:39:21 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// t_node	*parse_arguments(int argc, char **argv)
// {
// 	t_node	*stack_a;
// 	int		i;

// 	stack_a = NULL;
// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (!is_number(argv[i]) || !is_valid_int(argv[i]))
// 		{
// 			wirte(2, "Error\n", 6);
// 			exit(1);
// 		}
// 		add_to_stack(&stack_a, ft_atoi(argv[i]));
// 		i++;
// 	}
// 	check_duplicate(stack_a);
// 	return (stack_a);
// }

// void	sort_stack(t_node **stack_a, t_node **stack_b)
// {
// 	int	size;

// 	size = list_size(*stack_a);
// 	if (size = 2)
// 	{
// 		sa(stack_a);
// 	}
// 	else if (size == 3)
// 		sort_three(stack_a);
// 	else if (size <= 5)
// 		sort_five(stack_a, stack_b);
// 	else
// 		radix_sort(stack_a, stack_b);
// }

// int	main(int argc, char **argv)
// {
// 	t_node *stack_a;
// 	t_node *stack_b;
// 	stack_a = NULL;
// 	stack_b = NULL;

// 	if (argc < 2)
// 		return (0);
// 	stack_a = parse_argument(argc, argv);
// 	if (!is_sorted(stack_a))
// 		sort_atack(&stack_a);
// 	free_stack(&stack_a);
// 	free_stack(&stack_b);

// 	return (0);
// }

#include "push_swap.h"
#include <stdio.h>

/**
 * @brief スタックの状態を表示する関数
 */
void	print_stack(t_node *stack, char stack_name)
{
	printf("Stack %c: ", stack_name);
	if (!stack)
	{
		printf("(empty)\n");
		return ;
	}
	while (stack)
	{
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

/**
 * @brief スタックに要素を追加する関数
 */
void	add_to_stack(t_node **stack, int value)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!new)
		exit(1);
	new->data = value;
	new->next = NULL;
	new->prev = NULL;
	if (!(*stack))
	{
		*stack = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

/**
 * @brief スタックを解放する関数
 */
void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	test_sort_three(int a, int b, int c)
{
	t_node	*stack_a;

	stack_a = NULL;
	add_to_stack(&stack_a, a);
	add_to_stack(&stack_a, b);
	add_to_stack(&stack_a, c);
	printf("Before sort_three:\n");
	print_stack(stack_a, 'A');
	sort_three(&stack_a);
	printf("After sort_three:\n");
	print_stack(stack_a, 'A');
	free_stack(&stack_a);
}

void	sort_numbers(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 1)
	{
	}
	else if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 6)
		sort_six_or_less(stack_a, stack_b, size);
	else
	{
		sort_large(stack_a, stack_b, size);
	}
}
/**
 * @brief コマンドライン引数を解析し、スタックを作成
 */
t_node	*parse_arguments(int argc, char **argv)
{
	t_node	*stack_a;
	int		i;
	int		value;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		add_to_stack(&stack_a, value);
		i++;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Usage: ./push_swap <numbers>\n");
		return (1);
	}

	t_node *stack_a = parse_arguments(argc, argv);
	t_node *stack_b = NULL;
	printf("Before sorting:\n");
	print_stack(stack_a, 'A');

	sort_numbers(&stack_a, &stack_b, argc - 1);

	printf("After sorting:\n");
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B'); ///
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}