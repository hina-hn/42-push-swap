/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:18:17 by YourName          #+#    #+#             */
/*   Updated: 2025/02/06 17:56:00 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_b = second;
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a) && (*stack_a)->next)
		sa(stack_a);
	if ((*stack_b) && (*stack_b)->next)
		sb(stack_b);
	write(1, "ss\n", 3);
}
