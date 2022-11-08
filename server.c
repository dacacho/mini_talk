/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/08 21:07:44 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	pp(int nb)
{
	if (nb > 9)
		pp(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

void	unbin(int sig)
{
	static char	c;
	static int	i;

	c = (sig == SIGUSR2) << i++ | c;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = 0;
	pid = getpid();
	write(1, "PID: ", 5);
	pp(pid);
	write(1, "\n\n", 2);
	signal(SIGUSR1, unbin);
	signal(SIGUSR2, unbin);
	while (1)
		pause();
	return (0);
}