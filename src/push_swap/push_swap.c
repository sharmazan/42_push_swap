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

int	stack_to_array(t_list *stack, int **a)
{
	// logmessage("Save numbers to an array");
	int	numbers = ft_lstsize(stack);
	// ft_printf("There is %d numbers\n", numbers);
	*a = malloc(numbers * sizeof(int));
	if (!a)
		errexit("Malloc error");
	int	i = 0;
	while (i < numbers)
	{
		(*a)[i] = *(int *)stack->content;
		rotate(&stack);
		// ft_printf("%d\n", a[i]);
		i++;
	}
	return numbers;
}

void	clear_and_exit(int *a, t_list **stackA, t_list **stackB)
{
	free(a);
	ft_lstclear(stackA, free);
	ft_lstclear(stackB, free);
	exit(0);
}

int	find_in_array(int n, int *a, size_t len)
{
	size_t	pos, l, r;

	pos = len / 2;
	l = 0;
	r = len;
	while (n != a[pos])
	{
		if (n < a[pos])
		{
			r = pos - 1;
			pos = (r - l) /2;
		}
		else
		{
			l = pos + 1;
			pos = l + (r - l) / 2;
		}
		if (l > r)
			return -1;
	}
	return pos;
}

void	sort_array(int *a, size_t len)
{
	size_t	n, i, j, middle;
	int sorted[len];

	// logmessage("Sorting array");
	if (len == 1)
		return;
	middle = len / 2;
	sort_array(a, middle);
	sort_array(a + middle, len - middle);
	n = 0;
	i = 0;
	j = middle;
	while (n < len)
	{
		if (i < middle && j < len)
		{
			if (a[i] < a[j])
				sorted[n] = a[i++];
			else
				sorted[n] = a[j++];
		}
		else if (i < middle)
			sorted[n] = a[i++];
		else 
			sorted[n] = a[j++];
		n++;
	}
	while (n--)
		a[n] = sorted[n];
}

int	is_duplicates(int *a, size_t len)
{
	size_t	i;
	
	// logmessage("Verify duplicates");
	if (len < 2)
		return 0;
	i = 0;
	while (i++ < len - 1)
		if (a[i - 1] == a[i])
			return 1;
	return 0;
}

int	min_index_in_stack(t_list *stack)
{
	int	min_pos, min, pos;
	t_list	*el;

	if (!stack)
		return -1;
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
	return min_pos;
}

void	selection_sort_stacks(t_list **stackA, t_list **stackB)
{
	int	i, num_count;
	void	(*op)(t_list **stack);

	while (*stackA && (*stackA)->next)
	{
		num_count = ft_lstsize(*stackA);
		i = min_index_in_stack(*stackA);
		// ft_printf("NUmbers in A: %d, minimum index: %d\n", num_count, i);
		op = ra;
		if (i > num_count - i)
		{
			op = rra;
			i = num_count - i;
		}
		while (i--)
			op(stackA);
		pb(stackA, stackB);
	}
	while (*stackB)
		pa(stackA, stackB);
	// print_stack(*stackA);
	// rra(stackA);
	// print_stack(*stackB);

	// pb(stackA, stackB);
	// pb(stackA, stackB);

	// print_stack(*stackB);
	// rrb(stackB);
	// print_stack(*stackB);
}

void	sort_stacks(t_list **stackA, t_list **stackB)
{
	// logmessage("Sorting stacks");
	selection_sort_stacks(stackA, stackB);
}

void	print_array(int *a, int len)
{
	int i;

	i = 0;
	ft_printf("Printing array\n");
	while (i < len)
		ft_printf("%d\n", a[i++]);
}

int	main(int ac, char **av)
{
	t_list	*stackA;
	t_list	*stackB;
	int		*array = NULL;
	int		num_count;

	stackA = NULL;
	stackB = NULL;
	
	verify_and_store_numbers(ac, av, &stackA);
	// logmessage("Printing stack A");
	// print_stack(stackA);

	num_count = stack_to_array(stackA, &array);
	// print_array(array, num_count);
	if (sorted(stackA))
		clear_and_exit(array, &stackA, &stackB);
	sort_array(array, num_count);

	if (is_duplicates(array, num_count))
		logmessage("Error");
	else
		sort_stacks(&stackA, &stackB);

	clear_and_exit(array, &stackA, &stackB);
}

	// logmessage("stackA: ");
	// print_pointer(stackA);
	// ft_printf("stackA: %p\n", stackA);
	// print_stack(stackA);

	// ft_lstiter(stackA, print_pointer);
	// ft_lstiter(stackA, print_number);

	// logmessage("stackB: ");
	// print_pointer(stackB);
	// print_stack(stackB);

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

	// ra(&stackA);
	// rb(&stackB);
	// print_stack(stackA);
	// print_stack(stackB);
	// pa(&stackA, &stackB);
	// print_stack(stackA);
	// print_stack(stackB);


	// print_array(array, num_count);
	// // ft_printf("Numbers %d\n", num_count);
	// int i = 0;
	// while (i < num_count)
	// {
	// 	ft_printf("Index of %d is %d\n", array[i], find_in_array(array[i], array, num_count));
	// 	i++;
	// }
	// ft_printf("Index of 15 is %d\n", find_in_array(15, array, num_count));


	// print_stack(stackA);
	// reverse_rotate(&stackA);
	// print_stack(stackA);

	// print_stack(stackA);
	// rra(&stackA);
	// print_stack(stackA);

	// pb(&stackA, &stackB);
	// pb(&stackA, &stackB);
	// pb(&stackA, &stackB);

	// print_stack(stackB);
	// rrb(&stackB);
	// print_stack(stackB);

