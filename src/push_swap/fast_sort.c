/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/13 16:31:10 by ssharmaz         ###   ########.fr       */
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

void	fast_sort_two_numbers(t_list **stack_a)
{
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		ra(stack_a);
}

void	fast_sort_three_numbers(t_list **stack_a)
{
	int	min_pos;

	min_pos = min_index_in_stack(*stack_a);
	if (min_pos == 2)
	{
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
		rra(stack_a);
		return ;
	}
	else if (min_pos == 1)
	{
		if (*(int *)(*stack_a)->content
				> *(int *)(*stack_a)->next->next->content)
			ra(stack_a);
		else
			sa(stack_a);
		return ;
	}
	rra(stack_a);
	sa(stack_a);
}
