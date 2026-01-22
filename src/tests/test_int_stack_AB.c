/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int_stack_AB.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/01/22 18:49:20 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct my_int_stack_struct
{
	int							number;
	struct my_int_stack_struct	*next;
}								my_stack;

void	print_stack(my_stack *stack)
{
	my_stack	*el;

	printf("Printing stack %p\n", stack);
	el = stack;
	while (el)
	{
		printf("Number is %d\n", el->number);
		el = el->next;
	}
}

void	free_stack(my_stack *stack)
{
	my_stack	*el;

	while (stack)
	{
		el = stack;
		stack = el->next;
		free(el);
	}
}

int	sorted(my_stack *stack)
{
	my_stack	*el;
	int			flag;

	flag = 1;
	while (stack)
	{
		el = stack;
		if (el->next)
			flag = el->number >= el->next->number;
		stack = el->next;
		if (!flag)
			break ;
	}
	return (flag);
}

int	main(int ac, char **av)
{
	my_stack	*stackA;
	my_stack	*stackB;
	my_stack	*el;
	int			i;

	if (ac == 1)
	{
		printf("Provide one or more numbers\n");
		return (1);
	}
	stackA = NULL;
	i = 1;
	while (i < ac)
	{
		el = malloc(sizeof(my_stack));
		el->number = atoi(av[i]);
		el->next = stackA;
		stackA = el;
		i++;
	}
	print_stack(stackA);
	if (sorted(stackA))
		printf("Sorted\n");
	else
		printf("Not sorted\n");
	free_stack(stackA);
	return (0);
}
