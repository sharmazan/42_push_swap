/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/13 16:31:10 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <unistd.h>

static void	swap(t_list *stack)
{
	int	n;

	n = *(int *)stack->content;
	*(int *)stack->content = *(int *)stack->next->content;
	*(int *)stack->next->content = n;
}

void	sa(t_list **stack)
{
	logmessage("sa");
	swap(*stack);
}

void	sb(t_list **stack)
{
	logmessage("sb");
	swap(*stack);
}
