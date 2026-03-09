/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/09 15:51:09 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_header.h"
#include <unistd.h>

void	pb(t_list **stackA, t_list **stackB)
{
	t_list	*el;

	if (*stackA)
	{
		logmessage("pb");
		el = *stackA;
		*stackA = (*stackA)->next;
		ft_lstadd_front(stackB, el);
	}
}

void	pa(t_list **stackA, t_list **stackB)
{
	t_list	*el;

	if (*stackB)
	{
		logmessage("pa");
		el = *stackB;
		*stackB = (*stackB)->next;
		ft_lstadd_front(stackA, el);
	}
}
