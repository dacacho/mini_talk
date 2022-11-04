/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danierod <danierod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:36:58 by danierod          #+#    #+#             */
/*   Updated: 2022/11/04 17:21:17 by danierod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void    print(char *str, s_a *arg)
{
    arg->i = -1;
    while (str[++arg->i] != '\0')
        write(1, &str[arg->i], 1);
}

void    stoi(char *str, s_a *arg)
{
    arg->pid = arg->i = 0;
    while (str[arg->i] && str[arg->i] != '\0')
        arg->pid = arg->pid * 10 + (str[arg->i++] - 48);
}
void    bin_conv(char *str, s_a *arg)
{
    arg->i = -1;
    while (str[++arg->i] != '\0')
    {
        arg->bin_str[arg->i] = str[arg->i] >> 1 & 1;
        arg->var++;
    }
    arg->bin_str[arg->i] = '\0';
}
int     main(int ac, char **av)
{
    s_a arg;

    if (ac != 3)
        print("Wrong number of arguments.", &arg);
    
    stoi(av[1], &arg);

    bin_conv(av[2], &arg);

    printf("\n%d\n", arg.pid);
    printf("%s\n", arg.bin_str);
    return (0);
}