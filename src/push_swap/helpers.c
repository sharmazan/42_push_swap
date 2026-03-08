/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/01/12 18:49:59 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_header.h"
#include <unistd.h>

void logmessage(char *s)
{
	while (*s)
		write(STDOUT, s++, 1);
	write(STDOUT, "\n", 1);
}

void logerr(char *s)
{
	while (*s)
		write(STDERR, s++, 1);
	write(STDERR, "\n", 1);
}

void	errexit(char *s)
{
	logerr(s);
	exit(1);
}

void	print_number(void *number)
{
	ft_printf("%d\n", *(int *)number);
}

void	print_pointer(void *pointer)
{
	ft_printf("%p\n", pointer);
}

void	print_stack(void *stack)
{
	logmessage("print_stack");
	ft_lstiter(stack, print_number);
}
