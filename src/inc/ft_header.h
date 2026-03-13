/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/13 16:09:10 by ssharmaz         ###   ########.fr       */
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

# include "../ft_printf/libftprintf.h"
# include "../libft/libft.h"

int		sorted(t_list *stack);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
char	get_bit(int pos, unsigned int c);

void	logmessage(char *s);
void	logerr(char *s);
void	errexit(char *s);

int		stack_to_array(t_list *stack, int **a);
int		bits_in_number(int n);
void	sort_array(int *a, size_t len);
int		is_duplicates(int *a, size_t len);
int		index_in_array(int n, int *a, size_t len);

int		is_int(char *s);
int		verify_arguments_int(int ac, char **av);

void	clear_and_exit(int *a, t_list **stack_a, t_list **stack_b);
void	store_numbers(int ac, char **av, t_list **stack);
void	verify_and_store_numbers(int ac, char **av, t_list **stack);

#endif
