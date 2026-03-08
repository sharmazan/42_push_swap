/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/01/12 16:15:51 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEADER_H
# define FT_HEADER_H

# ifndef STDOUT
#  define STDOUT 1
# endif
# ifndef STDERR
#  define STDERR 2
# endif

#include "../libft/libft.h"
#include "../ft_printf/libftprintf.h"

int     sorted(t_list *stack);
void	pa(t_list **stackA, t_list **stackB);
void	pb(t_list **stackA, t_list **stackB);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

void    logmessage(char *s);
void    logerr(char *s);
void	errexit(char *s);
void	print_number(void *number);
void	print_pointer(void *pointer);

#endif
