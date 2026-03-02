/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/01/12 18:49:59 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_header.h"


int	sorted(t_list *stack)
{
	t_list  	*el;
	int			flag;

	flag = 1;
	while (stack)
	{
		el = stack;
		if (el->next)
			flag = *(int *)el->content <= *(int *)el->next->content;
		stack = el->next;
		if (!flag)
			break ;
	}
	return (flag);
}

void	pb(t_list **stackA, t_list **stackB)
{
	t_list  *el;

	if (*stackA)
	{
		logmessage("pb");
		el = *stackA;
		*stackA = (*stackA)->next;
		el->next = *stackB;
		*stackB = el;
	}
}
