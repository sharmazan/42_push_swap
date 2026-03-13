/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/13 16:31:10 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	get_bit(int pos, unsigned int c)
{
	return ((1 << pos) & c);
}

int	bits_in_number(int n)
{
	int	bits;

	bits = 0;
	while (n)
	{
		bits++;
		n >>= 1;
	}
	return (bits);
}

int	is_int(char *s)
{
	long	num;
	int		sign;

	if (!s || !*s || ft_strlen(s) > 11)
		return (0);
	sign = 1;
	if ((*s == '+' || *s == '-') && (*s == '-'))
	{
		sign = -1;
		s++;
	}
	if (!*s)
		return (0);
	num = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		num = num * 10 + (*s - '0');
		if ((sign == 1 && num > 2147483647)
			|| (sign == -1 && -(num) < -2147483648L))
			return (0);
		s++;
	}
	return (1);
}

int	verify_arguments_int(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
		if (!is_int(av[i++]))
			return (0);
	return (1);
}
