/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 06:04:42 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/09/29 03:04:18 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "minitalk.h"

/*
Sinal Handler
*/

void	signal_handler(int signum)
{
	static char	c = 0xFF;
	static int	bits = 0;
	int			pid;

	if (signum == 2)
	{
		write(1, "\nGreetings evaluator, I hope my eval is going well 😀\n", 58);
		write(1, "Interrupted with the command line", 34);
		pid = getpid();
		kill(pid, 3);
	}
	if (signum == 30)
		c ^= 0x80 >> bits;
	else if (signum == 31)
		c |= 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		ft_putchar_fd(c, 1);
		bits = 0;
		c = 0xFF;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal(SIGINT, signal_handler);
	while (1)
		pause();
	return (0);
}
