/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:47:56 by mel-yous          #+#    #+#             */
/*   Updated: 2023/01/01 21:45:37 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <signal.h>
# include "libft/libft.h"

char	ft_binary2char(const char *binary);
int		ft_send_signal(char c, int s_pid);
void	ft_print_unicode(int *r_bytes, char **unicode);
void	ft_clear_unicode(int *r_bytes, char **unicode);
void	ft_acknowledge(int pid, char *bits);
#endif