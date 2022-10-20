/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:30:14 by scartage          #+#    #+#             */
/*   Updated: 2022/03/25 19:16:16 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 *Funcion que pasa de binario a decial,
 *despues imprime en pantalla caracter por caracter.
 *Ademas de convertir y mostrar los caracteres, esta
 *funcion se encarga de avisarle al cliente cada vez que 
 *escucha una senal, enviando un SIGUSR2 solo cuando ya se
 *ha impreso todo el texto pasado
 */

static void	desifrado(int sig, int client_pid)
{
	static t_byna	byna;

	if (byna.starter != 1)
	{
		byna.starter = 1;
		byna.character = 0;
		byna.current_bit = 0;
	}
	if (sig == SIGUSR2)
		byna.character = byna.character | 1 << byna.current_bit;
	byna.current_bit++;
	if (byna.current_bit == 8)
	{
		write(1, &byna.character, 1);
		if (byna.character == '\0')
			kill(client_pid, SIGUSR2);
		byna.character = 0;
		byna.current_bit = 0;
	}
	usleep(400);
	kill(client_pid, SIGUSR1);
}

/*
 * funcion con la cual obtenemos mediante
 * estructura el PID de un cliente que nos envia senales.
 * Despues de tener el PID enviamos a desifrar las senales.
 *
 */

static void	get_client_pid(int sig, siginfo_t *info, void *context)
{
	static pid_t	client_pid;

	(void)context;
	client_pid = 0;
	client_pid = info->si_pid;
	desifrado(sig, client_pid);
}

/*servidor, que al comienzo nos muestra su PID
 * luego espera escuchando a que lleguen las senales
 * una vez estas llegan se hacen unas funciones respectivas.
 * El servidor nunca se cierra.
 */

int	main(void)
{
	struct sigaction	sen;

	ft_printf("el PID es: %d\n", getpid());
	sen.sa_sigaction = get_client_pid;
	sen.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sen, NULL);
	sigaction(SIGUSR2, &sen, NULL);
	pause();
	while (1)
		sleep(10);
	return (0);
}
