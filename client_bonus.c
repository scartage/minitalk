/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:30:16 by scartage          #+#    #+#             */
/*   Updated: 2022/03/25 19:20:42 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 *Esta funcion espera a que el servidor
 *envie una senal SIGUSR2 la cual nos
 *indica que ya todo el texto ha sido impreso,
 *por lo tanto el cliente se puede cerrar.
 */

static void	end_server(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("mensaje completado\n");
		exit(0);
	}
}

/*
 * Nos indica mediante la recepcion de una
 * senal SIGUSR1 que el servidor recibio
 * correctamente una senal
 */

static void	recibiendo_server(int sig)
{
	static int	recibido = 0;

	if (sig == SIGUSR1)
	{
		ft_printf("senal recibida\n");
		recibido++;
		usleep(200);
	}
}

/*
 * Esta funcion manda el char pasado a binario al servidor
 * mediante senales.
 *
 * SIGURS2 = 1
 * SIGURS1 = 0
 * con su PID especifico.
 */

void	send_char(int pid, unsigned char caracter)
{
	int	current_bit;

	current_bit = 0;
	while (current_bit < 8)
	{
		if (0 != (caracter & 1 << current_bit))
		{
			kill(pid, SIGUSR2);
			usleep(300);
		}
		else
		{
			kill(pid, SIGUSR1);
			usleep(300);
		}	
		current_bit++;
		usleep(500);
	}
}

/*
 * Funcion a la que le pasamos como argv[1] el PID (en numero)
 * y en el argv[2] el mensaje (en string).
 *
 * Este mensaje lo recorremos para enviar a convertir
 * caracter a caracter en binario.
 */

void	mensaje_a_enviar(int pid, char *mensaje)
{
	while (*mensaje)
	{
		send_char(pid, *mensaje);
		mensaje++;
	}
	send_char(pid, '\n');
	send_char(pid, *mensaje);
}

/*
 * Parte principal, donde le pasamos como paramentro
 * el PID (numero de identificacion de otro proceso)
 * y el mensaje a enviar al servidor.
 */

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("el uso correcto es: ./client [PID del server] [mensaje]\n");
		exit(0);
	}	
	signal(SIGUSR1, recibiendo_server);
	signal(SIGUSR2, end_server);
	mensaje_a_enviar(ft_atoi(argv[1]), argv[2]);
	pause();
	return (0);
}
