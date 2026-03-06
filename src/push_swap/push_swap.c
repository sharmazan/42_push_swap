/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/01/12 18:49:59 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/libftprintf.h"
#include "../inc/ft_header.h"
#include <stdlib.h>

static void	print_stack(void *stack)
{
	logmessage("print_stack");
	ft_lstiter(stack, print_number);
}

static void	verify_int(char *s)
{
	char	*converted;
	size_t	len;

	len = ft_strlen(s);
	converted = ft_itoa(ft_atoi(s));
	if (!converted)
		errexit("malloc Error");
	if (ft_strncmp(s, converted, len + 1))
	{
		free(converted);
		errexit("Error");
	}
	free(converted);
}

// ft_printf("%d\n", ft_atoi(av[i++]));
static void	verify_arguments(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
		verify_int(av[i++]);
}

// logmessage("store_numbers");
// ft_printf("%d converted\n", *n);
// ft_printf("%d stored\n", *(int *)(el->content));
// ft_printf("List size: %d\n", ft_lstsize(*stack));
// ft_printf("stack: %p\n", *stack);
// print_stack(*stack);
static void	store_numbers(int ac, char **av, t_list **stack)
{
	int		i;
	int		*n;
	t_list	*el;

	i = 0;
	while (i < ac)
	{
		n = malloc(sizeof(int));
		if (!n)
		{
			ft_lstclear(stack, free);
			errexit("malloc Error");
		}
		*n = ft_atoi(av[i++]);
		el = ft_lstnew(n);
		if (!el)
		{
			ft_lstclear(stack, free);
			errexit("malloc Error");
		}
		ft_lstadd_back(stack, el);
	}
}

void verify_and_store_numbers(int ac, char **av, t_list **stack)
{
	char	**args;
	int		count;

	if (ac == 1)
		exit(0);
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			errexit("malloc Error");
		count = 0;
		while (args[count])
			count++;
		if (count == 0)
		{
			free(args);
			exit(0);
		}
		verify_arguments(count, args);
		store_numbers(count, args, stack);
		while (count--)
			free(args[count]);
		free(args);
		return ;
	}
	verify_arguments(ac - 1, av + 1);
	store_numbers(ac - 1, av + 1, stack);
}

int	main(int ac, char **av)
{
	t_list	*stackA;
	t_list	*stackB;

	stackA = NULL; // malloc(sizeof(t_list *));
	stackB = NULL;
	// logmessage("verify_arguments");

	// verify_arguments(ac, av);
	// // ft_printf("stackA: %p\n", stackA);
	// // logmessage("store_numbers");
	verify_and_store_numbers(ac, av, &stackA);
	// logmessage("stackA: ");
	// print_pointer(stackA);
	// ft_printf("stackA: %p\n", stackA);
	// print_stack(stackA);
	if (sorted(stackA))
	{
		ft_lstclear(&stackA, free);
		ft_lstclear(&stackB, free);
		return (0);
	}
	// ft_lstiter(stackA, print_pointer);
	// ft_lstiter(stackA, print_number);

	// logmessage("stackB: ");
	// print_pointer(stackB);
	// print_stack(stackB);
	// if (sorted(stackB))
	// 	ft_printf("B is sorted\n");
	// else
	// 	ft_printf("B is not sorted\n");
	// pb(&stackA, &stackB);
	// print_stack(stackA);
	// print_stack(stackB);
	// if (sorted(stackA))
	// 	ft_printf("A is sorted\n");
	// else
	// 	ft_printf("A is not sorted\n");
	// if (sorted(stackB))
	// 	ft_printf("B is sorted\n");
	// else
	// 	ft_printf("B is not sorted\n");

	// pa(&stackA, &stackB);
	// print_stack(stackA);
	// print_stack(stackB);
	// if (sorted(stackA))
	// 	ft_printf("A is sorted\n");
	// else
	// 	ft_printf("A is not sorted\n");
	// if (sorted(stackB))
	// 	ft_printf("B is sorted\n");
	// else
	// 	ft_printf("B is not sorted\n");

	// ra(&stackA);
	// print_stack(stackA);
	// print_stack(stackB);

	logmessage("Save numbers to an array");
	int	numbers = ft_lstsize(stackA);
	ft_printf("There is %d numbers\n", numbers);
	int	*a = malloc(numbers * sizeof(int));
	if (!a)
		errexit("Malloc error");
	int	i = 0;
	while (i < numbers)
	{
		a[i] = *(int *)stackA->content;
		rotate(&stackA);
		ft_printf("%d\n", a[i]);
		i++;
	}
	logmessage("Printing stack A");
	print_stack(stackA);


	// logmessage("Normalize stack A");

	logmessage("free stacks");
	free(a);
	ft_lstclear(&stackA, free);
	ft_lstclear(&stackB, free);
	return (0);
}
