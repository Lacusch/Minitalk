/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:55:51 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/09/29 02:37:53 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "minitalk.h"

void	sent_signal(char *str, int pid)
{
	int	bits;
	int	i;

	i = 0;
	bits = -1;
	while (str[i])
	{
		while (++bits < 8)
		{
			if (str[i] & (0x80 >> bits))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(40);
		}
		i++;
	}
}

int	main(int agrc, char *argv[])
{
	int		pid;
	size_t	i;

	i = 0;
	if (agrc != 3)
	{
		ft_printf("Wrong format, format it: \n");
		ft_printf("./server %s than the string in quotes", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (i < ft_strlen(argv[2]))
		sent_signal(&argv[2][i++], ft_atoi(argv[1]));
	ft_printf("The client sent %i messages\n", i);
	return (EXIT_SUCCESS);
}
