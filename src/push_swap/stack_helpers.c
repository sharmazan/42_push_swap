/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/13 16:31:10 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <unistd.h>

void	rotate(t_list **stack)
{
	t_list	*el;

	if (*stack)
	{
		el = *stack;
		*stack = (*stack)->next;
		el->next = NULL;
		ft_lstadd_back(stack, el);
	}
}

void	reverse_rotate(t_list **stack)
{
	t_list	*el;
	t_list	*prev;
	t_list	*head;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		el = head->next;
		prev = head;
		while (el->next)
		{
			prev = el;
			el = el->next;
		}
		prev->next = NULL;
		ft_lstadd_front(stack, el);
	}
}

int	sorted(t_list *stack)
{
	t_list	*el;
	int		flag;

	flag = 1;
	while (stack)
	{
		el = stack;
		if (el->next)
			flag = *(int *)el->content < *(int *)el->next->content;
		stack = el->next;
		if (!flag)
			break ;
	}
	return (flag);
}

int	stack_to_array(t_list *stack, int **a)
{
	int	numbers;
	int	i;

	numbers = ft_lstsize(stack);
	*a = malloc(numbers * sizeof(int));
	if (!a)
		errexit("Malloc error");
	i = 0;
	while (i < numbers)
	{
		(*a)[i] = *(int *)stack->content;
		rotate(&stack);
		i++;
	}
	return (numbers);
}
