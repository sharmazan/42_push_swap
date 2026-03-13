/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/03/13 16:31:10 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/libftprintf.h"
#include "ft_header.h"
#include <stdlib.h>

// void	merge_sorted_halves(int *a, size_t middle, size_t len)
// {
// 	int		sorted[len];
// 	size_t	n;
// 	size_t	i;
// 	size_t	j;

// 	n = 0;
// 	i = 0;
// 	j = middle;
// 	while (n < len)
// 	{
// 		if (i < middle && j < len)
// 		{
// 			if (a[i] < a[j])
// 				sorted[n] = a[i++];
// 			else
// 				sorted[n] = a[j++];
// 		}
// 		else if (i < middle)
// 			sorted[n] = a[i++];
// 		else
// 			sorted[n] = a[j++];
// 		n++;
// 	}
// 	while (n--)
// 		a[n] = sorted[n];
// }

// void	sort_array(int *a, size_t len)
// {
// 	size_t	middle;

// 	if (len == 1)
// 		return ;
// 	middle = len / 2;
// 	sort_array(a, middle);
// 	sort_array(a + middle, len - middle);
// 	merge_sorted_halves(a, middle, len);
// }

// void    selection_sort_stacks(t_list **stack_a, t_list **stack_b)
// {
//    void    (*op)(t_list * *stack);

//    int i, num_count;
//    while (*stack_a && (*stack_a)->next)
//    {
//        num_count = ft_lstsize(*stack_a);
//        i = min_index_in_stack(*stack_a);
//        op = ra;
//        if (i > num_count - i)
//        {
//            op = rra;
//            i = num_count - i;
//        }
//        while (i--)
//            op(stack_a);
//        pb(stack_a, stack_b);
//    }
//    while (*stack_b)
//        pa(stack_a, stack_b);
// }

void	normalize_stack(t_list **stack, int *arr, int len)
{
	t_list	*el;

	el = *stack;
	while (el)
	{
		*(int *)(el->content) = index_in_array(*(int *)(el->content), arr, len);
		el = el->next;
	}
}

void	radix_sort_stacks(t_list **stack_a, t_list **stack_b, int num_count)
{
	int	i;
	int	max_bits;

	max_bits = bits_in_number(num_count - 1);
	i = 0;
	while (i < max_bits)
	{
		num_count = ft_lstsize(*stack_a);
		while (num_count)
		{
			if (get_bit(i, *(int *)(*stack_a)->content))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			num_count--;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

// void	print_number(void *number)
// {
// 	ft_printf("%d\n", *(int *)number);
// }

// void	print_stack(void *stack)
// {
// 	logmessage("print_stack");
// 	ft_lstiter(stack, print_number);
// }

void	fast_sort_stacks(t_list **stack_a, t_list **stack_b, int num_count)
{
	if (num_count == 2)
		fast_sort_two_numbers(stack_a);
	else if (num_count == 3)
		fast_sort_three_numbers(stack_a);
	(void)stack_b;
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*array;
	int		num_count;

	if (ac == 1)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	verify_and_store_numbers(ac, av, &stack_a);
	num_count = stack_to_array(stack_a, &array);
	if (sorted(stack_a))
		clear_and_exit(array, &stack_a, &stack_b);
	sort_array(array, num_count);
	if (is_duplicates(array, num_count))
		logmessage("Error");
	else
	{
		normalize_stack(&stack_a, array, num_count);
		if (num_count > 5)
			radix_sort_stacks(&stack_a, &stack_b, num_count);
		else
			fast_sort_stacks(&stack_a, &stack_b, num_count);
	}
	clear_and_exit(array, &stack_a, &stack_b);
}
