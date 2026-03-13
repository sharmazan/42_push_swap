/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/13 17:24:43 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	min_index_in_stack(t_list *stack)
{
	t_list	*el;
	int		min_pos;
	int		min;
	int		pos;

	if (!stack)
		return (-1);
	el = stack;
	min = *(int *)el->content;
	min_pos = 0;
	pos = 0;
	while (el->next)
	{
		el = el->next;
		pos++;
		if (*(int *)el->content < min)
		{
			min = *(int *)el->content;
			min_pos = pos;
		}
	}
	return (min_pos);
}

// int	max_index_in_stack(t_list *stack)
// {
// 	t_list	*el;
// 	int		max_pos;
// 	int		max;
// 	int		pos;

// 	if (!stack)
// 		return (-1);
// 	el = stack;
// 	max = *(int *)el->content;
// 	max_pos = 0;
// 	pos = 0;
// 	while (el->next)
// 	{
// 		el = el->next;
// 		pos++;
// 		if (*(int *)el->content > max)
// 		{
// 			max = *(int *)el->content;
// 			max_pos = pos;
// 		}
// 	}
// 	return (max_pos);
// }

void	fast_sort_two_numbers(t_list **stack_a)
{
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		ra(stack_a);
}

void	fast_sort_three_numbers(t_list **stack)
{
	int	min_pos;

	if (sorted(*stack))
		return ;
	min_pos = min_index_in_stack(*stack);
	if (min_pos == 2)
	{
		if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
			sa(stack);
		rra(stack);
		return ;
	}
	else if (min_pos == 1)
	{
		if (*(int *)(*stack)->content
				> *(int *)(*stack)->next->next->content)
			ra(stack);
		else
			sa(stack);
		return ;
	}
	rra(stack);
	sa(stack);
}

void	fast_sort_four_numbers(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;

	if (sorted(*stack_a))
		return ;
	min_pos = min_index_in_stack(*stack_a);
	if (min_pos == 3)
		rra(stack_a);
	while (min_index_in_stack(*stack_a) != 0)
		ra(stack_a);
	if (!sorted(*stack_a))
	{
		pb(stack_a, stack_b);
		fast_sort_three_numbers(stack_a);
		pa(stack_a, stack_b);
	}
}

void	fast_sort_five_numbers(t_list **stack_a, t_list **stack_b, int len)
{
	int	min_pos;

	if (sorted(*stack_a))
		return ;
	min_pos = min_index_in_stack(*stack_a);
	if (min_pos == len - 1)
		rra(stack_a);
	else if (min_pos > len / 2)
		while (min_index_in_stack(*stack_a) != 0)
			rra(stack_a);
	while (min_index_in_stack(*stack_a) != 0)
		ra(stack_a);
	if (!sorted(*stack_a))
	{
		pb(stack_a, stack_b);
		fast_sort_four_numbers(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
