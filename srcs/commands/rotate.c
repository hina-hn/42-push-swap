/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:22:59 by YourName          #+#    #+#             */
/*   Updated: 2025/02/06 17:56:03 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	t_node	*first;
	t_node	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	*stack_a = first->next;
	(*stack_a)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "ra\n", 3);
}
void	rb(t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	*stack_b = first->next;
	(*stack_b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	write(1, "rb\n", 3);
}
void	rr(t_node **stack_a, t_node **stack_b)
{
	if ((*stack_a) && (*stack_a)->next)
		ra(stack_a);
	if ((*stack_b) && (*stack_b)->next)
		rb(stack_b);
	write(1, "rr\n", 3);
}
