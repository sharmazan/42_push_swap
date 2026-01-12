/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/01/12 16:40:07 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/libftprintf.h"
#include "../inc/ft_header.h"
#include "../libft/libft.h"
#include <stdlib.h>

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
	}
}

int	main(int ac, char **av)
{
	verify_arguments(ac, av);
	return (0);
}
