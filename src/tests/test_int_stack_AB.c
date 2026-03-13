/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int_stack_AB.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/13 15:19:22 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct my_int_stack_struct
// {
// 	int							number;
// 	struct my_int_stack_struct	*next;
// }								my_stack;

// void	print_stack(my_stack *stack)
// {
// 	my_stack	*el;

// 	printf("Printing stack %p\n", stack);
// 	el = stack;
// 	while (el)
// 	{
// 		printf("Number is %d\n", el->number);
// 		el = el->next;
// 	}
// }

// void	free_stack(my_stack *stack)
// {
// 	my_stack	*el;

// 	while (stack)
// 	{
// 		el = stack;
// 		stack = el->next;
// 		free(el);
// 	}
// }

// int	sorted(my_stack *stack)
// {
// 	my_stack	*el;
// 	int			flag;

// 	flag = 1;
// 	while (stack)
// 	{
// 		el = stack;
// 		if (el->next)
// 			flag = el->number <= el->next->number;
// 		stack = el->next;
// 		if (!flag)
// 			break ;
// 	}
// 	return (flag);
// }

// void	pb(my_stack **stack_a, my_stack **stack_b)
// {
// 	my_stack	*el;

// 	if (*stack_a)
// 	{
// 		el = *stack_a;
// 		*stack_a = (*stack_a)->next;
// 		el->next = *stack_b;
// 		*stack_b = el;
// 	}
// }

// void	read_arguments(my_stack **stack, int ac, char **av)
// {
// 	int			i;
// 	my_stack	*el;

// 	i = 1;
// 	while (i < ac)
// 	{
// 		el = malloc(sizeof(my_stack));
// 		el->number = atoi(av[i]);
// 		el->next = *stack;
// 		*stack = el;
// 		i++;
// 	}
// }

// void	read_arguments_backwards(my_stack **stack, int ac, char **av)
// {
// 	int			i;
// 	my_stack	*el;

// 	i = ac - 1;
// 	while (i > 0)
// 	{
// 		el = malloc(sizeof(my_stack));
// 		el->number = atoi(av[i]);
// 		el->next = *stack;
// 		*stack = el;
// 		i--;
// 	}
// }

// void	read_arguments_backwards(my_stack **stack, int ac, char **av)
// {
// 	int			i;
// 	my_stack	*el;
// 	my_stack	*last;

// 	last = *stack;
// 	while (last && last->next)
// 		last = last->next;
// 	i = 1;
// 	while (i < ac)
// 	{
// 		el = malloc(sizeof(my_stack));
// 		el->number = atoi(av[i]);
// 		el->next = NULL;
// 		if (last)
// 			last->next = el;
// 		else
// 		{
// 			*stack = el;
// 			last = el;
// 		}
// 		i++;
// 	}
// }

// int	main(int ac, char **av)
// {
// 	my_stack	*stack_a;
// 	my_stack	*stack_b;

// 	printf("%d arguments provided\n", ac);
// 	if (ac == 1)
// 	{
// 		printf("Provide one or more numbers\n");
// 		return (1);
// 	}
// 	stack_a = NULL;
// 	stack_b = NULL;
// 	// read_arguments(&stack_a, ac, av);
// 	read_arguments_backwards(&stack_a, ac, av);
// 	print_stack(stack_a);
// 	print_stack(stack_b);
// 	if (sorted(stack_a))
// 		printf("A is sorted\n");
// 	else
// 		printf("A is not sorted\n");
// 	if (sorted(stack_b))
// 		printf("B is sorted\n");
// 	else
// 		printf("B is not sorted\n");
// 	pb(&stack_a, &stack_b);
// 	print_stack(stack_a);
// 	print_stack(stack_b);
// 	if (sorted(stack_a))
// 		printf("A is sorted\n");
// 	else
// 		printf("A is not sorted\n");
// 	if (sorted(stack_b))
// 		printf("B is sorted\n");
// 	else
// 		printf("B is not sorted\n");
// 	free_stack(stack_a);
// 	free_stack(stack_b);
// 	return (0);
// }
