/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 06:04:42 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/09/15 11:53:18 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "minitalk.h"

// added prototype signal handler
// Can test with kill -s SIGUSR1 "pip" or
// kill -s SIGUSR2 "pip"
void signal_handler(int signum)
{
	static int bits;

	if (signum == 30)
	{
		ft_printf("got signal SIGUSR1\n");
	}
	if (signum == 31)
	{
		ft_printf ("got signal SIGUSR2\n");
	}
	if (signum == 2)
	{
		ft_printf("\ninterrupted with the command line\n");
		raise(3);
	}
}
int main (void)
{
	pid_t	pid;
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1,signal_handler);
	signal(SIGUSR2,signal_handler);
	signal(SIGINT,signal_handler);
	while (1)
		pause();
	return (0);
}
