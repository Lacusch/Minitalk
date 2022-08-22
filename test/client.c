/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:23:20 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/08/22 17:57:13 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main (int argc, char* argv[])
{
	int pid;
	int counter = -1;
	// if (argc != 3)
	// {
	// 	printf ("error, format correctly");
	// 	return (1);
	// }
	pid = atoi(argv[1]);
	while (counter != 8)
	{
		kill (pid, SIGUSR1);
	}
	if (counter == 8)
	{
		counter = -1;
		return (0);
	}
	// if (atoi (argv[2]) == 1)
	// 	kill (pid, SIGUSR1);
	// else if (atoi(argv[2]) == 2)
	// 	kill (pid, SIGUSR2);
	// else
	// 	printf("Error, try again");
	return (0);
}