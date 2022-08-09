/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:28:18 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/08/09 20:30:52 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/_types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void signal_handler(int signum)
{
	static int test = 0xFF;
	static int bits = 0;
	printf ("number: %i\n", test);
	printf ("bits: %i\n", bits);
 	if (signum == 30)
	{
 		printf("got signal 1\n");
		test++;
		bits++;
	}
 	if (signum == 31)
	{
 		printf ("got signal 2\n");
		test--;
		bits++;
	}
	if (bits == 8)
	{
		printf ("end\n");
		bits = 0;
		test = 0xFF;
	}
}

int main (int argc, char *argv[])
{
	// char a = 0xFF;
	// char b = 0xF0;
	// int i = 0;
	pid_t	pid;
	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR1,signal_handler);
	signal(SIGUSR2,signal_handler);
	while (1)
		pause();
	return (0);
}
