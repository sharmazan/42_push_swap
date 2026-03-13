/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/13 14:08:53 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_header.h"

void	store_numbers(int ac, char **av, t_list **stack)
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

void	verify_and_store_numbers_from_string(char *s, t_list **stack)
{
	char	**args;
	int		count;
	int		error;

	error = 0;
	args = ft_split(s, ' ');
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
	if (!verify_arguments_int(count, args))
		error = 1;
	else
		store_numbers(count, args, stack);
	while (count--)
		free(args[count]);
	free(args);
	if (error)
		errexit("Error");
}

void	verify_and_store_numbers(int ac, char **av, t_list **stack)
{
	if (ac == 2)
		verify_and_store_numbers_from_string(av[1], stack);
	else
	{
		if (!verify_arguments_int(ac - 1, av + 1))
			errexit("Error");
		store_numbers(ac - 1, av + 1, stack);
	}
}
