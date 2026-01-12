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

static void	errexit(char *s)
{
	ft_fprintf(STDERR, "%s\n", s);
	exit(1);
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
	{
		verify_int(av[i]);
		ft_printf("%d\n", ft_atoi(av[i++]));
	}
}

static void	store_numbers(int ac, char **av, t_list **stack)
{
	int		i;
	int		*n;
	t_list	*el;

	i = 1;
	n = malloc(sizeof(int));
	if (!n)
	{
		ft_lstclear(stack, free);
		errexit("malloc Error");
	}
	while (i < ac)
	{
		*n = ft_atoi(av[i++]);
		ft_printf("%d converted\n", *n);
		el = ft_lstnew(n);
		if (!el)
		{
			ft_lstclear(stack, free);
			errexit("malloc Error");
		}
		ft_lstadd_back(stack, el);
		ft_printf("%d stored\n", *(int *)(el->content));
		ft_printf("List size: %d\n", ft_lstsize(*stack));
		ft_printf("stack: %p\n", *stack);
		ft_printf("first el: %p\n", **stack);
	}
}

static void	print_number(void *number)
{
	ft_printf("%d\n", *(int *)number);
}

static void	print_pointer(void *pointer)
{
	ft_printf("%p\n", pointer);
}

// static void	print_stack(void *stack)
// {
// 	ft_lstiter(stack, print_number);
// }

int	main(int ac, char **av)
{
	t_list	*stackA;
	t_list	*stackB;

	stackA = NULL; // malloc(sizeof(t_list *));
	stackB = NULL;
	verify_arguments(ac, av);
	write(STDOUT, "verify_arguments", 10);
	ft_printf("stackA: %p\n", stackA);
	store_numbers(ac, av, &stackA);
	write(STDOUT, "store_numbers", 10);
	ft_printf("stackA: %p\n", stackA);
	// print_stack(stackA);
	ft_lstiter(stackA, print_pointer);
	ft_lstiter(stackA, print_number);
	write(STDOUT, "print_stack", 10);
	ft_lstclear(&stackA, free);
	ft_lstclear(&stackB, free);
	return (0);
}
