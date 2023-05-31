/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mivendit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:34:45 by mivendit          #+#    #+#             */
/*   Updated: 2023/01/27 13:34:49 by mivendit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}

/*La funzione inizia scorrendo la stringa str alla ricerca di eventuali 
spazi bianchi o caratteri di controllo all'inizio della stringa. 
Successivamente, viene controllato se il primo carattere
valido è un segno + o -, a cui viene assegnato il valore 1 o -1 di conseguenza. 
Infine, la funzione continua a scorrere la stringa e ad accumulare il valore
numerico finché non incontra un carattere che non è una cifra. 
Il risultato finale viene moltiplicato per sign per ottenere il
risultato corretto.
*/
