/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:23:20 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/08/23 13:13:21 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main (int argc, char* argv[])
{
	int s_pid;
	int c_pid;
	int counter = -1;

	c_pid = getpid();
	printf("my pid is:%i", c_pid);
	// if (argc != 3)
	// {
	// 	printf ("error, format correctly");
	// 	return (1);
	// }
	s_pid = atoi(argv[1]);
	while (++counter != 8)
	{
		kill (s_pid, SIGUSR1);
		counter++;
	}
	if (counter == 8)
	{
		counter = 0;
		return (0);
	}
	// if (atoi (argv[2]) == 1)
	// 	kill (pid, SIGUSR1);
	// else if (atoi(argv[2]) == 2)
	// 	kill (pid, SIGUSR2);
	// else
	// 	printf("Error, try again");
}