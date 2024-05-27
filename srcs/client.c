/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxchen <yuxchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:33:30 by yuxchen           #+#    #+#             */
/*   Updated: 2024/04/12 13:55:23 by yuxchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_signal(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			if ((str[i] >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			j++;
			usleep(420);
		}
		i++;
	}
	j = 0;
	while (j < 8)
	{
		kill(pid, SIGUSR1);
		usleep(420);
		j++;
	}
}

bool	is_valid_pid(char *pid_str)
{
	if (pid_str[0] == '-')
		return (false);
	if (pid_str[0] == '0' && pid_str[1] != '\0')
		return (false);
	while (*pid_str)
	{
		if (!ft_isdigit(*pid_str))
			return (false);
		pid_str++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (is_valid_pid(av[1]) != 1 || pid <= 0)
		{
			ft_printf("[Error] Invalid PID!");
			return (0);
		}
		str = av[2];
		send_signal(pid, str);
	}
	else
		ft_printf("[Error] Invalid input! Example: ./client <PID> <MESSAGE>");
	return (0);
}
