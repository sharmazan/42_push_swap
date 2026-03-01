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
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

static void logmessage(char *s)
{
	while (*s)
		write(STDOUT, s++, 1);
	write(STDOUT, "\n", 1);
}

static void logerr(char *s)
{
	while (*s)
		write(STDERR, s++, 1);
	write(STDERR, "\n", 1);
}

static void	errexit(char *s)
{
	logerr(s);
	exit(1);
}

static void	print_number(void *number)
{
	ft_printf("%d\n", *(int *)number);
}

static void	print_pointer(void *pointer)
{
	ft_printf("%p\n", pointer);
}

static void	print_stack(void *stack)
{
	logmessage("print_stack");
	ft_lstiter(stack, print_number);
}

static void	verify_int(char *s)
{
	if (ft_strncmp(s, ft_itoa(ft_atoi(s)), ft_strlen(s)))
		errexit("Error");
}

// ft_printf("%d\n", ft_atoi(av[i++]));
static void	verify_arguments(int ac, char **av)
{
	int	i;

	if (ac == 1)
		exit(0);
	i = 1;
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

	i = 1;
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

int	main(int ac, char **av)
{
	t_list	*stackA;
	t_list	*stackB;

	stackA = NULL; // malloc(sizeof(t_list *));
	stackB = NULL;
	logmessage("verify_arguments");
	verify_arguments(ac, av);
	ft_printf("stackA: %p\n", stackA);
	logmessage("store_numbers");
	store_numbers(ac, av, &stackA);
	logmessage("stackA: ");
	print_pointer(stackA);
	// ft_printf("stackA: %p\n", stackA);
	print_stack(stackA);
	// ft_lstiter(stackA, print_pointer);
	// ft_lstiter(stackA, print_number);
	logmessage("free stacks");
	ft_lstclear(&stackA, free);
	ft_lstclear(&stackB, free);
	return (0);
}
