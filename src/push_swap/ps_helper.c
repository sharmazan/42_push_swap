/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/13 16:31:10 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ra(t_list **stack)
{
	logmessage("ra");
	rotate(stack);
}

void	rb(t_list **stack)
{
	logmessage("rb");
	rotate(stack);
}

void	rra(t_list **stack)
{
	logmessage("rra");
	reverse_rotate(stack);
}

void	rrb(t_list **stack)
{
	logmessage("rrb");
	reverse_rotate(stack);
}
