/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:33:25 by scartage          #+#    #+#             */
/*   Updated: 2022/03/25 17:03:27 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include	<unistd.h>
# include	<stdlib.h>
# include	<signal.h> 
# include	"libft/libft.h"
# include	"printf/ft_printf.h"

typedef struct s_byna
{
	char	character;
	int		current_bit;
	int		starter;
}	t_byna;

#endif
