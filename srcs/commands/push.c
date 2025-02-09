/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:50:07 by YourName          #+#    #+#             */
/*   Updated: 2025/02/09 15:36:22 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //////////////////////////////////////

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*top_b;

	if (!*stack_b)
		return ;
	top_b = *stack_b;
	*stack_b = top_b->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	top_b->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = top_b;
	*stack_a = top_b;
	write(1, "pa\n", 3);
	print_stack(*stack_a, 'A');
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*top_a;

	if (!*stack_a)
		return ;
	top_a = *stack_a;
	*stack_a = top_a->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	top_a->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = top_a;
	*stack_b = top_a;
	write(1, "pb\n", 3);
	print_stack(*stack_b, 'B'); /////////////////////////////
}
