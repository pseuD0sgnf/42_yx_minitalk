/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxchen <yuxchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:33:28 by yuxchen           #+#    #+#             */
/*   Updated: 2024/04/12 13:55:10 by yuxchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int sig)
{
	int				bit;
	static t_str	save_str = {0, 0};

	bit = (sig == SIGUSR2);
	save_str.c += ((bit & 1) << save_str.i);
	save_str.i++;
	if (save_str.i == 8)
	{
		ft_printf("%c", save_str.c);
		if (!save_str.c)
			ft_printf("\n");
		save_str.c = 0;
		save_str.i = 0;
	}
}

void	print_welcome(int pid)
{
	ft_printf("\n");
	ft_printf("888b     d888 d8b          d8b 888             888 888      \n");
	ft_printf("8888b   d8888 Y8P          Y8P 888             888 888      \n");
	ft_printf("88888b.d88888                  888             888 888      \n");
	ft_printf("888Y88888P888 888 88888b.  888 888888  8888b.  888 888  888 \n");
	ft_printf("888 Y888P 888 888 888 '88b 888 888        '88b 888 888 .88P \n");
	ft_printf("888  Y8P  888 888 888  888 888 888    .d888888 888 888888K  \n");
	ft_printf("888   '   888 888 888  888 888 Y88b.  888  888 888 888 '88b \n");
	ft_printf("888       888 888 888  888 888  'Y888 'Y888888 888 888  888 \n");
	ft_printf("\n");
	ft_printf("--- Server PID: [%d] ---\n", pid);
	ft_printf("\n");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	print_welcome(pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
