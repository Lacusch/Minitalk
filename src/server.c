/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 06:04:42 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/08/08 15:52:55 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/_types.h>
#include "../libft/libft.h"

void signal_handler(int signum)
{
	
}
int main (void)
{
	pid_t	pid;
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}