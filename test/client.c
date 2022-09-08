/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaszlo- <slaszlo-@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:23:20 by slaszlo-          #+#    #+#             */
/*   Updated: 2022/08/24 12:15:59 by slaszlo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sent_signal (char *string, int pid)
{
	
}
int main (int argc, char* argv[])
{
	int s_pid;
	int counter = -1;
	int i;

	if (argc != 3)
	{
		printf ("error, format correctly");
		return (1);
	}
	s_pid = atoi(argv[1]);
	ft_isdigit(argv[1][i]);
	{
		if (ft_isdigit(argv[1][i]) == 0)
		{
			ft_printf("wrong pid, try again");
			return (0);
		}
		i++;
	}
}