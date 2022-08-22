/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:28:18 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/08/16 12:23:08 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void signal_handler(int signum)
{
	static unsigned char c = 0xFF;
	static int bits = 0;
	printf ("number: %i\n", c);
	printf ("bits: %i\n", bits);
 	if (signum == SIGUSR1)
	{
 		printf("got signal 1 which means '1'\n");
		c ^= 0x80 >> bits;
	}
 	else if (signum == SIGUSR2)
	{
 		printf ("got signal 2 which means '0'\n");
		c |= 0x80 >> bits;
	}
	bits++;
	if (bits == 8)
	{
		write (1, &c, 1);
		bits = 0;
		c = 0xFF;
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
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
