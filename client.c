/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:04:15 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/01 21:39:41 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int	server_pid;
	int	i;

	if (argc == 3)
	{
		i = 0;
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
		{
			ft_putstr_fd("The server PID is not valid !", 1);
			exit(1);
		}
		while (argv[2][i])
		{
			ft_send_signal(argv[2][i], server_pid);
			i++;
		}
	}
}
