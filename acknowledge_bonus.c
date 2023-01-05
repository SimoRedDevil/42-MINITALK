/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acknowledge_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 17:42:04 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/01 21:35:21 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_acknowledge(int pid, char *bits)
{
	int	i;

	i = 0;
	while (bits[i] && bits[i] == '0')
		i++;
	if (i == 8)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("Fail to send the acknowledge signal !", 1);
			exit(1);
		}
	}
}
