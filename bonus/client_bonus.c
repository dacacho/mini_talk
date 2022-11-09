/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/09 15:27:15 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

int	set_pid(char *str)
{
	t_a	arg;

	arg.pid = 0;
	arg.i = 0;
	while (str[arg.i])
		arg.pid = arg.pid * 10 + (str[arg.i++] - 48);
	return (arg.pid);
}

void	set_bin(char *pid, char *str)
{
	t_a		arg;

	arg.i = -1;
	while (str[++arg.i] != '\0')
	{
		arg.x = -1;
		while (++arg.x < 8)
		{
			if ((str[arg.i] >> arg.x & 1))
				kill(set_pid(pid), SIGUSR2);
			else
				kill(set_pid(pid), SIGUSR1);
			usleep(80);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		write(1, "Wrong number of arguments.", 26);
	else
	{
		set_bin(av[1], av[2]);
		set_bin(av[1], "\n");
	}
	return (0);
}
