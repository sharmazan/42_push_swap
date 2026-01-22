/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssharmaz <ssharmaz@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 23:17:00 by ssharmaz          #+#    #+#             */
/*   Updated: 2026/01/22 18:01:55 by ssharmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

typedef struct
{
	char	brand[50];
	int		year;
}			Car;

int	main(void)
{
	Car	mycar;

	mycar.year = 1999;
	strcpy(mycar.brand, "Mersedes");
	printf("My car is %s from %d\n", mycar.brand, mycar.year);
	return (0);
}
