/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/13 16:31:10 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <unistd.h>

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*el;

	if (*stack_a)
	{
		logmessage("pb");
		el = *stack_a;
		*stack_a = (*stack_a)->next;
		ft_lstadd_front(stack_b, el);
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*el;

	if (*stack_b)
	{
		logmessage("pa");
		el = *stack_b;
		*stack_b = (*stack_b)->next;
		ft_lstadd_front(stack_a, el);
	}
}
